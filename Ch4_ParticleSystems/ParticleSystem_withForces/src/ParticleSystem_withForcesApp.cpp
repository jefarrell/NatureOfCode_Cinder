#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class ParticleSystem_withForcesApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    ParticleSystemRef ps;
};

void ParticleSystem_withForcesApp::setup()
{
    ps = ParticleSystem::create(getWindowCenter());
}

void ParticleSystem_withForcesApp::mouseDown( MouseEvent event )
{
}

void ParticleSystem_withForcesApp::update()
{
    ps->addParticle();
    vec2 wind = vec2(0.001,0);
    vec2 gravity = vec2(0,0.001);
    ps->addForce(wind);
    ps->addForce(gravity);
    ps->update();
}

void ParticleSystem_withForcesApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    ps->draw();
}

CINDER_APP( ParticleSystem_withForcesApp, RendererGl )
