//
//  Particle.hpp
//  ParticleSystem_InheritancePolymorphism
//
//  Created by John Farrell on 3/9/16.
//
//
#pragma once

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

#endif /* Particle_hpp */

using namespace ci;

typedef std::shared_ptr<class Particle> ParticleRef;


class Particle {
public:
    
    static ParticleRef create(vec2 l_){
        return ParticleRef(new Particle(l_));
    }
    
    vec2 location_;
    vec2 velocity_;
    vec2 acceleration_;
    float lifespan_;
    
    void update();
    bool isDead();
    
    friend class Confetti;
    friend class ParticleSystem;
    
    
protected:
    Particle(vec2 l_);
    virtual void draw();
};
