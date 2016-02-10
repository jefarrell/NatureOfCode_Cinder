#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Ball.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class BouncingBall_VectorApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    BallRef ball;
};

void BouncingBall_VectorApp::setup()
{
    ball = Ball::create();
}

void BouncingBall_VectorApp::mouseDown( MouseEvent event )
{
}

void BouncingBall_VectorApp::update()
{
    ball->update();
}

void BouncingBall_VectorApp::draw()
{
    ball->draw();
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( BouncingBall_VectorApp, RendererGl )
