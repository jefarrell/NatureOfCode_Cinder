//
//  Mover.hpp
//  MutualAttraction
//
//  Created by John Farrell on 2/28/16.
//
//
#ifndef Mover_hpp
#define Mover_hpp

#include <stdio.h>

#endif /* Mover_hpp */

using namespace glm;

typedef std::shared_ptr<class Mover> MoverRef;

class Mover {
public:
    static MoverRef create(float x_, float y_, float m_){
        return MoverRef(new Mover(x_, y_, m_));
    }
    
    void update();
    void draw();
    void applyForce(vec2 force_);
    vec2 attract(MoverRef m);
    vec2 location_;
    vec2 velocity_;
    vec2 acceleration_;
    float mass_;
    float G_;
    
private:
    Mover(float x_, float y_, float m_);
};