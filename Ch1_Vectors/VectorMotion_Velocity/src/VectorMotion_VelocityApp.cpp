#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Mover.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class VectorMotion_VelocityApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    MoverRef mover;
};

void VectorMotion_VelocityApp::setup()
{
    mover=Mover::create();
}

void VectorMotion_VelocityApp::mouseDown( MouseEvent event )
{
}

void VectorMotion_VelocityApp::update()
{
    mover->update();
}

void VectorMotion_VelocityApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    mover->draw();
}

CINDER_APP( VectorMotion_VelocityApp, RendererGl )
