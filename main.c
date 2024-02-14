#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_INIT error: %s.\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("hello_sdl", SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if (window == NULL) {
        printf("SDL_CreateWindow error: %s.\n", SDL_GetError()); // Seems to be repetitive pattern for init., could extract
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("SDL_CreateRenderer error: %s.\n", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(2000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
