//
//  Walker.cpp
//  PerlinWalker
//
//  Created by John Farrell on 2/8/16.
//
//

#include "Walker.hpp"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Walker::Walker()
{
    x_ = 0, y_ = 0;
    tx_ = 0;
    ty_ = 1000;
   
   
    
    
}

void Walker::update()
{
    float w = getWindowWidth();
    float h = getWindowHeight();

    x_ = (w/2) + lmap(perlin_.noise(tx_), 0.0f, 1.0f, 0.0f, w);
    y_ = (h/2) + lmap(perlin_.noise(ty_), 0.0f, 1.0f, 0.0f, h);
    
    tx_+= 0.001;
    ty_+= 0.001;
    
    
}

void Walker::draw()
{
  
    
    
    gl::color(1,1,1,0.5);
    gl::drawSolidCircle(vec2(x_,y_), 2.5);
    
}