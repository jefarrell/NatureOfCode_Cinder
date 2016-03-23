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
    Confetti(vec2 loc_);
    void draw();

};
