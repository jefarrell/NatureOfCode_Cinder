//
//  Mover.hpp
//  VectorMotion_Acceleration
//
//  Created by John Farrell on 2/14/16.
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
    static MoverRef create(){
        return MoverRef(new Mover());
    }
    
    void update();
    void checkEdges();
    void draw();
    vec2 limit(vec2 input, float max);
    
    vec2 location_;
    vec2 velocity_;
    vec2 acceleration_;
    float topSpeed_;
    
private:
    Mover();
};