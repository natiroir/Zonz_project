#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "actions.h"
#include "param.h"
#include "splash.h"
#include "world.h"

uint32_t colors[MAX_PLAYERS + 1] = {0};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void init_colors(void /*SDL_PixelFormat* format*/)
{
    // Noir
    colors[0] = (0x00 << 16) | (0x00 << 8) | 0x00;

    // Rouge
    colors[1] = (0xFF << 16) | (0x00 << 8) | 0x00;

    // Vert
    colors[2] = (0x00 << 16) | (0xFF << 8) | 0x00;

    // Bleu
    colors[3] = (0x00 << 16) | (0x00 << 8) | 0xFF;

    // Magenta
    colors[4] = (0xFF << 16) | (0x00 << 8) | 0xFF;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void inits(int argc, char* argv[])
{
    // Get window surface
    //screenSurface           = SDL_GetWindowSurface(window);
    //SDL_PixelFormat* format = screenSurface->format;
    init_colors();
    actions_init();
    world_create_players();
}