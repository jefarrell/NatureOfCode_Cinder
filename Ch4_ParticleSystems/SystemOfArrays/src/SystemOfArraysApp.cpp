#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class SystemOfArraysApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    ParticleSystemRef ps;
    vector<ParticleSystemRef> systems_;
    
};

void SystemOfArraysApp::setup()
{
    gl::enableAlphaBlending();
    
}

void SystemOfArraysApp::mouseDown( MouseEvent event )
{
    systems_.push_back(ps = ParticleSystem::create(event.getPos()));
}

void SystemOfArraysApp::update()
{
    for (auto s : systems_) {
        s->addParticle();
        s->update();
    }
    
}

void SystemOfArraysApp::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    for (auto s : systems_) {
        s->draw();
    }
    
    
}
CINDER_APP( SystemOfArraysApp, RendererGl )
