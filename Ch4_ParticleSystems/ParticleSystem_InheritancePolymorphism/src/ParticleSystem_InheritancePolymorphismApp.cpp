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
	void update() override;
	void draw() override;
    
    ParticleSystemRef ps;
    vector<ParticleSystemRef> systems_;
};

void ParticleSystem_InheritancePolymorphismApp::setup()
{
    systems_.push_back(ps = ParticleSystem::create(getWindowCenter()));
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

// Nice tip from Craig
CINDER_APP( ParticleSystem_InheritancePolymorphismApp, RendererGl(RendererGl::Options().msaa(16)),
           [&](App::Settings *settings){
               settings->setHighDensityDisplayEnabled();
           })
