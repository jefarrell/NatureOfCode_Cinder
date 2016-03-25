//
//  Repeller.hpp
//  ParticleSystem_withRepeller
//
//  Created by John Farrell on 3/24/16.
//
//

#ifndef Repeller_hpp
#define Repeller_hpp

#include <stdio.h>
#include "Particle.hpp"

using namespace glm;

#endif /* Repeller_hpp */


typedef std::shared_ptr<class Repeller> RepellerRef;

class Repeller {
public:
    static RepellerRef create(vec2 loc_){
        return RepellerRef(new Repeller(loc_));
    }
    
    vec2 location_;
    float mass_;
    float G_;
    
    void draw();
    vec2 repel(ParticleRef);
    
private:
    Repeller(vec2 loc_);
};