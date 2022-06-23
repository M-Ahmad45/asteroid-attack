#include "../include/GameObject.hpp"
#include "SDL2/SDL_image.h"

GameObject::GameObject(const char* sprite, SDL_Renderer* renderer,
                    int collision_radius, const SDL_FRect& pos_size, double direction)
                    :m_collision_radius(collision_radius), m_pos_size(pos_size),m_direction(direction) {
    
    m_center.m_x = (pos_size.x+pos_size.w)/2;
    m_center.m_y = (pos_size.y+pos_size.h)/2;
    SDL_Surface* sprite_surface = IMG_Load(sprite);
    m_sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);
    SDL_FreeSurface(sprite_surface);
}
 
void GameObject::draw( SDL_Renderer* renderer){
    SDL_RenderCopyExF(renderer,m_sprite_texture,NULL,&m_pos_size,m_direction,NULL, SDL_FLIP_NONE);
}
void GameObject::update(float delta_time){
    m_pos_size.x = m_pos_size.x + m_velocity.m_x*delta_time;
    m_pos_size.y = m_pos_size.y + m_velocity.m_y*delta_time;
}
GameObject::~GameObject(){
    SDL_DestroyTexture(m_sprite_texture);
}

void GameObject::set_pos(const Vector2& new_pos){
    m_pos_size.x = new_pos.m_x;
    m_pos_size.y = new_pos.m_y;
}

GameObject::GameObject(GameObject&& other)
    :m_sprite_texture(other.m_sprite_texture), m_velocity(other.m_velocity),m_pos_size(other.m_pos_size), m_direction(other.m_direction),
    m_collision_radius(other.m_collision_radius), m_center(other.m_center){

    other.m_sprite_texture=NULL;
}

bool GameObject::collide(const GameObject& other){
    return false;
}