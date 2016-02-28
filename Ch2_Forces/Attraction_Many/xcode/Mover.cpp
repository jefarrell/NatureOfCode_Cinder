//
//  Mover.cpp
//  Attraction_Many
//
//  Created by John Farrell on 2/28/16.
//
//

#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;

Mover::Mover(float x_, float y_, float m_){
    location_ = vec2(x_, y_);
    velocity_ = vec2(1.0f,0.0f);
    acceleration_ = vec2(0.0f,0.0f);
    mass_ = m_;
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