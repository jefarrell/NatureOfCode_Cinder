#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Particle.hpp"
#include "cinder/Rand.h"
using namespace ci;
using namespace ci::app;
using namespace std;

class ArrayofParticles_withIteratorApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    ParticleRef particle;
    vector<ParticleRef> particles;
};

void ArrayofParticles_withIteratorApp::setup()
{
    gl::enableAlphaBlending();
}

void ArrayofParticles_withIteratorApp::mouseDown( MouseEvent event )
{
}

void ArrayofParticles_withIteratorApp::update()
{

    particles.push_back(particle=Particle::create(getWindowCenter()));
    
    vector<ParticleRef>::iterator it = particles.begin();
    while(it != particles.end()) {
        (*it)->update();
        if((*it)->isDead())
            particles.erase(it);
        it++;
    }
     
}

void ArrayofParticles_withIteratorApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    vector<ParticleRef>::iterator it;
    for (it = particles.begin(); it != particles.end(); it++){
        (*it)->draw();
    }
        
    
}

CINDER_APP( ArrayofParticles_withIteratorApp, RendererGl )
