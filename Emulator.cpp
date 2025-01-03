
#include "SDL2/SDL.h"
#include ".\pch.hpp"
#include <iostream>

typedef unsigned char BYTE;       // 0 to 255
typedef char SIGNED_BYTE;         //-128 to 127
typedef unsigned short WORD;      // 16 bit unsigned int
typedef signed short SIGNED_WORD; // 16 bit signed int

class Emulator
{
public:
    Emulator()
    {
    }
    void Update()
    {
    }
    void WriteMemory(WORD address, BYTE data)
    {
    }
    BYTE ReadMemory(WORD address) const
    {
    }
    void LoadRom(BYTE *m_CartridgeMemory, bool *m_MBC1, bool *m_MBC2)
    {
    }
    void HandleBanking(WORD address, BYTE data)
    {

    }
private:
    /// Create gameboy cart representation in memory
    // with char array (string)
    BYTE m_CartridgeMemory[0x200000];

    // three dimensional array that will allow a color matrix to be created
    // will actually draw the graphics
    BYTE m_ScreenData[160][144][3];

    // repsentation of gameboy ram
    BYTE m_Rom[0x1000];

    bool m_MBC1;
    // true false flags to represent the precense of memory bank switching
    // and define bank switching type either m_MBC1 or M_MBC2
    bool m_MBC2;

     /*
         this variable tracks which cartridge ROM bank is active
         ROM bank 0 is always active therefor this value initialized to zero
     */
    BYTE m_CurrentROMBank;

    /*
        this variable tracks how many RAM banks the game will use
        as well as what RAM bank is currently active
    */
    BYTE m_RAMBanks[0x800];

    // RAM banking is not used in MBC2 rom banking mode therefor
    //  m_CurrentRamBank will always be zero
    BYTE m_CurrentRAMBank;
};

Emulator::Emulator()
{
    //initialize class members

    m_MBC1 = false;

    m_MBC2 = false;

    m_CurrentROMBank = 1;

 //  m_CurrentRamBank will always be zero
    m_CurrentRAMBank = 0;

    // fill our catridge memory with 0 to initialize
    memset(m_CartridgeMemory, 0, sizeof(m_CartridgeMemory));

    // pointer to a file object named in
    FILE *in;
    // in set to the value of opening the game file
    in = fopen("Tetris.gb", "rb");
    // read from the catridge memory the first 2.1 million bites
    fread(m_CartridgeMemory, 1, 0x200000, in);
    // close the file
    fclose(in);

    // initialize these variables to prevent null access
    memset(m_RAMBanks, 0, sizeof(m_RAMBanks));
}

void Emulator::Update()
{
    // we can execute MaxCycles clock cycles per second at 60 frames per second
    // define MaxCycles as const because it cannot change
    const int MaxCycles = 69905;
    // integer variable that counts how many times the update loop runs
    int cyclesThisUpdate = 0;

    while (cyclesThisUpdate < MaxCycles)
    {
        // this loop should be something like run the operation code,
        // update the clock, and set the upcoming state for the graphics

        // int cycles = ExecuteNextOpcode();
        // cyclesThisUpdate += cycles;
        // UpdateTimers(cycles);
        // UpdateGraphics(cycles);
        // DoInterupts();
    }
    // this function should draw the updated screen based on the new values
    // RenderScreen();
}
void Emulator::WriteMemory(WORD address, BYTE data)
{
    if (address < 0x8000)
    {
        // establish representation of read only memory
        HandleBanking(address, data); 
    }

    else if ((address >= 0xE000) && (address < 0xFE00))
    {

        if (m_EnableRAM)
        {
            WORD newAddress = address - 0xA000;
            m_RAMBanks[newAddress + (m_CurrentRAMBank *0x2000)] = data; 
        }

        // if we write to echo ram we also write to ram
        m_Rom[address] = data;
        WriteMemory(address - 0x2000, data);
    }
    else if ((address >= 0xFEA0) && (address < 0xFEFF))
    {
        // system reserved memory
    }
    else
    {
        m_Rom[address] = data;
        // freely write to this area in ram
    }
}

//this function cannot modify arguments
BYTE Emulator::ReadMemory(WORD address) const
{
    //read from rom memory bank
    if ((address >= 0x4000) && (address <= 0x7FFF))
    {
        WORD newAddress = address - 0x4000; 
        return m_CartridgeMemory[newAddress + (m_CurrentROMBank * 0x4000)];
    }

    else if ((address >= 0xA000) && (address <= 0xBFFF))
    {
        WORD newAddress = address - 0xA000;
        return m_RAMBanks[newAddress + (m_CurrentRAMBank * 0x2000)]; 
    }
}

void Emulator::LoadRom(BYTE *m_CartridgeMemory, bool *m_MBC1, bool *m_MBC2)
{
    // pointer to a file object named in
    FILE *in;
    // in set to the value of opening the game file
    in = fopen("Tetris.gb", "rb");
    // read from the catridge memory the first 2.1 million bites
    fread(m_CartridgeMemory, 1, 0x200000, in);
    // close the file
    fclose(in);

    /*
    switch statement that looks at cartridge memory at a specific address
    the address is the documented location where developers would specify
    if the game utilized bank switching or not
    there are technically more than two types of bank switching processes
    but these two cover 90+ percent of the gameboy library
    */
    switch (m_CartridgeMemory[0x147])
    {
    case 1:
        *m_MBC1 = true;
        break;
    case 2:
        *m_MBC1 = true;
        break;
    case 3:
        *m_MBC1 = true;
        break;
    case 5:
        *m_MBC2 = true;
        break;
    case 6:
        *m_MBC2 = true;
    default:
        break;
    }
}

void Emulator::HandleBanking(WORD address, BYTE data)
{
    //enable RAM
    if (address < 0x2000)
    {
        if (m_MBC1 || m_MBC2)
        {
            DoRamBankEnable(address, data); 
        }
    }

    //change ROM bank
    else if ((address >= 0x200) && address <0x4000)
    {
        if (m_MBC1 || m_MBC2)
        {
            DoChangeLoROMBank(data); 
        }
    }

    else if ((address >= 0x4000) && (address < 0x6000))
    {
        if(m_MBC1)
        {
            if(m_ROMBanking)
            {
                DoChangeHiRomBank(data); 
            }
            else
            {
                DoRamBankChange(data);     
            }
        }
    }

    else if ((address >= 0x6000) && (address < 0x8000))
    {
        if (m_MBC1)
        {
            DoChangeROMRAMMode(data); 
        }
    }
}

int WinMain()
{
    unique_ptr<Emulator> myEmulator(new Emulator); 

    return 0;
}
