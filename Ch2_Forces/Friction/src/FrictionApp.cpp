#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class FrictionApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    int NUM_MOVERS = 10;
    MoverRef mover;
    vector<MoverRef> movers_;
};

void FrictionApp::setup()
{
    for (int i = 0; i < NUM_MOVERS; i++) {
        mover=Mover::create(randFloat()*6.0f,10,10);
        movers_.push_back(mover);
    }
}

void FrictionApp::mouseDown( MouseEvent event )
{
}

void FrictionApp::update()
{
    vec2 wind = vec2(0.01,0);
    vec2 gravity = vec2(0,0.1);
    float c = 0.05;
    
    for (auto m : movers_) {
        
        m->applyForce(wind);
        m->applyForce(gravity);
        
        vec2 friction = m->velocity_;
        friction *= -1;
        if (length(friction) > 0)
            friction = glm::normalize(friction);
        
        friction *= c;
        m->applyForce(friction);
        
        m->update();
        m->checkEdges();
    }
}

void FrictionApp::draw()
{
    
    gl::clear( Color( 1, 1, 1 ) );
    for (auto m : movers_) {
        m->draw();
    }
}

CINDER_APP( FrictionApp, RendererGl )
