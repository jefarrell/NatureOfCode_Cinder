//
//  Mover.hpp
//  DirectionofMotion
//
//  Created by John Farrell on 3/1/16.
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
    void mouseTarget(vec2 mouseMove_);
    vec2 limit(vec2 input, float max);
    
    vec2 location_;
    vec2 velocity_;
    vec2 acceleration_;
    vec2 mousePos_;
    
    float mass_;
    float angle_;
    
private:
    Mover(float x_, float y_, float m_);
};