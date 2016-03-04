//
//  Pendulum.hpp
//  SwingingPendulum
//
//  Created by John Farrell on 3/4/16.
//
//

#ifndef Pendulum_hpp
#define Pendulum_hpp

#include <stdio.h>

#endif /* Pendulum_hpp */

using namespace ci;
using namespace ci::app;

typedef std::shared_ptr<class Pendulum> PendulumRef;

class Pendulum {
public:
    static PendulumRef create(){
        return PendulumRef(new Pendulum());
    }
    
    float r_;
    float angle_;
    float aVelocity_;
    float aAcceleration_;
    float gravity_;
    vec2 origin_;
    vec2 location_;
    
    
    void update();
    void draw();
    
    
private:
    Pendulum();
};