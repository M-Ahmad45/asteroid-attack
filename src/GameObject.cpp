#include "../include/GameObject.hpp"
#include "SDL2/SDL_image.h"

GameObject::GameObject(const char* sprite, SDL_Renderer* renderer,
                    int collision_radius, const SDL_FRect& pos_size, double direction)
                    :collision_radius(collision_radius), pos_size(pos_size),direction(direction) {

    SDL_Surface* sprite_surface = IMG_Load(sprite);
    sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);
    SDL_FreeSurface(sprite_surface);
}
 
void GameObject::draw( SDL_Renderer* renderer){
    SDL_RenderCopyExF(renderer,sprite_texture,NULL,&pos_size,direction,NULL, SDL_FLIP_NONE);
}
void GameObject::update(float delta_time){
    pos_size.x = pos_size.x + velocity.m_x*delta_time;
    pos_size.y = pos_size.y + velocity.m_y*delta_time;
}
GameObject::~GameObject(){
    SDL_DestroyTexture(sprite_texture);
}

void GameObject::set_pos(const Vector2 new_pos){
    pos_size.x = new_pos.m_x;
    pos_size.y = new_pos.m_y;
}