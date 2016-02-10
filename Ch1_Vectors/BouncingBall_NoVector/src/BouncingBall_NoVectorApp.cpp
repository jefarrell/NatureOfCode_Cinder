#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Ball.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class BouncingBall_NoVectorApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    BallRef ball;
};

void BouncingBall_NoVectorApp::setup()
{
    ball=Ball::create();
}

void BouncingBall_NoVectorApp::mouseDown( MouseEvent event )
{
}

void BouncingBall_NoVectorApp::update()
{
    ball->update();
}

void BouncingBall_NoVectorApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    ball->draw();
	
}

CINDER_APP( BouncingBall_NoVectorApp, RendererGl )
