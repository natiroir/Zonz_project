#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "actions.h"
#include "param.h" // modifier les cst pour le nombre de pixels 
#include "splash.h"
#include "world.h"

#define MAX_DIGITS 10000
#define NB_LIB_PROG 4

int          quitting      = 0;
SDL_Window*  window        = NULL;
SDL_Surface* screenSurface = NULL;
static uint8_t action_joueur_1[MAX_DIGITS], action_joueur_2[MAX_DIGITS], game_mode[2]; // Tableaux pour stocker les chiffres
static uint16_t nb_action_j1 = 0;
static uint16_t nb_action_j2 = 0;

void parse_list(const char *list_str);
void extract_data(const char *str, uint8_t *numbers, int *size);

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
    /*if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    }*/

    /*window = SDL_CreateWindow("SplashMem", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500,
                            500, SDL_WINDOW_SHOWN);*/
    //SDL_AddEventWatch(watch, NULL);
    
    if (argc != NB_LIB_PROG)
    {
        printf("Wrong argument number\n");
    }
    
    int size1, size2, size3; // Tailles des tableaux

    // Extraction des données des deux paramètres
    extract_data(argv[1], action_joueur_1, &size1);
    extract_data(argv[2], action_joueur_2, &size2);
    extract_data(argv[3], game_mode, &size3);

    // Affichage des résultats
    for (int i = 0; i < size1; i++) {
        nb_action_j1++;
    }
    for (int i = 0; i < size2; i++) {
        nb_action_j2++;
    }


    inits(argc, argv);

    main_loop();

    //SDL_DelEventWatch(watch, NULL);
    //SDL_DestroyWindow(window);
    //SDL_Quit();

    exit(0);
} // main

void parse_list(const char *list_str) 
{
    // Parcourir chaque caractère de la chaîne
    for (int i = 0; i < strlen(list_str); i++) {
        // Afficher chaque caractère
    }
}

void extract_data(const char *str, uint8_t *numbers, int *size) 
{
    *size = 0;

    // Parcours de la chaîne
    for (int i = 0; str[i] != '\0' && *size < MAX_DIGITS; i++) {
        if (isdigit(str[i])) {
            numbers[*size] = str[i] - '0';  // Convertit le chiffre
            (*size)++;
        } else if (isalpha(str[i]) && (toupper(str[i]) >= 'A' && toupper(str[i]) <= 'F')) {
            numbers[*size] = toupper(str[i]) - 'A' + 10;  // Convertit A=10, B=11, ..., F=15
            (*size)++;
        }
    }
}

void action_joueur(uint8_t** action_tab_j1, uint8_t** action_tab_j2, uint16_t* nombre_act_j1, uint16_t* nombre_act_j2)
{
    *action_tab_j1 = action_joueur_1;
    *action_tab_j2 = action_joueur_2;
    *nombre_act_j1 = nb_action_j1;
    *nombre_act_j2 = nb_action_j2;
}

uint8_t get_mode_game(void)
{
    return game_mode[0];
}
