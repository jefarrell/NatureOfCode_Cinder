#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class StaticWaveApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    

    float angleVel_ = 0.1;
    float startAngle_ = 0;
};

void StaticWaveApp::setup()
{
}

void StaticWaveApp::mouseDown( MouseEvent event )
{
}

void StaticWaveApp::update()
{
}

void StaticWaveApp::draw()
{
    gl::clear( Color( 1,1,1 ) );
    float angle_ = startAngle_;
    gl::begin(GL_LINE_STRIP);
    for (int x = 0; x < getWindowWidth(); x+=5) {
        float y = lmap(sin(angle_), -1.0f, 1.0f, 0.0f, 1.0f*getWindowHeight());
        gl::color(0,0,0);
        gl::vertex(x,y);
        angle_ += angleVel_;
    }
    gl::end();
}




CINDER_APP( StaticWaveApp, RendererGl )
