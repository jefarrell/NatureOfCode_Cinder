//
//  Confetti.cpp
//  ParticleSystem_InheritancePolymorphism
//
//  Created by John Farrell on 3/9/16.
//
//

#include "Confetti.hpp"

using namespace ci;
using namespace ci::app;

Confetti::Confetti(vec2 loc_) : Particle(loc_){
    
};


void Confetti::draw() {
    float theta = lmap(location_.x, 0.0f, (float)getWindowWidth(), 0.0f, (float)M_PI*2);
    gl::color(0, 0, 0, lifespan_);
    
    gl::pushMatrices();
    gl::translate(location_);
    gl::rotate(theta);
    gl::drawSolidRect(Rectf(-vec2(8,8), vec2(8,8)));
    gl::popMatrices();
}