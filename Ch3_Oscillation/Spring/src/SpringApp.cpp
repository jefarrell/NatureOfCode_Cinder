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
	void mouseDrag( MouseEvent event ) override;
    void mouseUp( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    vec2 gravity_;
    SpringRef spring;
    BobRef bob;
    
    bool mousePressed;
    bool isDragging;
};

void SpringApp::setup()
{
    spring = Spring::create(getWindowWidth()/2, 0, 150);
    bob = Bob::create(getWindowWidth()/3, 200);
    
}

void SpringApp::mouseUp( MouseEvent event)
{
    mousePressed = false;
    isDragging = false;
    bob->fill_ = 0;
}

void SpringApp::mouseDrag( MouseEvent event )
{
    float pos = sqrt(pow(bob->location_.x-event.getPos().x,2.0)+pow(bob->location_.y-event.getPos().y,2.0));
    
    if (pos < bob->mass_) {
        bob->location_.x = event.getPos().x;
        bob->location_.y = event.getPos().y;
        bob->fill_ = 1;
    }
}


void SpringApp::update()
{
    gravity_ = vec2(0,2);
    bob->applyForce(gravity_);
    spring->connect(bob);
    spring->constrain(bob,30,300);
    bob->update();
}

void SpringApp::draw()
{
	gl::clear( Color( 0,0,0 ) );
    bob->draw();
    spring->draw();
    spring->drawLine(bob);
}

CINDER_APP( SpringApp, RendererGl )
