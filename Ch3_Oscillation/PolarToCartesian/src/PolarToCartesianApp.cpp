#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class PolarToCartesianApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    float r_ = 75;
    float theta_ = 0;
    float x_, y_;
};

void PolarToCartesianApp::setup()
{
}

void PolarToCartesianApp::mouseDown( MouseEvent event )
{
}

void PolarToCartesianApp::update()
{
    x_ = r_ * cos(theta_);
    y_ = r_ * sin(theta_);
    
    theta_ += 0.01;


}

void PolarToCartesianApp::draw()
{
	gl::clear( Color( 1,1,1 ) );
    
    gl::pushMatrices();
    gl::translate(getWindowWidth()/2,getWindowHeight()/3);
    gl::color(0,0,0);
    gl::drawLine(vec2(0,0), vec2(x_,y_));
    gl::color(0.5,0.5,0.5);
    gl::drawSolidCircle(vec2(x_, y_),25);
    gl::color(0,0,0);
    gl::drawStrokedCircle(vec2(x_, y_),25);
    gl::popMatrices();
}

CINDER_APP( PolarToCartesianApp, RendererGl )
