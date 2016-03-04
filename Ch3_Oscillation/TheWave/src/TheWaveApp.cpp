#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TheWaveApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    

    float startAngle_ = 0;
    float angleVel_ = 0.23;
    
};

void TheWaveApp::setup()
{
    
}

void TheWaveApp::mouseDown( MouseEvent event )
{
}

void TheWaveApp::update()
{
}

void TheWaveApp::draw()
{
	gl::clear( Color( 1,1,1 ) );
    
    startAngle_ += 0.015;
    float angle_ = startAngle_;
    
    for (int x = 0; x < getWindowWidth(); x+=8) {
        float y = lmap(sin(angle_), -1.0f, 1.0f, 1.0f*getWindowWidth()/2, 1.0f*getWindowHeight()/3);
        
        gl::color(0.5,0.5,0.5,0.75);
        gl::drawSolidCircle(vec2(x,y),20);
        gl::color(0,0,0);
        gl::drawStrokedCircle(vec2(x,y),20);
        
        angle_ += angleVel_;
    }
}

CINDER_APP( TheWaveApp, RendererGl )
