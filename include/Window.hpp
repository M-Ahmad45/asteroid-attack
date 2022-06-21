#ifndef WINDOW
#define WINDOW

#include "SDL2/SDL.h"
class Window{
public:
    Window(const char* name, int width, int height);
    void start();
    ~Window();
private:
    bool window_init;//is the window initialized?
    bool renderer_init; //is the renderer initialized?
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif