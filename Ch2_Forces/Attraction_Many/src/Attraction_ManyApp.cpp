#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Attractor.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Attraction_ManyApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    
    AttractorRef attractor_;
    MoverRef mover;
    vector<MoverRef> movers;

};

void Attraction_ManyApp::setup()
{
    int NUM_MOVERS = 10;
    for (int i = 0; i < NUM_MOVERS; i++) {
        mover = Mover::create(randFloat(getWindowWidth()), randFloat(getWindowHeight()), randFloat(0.2,2));
        movers.push_back(mover);
    }

    attractor_ = Attractor::create();
    
}

void Attraction_ManyApp::mouseDown( MouseEvent event )
{
}

void Attraction_ManyApp::update()
{
    for (auto m : movers) {
        vec2 force = attractor_->attract(m);
        m->applyForce(force);
        m->update();
    }
}

void Attraction_ManyApp::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    attractor_->draw();
    for (auto m : movers) {
        m->draw();
    }
    
}

CINDER_APP( Attraction_ManyApp, RendererGl )
