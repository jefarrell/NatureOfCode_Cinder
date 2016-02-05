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
    gl::drawSolidCircle(vec2(x_,y_), 2.5);
    
}

void Walker::step()
{
    float r = randFloat();
    
    if (r < 0.2) {
        x_++;
    } else if (r > 0.2 && r < 0.4) {
        x_--;
    } else if (r > 0.4 && r < 0.6) {
        y_++;
    } else {
        y_--;
    }
    
}

