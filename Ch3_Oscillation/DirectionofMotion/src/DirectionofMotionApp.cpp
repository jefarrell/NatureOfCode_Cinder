#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class DirectionofMotionApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    void mouseMove(MouseEvent event) override;
    MoverRef mover;
   
    
};

void DirectionofMotionApp::setup()
{
    
    mover = Mover::create(randFloat(getWindowWidth()), randFloat(getWindowHeight()), randFloat(4));
   
}

void DirectionofMotionApp::mouseDown( MouseEvent event )
{
}

void DirectionofMotionApp::update()
{

    mover->update();
    
}

void DirectionofMotionApp::draw()
{
    
    gl::clear( Color( 1, 1, 1 ) );
    mover->draw();
    
}

void DirectionofMotionApp::mouseMove( MouseEvent event)
{
    vec2 mouseCoord = event.getPos();
    mover->mouseTarget(mouseCoord);
    
}


CINDER_APP( DirectionofMotionApp, RendererGl )
