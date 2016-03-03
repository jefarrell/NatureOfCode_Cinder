//
//  Oscillator.cpp
//  oscillatorObjects
//
//  Created by John Farrell on 3/2/16.
//
//

#include "Oscillator.hpp"


Oscillator::Oscillator()
{

    velocity_ = vec2(randFloat(-0.05,0.05), randFloat(-0.05,0.05));
    amplitude_ = vec2(randFloat(20,getWindowWidth()/2), randFloat(20,getWindowHeight()/2));

}



void Oscillator::update()
{
    angle_ += velocity_;
    
    
}


void Oscillator::draw()
{
    
    
    float x_ = sin(angle_.x) * amplitude_.x;
    float y_ = sin(angle_.y) * amplitude_.y;
    
    gl::pushMatrices();
    gl::translate(getWindowCenter());
    gl::color(0,0,0);
    gl::drawLine(vec2(0,0), vec2(x_,y_));
    gl::color(0.5,0.5,0.5,0.5);
    gl::drawSolidCircle(vec2(x_, y_),25);
    gl::color(0,0,0);
    gl::drawStrokedCircle(vec2(x_, y_),25);
    gl::popMatrices();
}