#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;



class VectorMultiplicationApp : public App {
  public:
	void setup();
	void update();
	void draw();
    void mouseMove( MouseEvent event);
    
    vec2 mousePos_;
    vec2 center_;
};

void VectorMultiplicationApp::setup()
{
    center_ = getWindowCenter();
}

void VectorMultiplicationApp::update()
{
      mousePos_ = mousePos_ - center_;
      mousePos_ *= 0.5;
}

void VectorMultiplicationApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    
    gl::pushModelMatrix();
    gl::translate(center_);
    gl::drawLine(vec2(0,0), mousePos_);
    gl::popModelMatrix();
}

void VectorMultiplicationApp::mouseMove( MouseEvent event ){
    mousePos_ = event.getPos();
}


CINDER_APP( VectorMultiplicationApp, RendererGl )
