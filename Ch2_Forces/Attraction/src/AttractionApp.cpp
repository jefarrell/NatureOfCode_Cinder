#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Attractor.hpp"


using namespace ci;
using namespace ci::app;


class AttractionApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    AttractorRef attractor_;
    MoverRef mover_;
};

void AttractionApp::setup()
{
        mover_ = Mover::create();
    attractor_ = Attractor::create();

}

void AttractionApp::mouseDown( MouseEvent event )
{
}

void AttractionApp::update()
{
    vec2 force = attractor_->attract(mover_);
    mover_->applyForce(force);
    mover_->update();
}

void AttractionApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    attractor_->draw();
    mover_->draw();

}

CINDER_APP( AttractionApp, RendererGl )
