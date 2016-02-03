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
    //std::cout << x1_ << ", " << x2_ << ", " << y2_;
}

void Block::display()//draw
{
    gl::color(1,1,1);
    gl::drawStrokedRect(Rectf(x1_, y1_-randomNum, x2_, y2_));
   // std::cout << x1_ << ", " << x2_ << ", " << y2_;
 
}


void Block::increase()//update
{
    randomNum++;
    // dont draw again, just update y1;
        // neneds to be seeded the right starting place in block()
            //that will happen through a loop in the app
    //then increase will add via random number
}