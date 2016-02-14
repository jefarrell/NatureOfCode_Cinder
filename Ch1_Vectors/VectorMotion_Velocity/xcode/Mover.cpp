//
//  Mover.cpp
//  VectorMotion_Velocity
//
//  Created by John Farrell on 2/14/16.
//
//

#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;


Mover::Mover()
{
    
    location_ = vec2(getWindowWidth()/2, getWindowHeight()/2);
    velocity_ = vec2(randFloat(-7,7), randFloat(-7,7));
    
}

void Mover::update()
{
    location_ += velocity_;
    
    checkEdges();
}

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
    gl::color(1,1,1);
    gl::drawStrokedCircle(location_,10);
    
}