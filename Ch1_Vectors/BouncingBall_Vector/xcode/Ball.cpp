//
//  Ball.cpp
//  BouncingBall_Vector
//
//  Created by John Farrell on 2/9/16.
//
//

#include "Ball.hpp"

using namespace ci;
using namespace ci::app;

Ball::Ball()
{
    position_ = vec2(100,100);
    speed_ = vec2(6,2.5);
}

void Ball::update()
{
    position_ += speed_;
    
    if (position_.x > getWindowWidth() || position_.x < 0) {
        speed_.x *= -1;
    }
    if (position_.y > getWindowHeight() || position_.y < 0) {
        speed_.y *= -1;
    }
}

void Ball::draw()
{
    gl::color(1,1,1);
    gl::drawSolidCircle(position_,20);
    
    
}