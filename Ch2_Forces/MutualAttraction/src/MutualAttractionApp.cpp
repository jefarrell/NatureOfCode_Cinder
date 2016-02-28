#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MutualAttractionApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;

    MoverRef mover;
    vector<MoverRef> movers;
    
};

void MutualAttractionApp::setup()
{
    int NUM_MOVERS = 10;
    for (int i = 0; i < NUM_MOVERS; i++) {
        mover = Mover::create(randFloat(getWindowWidth()), randFloat(getWindowHeight()), randFloat(0.2,2));
        movers.push_back(mover);
    }
}


void MutualAttractionApp::mouseDown( MouseEvent event )
{
}

void MutualAttractionApp::update()
{
    for (auto m : movers) {
        for (auto j : movers) {
            if (m != j) {
                vec2 force = j->attract(m);
                m->applyForce(force);
            }
        }
        m->update();
    }
}

void MutualAttractionApp::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    for (auto m : movers) {
        m->draw();
    }
    
}


CINDER_APP( MutualAttractionApp, RendererGl )

