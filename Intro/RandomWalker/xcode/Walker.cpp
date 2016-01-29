//
//  Walker.cpp
//  RandomWalker
//
//  Created by John Farrell on 1/27/16.
//
//

#include "Walker.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;


Walker::Walker()
{
    ci::vec2 center = getWindowCenter();
    x_ = center.x;
    y_ = center.y;
    
}

void Walker::display()
{
    gl::color(1,1,1,0.5);
    gl::drawSolidCircle(vec2(x_,y_), 1.0);
    
}

void Walker::step()
{
    x_ += randFloat(-1,1);
    y_ += randFloat(-1,1);
    
}

