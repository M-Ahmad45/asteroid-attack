#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "SDL2/SDL.h"
class GameObject{
public:
    GameObject(const char* sprite,SDL_Renderer* renderer, int collision_radius, const SDL_Rect& pos_size, double direction);
    void draw(SDL_Renderer* renderer);

    ~GameObject();

private:
    int collision_radius; //radius for the collision circle
    double direction; //direction of the object
    SDL_Rect pos_size; //position of object and size of object
    SDL_Texture* sprite_texture;
};



#endif