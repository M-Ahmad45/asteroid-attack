#include "../include/Window.hpp"
#include "../include/GameObject.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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

    srand(time(0));

    GameObject spaceship("../assets/spaceship.png", renderer, 2, SDL_FRect{100,100,64,64},90);

    std::vector<GameObject> asteroids;
    for(int i=0;i<10;i++){
        
        asteroids.push_back(GameObject("../assets/asteroid_100.png", renderer,2, SDL_FRect{100,100,64,64},0));
        asteroids[i].set_pos(Vector2{(float)(rand()%320), (float)(rand()%240)});
        asteroids[i].set_velocity(Vector2{0.5f*(rand()%10), 0.5f*(rand()%10)});
    }

    while (is_running && (window_init && renderer_init)){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                is_running=false;
            }
        }
        SDL_SetRenderDrawColor(renderer,255,255,255,0);
        SDL_RenderClear(renderer);
        spaceship.draw(renderer);
        for(int i=0;i<10;i++){
            asteroids[i].draw(renderer);
        }
        SDL_RenderPresent(renderer);
        for(int i=0;i<10;i++){
            asteroids[i].update(0.1);
        }
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