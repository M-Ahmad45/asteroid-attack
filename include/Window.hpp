#ifndef WINDOW
#define WINDOW

#include "SDL2/SDL.h"
#include <vector>
#include "../include/GameObject.hpp"
#include "../include/SpaceShip.hpp"

class Window{
public:
    Window(const char* name, int width, int height);
    void start();
    ~Window();
private:

    void draw();
    void update();
    void input();

    std::vector<GameObject> asteroids;
    SpaceShip spaceship;

    enum INPUT_EVENT{
        KEY_UP=1,
        KEY_LEFT=2,
        KEY_RIGHT=4
    };
    bool is_running;
    SDL_Event event;
    bool window_init;//is the window initialized?
    bool renderer_init; //is the renderer initialized?
    SDL_Window* window;
    SDL_Renderer* renderer;
    int key_event;

};

#endif