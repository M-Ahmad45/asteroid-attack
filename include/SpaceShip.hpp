#ifndef SPACESHIP
#define SPACESHIP

#include "../include/GameObject.hpp"

class SpaceShip: public GameObject{

public:
    SpaceShip()=default;
    SpaceShip(const char* sprite,SDL_Renderer* renderer, int collision_radius, const SDL_FRect& pos_size):
        GameObject(sprite, renderer, collision_radius,pos_size, direction+ 90){

        }
    
    void moving(bool m);
    void rotate(double angle);

private:
    int speed=10;
    double direction = 0;
    
};

#endif