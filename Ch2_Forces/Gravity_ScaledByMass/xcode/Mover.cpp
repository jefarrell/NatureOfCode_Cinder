//
//  Mover.cpp
//  Gravity_ScaledByMass
//
//  Created by John Farrell on 2/24/16.
//
//

#include "Mover.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

Mover::Mover(float m_, float x_, float y_){
    location_ = vec2(x_, y_);
    velocity_ = vec2(0,0);
    acceleration_ = vec2(0,0);
    mass_ = m_;
    topSpeed_ = 10.0f;
    
}


void Mover::applyForce(vec2 force_)
{
    force_ = force_ / mass_;
    acceleration_ += force_;
}

void Mover::update()
{
    
    
    velocity_ += acceleration_;
    limit(velocity_, topSpeed_);
    location_ += velocity_;
}


void Mover::draw()
{
    gl::color(0.5,0.5,0.5,0.5);
    gl::drawSolidCircle(location_, mass_*16);
    gl::color(0,0,0);
    gl::drawStrokedCircle(location_, mass_*16);
    
}

void Mover::checkEdges()
{
    int width_ = getWindowWidth();
    int height_ = getWindowHeight();
    
    if (location_.x > width_) {
        location_.x = width_;
        velocity_.x *= -1;
    } else if (location_.x < 0) {
        location_.x = 0;
        velocity_.x *= -1;
    }
    
    if (location_.y > height_) {
        location_.y = height_;
        velocity_.y *= -1;
    } else if (location_.y < 0) {
        location_.y = 0;
        velocity_.y *= -1;
    }
}

vec2 Mover::limit(vec2 input, float max)
{
    auto I = length(input);
    if (I > max) {
        return glm::normalize(input)*max;
    }
    return input;
};



