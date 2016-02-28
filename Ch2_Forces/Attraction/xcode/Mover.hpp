//
//  Mover.hpp
//  Attraction
//
//  Created by John Farrell on 2/27/16.
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
    void draw();
    void applyForce(vec2 force_);
    
    vec2 location_;
    vec2 velocity_;
    vec2 acceleration_;
    float mass_;
    
private:
    Mover();
};