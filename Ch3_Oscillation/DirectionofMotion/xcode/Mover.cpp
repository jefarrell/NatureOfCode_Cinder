//
//  Mover.cpp
//  DirectionofMotion
//
//  Created by John Farrell on 3/1/16.
//
//

#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;

Mover::Mover(float x_, float y_, float m_){
    location_ = vec2(x_, y_);
    velocity_ = vec2(0.0f,0.0f);
    mass_ = m_;
    angle_ = 0;
    mousePos_ = vec2(0,0);
}


void Mover::update()
{
 
    acceleration_ = mousePos_ - location_;
    acceleration_ = glm::normalize(acceleration_);

    velocity_ += acceleration_;
    velocity_ = limit(velocity_, 5.0);
    location_ += velocity_;

    angle_ = atan2(velocity_.y, velocity_.x);
    
    acceleration_ *= 0;
    
}

void Mover::draw()
{
    gl::pushMatrices();
    gl::translate(location_);
    
    gl::rotate(angle_);
    gl::color(0.75,0.75,0.75);
    gl::drawSolidRect(Rectf(-vec2(mass_*7, mass_*3), vec2(mass_*7,mass_*3)));
    gl::color(0,0,0);
    gl::drawStrokedRect(Rectf(-vec2(mass_*7, mass_*3), vec2(mass_*7,mass_*3)));
    
    gl::popMatrices();
}


void Mover::mouseTarget(vec2 mouseMove_)
{
    mousePos_ = mouseMove_;
}

vec2 Mover::limit(vec2 input, float max)
{
    auto I = length(input);
    if (I > max) {
        return glm::normalize(input)*max;
    }
    return input;
};
