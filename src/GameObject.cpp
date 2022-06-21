#include "../include/GameObject.hpp"
#include "SDL2/SDL_image.h"

GameObject::GameObject(const char* sprite, SDL_Renderer* renderer,
                    int collision_radius, const SDL_Rect& pos_size, double direction)
                    :collision_radius(collision_radius), pos_size(pos_size),direction(direction) {
    SDL_Surface* sprite_surface = IMG_Load(sprite);
    sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);
    SDL_FreeSurface(sprite_surface);
}
 
void GameObject::draw( SDL_Renderer* renderer){
    SDL_RenderClear(renderer);
    SDL_RenderCopyEx(renderer,sprite_texture,NULL,&pos_size,direction,NULL, SDL_FLIP_NONE);
}

GameObject::~GameObject(){
    SDL_DestroyTexture(sprite_texture);
}