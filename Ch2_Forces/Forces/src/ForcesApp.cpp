#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Mover.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class ForcesApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    MoverRef mover;
    vec2 wind = vec2(0.001,0);
    vec2 gravity = vec2(0,0.01);
};

void ForcesApp::setup()
{
    mover = Mover::create();
}

void ForcesApp::mouseDown( MouseEvent event )
{
}

void ForcesApp::update()
{
    mover->update();
    mover->applyForce(wind);
    mover->applyForce(gravity);
    mover->checkEdges();
    
}

void ForcesApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    mover->draw();
}

CINDER_APP( ForcesApp, RendererGl )
