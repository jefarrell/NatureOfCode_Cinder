#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Spring.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class SpringApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    vec2 gravity_;
    SpringRef spring;
    BobRef bob;
};

void SpringApp::setup()
{
    spring = Spring::create(getWindowWidth()/2, 0, 150);
    bob = Bob::create(getWindowWidth()/6, 200);
    
}

void SpringApp::mouseDown( MouseEvent event )
{
}

void SpringApp::update()
{
    gravity_ = vec2(0,2);
    bob->applyForce(gravity_);
    spring->connect(bob);
    bob->update();
    

}

void SpringApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    bob->draw();
    spring->draw();
    spring->drawLine(bob);
}

CINDER_APP( SpringApp, RendererGl )
