#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>  // Nécessaire pour afficher du texte
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "actions.h"
#include "param.h" // modifier les cst pour le nombre de pixels 
#include "splash.h"
#include "world.h"

int          quitting      = 0;
SDL_Window*  window        = NULL;
SDL_Surface* screenSurface = NULL;
static uint8_t lancer_jeu = 0;
static int32_t value_pl = 0;
static int32_t value_cr = 0;

#define WINDOW_WIDTH 650
#define WINDOW_HEIGHT 400

void creat_page_acceuil(void) ;

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
int SDLCALL watch(void* userdata, SDL_Event* event)
{
    if (event->type == SDL_APP_WILLENTERBACKGROUND)
    {
        quitting = 1;
    }

    return 1;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
int main(int argc, char* argv[])
{
    creat_page_acceuil();

    if(lancer_jeu == 1)
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
        {
            SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        }

        window = SDL_CreateWindow("SplashMem", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_SIZE,
                                WIN_SIZE, SDL_WINDOW_SHOWN);
        SDL_AddEventWatch(watch, NULL);

        if (argc != 5)
        {
            printf("Wrong argument number\n");
        }
        inits(argc, argv);

        main_loop();

        SDL_DelEventWatch(watch, NULL);
        SDL_DestroyWindow(window);
        SDL_Quit();

        exit(0);
    }
} // main

void renderText(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y, SDL_Color color) {
    if (!renderer || !font || !text) {
        printf("Erreur : renderer, font ou text est NULL dans renderText()\n");
        return;
    }
    const char *display_text = (strlen(text) == 0) ? "..." : text;
    SDL_Surface *surface = TTF_RenderUTF8_Solid(font, display_text, color);
    
    //SDL_Surface *surface = TTF_RenderUTF8_Solid(font, text, color);
    if (!surface) {
        printf("Erreur SDL_ttf : %s\n", TTF_GetError());
        return;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);  // Libérer la surface après création de la texture
    if (!texture) {
        printf("Erreur SDL : %s\n", SDL_GetError());
        return;
    }

    SDL_Rect dstRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_DestroyTexture(texture);  // Libérer la texture après l'affichage
}

int32_t get_number_player(void)
{
    return value_pl;
}

int32_t get_number_credit(void)
{
    return value_cr;
}