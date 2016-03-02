//
//  Mover.cpp
//  Forces_withAngularMotion
//
//  Created by John Farrell on 3/1/16.
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
    angle_ = 0;
    aVelocity = 0.0;
    aAcceleration = 0.01;
}


void Mover::update()
{
    
    velocity_ += acceleration_;
    location_ += velocity_;
    
    aAcceleration = acceleration_.x/25;
    aVelocity += aAcceleration;
    angle_ += aVelocity;
    
    acceleration_ *= 0;
    
}

void Mover::draw()
{
    gl::pushMatrices();
    gl::translate(location_);
    
    gl::rotate(angle_);
    gl::color(0.75,0.75,0.75);
    gl::drawSolidRect(Rectf(-vec2(mass_*7, mass_*7), vec2(mass_*7,mass_*7)));
    gl::color(0,0,0);
    gl::drawStrokedRect(Rectf(-vec2(mass_*7, mass_*7), vec2(mass_*7,mass_*7)));
    
    gl::popMatrices();
}

void Mover::applyForce(vec2 force_)
{
    vec2 f = force_ / mass_;
    acceleration_ += f;
}