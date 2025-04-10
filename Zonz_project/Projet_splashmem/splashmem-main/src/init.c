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
void init_colors(SDL_PixelFormat* format)
{
    colors[0] = SDL_MapRGB(format, 0x00, 0x00, 0x00); //noir
    colors[1] = SDL_MapRGB(format, 0xFF, 0, 0); // rouge
    colors[2] = SDL_MapRGB(format, 0, 0xFF, 0); // vert
    colors[3] = SDL_MapRGB(format, 0, 0x0, 0xFF); //bleu
    colors[4] = SDL_MapRGB(format, 0xFF, 0, 0xFF); // magenta
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void inits(int argc, char* argv[])
{
    // Get window surface
    screenSurface           = SDL_GetWindowSurface(window);
    SDL_PixelFormat* format = screenSurface->format;
    init_colors(format);
    actions_init();
    world_create_players();
}