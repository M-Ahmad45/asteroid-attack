#include "../include/Window.hpp"
#include "../include/GameObject.hpp"
#include <iostream>
#include <vector>

Window::Window(const char* name, int width, int height){
    window_init = false;
    renderer_init = false;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(name,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    if (window==NULL){
        std::cerr<<"Failed to initialize window: "<<SDL_GetError()<<"\n";
        return;
    }
    window_init=true;
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (renderer==NULL){
        std::cerr<<"Failed to initialize window: "<<SDL_GetError()<<"\n";
        return;
    }
    renderer_init=true;
}

void Window::start(){
    SDL_Event event;
    bool is_running = true;

    GameObject spaceship("../assets/spaceship.png", renderer, 2, SDL_Rect{100,100,64,64},90);
    GameObject asteroid("../assets/asteroid_100.png",renderer,10,SDL_Rect{250,50, 100,100},0);


    while (is_running && (window_init && renderer_init)){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                is_running=false;
            }
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        spaceship.draw(renderer);
        asteroid.draw(renderer);
        SDL_RenderPresent(renderer);
    }
}

Window::~Window(){
    if(window_init){
        SDL_DestroyWindow(window);
    }
    if(renderer_init){
        SDL_DestroyRenderer(renderer);
    }
    SDL_Quit();
}