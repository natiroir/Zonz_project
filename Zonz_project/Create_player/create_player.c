#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>
#include "create_player.h"

int quitting = 0;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

void drawText(const char *text, int x, int y, SDL_Color color, TTF_Font *police) {
    int textWidth, textHeight;
    if (TTF_SizeText(police, text, &textWidth, &textHeight) != 0) {
        SDL_Log("Unable to calculate text size: %s", TTF_GetError());
        return;
    }

    SDL_Surface *surface = TTF_RenderText_Solid(police, text, color);
    if (surface == NULL) {
        SDL_Log("Unable to create text surface: %s", TTF_GetError());
        return;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (texture == NULL) {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        return;
    }

    SDL_Rect dstRect = {x - textWidth / 2, y - textHeight / 2, textWidth, textHeight};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);

    SDL_DestroyTexture(texture);
}


Button createButton(int x, int y, int w, int h, SDL_Color color, const char *text)  // création du bouton 
{
    Button btn;
    btn.rect.x = x;
    btn.rect.y = y;
    btn.rect.w = w;
    btn.rect.h = h;
    btn.color = color;
    btn.text = text;
    return btn;
}

void drawButton(Button *btn, TTF_Font *font) {
    SDL_SetRenderDrawColor(renderer, btn->color.r, btn->color.g, btn->color.b, btn->color.a);
    SDL_RenderFillRect(renderer, &btn->rect);

    SDL_Color textColor = {0, 0, 0, 255}; // Noir
    int centerX = btn->rect.x + btn->rect.w / 2;
    int centerY = btn->rect.y + btn->rect.h / 2;
    drawText(btn->text, centerX, centerY, textColor, font);
}


int isMouseOver(Button *btn, int mouseX, int mouseY)
{
    return (mouseX >= btn->rect.x && mouseX <= btn->rect.x + btn->rect.w &&
            mouseY >= btn->rect.y && mouseY <= btn->rect.y + btn->rect.h);
}


int main()
{
    char *lastAction = "";
    int nb_action = 0;
    char nb_action_text[10];
    char action[500] = "";

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1) {
        SDL_Log("Failed to initialize TTF: %s", TTF_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Create Player", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font *font = TTF_OpenFont("./FreeSans.ttf", 24);
    if (!font) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return 1;
    }



    SDL_Color btnColor = {255, 255, 255, 255};  // Blanc
    Button Move_L = createButton(28, 900, 150, 50, btnColor, "Move Left"); 
    Button Move_R = createButton(218, 900, 150, 50, btnColor, "Move Right"); 
    Button Move_U = createButton(408, 900, 150, 50, btnColor, "Move Up"); 
    Button Move_D = createButton(598, 900, 150, 50, btnColor, "Move Down"); 
    Button Tel_L = createButton(28, 820, 150, 50, btnColor, "Teleport Left"); 
    Button Tel_R = createButton(218, 820, 150, 50, btnColor, "Teleport Right"); 
    Button Tel_U = createButton(408, 820, 150, 50, btnColor, "Teleport Up"); 
    Button Tel_D = createButton(598, 820, 150, 50, btnColor, "Teleport Down"); 
    Button Dash_L = createButton(28, 740, 150, 50, btnColor, "Dash Left"); 
    Button Dash_R = createButton(218, 740, 150, 50, btnColor, "Dash Right"); 
    Button Dash_U = createButton(408, 740, 150, 50, btnColor, "Dash Up"); 
    Button Dash_D = createButton(598, 740, 150, 50, btnColor, "Dash Down");
    Button Still = createButton(788, 740, 150, 50, btnColor, "Still"); 
    Button Splash = createButton(788, 820, 150, 50, btnColor, "Splash");
    Button Bomb = createButton(788, 900, 150, 50, btnColor, "Bombe"); 
    Button Valider = createButton(800, 100, 150, 50, btnColor, "Valider"); 
    Button Retour = createButton(800, 200, 150, 50, btnColor, "Supprimer"); 
    Button Effacer = createButton(800, 300, 150, 50, btnColor, "Effacer"); 
    Button Previsualisation = createButton(28, 100, 200, 50, btnColor, "Previsualisation"); 

    
    
    


    while (!quitting) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) 
            {
                quitting = 1;
            }


            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX = event.button.x;
                int mouseY = event.button.y;


                if (isMouseOver(&Move_L, mouseX, mouseY))
                {
                    lastAction = "Move Left";
                    strcat(action, "1");
                    nb_action++;
                }
                if (isMouseOver(&Move_R, mouseX, mouseY))
                {
                    lastAction = "Move Right";
                    strcat(action, "2");
                    nb_action++;
                }
                if (isMouseOver(&Move_U, mouseX, mouseY))
                {
                    lastAction = "Move Up";
                    strcat(action, "3");
                    nb_action++;
                }
                if (isMouseOver(&Move_D, mouseX, mouseY))
                {
                    lastAction = "Move Down";
                    strcat(action, "4");
                    nb_action++;
                }
                if (isMouseOver(&Tel_L, mouseX, mouseY))
                {
                    lastAction = "Teleport Left";
                    strcat(action, "9");
                    nb_action++;
                }
                if (isMouseOver(&Tel_D, mouseX, mouseY))
                {
                    lastAction = "Teleport Down";
                    strcat(action, "C");
                    nb_action++;
                }
                if (isMouseOver(&Tel_R, mouseX, mouseY))
                {
                    lastAction = "Teleport Right";
                    strcat(action, "A");
                    nb_action++;
                }
                if (isMouseOver(&Tel_U, mouseX, mouseY))
                {
                    lastAction = "Teleport Up";
                    strcat(action, "B");
                    nb_action++;
                }
                if (isMouseOver(&Dash_L, mouseX, mouseY))
                {
                    lastAction = "Dash Left";
                    strcat(action, "5");
                    nb_action++;
                }
                if (isMouseOver(&Dash_D, mouseX, mouseY))
                {
                    lastAction = "Dash Down";
                    strcat(action, "8");
                    nb_action++;
                }
                if (isMouseOver(&Dash_R, mouseX, mouseY))
                {
                    lastAction = "Dash Right";
                    strcat(action, "6");
                    nb_action++;
                }
                if (isMouseOver(&Dash_U, mouseX, mouseY))
                {
                    lastAction = "Dash Up";
                    strcat(action, "7");
                    nb_action++;
                }
                if (isMouseOver(&Still, mouseX, mouseY))
                {
                    lastAction = "Still";
                    strcat(action, "0");
                    nb_action++;
                }
                if (isMouseOver(&Splash, mouseX, mouseY))
                {
                    lastAction = "Splash";
                    strcat(action, "D");
                    nb_action++;
                }
                if (isMouseOver(&Bomb, mouseX, mouseY))
                {
                    lastAction = "Bomb";
                    strcat(action, "E");
                    nb_action++;
                }
                if (isMouseOver(&Valider, mouseX, mouseY))
                {
                    SDL_SetClipboardText(action);
                    lastAction = "Copy on Clipboard";
                }
                if (isMouseOver(&Retour, mouseX, mouseY))
                {
                    action[strlen(action)-1] = '\0';
                    if (nb_action>0)
                    {
                        nb_action--;
                    }          
                    switch (action[strlen(action)-1])
                    {
                    case 'E':
                        lastAction = "Bomb";
                        break;
                    case 'D':
                        lastAction = "Splash";
                        break;
                    case '0':
                        lastAction = "Still";
                        break;
                    case '7':
                        lastAction = "Dash Up";
                        break;
                    case '6':
                        lastAction = "Dash Right";
                        break;
                    case '5':
                        lastAction = "Dash Left";
                        break;
                    case '8':
                        lastAction = "Dash Down";
                        break;
                    case 'B':
                        lastAction = "Teleport Up";
                        break;
                    case 'A':
                        lastAction = "Teleport Right";
                        break;
                    case 'C':
                        lastAction = "Teleport Down";
                        break;
                    case '9':
                        lastAction = "Teleport Left";
                        break;
                    case '4':
                        lastAction = "Move Down";
                        break;
                    case '3':
                        lastAction = "Move Up";
                        break;
                    case '2':
                        lastAction = "Move Right";
                        break;
                    case '1':
                        lastAction = "Move Left";
                        break;
                    default:
                        break;
                    }
                }
                if (isMouseOver(&Effacer, mouseX, mouseY))
                {
                    memset(action, 0, sizeof(action));
                    nb_action = 0;
                    lastAction = "";
                }
                if (isMouseOver(&Previsualisation, mouseX, mouseY))
                {
                    char commande[1024];
                    sprintf(commande, "./Projet_splashmem/splashmem-main/splashmem %s 2",action);
                    system(commande);
                }
                
            }

        }
        sprintf(nb_action_text,"%d", nb_action);
        Button Nombre = createButton(475, 150, 50, 50, btnColor, nb_action_text);
        
         

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        


        drawButton(&Move_L, font);
        drawButton(&Move_R, font);
        drawButton(&Move_U, font);
        drawButton(&Move_D, font);
        drawButton(&Tel_L, font);
        drawButton(&Tel_R, font);
        drawButton(&Tel_U, font);
        drawButton(&Tel_D, font);
        drawButton(&Still, font);
        drawButton(&Dash_D, font);
        drawButton(&Dash_L, font);
        drawButton(&Dash_R, font);
        drawButton(&Dash_U, font);
        drawButton(&Bomb, font);
        drawButton(&Splash, font);
        drawButton(&Valider, font);
        drawButton(&Retour, font);
        drawButton(&Nombre, font);
        drawButton(&Effacer, font);
        drawButton(&Previsualisation, font);

        if (lastAction && lastAction[0] != '\0') {
            Button Text_bar = createButton(400, 200, 200, 50, btnColor, lastAction);
            drawButton(&Text_bar, font);
        }

    
        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();

    return 0;
}
