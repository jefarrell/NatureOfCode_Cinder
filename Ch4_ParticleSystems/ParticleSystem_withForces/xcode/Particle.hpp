//
//  Particle.hpp
//  ParticleSystem_withForces
//
//  Created by John Farrell on 3/23/16.
//
//

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
    float mass_;
    
    void update();
    void draw();
    void applyForce(vec2 force_);
    bool isDead();
    
    
    
private:
    Particle(vec2 l_);
};
