#ifndef VECTOR2
#define VECTOR2

class Vector2{
public:
    Vector2():m_x(0.0f),m_y(0.0f){}
    Vector2(float x, float y):m_x(x), m_y(y){}
    float m_x,m_y;
};


#endif