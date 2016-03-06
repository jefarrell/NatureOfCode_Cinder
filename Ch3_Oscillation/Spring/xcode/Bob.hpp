//
//  Bob.hpp
//  Spring
//
//  Created by John Farrell on 3/4/16.
//
//

#ifndef Bob_hpp
#define Bob_hpp

#include <stdio.h>

#endif /* Bob_hpp */
using namespace ci;
typedef std::shared_ptr<class Bob> BobRef;

class Bob{
public:
    static BobRef create(float x_, float y_){
        return BobRef(new Bob(x_, y_));
    }
    
    vec2 location_;
    vec2 velocity_;
    vec2 acceleration_;
    float mass_;
    float damping_;
    float fill_;
    
    void applyForce(vec2 force_);
    void update();
    void draw();
    
private:
    Bob(float x_, float y_);
};