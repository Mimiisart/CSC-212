#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Test", 800, 800, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    SDL_Surface* surface0 = IMG_Load("/Users/miraclechiji/CSC-212/Blenderclass/pink.jpg");
    SDL_Texture* texture0 = SDL_CreateTextureFromSurface(renderer, surface0);
     SDL_FRect imgrect0 = { 100,300,200,200 };
         SDL_DestroySurface(surface0);


    SDL_Surface* surface1= IMG_Load("/Users/miraclechiji/CSC-212/Blenderclass/vogue.jpg");
    SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_FRect imgrect1= { 500,300,200,200 };
         SDL_DestroySurface(surface1);


    SDL_Surface* surface2 = IMG_Load("/Users/miraclechiji/CSC-212/Blenderclass/tiger.jpg");
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_FRect imgrect2 = { 300,50,200,200 };
         SDL_DestroySurface(surface2);

    SDL_Surface* surface3 = IMG_Load("/Users/miraclechiji/CSC-212/Blenderclass/fruit.jpg");
    SDL_Texture* texture3= SDL_CreateTextureFromSurface(renderer, surface3);
    SDL_FRect imgrect3 = { 300,550,200,200 };
         SDL_DestroySurface(surface3);



    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }

        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, texture0, NULL, &imgrect0);
        SDL_RenderTexture(renderer, texture1, NULL, &imgrect1);
        SDL_RenderTexture(renderer, texture2, NULL, &imgrect2);
        SDL_RenderTexture(renderer, texture3, NULL, &imgrect3);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}