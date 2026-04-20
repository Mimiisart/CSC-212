#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


// ─── COMPLETE EXAMPLE: Creating windows ─────────────────────────────────
 
int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window * window = SDL_CreateWindow("Connected Lines", 800,600,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,NULL);

float rectx =0.0f;
float recty = 250.0f;
float speed = 200.0f;
Uint64 lastTime = SDL_GetTicks();

bool running = true;
SDL_Event e;

while(running){
    Uint64 currentTime =SDL_GetTicks();
    float deltaTime = (currentTime -lastTime)/ 1000.0f;
    lastTime =currentTime;


    while(SDL_PollEvent(&e)){
            if(e.type == SDL_EVENT_QUIT)
            running = false;
        
        }

        rectx += speed * deltaTime;
        if(rectx> 800){
            rectx= 0;
        }
        recty += speed * deltaTime;
        if(recty> 600){
            recty= 0;
        }


SDL_FRect rect = {rectx, recty, 100, 200};



SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
SDL_RenderClear(renderer);


SDL_SetRenderDrawColor(renderer, 0, 65, 255, 255);
SDL_RenderFillRect(renderer, &rect);
SDL_RenderPresent(renderer) ;
}









}