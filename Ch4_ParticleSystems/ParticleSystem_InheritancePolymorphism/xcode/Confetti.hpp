//
//  Confetti.hpp
//  ParticleSystem_InheritancePolymorphism
//
//  Created by John Farrell on 3/9/16.
//
//
#pragma once

#ifndef Confetti_hpp
#define Confetti_hpp

#include <stdio.h>
#include "Particle.hpp"

#endif /* Confetti_hpp */

typedef std::shared_ptr<class Confetti> ConfettiRef;

class Confetti : public Particle {
public:
    static ConfettiRef create(vec2 l_){
        return ConfettiRef (new Confetti(l_));
    }
    
    using Particle::Particle;
    void draw();
    
    Confetti(vec2 loc_);
};
