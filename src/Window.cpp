#include "../include/Window.hpp"
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
    is_running = true;

    srand(time(0));
    
    spaceship = SpaceShip("../assets/spaceship.png", renderer, 2, SDL_FRect{100,100,64,64});

    while (is_running && (window_init && renderer_init)){

       input(); 
       update();
       draw();        
        
    }
}

void Window::input(){
    key_event = 0;
    while(SDL_PollEvent(&event)){
        if(event.type==SDL_QUIT){
            is_running=false;
        }else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                key_event = key_event | KEY_UP;
                break;

            case SDLK_LEFT:
                key_event = key_event | KEY_LEFT;
                break;

            case SDLK_RIGHT:
                key_event = key_event | KEY_RIGHT;
                break;
            default:
                break;
            }
        }
    }
}


void Window::draw(){
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderClear(renderer);

    spaceship.draw(renderer);

    SDL_RenderPresent(renderer);
}

void Window::update(){

    switch (key_event)
    {
    case KEY_UP:
        spaceship.moving(true);
        break;
    case KEY_LEFT:
        spaceship.rotate(-15);
        break;
    case KEY_RIGHT:
        spaceship.rotate(15);
        break;
    case KEY_UP | KEY_LEFT:
        spaceship.moving(true);
        spaceship.rotate(-15);
        break;
    case KEY_UP | KEY_RIGHT:
        spaceship.moving(true);
        spaceship.rotate(-15);
        break;
    default:
        spaceship.moving(false);
        break;
    }

    spaceship.update(0.1);


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