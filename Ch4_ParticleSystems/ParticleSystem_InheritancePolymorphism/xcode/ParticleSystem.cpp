//
//  ParticleSystem.cpp
//  ParticleSystem_InheritancePolymorphism
//
//  Created by John Farrell on 3/9/16.
//
//

#include "ParticleSystem.hpp"
#include "Confetti.hpp"
#include "cinder/Rand.h"

ParticleSystem::ParticleSystem(vec2 location_) {
    vector<ParticleRef> particles_;
    origin_ = location_;
    
    ParticleRef particle_;
    
}


void ParticleSystem::addParticle()
{
    float r = randFloat();
    if (r < 0.5)
        particles_.push_back(particle_=Particle::create(origin_));
    else
        particles_.push_back(new Confetti(origin_));  //////////
}

void ParticleSystem::update()
{
    vector<ParticleRef>::iterator it = particles_.begin();
    while(it != particles_.end()) {
        (*it)->update();
        if((*it)->isDead())
            particles_.erase(it);
        it++;
    }
    
    
}


void ParticleSystem::draw()
{
    vector<ParticleRef>::iterator it;
    for (it = particles_.begin(); it != particles_.end(); it++){
        (*it)->draw();
    }
}