#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <math.h>  

using namespace ci;
using namespace ci::app;
using namespace std;



class VectorMultiplicationApp : public App {
public:
    void setup();
    void update();
    void draw();
    void mouseMove( MouseEvent event);
    
    vec2 mousePos_;
    vec2 center_;
    float mag;
};

void VectorMultiplicationApp::setup()
{
    center_ = getWindowCenter();
}

void VectorMultiplicationApp::update()
{
}

void VectorMultiplicationApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    gl::drawSolidRect(Rectf(0,0,mag,10));
    gl::pushModelMatrix();
    gl::translate(center_);
    gl::drawLine(vec2(0,0), mousePos_);
    gl::popModelMatrix();
}

void VectorMultiplicationApp::mouseMove( MouseEvent event ){
    mousePos_ = event.getPos();
    mousePos_ = mousePos_ - center_;
    mag = sqrt(mousePos_[0]*mousePos_[0]+mousePos_[1]*mousePos_[1]);
}


CINDER_APP( VectorMultiplicationApp, RendererGl )
