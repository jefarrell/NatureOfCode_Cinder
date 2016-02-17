//
//  Mover.cpp
//  VectorMotion_Acceleration
//
//  Created by John Farrell on 2/14/16.
//
//

#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;

Mover::Mover(){
    location_ = vec2(getWindowWidth()/2, getWindowHeight()/2);
    velocity_ = vec2(randFloat(-2,2), randFloat(-2,2));
    acceleration_ = vec2(0.01,0.01);
    topSpeed_ = 10.0f;
}


void Mover::update()
{
    velocity_ += acceleration_;
    location_ += velocity_;
    velocity_ = limit(velocity_, topSpeed_);
    checkEdges();
}

vec2 Mover::limit(vec2 input, float max)
{
    auto I = length(input);
    if (I > max) {
        return glm::normalize(input)*max;
    }
    return input;
};


void Mover::checkEdges()
{
    if (location_.x > getWindowWidth()) {
        location_.x = 0;
    } else if (location_.x < 0) {
        location_.x = getWindowWidth();
    }
    
    if (location_.y > getWindowHeight()) {
        location_.y = 0;
    } else if (location_.y < 0) {
        location_.y = getWindowHeight();
    }
    
}


void Mover::draw()
{
    gl::drawStrokedCircle(location_, 10);
    
}