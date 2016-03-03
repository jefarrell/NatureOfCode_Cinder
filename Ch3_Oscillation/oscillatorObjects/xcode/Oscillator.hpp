//
//  Oscillator.hpp
//  oscillatorObjects
//
//  Created by John Farrell on 3/2/16.
//
//

#ifndef Oscillator_hpp
#define Oscillator_hpp

#include <stdio.h>
#include "cinder/Rand.h"

#endif /* Oscillator_hpp */


using namespace ci;
using namespace ci::app;

typedef std::shared_ptr<class Oscillator> OscillatorRef;

class Oscillator{
public:
    static OscillatorRef create(){
        return OscillatorRef(new Oscillator());
    }
    
    vec2 angle_;
    vec2 velocity_;
    vec2 amplitude_;

    
    void update();
    void draw();

    
private:
    Oscillator();
};