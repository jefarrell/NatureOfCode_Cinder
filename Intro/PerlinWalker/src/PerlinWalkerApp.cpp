#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Walker.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class PerlinWalkerApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    WalkerRef walker;
};


void PerlinWalkerApp::setup()
{
    gl::clear( Color( 0, 0, 0 ) );
    walker=Walker::create();
}



void PerlinWalkerApp::mouseDown( MouseEvent event )
{
}

void PerlinWalkerApp::update()
{
    walker->update();
}

void PerlinWalkerApp::draw()
{
    walker->draw();
}

CINDER_APP( PerlinWalkerApp, RendererGl )
