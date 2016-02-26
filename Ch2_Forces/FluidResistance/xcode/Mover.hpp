//
//  Mover.hpp
//  FluidResistance
//
//  Created by John Farrell on 2/24/16.
//
//

#ifndef Mover_hpp
#define Mover_hpp

#include <stdio.h>
#include "Liquid.hpp"

#endif /* Mover_hpp */

using namespace glm;
using namespace ci::app;

typedef std::shared_ptr<class Mover> MoverRef;

class Mover {
public:
    static MoverRef create(float m_, float x_, float y_){
        return MoverRef(new Mover(m_, x_, y_));
    }
    
    void update();
    void draw();
    void applyForce(vec2 force_);
    void checkEdges();
    void drag(LiquidRef l);
    
    vec2 location_;
    vec2 velocity_;
    vec2 acceleration_;
    float topSpeed_;
    float mass_;
    
private:
    Mover(float m_, float x_, float y_);
};