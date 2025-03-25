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

// Déclaration des pointeurs de fonction
char (*get_action1)();
char (*get_action2)();
char (*get_action3)();
char (*get_action4)();

void* handle1 = NULL;
void* handle2 = NULL;
void* handle3 = NULL;
void* handle4 = NULL;

static uint16_t cpt_non_color = 0;

void count_pixels(t_player *players[MAX_PLAYERS]);
void load_libraries();
void close_libraries();  // Ajout de cette fonction
void display_score_window(t_player *players[MAX_PLAYERS]);
int MyEventFilter(void *userdata, SDL_Event *event);
int compare_players(const void *a, const void *b);
void display_sorted_scores(t_player **players, int number_of_players, SDL_Renderer *renderer_sw,TTF_Font *font_sw);
int compare_players(const void *a, const void *b);

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

    for (i = 0; i < get_number_player(); i++)
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
    static char action_result_1, action_result_2, action_result_3, action_result_4;
    static int32_t credit_player_1 = 0;
    static int32_t credit_player_2 = 0;
    static int32_t credit_player_3 = 0;
    static int32_t credit_player_4 = 0;
    static int32_t nb_player = 0;

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
        if(credit_player_1>0)
        {
            if (!players[0]) { printf("Erreur : players[0] est NULL !\n"); exit(EXIT_FAILURE); }
            if (get_action1) {
            action_result_1 = get_action1();
            actions_do(players[0], action_result_1);// rouge
            }
        }
        credit_player_2 = get_credit_player(players[1]);
        if(credit_player_2 > 0)
        {
            if (!players[1]) { printf("Erreur : players[1] est NULL !\n"); exit(EXIT_FAILURE); }
            if (get_action2) {
                action_result_2 = get_action2();
                actions_do(players[1], action_result_2);// vert
            }
        }
        if(get_number_player() > 2 )
        {
            credit_player_3 = get_credit_player(players[2]);
            if(credit_player_3 > 0)
            {
                if (!players[2]) { printf("Erreur : players[2] est NULL !\n"); exit(EXIT_FAILURE); }
                if (get_action3) {
                    action_result_3 = get_action3();
                    actions_do(players[2], action_result_3); //bleu
                }
            }
        }
        if(get_number_player() > 3 )
        {
            credit_player_4 = get_credit_player(players[3]);
            if(credit_player_4 > 0)
            {
                if (!players[3]) { printf("Erreur : players[3] est NULL !\n"); exit(EXIT_FAILURE); }
                if (get_action4) {
                    action_result_4 = get_action4();
                    actions_do(players[3], action_result_4);//violet
                }
            }
        }
        // Affichage et mise à jour
        render_map();
        nb++;
        SDL_Delay(100);

        if((credit_player_1<=0) && (credit_player_2<=0) && (credit_player_3<=0) && (credit_player_4<=0))
        {
            quitting = 1;
        }
    }
    // Compter les pixels recouverts par chaque joueur
    count_pixels(players);

    nb_player = get_number_player();
    switch (nb_player)
    {
    case 2:
        players[0]->count = players[1]->count;
        players[1]->count = cpt_non_color;
        //printf("Pixels recouverts - Joueur 1: %d | Joueur 2: %d \n", players[0]->count, players[1]->count);
        break;
    case 3:
        players[0]->count = players[1]->count;
        players[1]->count = players[2]->count;
        players[2]->count = cpt_non_color;
        //printf("Pixels recouverts - Joueur 1: %d | Joueur 2: %d | Joueur 3: %d \n",players[0]->count, players[1]->count, players[2]->count);
        break;
    case 4:
        players[0]->count = players[1]->count;
        players[1]->count = players[2]->count;
        players[2]->count = players[3]->count;
        players[3]->count = cpt_non_color;
        //printf("Pixels recouverts - Joueur 1: %d | Joueur 2: %d | Joueur 3: %d | Joueur 4: %d\n",players[0]->count, players[1]->count, players[2]->count, players[3]->count);
    default:
        break;
    }

    display_score_window(players);

    // Fermer les bibliothèques après utilisation
    close_libraries();
}

void load_libraries() 
{
    handle1 = dlopen("players/player1.so", RTLD_LAZY);
    if (!handle1) { fprintf(stderr, "Erreur dlopen player1.so : %s\n", dlerror()); close_libraries(); exit(EXIT_FAILURE); }

    handle2 = dlopen("players/player2.so", RTLD_LAZY);
    if (!handle2) { fprintf(stderr, "Erreur dlopen player2.so : %s\n", dlerror()); close_libraries(); exit(EXIT_FAILURE); }

    handle3 = dlopen("players/player3.so", RTLD_LAZY);
    if (!handle3) { fprintf(stderr, "Erreur dlopen player3.so : %s\n", dlerror()); close_libraries(); exit(EXIT_FAILURE); }

    handle4 = dlopen("players/player4.so", RTLD_LAZY);
    if (!handle4) { fprintf(stderr, "Erreur dlopen player4.so : %s\n", dlerror()); close_libraries(); exit(EXIT_FAILURE); }

    get_action1 = (char (*)()) dlsym(handle1, "get_action_1");

    get_action2 = (char (*)()) dlsym(handle2, "get_action_2");

    get_action3 = (char (*)()) dlsym(handle3, "get_action_3");

    get_action4 = (char (*)()) dlsym(handle4, "get_action_4");
}

/* Fonction pour fermer les bibliothèques */
void close_libraries() {
    if (handle1) dlclose(handle1);
    if (handle2) dlclose(handle2);
    if (handle3) dlclose(handle3);
    if (handle4) dlclose(handle4);
}

/* Fonction pour compter les pixels recouverts par chaque joueur */
void count_pixels(t_player *players[MAX_PLAYERS]) 
{
    uint8_t player_id = 0;
    // Initialiser les compteurs
    for (int i = 0; i < get_number_player(); i++) {
        players[i]->count = 0;
    }

    // Parcourir la carte mémoire et compter les pixels de chaque joueur
    for (int i = 0; i < SPOT_NUM; i++) {
        player_id = mapmem[i];  // ID du joueur à cet emplacement

        if (player_id >= 0 && player_id < get_number_player()) 
        {
            players[player_id]->count++;
        }
        else{cpt_non_color++;}
    }
}

void display_score_window(t_player *players[MAX_PLAYERS]) 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() == -1) {
        printf("Erreur SDL/TTF : %s\n", SDL_GetError());
        return;
    }
    uint16_t window_width = 600;
    uint16_t window_height = 350;

    // Créer la fenêtre et le renderer
    SDL_Window *score_window = SDL_CreateWindow("Résultats de la Partie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(score_window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font *font = TTF_OpenFont("arial.ttf", 24);

    if (!score_window || !renderer || !font) {
        printf("Erreur création fenêtre scores : %s\n", SDL_GetError());
        return;
    }

    // Identifier l'ID de la fenêtre des scores
    uint32_t score_window_id = SDL_GetWindowID(score_window);

    // Déterminer le vainqueur
    int max_score = 0, winner = -1;
    for (int i = 0; i < get_number_player(); i++) {
        if (players[i]->count > max_score) {
            max_score = players[i]->count;
            winner = i;
        }
    }


    // Affichage des scores
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color yellow = {255, 255, 0, 255};
    SDL_Color color_rend[] = {{128, 128, 128, 255},{255, 165, 0, 255}, {0,255,0,255}};

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Fond noir
    SDL_RenderClear(renderer);

    // Afficher le gagnant
    if (winner != -1) {
            char winner_text[50];
            sprintf(winner_text, "Vainqueur : Joueur %d !", winner + 1);
            SDL_Surface *surface = TTF_RenderText_Solid(font, winner_text, yellow);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect rect = {200, 25, surface->w, surface->h};
    
            SDL_RenderCopy(renderer, texture, NULL, &rect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
    }
    const char *rend[] = {"2eme","3eme","4eme"};

    for(uint8_t c = 0; c< get_number_player()-1;c++)
    {
        char rend_text[50];
        sprintf(rend_text, "%s", rend[c]);
        SDL_Surface *surface_rend = TTF_RenderText_Solid(font, rend_text, color_rend[c]);
        SDL_Texture *texture_rend = SDL_CreateTextureFromSurface(renderer, surface_rend);
        SDL_Rect rect = {20 + (c+1) * 130, 75, surface_rend->w, surface_rend->h};
        SDL_RenderCopy(renderer, texture_rend, NULL, &rect);
        SDL_FreeSurface(surface_rend);
        SDL_DestroyTexture(texture_rend);
    }
    // Afficher les scores triés
    display_sorted_scores(players, get_number_player(), renderer, font);

    SDL_Rect button = {window_width / 2 - 75, window_height - 80, 150, 50};  // Centré en bas

    // Dessiner un bouton
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &button);

    // Dessiner le texte "Quitter" au centre du bouton
    SDL_Surface *text_surface = TTF_RenderText_Solid(font, "Quitter", white);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_Rect text_rect = {
        button.x + button.w / 2 - text_surface->w / 2,
        button.y + button.h / 2 - text_surface->h / 2,
        text_surface->w, text_surface->h
    };

    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
    SDL_RenderPresent(renderer);

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == score_window_id) {
                printf("Fermeture pour la fenêtre des scores \n");
                running = 0;
            }
            if (event.type == SDL_QUIT && event.window.windowID == SDL_GetWindowID(score_window)) {
                printf(" Fermeture demandée pour la fenêtre des scores\n");
                running = 0;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                //printf(" Fermeture via clic souris\n");
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= button.x && x <= button.x + button.w && y >= button.y && y <= button.y + button.h) {
                    printf("clic button \n");
                    running = 0;
                    
                }
            }
        }
        SDL_Delay(100);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

        SDL_RenderPresent(renderer);
    }

    // Nettoyage
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(score_window);

    //  Éviter que SDL_QUIT soit propagé après la fermeture
    SDL_PumpEvents();
    /*TTF_Quit();
    SDL_Quit();*/
}

// Définir la fonction de filtre d'événements
int MyEventFilter(void *userdata, SDL_Event *event) {
    if (event->type == SDL_KEYDOWN) {
        printf("Touche appuyée : %s\n", SDL_GetKeyName(event->key.keysym.sym));
    }
    return 0; // Retourner 0 pour continuer le traitement normal des événements
}

// Fonction de comparaison pour qsort
int compare_players(const void *a, const void *b) 
{
    t_player *playerA = *(t_player **)a;
    t_player *playerB = *(t_player **)b;
    return playerB->count - playerA->count; // Tri décroissant
}

void display_sorted_scores(t_player **players, int number_of_players, SDL_Renderer *renderer_sw,TTF_Font *font_sw)
 {
    SDL_Color colors_pl[] = {
        {255, 0, 0, 255},    // Rouge
        {0, 255, 0, 255},    // Vert
        {0, 0, 255, 255},    // Bleu
        {255, 0, 255, 255}  // Jaune
    };

    // Trier les joueurs par score décroissant
    qsort(players, number_of_players, sizeof(t_player *), compare_players);

    // Afficher les scores triés avec les identifiants des joueurs
    for (int i = 1; i < number_of_players; i++) 
    {
        char score_text[50];
        char joueur_text[50];
        SDL_Color currentColor = colors_pl[i % 5];

        sprintf(joueur_text, "Joueur %d :", players[i]->id);
        sprintf(score_text, "%d pixels", players[i]->count);
        /* affichage joueur */
        SDL_Surface *surface = TTF_RenderText_Solid(font_sw, joueur_text, currentColor);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer_sw, surface);
        SDL_Rect rect = {i * 128, 125, surface->w, surface->h};
        /* Affichage score */
        SDL_Surface *surface_score = TTF_RenderText_Solid(font_sw, score_text, currentColor);
        SDL_Texture *texture_score = SDL_CreateTextureFromSurface(renderer_sw, surface_score);
        SDL_Rect rect_score = {i * 128, 150, surface_score->w, surface_score->h};

        SDL_RenderCopy(renderer_sw, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);

        SDL_RenderCopy(renderer_sw, texture_score, NULL, &rect_score);
        SDL_FreeSurface(surface_score);
        SDL_DestroyTexture(texture_score);
        //printf("Position %d: Joueur %d avec un score de %d\n", i + 1, players[i]->id, players[i]->count);
    }
}