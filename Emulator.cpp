
#include "SDL2/SDL.h"
#include ".\pch.hpp"
#include <iostream>

typedef unsigned char BYTE; //0 to 255
typedef char SIGNED_BYTE; //-128 to 127
typedef unsigned short WORD; //16 bit unsigned int 
typedef signed short SIGNED_WORD;//16 bit signed int 


class Emulator
{
    public:
    Emulator()
    {
           ///Create gameboy cart representation in memory
    // with char array (string)
    BYTE m_CartridgeMemory[0x200000] ;

    //fill our catridge memory with 0 to initialize
    memset(m_CartridgeMemory, 0, sizeof(m_CartridgeMemory));

    //pointer to a file object named in
    FILE *in; 
    //in set to the value of opening the game file 
    in = fopen("Tetris.gb", "rb");
    //read from the catridge memory the first 2.1 million bites
    fread(m_CartridgeMemory, 1, 0x200000, in);
    //close the file 
    fclose(in);
    

    //three dimensional array that will allow a color matrix to be created
    //will actually draw the graphics 
    BYTE m_ScreenData[160][144][3];

    //repsentation of gameboy ram
    BYTE m_Rom[0x1000]; 
    }
    void Update()
    {
    }
    void Emulator::WriteMemory(WORD address, BYTE data)
    {
    }
};

void Emulator::Update()
    {
        //we can execute MaxCycles clock cycles per second at 60 frames per second
        //define MaxCycles as const because it cannot change
        const int MaxCycles = 69905;
        //integer variable that counts how many times the update loop runs
        int cyclesThisUpdate = 0;

        while(cyclesThisUpdate < MaxCycles)
        {
                //this loop should be something like run the operation code, 
                //update the clock, and set the upcoming state for the graphics 

           // int cycles = ExecuteNextOpcode();
           // cyclesThisUpdate += cycles;
           // UpdateTimers(cycles);
           // UpdateGraphics(cycles);
           // DoInterupts(); 
        }
            //this function should draw the updated screen based on the new values
        //RenderScreen(); 
    }
void Emulator::WriteMemory(WORD address, BYTE data)
{
    if (address < 0x8000)
    {
        //establish representation of read only memory
    }

    else if ((address >= 0xE000) && (address <0xFE00))
    {
        //if we write to echo ram we also write to ram 
        m_Rom[address] = data; 
        WriteMemory(address-0x2000, data);
    }
    else if ((address >=0xFEA0) && (address <0xFEFF))
    {
        //system reserved memory
    }
    else
    {
        m_Rom[address] = data; 
        //freely write to this area in ram
    }
}


int WinMain()
{
    
    Emulator myEmulator; 

    return 0;
}


