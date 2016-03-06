//
//  Spring.cpp
//  Spring
//
//  Created by John Farrell on 3/4/16.
//
//

#include "Spring.hpp"

Spring::Spring(float x_, float y_, float l_)
{
    anchor_ = vec2(x_,y_);
    len_ = l_;
    k_ = 0.2;
}




void Spring::connect(BobRef b)
{
    vec2 force = b->location_ - anchor_;
  
    float currentLength = sqrt(pow((b->location_.x - anchor_.x),2.0) + pow((b->location_.y-anchor_.y),2.0));
    float stretch = currentLength - len_;

    force = glm::normalize(force);
    force *= (-1 * k_ * stretch);
    b->applyForce(force);
}

void Spring::draw()
{
    gl::color(1,1,1);
    gl::drawSolidRect(Rectf(vec2(anchor_.x, anchor_.y), vec2(anchor_.x+10,anchor_.y+10)));
}

void Spring::drawLine(BobRef b)
{
    gl::color(1,1,1);
    gl::drawLine(vec2(b->location_.x, b->location_.y), vec2(anchor_.x+5, anchor_.y+5));
}

void Spring::constrain(BobRef b, float minL, float maxL)
{
    vec2 dir = b->location_ - anchor_;
    float d = sqrt(pow((b->location_.x - anchor_.x),2.0) + pow((b->location_.y-anchor_.y),2.0));
    if (d < minL) {
        dir = glm::normalize(dir);
        dir *= minL;
        b->location_ = anchor_ += dir;
        b->velocity_ *= 0;
    }
    else if (d > maxL) {
        dir = glm::normalize(dir);
        dir *= maxL;
        b->location_ = anchor_ += dir;
        b->velocity_ *= 0;
    }
}