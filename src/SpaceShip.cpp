#include "../include/SpaceShip.hpp"

void SpaceShip::moving(bool m){
        if(m){
            m_velocity.x = speed*cos(direction*(3.14159/180));//correction factor because direction is in degrees and cos sin take rads
            m_velocity.y = speed*sin(direction*(3.14159/180));
        }else{
            m_velocity.x = 0;
            m_velocity.y = 0;
        }
    }
void SpaceShip::rotate(double angle){
    m_sprite_rotation +=angle;
    direction+=angle;
    m_velocity.rotate(direction*(3.14159/180));
}