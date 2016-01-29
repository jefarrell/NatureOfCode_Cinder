#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Walker.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class RandomWalkerApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;

    WalkerRef walker;
    
};

void RandomWalkerApp::setup()
{
    walker=Walker::create();
}

void RandomWalkerApp::mouseDown( MouseEvent event )
{
}

void RandomWalkerApp::update()
{

    walker->step();
}

void RandomWalkerApp::draw()
{

    walker->display();
}

CINDER_APP( RandomWalkerApp, RendererGl )
