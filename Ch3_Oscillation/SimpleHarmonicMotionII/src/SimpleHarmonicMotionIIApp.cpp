#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SimpleHarmonicMotionIIApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    float amplitude_ = 100;
    float angle_ = 0;
    float velocity_ = 0.05;
    float x_;
    
    
};

void SimpleHarmonicMotionIIApp::setup()
{
}

void SimpleHarmonicMotionIIApp::mouseDown( MouseEvent event )
{
}

void SimpleHarmonicMotionIIApp::update()
{

    x_ = amplitude_ * cos(angle_);
    angle_ += velocity_;
}

void SimpleHarmonicMotionIIApp::draw()
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

CINDER_APP( SimpleHarmonicMotionIIApp, RendererGl )
