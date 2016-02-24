#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class Gravity_ScaledByMassApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    

    
    int NUM_MOVERS = 25;
    MoverRef mover;
    vector<MoverRef> movers_;
};

void Gravity_ScaledByMassApp::setup()
{
    for (int i = 0; i < NUM_MOVERS; i++) {
        mover=Mover::create(randFloat(6),10,10);
        movers_.push_back(mover);
    }
}

void Gravity_ScaledByMassApp::mouseDown( MouseEvent event )
{
}

void Gravity_ScaledByMassApp::update()
{
    for (auto m : movers_) {
        vec2 wind = vec2(0.0001,0);
        float movMass = m->mass_;
        vec2 gravity = vec2(0,0.001*movMass);
        m->update();
        m->applyForce(wind);
        m->applyForce(gravity);
        m->checkEdges();
    }
}

void Gravity_ScaledByMassApp::draw()
{

    gl::clear( Color( 1, 1, 1 ) );
    for (auto m : movers_) {
        m->draw();
    }
}

CINDER_APP( Gravity_ScaledByMassApp, RendererGl )
