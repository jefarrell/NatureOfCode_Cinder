#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;



class VectorSubtractionApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void mouseMove(MouseEvent event) override;
    
    vec2 mouse_pos;
};

void VectorSubtractionApp::setup()
{
}

void VectorSubtractionApp::mouseDown( MouseEvent event )
{
}

void VectorSubtractionApp::update()
{
    
}

void VectorSubtractionApp::draw()
{
    gl::clear();
    vec2 center = getWindowCenter();
    gl::drawLine(center,mouse_pos);
}

void VectorSubtractionApp::mouseMove( MouseEvent event ){
    mouse_pos = event.getPos();
}

CINDER_APP( VectorSubtractionApp, RendererGl )
