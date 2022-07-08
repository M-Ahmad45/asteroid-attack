#include "../include/GameObject.hpp"
#include "SDL2/SDL_image.h"
#include <cmath>
#include <iostream>

//default
GameObject::GameObject(){
    m_sprite_texture = NULL;
}

//initializer
GameObject::GameObject(const char* sprite, SDL_Renderer* renderer,
                    int collision_radius, const SDL_FRect& pos_size, double direction)
                    :m_radius(collision_radius), m_pos_size(pos_size),m_sprite_rotation(direction) {
    update_center();
    SDL_Surface* sprite_surface = IMG_Load(sprite);
    m_sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);
    SDL_FreeSurface(sprite_surface);
}
 
//move
GameObject::GameObject(GameObject&& other)
    :m_sprite_texture(other.m_sprite_texture), m_velocity(other.m_velocity),m_pos_size(other.m_pos_size), m_sprite_rotation(other.m_sprite_rotation),
    m_radius(other.m_radius), m_center(other.m_center){

    other.m_sprite_texture=NULL;
}
//move assign
GameObject& GameObject::operator=(GameObject&& rhs){    
    m_sprite_texture = rhs.m_sprite_texture;
    m_velocity = rhs.m_velocity;
    m_pos_size = rhs.m_pos_size;
    m_sprite_rotation = rhs.m_sprite_rotation;
    m_radius = rhs.m_radius;
    m_center = rhs.m_center;

    rhs.m_sprite_texture = NULL;

    return *this;
}
//destroy
GameObject::~GameObject(){
    SDL_DestroyTexture(m_sprite_texture);
}




void GameObject::draw( SDL_Renderer* renderer){
    SDL_RenderCopyExF(renderer,m_sprite_texture,NULL,&m_pos_size,m_sprite_rotation,NULL, SDL_FLIP_NONE);
}
void GameObject::update(float delta_time){
    m_pos_size.x = m_pos_size.x + m_velocity.x*delta_time;
    m_pos_size.y = m_pos_size.y + m_velocity.y*delta_time;
    update_center();
}

void GameObject::set_pos(const Vector2& new_pos){
    m_pos_size.x = new_pos.x;
    m_pos_size.y = new_pos.y;
    update_center();
}



inline void GameObject::update_center(){
    m_center.x = (m_pos_size.x+m_pos_size.w)/2;
    m_center.y = (m_pos_size.y+m_pos_size.h)/2;
}

bool GameObject::collide(const GameObject& other){
    float R = sqrtf(powf(m_center.x-other.m_center.x,2)+powf(m_center.y-other.m_center.y,2));
    bool collision = R<=(m_radius+ other.m_radius);
    return collision;
}

void GameObject::set_velocity(const Vector2& vel){
    m_velocity.x = vel.x;
    m_velocity.y = vel.y;
    m_sprite_rotation = atan(m_velocity.y/m_velocity.x);
}
