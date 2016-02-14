//
//  Mover.hpp
//  VectorMotion_Velocity
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

class Mover{
public:
    static MoverRef create(){
        return MoverRef(new Mover());
    }
    
    void checkEdges();
    void update();
    void draw();
    
    vec2 location_;
    vec2 velocity_;
    
private:
    Mover();
};
