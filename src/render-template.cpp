#include <iostream>
#include <SDL2/SDL.h>
#include <random>

// compile this project with: g++ -o render-template render-template.cpp -lSDL2

int main(){
    
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window =  SDL_CreateWindow("Random Walk",
                        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   

    bool isRunning = true;
    SDL_Event e;

    while(isRunning){

        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT){
            isRunning = false;
        }

        int x = 25;
        int y = 25;
        // render more stuff here or in a function
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
       // SDL_RenderDrawPoint(renderer, x, y);
        SDL_RenderPresent(renderer);

    }

    
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}