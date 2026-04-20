// #define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


// ─── COMPLETE EXAMPLE: Creating windows ─────────────────────────────────
 
int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window * window = SDL_CreateWindow("new window", 800,600,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,NULL);


    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    

    SDL_FPoint points[4] = {

        {400,300},{400,301},{400,302},{400,303}
    };

    SDL_SetRenderDrawColor(renderer ,255,0,0,255);
    SDL_RenderPoints(renderer,points,4);



    // SDL_FPoint lines[]={

    //     {0 ,300},{800,300},{400,0},{400,600}
    // };
    SDL_FPoint lines[]={

        {200 ,200},{200,400},{400,400},{400,200}, {200, 200}
    };
    SDL_SetRenderDrawColor(renderer, 0,0,255,255);

 SDL_RenderLines(renderer,lines,5);

SDL_RenderPresent(renderer);


    SDL_Event event;
    bool running =true;

    while(running){

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT)
            running = false;
            if(event.type ==SDL_EVENT_KEY_DOWN && event.key.key ==SDLK_ESCAPE)
            running =false;
        }
// SDL_SetRenderDrawColor
// (ren,255,255,255,255);
// SDL_RenderClear(ren);


// SDL_SetRenderDrawColor(ren,0,0,0,255);
// SDL_FRect box = {350.0f,250.0f,100.0f,100.0f };
// SDL_RenderFillRect(ren,&box);

// SDL_RenderPresent(ren);

    }
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
 
}




//  if (!SDL_Init(SDL_INIT_VIDEO)) {
//        SDL_Log("SDL_Init failed: %s", SDL_GetError());
//        return -1;
//    }
 
//    // ── Basic window ─────────────────────────────────────────────────
//    // SDL_CreateWindow(title, width, height, flags)
//    SDL_Window* win1 = SDL_CreateWindow("Standard Window", 800, 600, 0);
//    if (!win1) {
//        SDL_Log("Window failed: %s", SDL_GetError());
//        SDL_Quit();
//        return -1;
//    }
 
//    // ── Resizable, hi-DPI window (recommended for games) ─────────────
//    SDL_Window* win2 = SDL_CreateWindow(
//        "Resizable Game",
//        1280, 720,
//        SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY
//    );
 
//    // ── Borderless window (no title bar, no close button) ────────────
//    SDL_Window* win3 = SDL_CreateWindow(
//        "Borderless",
//        400, 300,
//        SDL_WINDOW_BORDERLESS
//    );
 
//    // ── Create window AND renderer in one call (convenience) ─────────
//    SDL_Window*   win4 = nullptr;
//    SDL_Renderer* ren4 = nullptr;
//    if (!SDL_CreateWindowAndRenderer("Quick Start", 800, 600, 0, &win4, &ren4)) {
//        SDL_Log("CreateWindowAndRenderer failed: %s", SDL_GetError());
//    }
 
//    SDL_Delay(2000);
 
//    if (ren4) SDL_DestroyRenderer(ren4);
//    if (win4) SDL_DestroyWindow(win4);
//    if (win3) SDL_DestroyWindow(win3);
//    if (win2) SDL_DestroyWindow(win2);
//    if (win1) SDL_DestroyWindow(win1);
//    SDL_Quit();
//    return 0;

// static SDL_Window *window = NULL;
// static SDL_Renderer *renderer = NULL;

// SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
// {
//     SDL_SetAppMetadata("Example Renderer Clear", "1.0", "com.example.renderer-clear");

//     if (!SDL_Init(SDL_INIT_VIDEO)) {
//         SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
//         return SDL_APP_FAILURE;
//     }

//     if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", 640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
//         SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
//         return SDL_APP_FAILURE;
//     }

//     SDL_SetRenderLogicalPresentation(renderer, 640, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);

//     return SDL_APP_CONTINUE;
// }

// SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
// {
//     if (event->type == SDL_EVENT_QUIT) {
//         return SDL_APP_SUCCESS;
//     }
//     return SDL_APP_CONTINUE;
// }

// SDL_AppResult SDL_AppIterate(void *appstate)
// {
//     const double now = ((double)SDL_GetTicks()) / 1000.0;

//     const float red = (float)(0.5 + 0.5 * SDL_sin(now));
//     const float green = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
//     const float blue = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));

//     SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);

//     SDL_RenderClear(renderer);
//     SDL_RenderPresent(renderer);

//     return SDL_APP_CONTINUE;
// }

// void SDL_AppQuit(void *appstate, SDL_AppResult result)
// {
// }