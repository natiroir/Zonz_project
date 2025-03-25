void creat_page_acceuil(void) 
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur d'initialisation de SDL: %s\n", SDL_GetError());
        return;
    }

    if (TTF_Init() != 0) {
        printf("Erreur d'initialisation de SDL_ttf: %s\n", TTF_GetError());
        SDL_Quit();
        return;
    }

    SDL_Window *window_1 = SDL_CreateWindow("Choix des paramètres", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window_1) {
        printf("Erreur de création de la fenêtre: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window_1, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur de création du renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window_1);
        TTF_Quit();
        SDL_Quit();
        return;
    }

    TTF_Font *font = TTF_OpenFont("arial.ttf", 24);
    if (!font) {
        printf("Erreur de chargement de la police: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window_1);
        TTF_Quit();
        SDL_Quit();
        return;
    }

    char players_text[3] = "2";  // Initialisation du texte pour le nombre de joueurs
    char credits_text[5] = "1500";  // Initialisation du texte pour le nombre de crédits

    SDL_Rect button = {350, 400, 100, 50}; // Position et taille du bouton
    SDL_bool running = SDL_TRUE;
    SDL_bool input_players = SDL_FALSE;
    SDL_bool input_credits = SDL_FALSE;

    SDL_StartTextInput(); // Activation de la saisie de texte

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = SDL_FALSE;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_RETURN) {
                    input_players = SDL_FALSE;
                    input_credits = SDL_FALSE;
                    SDL_StopTextInput();  // ✅ Arrêter la saisie de texte après validation
                } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    if (input_players && strlen(players_text) > 0) {
                        players_text[strlen(players_text) - 1] = '\0';
                    } else if (input_credits && strlen(credits_text) > 0) {
                        credits_text[strlen(credits_text) - 1] = '\0';
                    }
                }
            } else if (event.type == SDL_TEXTINPUT) {
                if (input_players && strlen(players_text) < 2) {
                    strcat(players_text, event.text.text);
                } else if (input_credits && strlen(credits_text) < 4) {
                    strcat(credits_text, event.text.text);
                }
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= button.x && x <= button.x + button.w && y >= button.y && y <= button.y + button.h) {
                    int players = atoi(players_text);
                    int credits = atoi(credits_text);
                    if (players >= 2 && players <= 4 && credits >= 1500 && credits <= 9000) {
                        printf("✅ Jeu lancé avec %d joueurs et %d crédits\n", players, credits);
                        lancer_jeu = 1;
                        running = SDL_FALSE;
                    } else {
                        printf("❌ Valeurs invalides. Entrez des valeurs valides.\n");
                    }
                } else if (x >= 50 && x <= 250 && y >= 50 && y <= 100) {
                    input_players = SDL_TRUE;
                    input_credits = SDL_FALSE;
                    SDL_StartTextInput();  // ✅ Activer la saisie de texte
                } else if (x >= 50 && x <= 250 && y >= 100 && y <= 150) {
                    input_players = SDL_FALSE;
                    input_credits = SDL_TRUE;
                    SDL_StartTextInput();  // ✅ Activer la saisie de texte
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Affichage du texte
        render_text(renderer, font, "Nombre de joueurs :", 50, 50);
        render_text(renderer, font, players_text, 250, 50);
        render_text(renderer, font, "Nombre de crédits :", 50, 100);
        render_text(renderer, font, credits_text, 250, 100);

        // Dessiner le bouton
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &button);
        render_text(renderer, font, "Valider", button.x + 10, button.y + 10);

        SDL_RenderPresent(renderer);
    }

    SDL_StopTextInput(); // ✅ Désactiver la saisie de texte à la fin
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window_1);
    TTF_Quit();
    SDL_Quit();
}
