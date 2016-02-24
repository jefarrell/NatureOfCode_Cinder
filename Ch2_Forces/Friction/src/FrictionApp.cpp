#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class FrictionApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    int NUM_MOVERS = 10;
    MoverRef mover;
    vector<MoverRef> movers_;
};

void FrictionApp::setup()
{
    for (int i = 0; i < NUM_MOVERS; i++) {
        mover=Mover::create(randFloat()*6.0f,10,10);
        movers_.push_back(mover);
    }
}

void FrictionApp::mouseDown( MouseEvent event )
{
}

void FrictionApp::update()
{
    vec2 wind = vec2(0.0001,0);
    vec2 gravity = vec2(0,0.001);
    float c = 0.1;
    for (auto m : movers_) {


        vec2 friction = m->velocity_;
        friction *= -1.0f;
        friction = glm::normalize(friction);
        friction *= c;
        
        
        m->applyForce(friction);
        
        m->applyForce(wind);
        m->applyForce(gravity);
        
        m->update();
        m->checkEdges();
 
//        cout<<"friction: " << friction <<endl;
//        cout<<"velocity: " << m->velocity_<<endl;
//        cout<<"wind: " << wind<<endl;
//        

    }
}

void FrictionApp::draw()
{
    
    gl::clear( Color( 1, 1, 1 ) );
    for (auto m : movers_) {
        m->draw();
    }
}

CINDER_APP( FrictionApp, RendererGl )
