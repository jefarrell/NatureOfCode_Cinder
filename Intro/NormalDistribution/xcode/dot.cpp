//
//  dot.cpp
//  NormalDistribution
//
//  Created by John Farrell on 2/4/16.
//
//

#include "dot.hpp"
#include "glm/gtc/random.hpp"

using namespace ci;
using namespace ci::app;

dot::dot()
{
    x_;
    y_= getWindowHeight()/2;
}


void dot::update()
{
    float std = 10;
    float mean = getWindowWidth()/2;
    x_ = glm::gaussRand(mean,std);
    
}

void dot::draw()
{
    gl::color(1,1,1);
    gl::drawSolidCircle(vec2(x_,y_), 5);
}