#include "../include/Vector2.hpp"
#include <cmath>

void Vector2::rotate(double angle){
    float tx = x;
    float ty = y;
    x = tx*cos(angle) - ty*sin(angle);
    y = tx*sin(angle) + ty*cos(angle);

}