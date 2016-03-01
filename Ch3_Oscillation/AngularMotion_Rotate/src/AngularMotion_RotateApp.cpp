#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/GeomIo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class AngularMotion_RotateApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    float angle = 0;
    float aVelocity = 0;
    float aAcceleration = 0.001;

};

void AngularMotion_RotateApp::setup()
{
}

void AngularMotion_RotateApp::mouseDown( MouseEvent event )
{
}

void AngularMotion_RotateApp::update()
{
    aVelocity += aAcceleration;
    angle += aVelocity;
}

void AngularMotion_RotateApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    gl::pushMatrices();
    gl::translate(getWindowCenter());
    gl::rotate(angle);
    
    gl::color(0,0,0);
    gl::drawLine(vec2(-50,0), vec2(50,0));
    gl::color(0.35,0.35,0.35);
    gl::drawSolidCircle(vec2(-50,0),10);
    gl::drawSolidCircle(vec2(50,0),10);
    gl::color(0,0,0);
    gl::drawStrokedCircle(vec2(-50,0),10,2.5,-1);
    gl::drawStrokedCircle(vec2(50,0),10,2.5,-1);

    gl::popMatrices();

   
}

CINDER_APP( AngularMotion_RotateApp, RendererGl )
