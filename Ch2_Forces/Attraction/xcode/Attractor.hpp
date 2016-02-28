//
//  Attractor.hpp
//  Attraction
//
//  Created by John Farrell on 2/27/16.
//
//

#ifndef Attractor_hpp
#define Attractor_hpp

#include <stdio.h>
#include "Mover.hpp"
#endif /* Attractor_hpp */


typedef std::shared_ptr<class Attractor> AttractorRef;

class Attractor {
public:
    static AttractorRef create(){
        return AttractorRef(new Attractor());
    }
    
    vec2 location_;
    float mass_;
    float G_;
    
    void draw();
    vec2 attract(MoverRef m);
    
private:
    Attractor();
};