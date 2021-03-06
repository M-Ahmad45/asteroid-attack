#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "SDL2/SDL.h"
#include "../include/Vector2.hpp"


class GameObject{
public:
    GameObject();
    GameObject(const char* sprite,SDL_Renderer* renderer, int collision_radius, const SDL_FRect& pos_size, double direction);
    GameObject(GameObject&& other);
    GameObject(const GameObject& other)=delete;
    GameObject& operator=(GameObject&& rhs);

    void draw(SDL_Renderer* renderer);
    void update(float delta_time);
    void set_pos(const Vector2& new_pos);
    void set_velocity(const Vector2& new_vel);

    bool collide(const GameObject& other);
    ~GameObject();

private:
    inline void update_center();
    
    Vector2 m_center;
    int m_radius; //radius for the collision circle
    SDL_FRect m_pos_size; //position of object and size of object
    SDL_Texture* m_sprite_texture;

protected:
    Vector2 m_velocity;
    double m_sprite_rotation; //rotation factor for sprite
};



#endif