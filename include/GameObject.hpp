#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "SDL2/SDL.h"
#include "../include/Vector2.hpp"

//TODO: Implement Copy and Move constructors

class GameObject{
public:
    GameObject(const char* sprite,SDL_Renderer* renderer, int collision_radius, const SDL_FRect& pos_size, double direction);
    void draw(SDL_Renderer* renderer);
    void update(float delta_time);
    void set_pos(const Vector2 new_pos);
   // bool collide(const GameObject& other);
    ~GameObject();

private:
    Vector2 velocity={1,1};
    int collision_radius; //radius for the collision circle
    double direction; //direction of the object
    SDL_FRect pos_size; //position of object and size of object
    SDL_Texture* sprite_texture;
};



#endif