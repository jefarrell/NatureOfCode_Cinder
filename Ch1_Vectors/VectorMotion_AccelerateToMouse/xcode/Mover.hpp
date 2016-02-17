//
//  Mover.hpp
//  VectorMotion_AccelerateToMouse
//
//  Created by John Farrell on 2/14/16.
//
//

#ifndef Mover_hpp
#define Mover_hpp

#include <stdio.h>

#endif /* Mover_hpp */

using namespace glm;
using namespace ci::app;

typedef std::shared_ptr<class Mover> MoverRef;

class Mover {
public:
    static MoverRef create(){
        return MoverRef(new Mover());
    }
    
    void update();
    void draw();
    void toMouse( MouseEvent event);
    void mouseTarget (vec2 mouseMove);
    vec2 limit(vec2 input, float max);
    
    vec2 location_;
    vec2 velocity_;
    vec2 acceleration_;
    vec2 mousePos_;
    float topSpeed_;
    
private:
    Mover();
};