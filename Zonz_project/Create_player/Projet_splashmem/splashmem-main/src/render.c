#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>  // Nécessaire pour dlopen et dlsym

#include "main.h"
#include "actions.h"
#include "param.h"
#include "splash.h"
#include "world.h"
#include "render.h"

// Déclaration des pointeurs de fonction
char (*get_action1)();

void* handle1 = NULL;



/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void render_map()
{
    int      i = 0;
    SDL_Rect rect;

    rect.x = 0;
    rect.y = 0;
    rect.w = 10;
    rect.h = 10;

    screenSurface = SDL_GetWindowSurface(window);

    for (i = 0; i < SPOT_NUM; i++)
    {
        rect.x = (i % 100) * 10;
        rect.y = (i / 100) * 10;
        SDL_FillRect(screenSurface, &rect, colors[mapmem[i]]);
    }
    SDL_UpdateWindowSurface(window);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void render_player()
{
    int i         = 0;
    screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect;

    rect.x = 0;
    rect.y = 0;
    rect.w = SQUARE_SIZE;
    rect.h = SQUARE_SIZE;

    for (i = 0; i < 2; i++)
    {
        rect.x = players[i]->x * SQUARE_SIZE;
        rect.y = players[i]->y * SQUARE_SIZE;
        SDL_FillRect(screenSurface, &rect, colors[i] - 0x00202020);
    }
    SDL_UpdateWindowSurface(window);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void main_loop()
{
    uint32_t nb = 0;
    //static char action_result_1, action_result_2;
    static int32_t credit_player_1 = 0;
    static uint8_t *action_j1 = 0;
    static uint16_t cpt_act_j1 = 0;
    static uint16_t nb_act_j1 = 0;

    action_joueur(&action_j1, &nb_act_j1);


    while (!quitting)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quitting = 1;
            }
        }

        // Vérification avant d’appeler les fonctions
        credit_player_1 = get_credit_player(players[0]);
        
        if(cpt_act_j1 <= nb_act_j1)
        {
            actions_do(players[0], action_j1[cpt_act_j1]);// rouge
            cpt_act_j1++; 
        }
        else
        {
            cpt_act_j1 = 0;
        }
        
        // Affichage et mise à jour
        render_map();
        nb++;
        SDL_Delay(200);

        //printf("credit 1 : %d \n",credit_player_2);
        if((credit_player_1<1))
        {
            quitting = 1;
        }
    }

}
