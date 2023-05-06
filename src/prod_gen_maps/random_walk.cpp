#include <iostream>
#include <SDL2/SDL.h>
#include <random>

// credit to "the builder" on youtube for this tutorial 
// https://www.youtube.com/watch?v=T46nu5e4pNI&ab_channel=TheBuilder

// compile this project with: g++ -o random_walk random_walk.cpp -lSDL2

int main(){
    

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window =  SDL_CreateWindow("Random Walk",
                        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        50 * 20, 50 * 20,
        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderSetScale(renderer,20,20);
   

    int x = 25;
    int y = 25;

    std::random_device dev;
    std::uniform_int_distribution<uint8_t> nd(0,3);


    bool isRunning = true;
    SDL_Event e;

    while(isRunning){

        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT){
            isRunning = false;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawPoint(renderer, x, y);
        SDL_RenderPresent(renderer);


        u_int8_t dir = nd(dev);

        switch(dir){

          
            case 0:
                x += 1;
                break;
            
            case 1:
                x -= 1;
                break;

            case 2:
                y += 1;
                break;

            case 3:
                y -= 1;
                break;

            /**
             *   case 0:
                x -= 1;
                y -= 1;
                break;

            case 1:
                x += 1;
                y -= 1;
                break;

            case 2:
                x -= 1;
                y += 1;
                break;

            case 3:
                x += 1;
                y += 1;
                break;
             * 
             */

            default:
                break;
        }


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawPoint(renderer, x, y);
        SDL_RenderPresent(renderer);

        if(x > 50 || y > 50 || x < 0 || y < 0){
            x = 25;
            y = 25;
        }

        // print coords for debugging
        //std::cout << "coords" << x << " " << y << std::endl;

        SDL_Delay(50);

        

    }

    
    //SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}