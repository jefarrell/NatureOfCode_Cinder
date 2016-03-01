//
//  Mover.cpp
//  MutualAttraction
//
//  Created by John Farrell on 2/28/16.
//
//

#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;

Mover::Mover(float x_, float y_, float m_){
    location_ = vec2(x_, y_);
    velocity_ = vec2(0.0f,0.0f);
    acceleration_ = vec2(0.0f,0.0f);
    mass_ = m_;
    G_ = 0.01;
}


void Mover::update()
{
    velocity_ += acceleration_;
    location_ += velocity_;
    
    acceleration_ *= 0;
    
}

void Mover::draw()
{
    gl::color(0.75,0.75,0.75);
    gl::drawSolidCircle(location_, mass_*12);
    gl::color(0,0,0);
    gl::drawStrokedCircle(location_, mass_*12);
    
}

void Mover::applyForce(vec2 force_)
{
    vec2 f = force_ / mass_;
    acceleration_ += f;
}

vec2 Mover::attract(MoverRef m)
{
    vec2 force = location_ - m->location_;
    float distance = sqrt(location_[0]*m->location_[0] + location_[1]*m->location_[1]);
    distance = glm::clamp(distance, 5.0f, 20.0f);
    
    glm::normalize(force);
    float strength = (G_ * mass_ * m->mass_) / (distance * distance) ;
    force *= strength;
    
    return force;
}