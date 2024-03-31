#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MENU_HEIGHT 50

int main() {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Crear una ventana
    SDL_Window* window = SDL_CreateWindow("Mi Ventana", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (window == NULL) {
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        return 1;
    }

    // Crear un renderizador
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Error al crear el renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Inicializar SDL_ttf
    if (TTF_Init() != 0) {
        printf("Error al inicializar SDL_ttf: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Cargar la fuente predeterminada del sistema
    TTF_Font* font = TTF_OpenFont(NULL, 24);
    if (font == NULL) {
        printf("Error al cargar la fuente: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Colores
    SDL_Color whiteColor = {255, 255, 255, 255};

    // Loop principal
    int quit = 0;
    SDL_Event event;
    while (!quit) {
        // Manejar eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Limpiar la pantalla
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dibujar el menú
        SDL_Rect menuRect = {0, 0, WINDOW_WIDTH, MENU_HEIGHT};
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_RenderFillRect(renderer, &menuRect);

        // Renderizar texto del menú
        const char* appNames[] = {"comand.c", "quicktext.c", "snake_game.c", "quicknav.c", "network_manager"};
        int numApps = sizeof(appNames) / sizeof(appNames[0]);
        int menuX = 10;
        int menuY = 10;
        for (int i = 0; i < numApps; ++i) {
            SDL_Surface* surface = TTF_RenderText_Solid(font, appNames[i], whiteColor);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect textRect = {menuX, menuY, surface->w, surface->h};
            SDL_RenderCopy(renderer, texture, NULL, &textRect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
            menuX += 10 + surface->w;
        }

        // Presentar el renderizador
        SDL_RenderPresent(renderer);
    }

    // Limpiar y cerrar SDL
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}