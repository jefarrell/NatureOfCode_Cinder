//
//  Liquid.cpp
//  FluidResistance
//
//  Created by John Farrell on 2/24/16.
//
//

#include "Liquid.hpp"


using namespace ci;
using namespace ci::app;
using namespace std;

Liquid::Liquid(float x1_, float y1_, float x2_, float y2_, float c_) {
    x1 = x1_;
    x2 = x2_;
    y1 = y1_;
    y2 = y2_;
    boundary_ = Rectf(x1,y1,x2,y2);
    c = c_;
}


void Liquid::update()
{
    
}


void Liquid::draw()
{
    gl::color(0.15,0.15,0.15,0.5);
    gl::drawSolidRect(boundary_);
}