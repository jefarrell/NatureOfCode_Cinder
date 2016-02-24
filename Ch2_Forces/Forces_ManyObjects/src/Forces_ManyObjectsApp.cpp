#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Mover.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Forces_ManyObjectsApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    
    vec2 wind = vec2(0.0001,0);
    vec2 gravity = vec2(0,0.001);
    
    int NUM_MOVERS = 25;
    MoverRef mover;
    vector<MoverRef> movers_;
};

void Forces_ManyObjectsApp::setup()
{
    for (int i = 0; i < NUM_MOVERS; i++) {
        mover=Mover::create(randFloat()*6.0f,10,10);
        movers_.push_back(mover);
    }
    
}

void Forces_ManyObjectsApp::mouseDown( MouseEvent event )
{
}

void Forces_ManyObjectsApp::update()
{
    for (auto m : movers_) {
        m->update();
        m->applyForce(wind);
        m->applyForce(gravity);
        m->checkEdges();
    }
    
}

void Forces_ManyObjectsApp::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    for (auto m : movers_) {
        m->draw();
    }
}

CINDER_APP( Forces_ManyObjectsApp, RendererGl )
