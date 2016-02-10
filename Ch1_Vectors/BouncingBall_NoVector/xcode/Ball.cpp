//
//  Ball.cpp
//  BouncingBall_NoVector
//
//  Created by John Farrell on 2/9/16.
//
//

#include "Ball.hpp"

using namespace ci;
using namespace ci::app;

Ball::Ball()
{
    x_ = 100;
    y_ = 100;
    xSpeed_ = 5;
    ySpeed_ = 10;
    
}

void Ball::update()
{


    x_ = x_ + xSpeed_;
    y_ = y_ + ySpeed_;
    
    if (x_ > getWindowWidth() || x_ < 0) {
        xSpeed_ *= -1;
    };
    
    if (y_ > getWindowHeight() || y_ < 0 ) {
        ySpeed_ *= -1;
    };
    
}


void Ball::draw()
{
    gl::color(1,1,1);
    gl::drawSolidCircle(vec2(x_,y_), 25);
    
}