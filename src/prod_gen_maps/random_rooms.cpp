#include <iostream>
#include <SDL2/SDL.h>
#include <random>
#include <vector>

int const ROOM_NUMBER = 5;

#include <iostream>
#include <SDL2/SDL.h>
#include <random>

// compile this project with: g++ -o random_rooms random_rooms.cpp -lSDL2


int create_roooms(){

    return 0;
}


int main(){

    
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window =  SDL_CreateWindow("Random Walk",
                        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //SDL_RenderSetScale(renderer,20,20);

    // declare room graph 

    // rooms are nodes 

    // the path between rooms are edges
   
    //vector<int> room_data = new vector();

    bool isRunning = true;
    SDL_Event e;

    while(isRunning){

        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT){
            isRunning = false;
        }

        int x = 25;
        int y = 25;

        // get the instructions to draw each room

        SDL_Rect rect;
        rect.x = 25;
        rect.y = 25;
        rect.w = 200;
        rect.h = 200;


        // draw the outline of each room

        // draw the paths between rooms


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderDrawRect(renderer, &rect);

        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        //SDL_RenderDrawPoint(renderer, x, y);

        SDL_RenderPresent(renderer);

    }

    
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}