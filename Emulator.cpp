#include ".\pch.hpp"
#include <SDL2/SDL.h>

typedef unsigned char BYTE;
typedef char SIGNED_BYTE;
typedef unsigned short WORD;
typedef signed short SIGNED_WORD;

int main(int argc, char *argv[])
{
    BYTE m_CartridgeMemory[0x200000];
    // initialize memory for gameboy game cart

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("%s",SDL_GetError());

        return 0;
    }
    printf("Success");
    SDL_Quit();
    return 0;
}
