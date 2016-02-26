#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FluidResistanceApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    int NUM_MOVERS = 10;
    MoverRef mover;
    vector<MoverRef> movers_;
    LiquidRef liquid;
};

void FluidResistanceApp::setup()
{
    for (int i = 0; i < NUM_MOVERS; i++) {
        mover=Mover::create(randFloat()*4.0f,randFloat()*getWindowWidth(),10);
        movers_.push_back(mover);
    }
    
    liquid = Liquid::create(0,2*getWindowHeight()/3,getWindowWidth(),getWindowHeight(),0.1);
}

void FluidResistanceApp::mouseDown( MouseEvent event )
{
}

void FluidResistanceApp::update()
{
    liquid->update();
    
    for (auto m : movers_) {
        vec2 gravity = vec2(0,0.1*m->mass_);
        m->applyForce(gravity);
       
        if (liquid->contains(m->location_))
            m->drag(liquid);
        
        
        m->update();
        m->checkEdges();
    }
}

void FluidResistanceApp::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    liquid->draw();
    for (auto m : movers_) {
        m->draw();
    }
}

CINDER_APP( FluidResistanceApp, RendererGl )
