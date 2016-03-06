//
//  Spring.hpp
//  Spring
//
//  Created by John Farrell on 3/4/16.
//
//

#ifndef Spring_hpp
#define Spring_hpp

#include <stdio.h>
#include "Bob.hpp"

#endif /* Spring_hpp */

using namespace ci;

typedef std::shared_ptr<class Spring> SpringRef;

class Spring {
public:
    static SpringRef create(float x_, float y_, float l_){
        return SpringRef(new Spring(x_, y_, l_));
    }
    
    vec2 anchor_;
    vec2 location_;
    float restLength_;
    float k_;
    float len_;
    
    void draw();
    void connect(BobRef b);
    void drawLine(BobRef b);
    void constrain(BobRef b, float minL, float maxL);
    
private:
    Spring(float x_, float y_, float l_);
};