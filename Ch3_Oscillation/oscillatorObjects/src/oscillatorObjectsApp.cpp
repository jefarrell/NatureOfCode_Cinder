#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Oscillator.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class oscillatorObjectsApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    OscillatorRef oscillator;
    
    int NUM_OSC = 15;
    vector <OscillatorRef> oscillators_;
};

void oscillatorObjectsApp::setup()
{
    for (int i = 0; i < NUM_OSC; i++) {
        oscillator = Oscillator::create();
        oscillators_.push_back(oscillator);
    }
}

void oscillatorObjectsApp::mouseDown( MouseEvent event )
{
}

void oscillatorObjectsApp::update()
{

    for (auto o : oscillators_)
        o->update();

}

void oscillatorObjectsApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto o : oscillators_)
        o->draw();
}

CINDER_APP( oscillatorObjectsApp, RendererGl )
