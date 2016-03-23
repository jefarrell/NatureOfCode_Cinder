//
//  ParticleSystem.hpp
//  ParticleSystem_InheritancePolymorphism
//
//  Created by John Farrell on 3/9/16.
//
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp


#include <stdio.h>
#include "Particle.hpp"
#include "Confetti.hpp"


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

    void addParticle();
    void update();
    void draw();
    
    
private:
    ParticleSystem(vec2 location_);
};