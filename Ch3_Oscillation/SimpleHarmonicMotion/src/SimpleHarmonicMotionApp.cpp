#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SimpleHarmonicMotionApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    float r_ = 75;
    float theta_ = 0;
    float x_;
    float amplitude = 100;
    float period = 20;

};

void SimpleHarmonicMotionApp::setup()
{
}

void SimpleHarmonicMotionApp::mouseDown( MouseEvent event )
{
}

void SimpleHarmonicMotionApp::update()
{
    x_ = amplitude * cos(M_2_PI * getElapsedFrames() / period);
}

void SimpleHarmonicMotionApp::draw()
{
    gl::clear( Color( 1,1,1 ) );
    
    gl::pushMatrices();
    gl::translate(getWindowWidth()/2,getWindowHeight()/3);
    gl::color(0,0,0);
    gl::drawLine(vec2(0,0), vec2(x_,0));
    gl::color(0.5,0.5,0.5);
    gl::drawSolidCircle(vec2(x_, 0),25);
    gl::color(0,0,0);
    gl::drawStrokedCircle(vec2(x_, 0),25);
    gl::popMatrices();
}

CINDER_APP( SimpleHarmonicMotionApp, RendererGl )
