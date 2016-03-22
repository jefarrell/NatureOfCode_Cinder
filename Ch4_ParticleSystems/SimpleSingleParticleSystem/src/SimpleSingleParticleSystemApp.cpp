#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class SimpleSingleParticleSystemApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    
    ParticleSystemRef ps;
};

void SimpleSingleParticleSystemApp::setup()
{
    gl::enableAlphaBlending();
    ps = ParticleSystem::create(getWindowCenter());
}

void SimpleSingleParticleSystemApp::mouseDown( MouseEvent event )
{
}

void SimpleSingleParticleSystemApp::update()
{
    ps->addParticle();
    ps->update();
    
}

void SimpleSingleParticleSystemApp::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    ps->draw();
    
    
}

CINDER_APP( SimpleSingleParticleSystemApp, RendererGl )
