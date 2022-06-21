#include <iostream>
#include "SDL2/SDL.h"

#include "../include/GameObject.hpp"

int main(){
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Asteroid Attack", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN);
    if (window==NULL){
        std::cerr<<"Failed to initialize window: "<<SDL_GetError()<<"\n";
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_Event event;
    bool is_running = true;

    GameObject spaceship("../assets/spaceship.png", renderer, 2, SDL_Rect{64,64,100,100},90);
    
    while (is_running){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                is_running=false;
            }
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        spaceship.draw(renderer);
        SDL_RenderPresent(renderer);
        
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}