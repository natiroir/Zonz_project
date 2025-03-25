#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 300
#define MAX_PLAYERS 4

// Définition des couleurs
SDL_Color colors[MAX_PLAYERS] = {
    {255, 0, 0, 255},   // 🔴 Rouge - Joueur 1
    {0, 255, 0, 255},   // 🟢 Vert - Joueur 2
    {0, 0, 255, 255},   // 🔵 Bleu - Joueur 3
    {255, 0, 255, 255}  // 🟣 Violet - Joueur 4
};

void render_text(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y, SDL_Color color);
void display_scores(SDL_Renderer *renderer, TTF_Font *font, int scores[MAX_PLAYERS]);

int main(int argc, char *argv[])
{
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur SDL: %s\n", SDL_GetError());
        return 1;
    }
    
    if (TTF_Init() == -1) {
        printf("Erreur TTF: %s\n", TTF_GetError());
        return 1;
    }

    // Création de la fenêtre et du renderer
    SDL_Window *window = SDL_CreateWindow("Scores des Joueurs", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!window || !renderer) {
        printf("Erreur lors de la création de la fenêtre/renderer: %s\n", SDL_GetError());
        return 1;
    }

    // Charger la police d'écriture
    TTF_Font *font = TTF_OpenFont("arial.ttf", 24);
    if (!font) {
        printf("Erreur chargement police: %s\n", TTF_GetError());
        return 1;
    }

    // Scores des joueurs (à récupérer dynamiquement dans un vrai jeu)
    int scores[MAX_PLAYERS] = {230, 310, 180, 275};  // Exemples de scores

    // Boucle principale
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Afficher les scores et le vainqueur
        display_scores(renderer, font, scores);

        // Mettre à jour l'affichage
        SDL_RenderPresent(renderer);

        SDL_Delay(100);
    }

    // Nettoyage
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

// 🔹 Fonction d'affichage de texte
void render_text(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y, SDL_Color color)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dest_rect = {x, y, surface->w, surface->h};
    
    SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
    
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

// 🔹 Fonction d'affichage des scores et du vainqueur
void display_scores(SDL_Renderer *renderer, TTF_Font *font, int scores[MAX_PLAYERS])
{
    char buffer[50];
    int max_score = 0, winner = -1;

    // Détecter le joueur avec le score le plus élevé
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
            winner = i;
        }
    }

    // Afficher les scores
    for (int i = 0; i < MAX_PLAYERS; i++) {
        sprintf(buffer, "Joueur %d: %d points", i + 1, scores[i]);
        render_text(renderer, font, buffer, 50, 50 + (i * 40), colors[i]);
    }

    // Afficher le vainqueur
    if (winner != -1) {
        sprintf(buffer, "Vainqueur: Joueur %d !", winner + 1);
        render_text(renderer, font, buffer, 50, 220, colors[winner]);
    }
}
