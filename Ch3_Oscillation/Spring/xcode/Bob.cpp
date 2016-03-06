//
//  Bob.cpp
//  Spring
//
//  Created by John Farrell on 3/4/16.
//
//

#include "Bob.hpp"


Bob::Bob(float x_, float y_){
    location_ = vec2(x_,y_);
    velocity_ = vec2(0,0);
    mass_ = 24;
    damping_ = 0.98;
    fill_ = 0;

}


void Bob::update()
{
    velocity_ += acceleration_;
    velocity_ *= damping_;
    location_ += velocity_;
    
    acceleration_ *= 0;

}


void Bob::applyForce(vec2 force_)
{
    vec2 f = force_ / mass_;
    acceleration_ += f;
}

void Bob::draw()
{
    gl::color(fill_, fill_, fill_);
    gl::drawSolidCircle(location_, mass_);
    gl::color(1,1,1);
    gl::drawStrokedCircle(location_, mass_);
}
