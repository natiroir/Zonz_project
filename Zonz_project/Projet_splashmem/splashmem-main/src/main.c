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


void creat_page_acceuil(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
    }

    if (TTF_Init() == -1) {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        printf("Il faut installer SDL_ttf.\n");
        SDL_Quit();
    }

    SDL_Window *window_2 = SDL_CreateWindow("Input Parameters", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window_2 == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window_2, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(window_2);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
    }

    TTF_Font *font = TTF_OpenFont("arial.ttf", 24);
    if (font == NULL) {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window_2);
        TTF_Quit();
        SDL_Quit();
    }

    char input1[256] = "";
    char input2[256] = "";
    int input1_len = 0;
    int input2_len = 0;
    int active_input = 1;
    char error_message[256] = "";

    SDL_Rect button = {280, 250, 100, 50};  // Bouton "Valider"

    SDL_StartTextInput();
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) 
        {
            if (e.type == SDL_QUIT) 
            {
                quit = 1;
            }
            else if (e.type == SDL_TEXTINPUT) {
                if (active_input == 1 && input1_len < sizeof(input1) - 1) 
                {
                    if(input1_len == 0)
                    {
                        strcat(input1, e.text.text);
                        input1_len += strlen(e.text.text);
                    }
                } 
                else if (active_input == 2 && input2_len < sizeof(input2) - 1) 
                {
                    if((input2_len>=0)&&(input2_len <= 3))
                    {
                        strcat(input2, e.text.text);
                        input2_len += strlen(e.text.text);
                    }
                }
            } 
            else if (e.type == SDL_KEYDOWN) 
            {
                if (e.key.keysym.sym == SDLK_TAB) {
                    active_input = (active_input == 1) ? 2 : 1;
                } 
                else if (e.key.keysym.sym == SDLK_BACKSPACE) 
                {
                    if (active_input == 1 && input1_len > 0) {
                        input1[--input1_len] = '\0';
                    } else if (active_input == 2 && input2_len > 0) {
                        input2[--input2_len] = '\0';
                    }
                }
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    int x = e.button.x, y = e.button.y;
                    if (x >= button.x && x <= button.x + button.w &&
                        y >= button.y && y <= button.y + button.h) 
                    {
                        if ((active_input == 1) || (active_input == 2))
                        {
                            value_pl = atoi(input1);
                            value_cr = atoi(input2);
                            if (value_pl < 2 || value_pl > 4) {
                                snprintf(error_message, sizeof(error_message), "Le premier paramètre doit être entre 2 et 4 !");
                            }
                            else if (value_cr < 1500 || value_cr > 9000) {
                                snprintf(error_message, sizeof(error_message), "Le deuxième paramètre doit être entre 1500 et 9000 !");
                            }
                            else
                            {
                                //printf("Valeurs saisies : joueurs = %d, Crédits = %d\n", value_pl, value_cr);
                                error_message[0] = '\0';
                                lancer_jeu = 1;
                                quit = 1;
                            }
                        }
                    }
                    else {  
                        active_input = (active_input == 1) ? 2 : 1;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Color color1 = (active_input == 1) ? (SDL_Color){0, 0, 255, 255} : (SDL_Color){255, 255, 255, 255};
        SDL_Color color2 = (active_input == 2) ? (SDL_Color){0, 0, 255, 255} : (SDL_Color){255, 255, 255, 255};

        renderText(renderer, font, "Choix des paramêtres :", 200, 50, (SDL_Color){255, 255, 255, 255});

        renderText(renderer, font, "Nombre de joueur :", 50, 100, color1);
        renderText(renderer, font, input1, 275, 100, color1);
        renderText(renderer, font, "Nombre de crédit :", 50, 150, color2);
        renderText(renderer, font, input2, 275, 150, color2);

        // Dessiner le bouton
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &button);
        renderText(renderer, font, "Valider", button.x + 14, button.y + 10, (SDL_Color){255, 255, 255, 255});

        if (strlen(error_message) > 0) {
            renderText(renderer, font, error_message, 50, 200, (SDL_Color){255, 0, 0, 255});
        }

        SDL_RenderPresent(renderer);
    }

    SDL_StopTextInput();
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window_2);
    /*TTF_Quit();
    SDL_Quit();*/
}

int32_t get_number_player(void)
{
    return value_pl;
}

int32_t get_number_credit(void)
{
    return value_cr;
}