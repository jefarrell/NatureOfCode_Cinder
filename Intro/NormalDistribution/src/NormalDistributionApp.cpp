#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "dot.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class NormalDistributionApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    dotRef dot;
};

void NormalDistributionApp::setup()
{
    
    dot=dot::create();
}

void NormalDistributionApp::mouseDown( MouseEvent event )
{
}

void NormalDistributionApp::update()
{
    dot->update();
   
}

void NormalDistributionApp::draw()
{
    dot->draw();
    gl::clear();
}

CINDER_APP( NormalDistributionApp, RendererGl )
