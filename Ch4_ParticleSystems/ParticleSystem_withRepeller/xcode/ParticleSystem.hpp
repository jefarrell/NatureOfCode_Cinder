//
//  ParticleSystem.hpp
//  ParticleSystem_withRepeller
//
//  Created by John Farrell on 3/24/16.
//
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include <stdio.h>
#include "Particle.hpp"
#include "Repeller.hpp"

using namespace std;

#endif /* ParticleSystem_hpp */

typedef std::shared_ptr<class ParticleSystem> ParticleSystemRef;

class ParticleSystem {
public:
    static ParticleSystemRef create(vec2 location_){
        return ParticleSystemRef(new ParticleSystem(location_));
    }
    
    vector<ParticleRef> particles_;
    vec2 origin_;
    ParticleRef particle_;
    
    void addParticle();
    void update();
    void draw();
    void addForce(vec2 force_);
    void addRepeller(Repeller);
    
    
private:
    ParticleSystem(vec2 location_);
};