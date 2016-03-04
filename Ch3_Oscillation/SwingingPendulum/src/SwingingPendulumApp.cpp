#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Pendulum.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class SwingingPendulumApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    PendulumRef pendulum;
};

void SwingingPendulumApp::setup()
{
    pendulum = Pendulum::create();
}

void SwingingPendulumApp::mouseDown( MouseEvent event )
{
}

void SwingingPendulumApp::update()
{
    pendulum->update();
}

void SwingingPendulumApp::draw()
{
	gl::clear( Color( 1,1,1 ) );
    pendulum->draw();
}

CINDER_APP( SwingingPendulumApp, RendererGl )
