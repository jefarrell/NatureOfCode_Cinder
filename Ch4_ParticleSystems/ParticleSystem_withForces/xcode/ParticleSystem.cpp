//
//  ParticleSystem.cpp
//  ParticleSystem_withForces
//
//  Created by John Farrell on 3/23/16.
//
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(vec2 location_) {
    vector<ParticleRef> particles_;
    origin_ = location_;
    
}


void ParticleSystem::addParticle()
{
    particles_.push_back(particle_=Particle::create(origin_));
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

void ParticleSystem::addForce(vec2 force_)
{
    vector<ParticleRef>::iterator it;
    for(it = particles_.begin(); it != particles_.end(); it++) {
        (*it)->applyForce(force_);
    }
    
}


void ParticleSystem::draw()
{
    vector<ParticleRef>::iterator it;
    for (it = particles_.begin(); it != particles_.end(); it++){
        (*it)->draw();
    }
}