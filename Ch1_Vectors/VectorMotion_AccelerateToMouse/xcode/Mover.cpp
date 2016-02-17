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
using namespace std;

Mover::Mover(){
    location_ = vec2(getWindowWidth()/2, getWindowHeight()/2);
    velocity_ = vec2(randFloat(-2,2), randFloat(-2,2));
    topSpeed_ = 10.0f;
}


void Mover::update()
{
    acceleration_ = mousePos_ - location_;
    acceleration_ = glm::normalize(acceleration_);
    velocity_ += acceleration_;
    velocity_ = limit(velocity_, topSpeed_);
    location_ += velocity_;

}

vec2 Mover::limit(vec2 input, float max)
{
    auto I = length(input);
    if (I > max) {
        return glm::normalize(input)*max;
    }
    return input;
};

void Mover::mouseTarget( vec2 mouseMove)
{
    mousePos_ = mouseMove;
}



void Mover::draw()
{
    gl::drawStrokedCircle(location_, 10);
    
}