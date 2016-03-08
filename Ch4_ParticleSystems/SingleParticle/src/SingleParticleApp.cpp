#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Particle.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class SingleParticleApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    ParticleRef particle;
};

void SingleParticleApp::setup()
{
    particle = Particle::create(vec2(100,100));
}

void SingleParticleApp::mouseDown( MouseEvent event )
{
}

void SingleParticleApp::update()
{
    particle->update();
}

void SingleParticleApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    particle->draw();
}

CINDER_APP( SingleParticleApp, RendererGl )
