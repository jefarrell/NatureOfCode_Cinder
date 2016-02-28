//
//  Attractor.cpp
//  Attraction
//
//  Created by John Farrell on 2/27/16.
//
//

#include "Attractor.hpp"
using namespace ci::app;
using namespace ci;

Attractor::Attractor() {
    location_ = vec2(getWindowWidth()/2, getWindowHeight()/2);
    mass_ = 20.0f;
    G_ = 0.01f;
}

vec2 Attractor::attract(MoverRef m)
{
    vec2 force = location_ - m->location_;
    float distance = sqrt(location_[0]*m->location_[0] + location_[1]*m->location_[1]);
    distance = glm::clamp(distance, 5.0f, 20.0f);
   
    glm::normalize(force);
    float strength = (G_ * mass_ * m->mass_) / (distance * distance) ;
    force *= strength;

    return force;
}

void Attractor::draw()
{
    gl::color(0.5, 0.5, 0.5, 0.5);
    gl::drawSolidCircle(location_, mass_);
    gl::color(0,0,0);
    gl::drawStrokedCircle(location_, mass_, 5.0f);
    
}