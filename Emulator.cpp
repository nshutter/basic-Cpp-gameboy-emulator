
#include "SDL2/SDL.h"
#include ".\pch.hpp"
#include <iostream>

typedef unsigned char BYTE; //0 to 255
typedef char SIGNED_BYTE; //-128 to 127
typedef unsigned short WORD; //16 bit unsigned int 
typedef signed short SIGNED_WORD;//16 bit signed int 

int WinMain()
{
    ///Create gameboy cart representation in memory
    // with char array (string)
    BYTE m_CartridgeMemory[0x200000] ;

    //fill our catridge memory with 0 to prevent null access
    memset(m_CartridgeMemory, 0, sizeof(m_CartridgeMemory));

    //open file in working directory with given name
    FILE *in; 
    in = fopen("Tetris.gb", "rb");
    
    fread(m_CartridgeMemory, 1, 0x200000, in);
    fclose(in);
   
    return 0;
}


