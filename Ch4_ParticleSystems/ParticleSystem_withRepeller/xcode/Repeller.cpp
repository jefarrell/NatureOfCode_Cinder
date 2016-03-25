//
//  Repeller.cpp
//  ParticleSystem_withRepeller
//
//  Created by John Farrell on 3/24/16.
//
//

#include "Repeller.hpp"

Repeller::Repeller(vec2 loc_) {
    mass_ = 40.0f;
    G_ = 0.1f;
    location_ = loc_;
}


void Repeller::draw()
{
    gl::color(0.8,0.8,0,0.8);
    gl::drawSolidCircle(location_, mass_);
    gl::color(1,1,1);
    gl::drawStrokedCircle(location_, mass_);
}

vec2 Repeller::repel(ParticleRef p)
{
    vec2 dir = location_ - p->location_;
    float distance = sqrt(location_[0]*p->location_[0] + location_[1]*p->location_[1]);
    distance = glm::clamp(distance, 5.0f,100.0f);
    glm::normalize(dir);
    
    float force_ = -1.0f * G_ / (distance*distance);
    dir *= force_;
    return dir;
    
}