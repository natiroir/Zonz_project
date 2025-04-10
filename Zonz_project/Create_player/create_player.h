#ifndef CREATE_PLAYER_H
#define CREATE_PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
    SDL_Rect rect;
    SDL_Color color;
    const char *text;  // Texte du bouton
} Button;

Button createButton(int x, int y, int w, int h, SDL_Color color, const char *text);
void drawButton(Button *btn, TTF_Font *font);
void drawText(const char *text, int x, int y, SDL_Color color, TTF_Font *font);

#endif // CREATE_PLAYER_H
