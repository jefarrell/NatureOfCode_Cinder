#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Mover.hpp"
using namespace ci;
using namespace ci::app;
using namespace std;

class VectorMotion_AccelerateToMouseApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void mouseMove( MouseEvent event) override;
    
    MoverRef mover;
};

void VectorMotion_AccelerateToMouseApp::setup()
{
    mover=Mover::create();
}

void VectorMotion_AccelerateToMouseApp::mouseDown( MouseEvent event )
{
}

void VectorMotion_AccelerateToMouseApp::update()
{
    mover->update();
}

void VectorMotion_AccelerateToMouseApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );

    mover->draw();
}

void VectorMotion_AccelerateToMouseApp::mouseMove( MouseEvent event ){
    vec2 mouseCoord = event.getPos();
    mover->mouseTarget(mouseCoord);
}

CINDER_APP( VectorMotion_AccelerateToMouseApp, RendererGl )
