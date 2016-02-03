//
//  block.cpp
//  randomNumberDist
//
//  Created by John Farrell on 1/29/16.
//
//

#include "block.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;


Block::Block(float x1, float y1, float x2, float y2)
{
    x1_ = x1;
    y1_ = y1;
    x2_ = x2;
    y2_ = y2;
}

void Block::draw()//draw
{
    gl::color(1,1,1);
    gl::drawStrokedRect(Rectf(x1_, y1_-counter, x2_, y2_));
 
}


void Block::update()
{
    counter++;
}