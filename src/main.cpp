#include <iostream>
#include "SDL2/SDL.h"

int main(){
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Asteroid Attack", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN);
    if (window==NULL){
        std::cerr<<"Failed to initialize window: "<<SDL_GetError()<<"\n";
        return 1;
    }
    SDL_Delay(5000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}