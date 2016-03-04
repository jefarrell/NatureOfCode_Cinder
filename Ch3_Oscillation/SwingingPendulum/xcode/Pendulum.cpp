//
//  Pendulum.cpp
//  SwingingPendulum
//
//  Created by John Farrell on 3/4/16.
//
//

#include "Pendulum.hpp"


Pendulum::Pendulum() {
    r_ = 125;
    angle_ = M_PI/4;
    gravity_ = 0.1;
}


void Pendulum::update()
{
    
    aAcceleration_ = (-1 * gravity_ * sin(angle_))/r_;;
    aVelocity_ += aAcceleration_;
    angle_ += aVelocity_;

    origin_ = vec2(getWindowWidth()/2,0);
    location_ = vec2(r_*sin(angle_), r_*cos(angle_));
    location_ += origin_;
    
    aVelocity_ *= 0.99;
}



void Pendulum::draw()
{
    gl::color(0,0,0);
    gl::drawLine(vec2(origin_.x, origin_.y), vec2(location_.x, location_.y));
    gl::color(0.5,0.5,0.5);
    gl::drawSolidCircle(location_,16);
    gl::color(0,0,0);
    gl::drawStrokedCircle(location_,16);
    
}