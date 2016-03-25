#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class ParticleSystem_withRepellerApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    ParticleSystemRef ps;
    RepellerRef r;
};

void ParticleSystem_withRepellerApp::setup()
{
    ps = ParticleSystem::create(vec2(getWindowWidth()/2, getWindowHeight()/3));
    r = Repeller::create(getWindowCenter());
}

void ParticleSystem_withRepellerApp::mouseDown( MouseEvent event )
{
}

void ParticleSystem_withRepellerApp::update()
{
    vec2 gravity = vec2(0,0.001);
    ps->addParticle();
    ps->addForce(gravity);
    ps->addRepeller((*r));
    ps->update();
}

void ParticleSystem_withRepellerApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    ps->draw();
    r->draw();
}

CINDER_APP( ParticleSystem_withRepellerApp, RendererGl(RendererGl::Options().msaa(16)),
           [&](App::Settings *settings){
               settings->setHighDensityDisplayEnabled();
           })

