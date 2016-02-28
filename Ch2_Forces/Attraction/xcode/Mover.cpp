//
//  Mover.cpp
//  Attraction
//
//  Created by John Farrell on 2/27/16.
//
//

#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;

Mover::Mover(){
    location_ = vec2(300,300);
    velocity_ = vec2(1.0f,0.0f);
    acceleration_ = vec2(0.0f,0.0f);
    mass_ = 1.0f;
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