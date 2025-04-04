#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>  // Nécessaire pour afficher du texte
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
char (*get_action2)();

void* handle1 = NULL;
void* handle2 = NULL;

static uint32_t tab_param[3] = {0};

static uint16_t cpt_non_color = 0;
static int winner = -1;
void count_pixels(t_player *players[MAX_PLAYERS]);
void load_libraries();
void close_libraries();  // Ajout de cette fonction
void found_winner(void);

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void render_map()
{
    int      i = 0;
    SDL_Rect rect;

    rect.x = 0;
    rect.y = 0;
    rect.w = SQUARE_SIZE;
    rect.h = SQUARE_SIZE;

    screenSurface = SDL_GetWindowSurface(window);

    for (i = 0; i < SPOT_NUM; i++)
    {
        rect.x = (i % MAP_SIZE) * SQUARE_SIZE;
        rect.y = (i / MAP_SIZE) * SQUARE_SIZE;
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
    static int32_t credit_player_2 = 0;
    static uint8_t *action_j1 = 0;
    static uint8_t *action_j2 = 0;
    static uint16_t cpt_act_j1 = 0;
    static uint16_t cpt_act_j2 = 0;
    static uint16_t nb_act_j1 = 0;
    static uint16_t nb_act_j2 = 0;

    action_joueur(&action_j1, &action_j2, &nb_act_j1, &nb_act_j2);

    // Charger les bibliothèques dynamiques
    load_libraries();

    while (!quitting)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quitting = 1;
            }
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
                if (event.window.windowID == SDL_GetWindowID(window)) {
                    printf(" Fermeture de la fenêtre principale\n");
                    quitting = 1;
                }
            }
        }

        // Vérification avant d’appeler les fonctions
        credit_player_1 = get_credit_player(players[0]);

        //action_result_1 = get_action1();
        
        if(cpt_act_j1 <= nb_act_j1)
        {
            actions_do(players[0], action_j1[cpt_act_j1]);// rouge
            cpt_act_j1++; 
        }
        else
        {
            cpt_act_j1 = 0;
        }
        
        credit_player_2 = get_credit_player(players[1]);

        //action_result_2 = get_action2();
        if(cpt_act_j2 <= nb_act_j2)
        {
            actions_do(players[1], action_j2[cpt_act_j2]);// rouge
            cpt_act_j2++; 
        }
        else
        {
            cpt_act_j2 = 0;
        }
        
        // Affichage et mise à jour
        render_map();
        nb++;
        SDL_Delay(0.250);

        //printf("credit 1 : %d \n",credit_player_1);
        if((credit_player_1<0) && (credit_player_2<=0))
        {
            quitting = 1;
        }
    }
    // Compter les pixels recouverts par chaque joueur
    count_pixels(players);

    players[0]->count = players[1]->count;
    players[1]->count = cpt_non_color;
    //printf("Pixels recouverts - Joueur 1: %d | Joueur 2: %d \n", players[0]->count, players[1]->count);
    printf("Pixels recouverts - Joueur 1: %d | Joueur 2: %d \n", get_player1_point(), get_player2_point());

    found_winner();

    // Fermer les bibliothèques après utilisation
    close_libraries();
}

void load_libraries() 
{
    handle1 = dlopen("players/player1.so", RTLD_LAZY);
    if (!handle1) { fprintf(stderr, "Erreur dlopen player1.so : %s\n", dlerror()); close_libraries(); exit(EXIT_FAILURE); }

    handle2 = dlopen("players/player2.so", RTLD_LAZY);
    if (!handle2) { fprintf(stderr, "Erreur dlopen player2.so : %s\n", dlerror()); close_libraries(); exit(EXIT_FAILURE); }

    get_action1 = (char (*)()) dlsym(handle1, "get_action_1");

    get_action2 = (char (*)()) dlsym(handle2, "get_action_2");

}

/* Fonction pour fermer les bibliothèques */
void close_libraries() {
    if (handle1) dlclose(handle1);
    if (handle2) dlclose(handle2);
}

/* Fonction pour compter les pixels recouverts par chaque joueur */
void count_pixels(t_player *players[MAX_PLAYERS]) 
{
    uint8_t player_id = 0;
    // Initialiser les compteurs
    for (int i = 0; i < 2; i++) {
        players[i]->count = 0;
    }

    // Parcourir la carte mémoire et compter les pixels de chaque joueur
    for (int i = 0; i < SPOT_NUM; i++) {
        player_id = mapmem[i];  // ID du joueur à cet emplacement

        if (player_id >= 0 && player_id < 2) 
        {
            players[player_id]->count++;
        }
        else{cpt_non_color++;}
    }
}

void found_winner(void) 
{
    // Déterminer le vainqueur
    int max_score = 0;
    for (int i = 0; i < 2; i++) {
        if (players[i]->count > max_score) {
            max_score = players[i]->count;
            winner = i;
        }
    }
    printf("le vainqueur est le joueur %d \n", winner +1 );
}

int get_winner(void)
{
    return winner;
}

uint32_t get_player1_point(void)
{
    return players[0]->count;
}

uint32_t get_player2_point(void)
{
    return players[1]->count;
}

uint32_t* get_output_param(void)
{
    tab_param[0] = winner;
    tab_param[1] = players[0]->count;
    tab_param[2] = players[1]->count;

    return tab_param;
}
