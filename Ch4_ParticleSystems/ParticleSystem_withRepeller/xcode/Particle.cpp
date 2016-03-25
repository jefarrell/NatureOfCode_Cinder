//
//  Particle.cpp
//  ParticleSystem_withRepeller
//
//  Created by John Farrell on 3/24/16.
//
//

#include "Particle.hpp"
#include "cinder/Rand.h"

Particle::Particle(vec2 l)
{
    location_ = l;
    lifespan_ = 1.0;
    acceleration_ = vec2(0,0);
    velocity_ = vec2(randFloat(-1,1), randFloat(-2,0));
    mass_ = 1;
}

void Particle::update()
{
    velocity_ += acceleration_;
    location_ += velocity_;
    
    lifespan_ -= 0.01;
}

void Particle::draw()
{
    gl::color(0.8, 0.8, 0.8, lifespan_);
    gl::drawSolidCircle(location_, 8);
    gl::color(1, 1, 1, lifespan_);
    gl::drawStrokedCircle(location_, 8);
}

void Particle::applyForce(vec2 force_)
{
    force_ = force_ / mass_;
    acceleration_ += force_;
}


bool Particle::isDead()
{
    if (lifespan_ < 0.0)
        return true;
    else
        return false;
}

