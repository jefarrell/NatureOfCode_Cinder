#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Mover.hpp"
using namespace ci;
using namespace ci::app;
using namespace std;

class VectorMotion_Acceleration_Array : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    void mouseMove( MouseEvent event) override;
    
    int NUM_MOVERS = 50;
    MoverRef mover;
    vector<MoverRef> movers_;

};

void VectorMotion_Acceleration_Array::setup()
{
    for (int i = 0; i < NUM_MOVERS; i ++) {
        mover=Mover::create();
        movers_.push_back(mover);
    }
    

}

void VectorMotion_Acceleration_Array::mouseDown( MouseEvent event )
{
}

void VectorMotion_Acceleration_Array::update()
{
    for (auto m : movers_) {
        m->update();
    }
}

void VectorMotion_Acceleration_Array::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    for (auto m : movers_) {
        m->draw();
    }
}

void VectorMotion_Acceleration_Array::mouseMove( MouseEvent event ){
    vec2 mouseCoord = event.getPos();
    for (auto m : movers_) {
        m->mouseTarget(mouseCoord);
    }
}

CINDER_APP( VectorMotion_Acceleration_Array, RendererGl )
