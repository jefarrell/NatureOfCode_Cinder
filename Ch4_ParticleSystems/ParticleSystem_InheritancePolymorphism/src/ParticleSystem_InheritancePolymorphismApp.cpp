#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class ParticleSystem_InheritancePolymorphismApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    ParticleSystemRef ps;
    vector<ParticleSystemRef> systems_;
};

void ParticleSystem_InheritancePolymorphismApp::setup()
{
}

void ParticleSystem_InheritancePolymorphismApp::mouseDown( MouseEvent event )
{
     systems_.push_back(ps = ParticleSystem::create(event.getPos()));
}

void ParticleSystem_InheritancePolymorphismApp::update()
{
    for (auto s : systems_) {
        s->addParticle();
        s->update();
    }
}

void ParticleSystem_InheritancePolymorphismApp::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    for (auto s : systems_) {
        s->draw();
    }

}

CINDER_APP( ParticleSystem_InheritancePolymorphismApp, RendererGl )
