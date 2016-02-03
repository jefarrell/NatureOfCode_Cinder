#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/rand.h"
#include "block.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

const int NUM_BARS = 500;

class randomNumberDistApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    std::vector<BlockRef> blocks;
private:
//    int randomCount[NUM_BARS];
};

void randomNumberDistApp::setup()
{
    
    
    float h = getWindowHeight();
    float w = getWindowWidth();
    
  
    
    for (int i = 0; i < NUM_BARS; i++){
        BlockRef block = Block::create(w*(i)/NUM_BARS,h/2,w*(i+1)/NUM_BARS,h);
        blocks.push_back(block);
    }
    
}

void randomNumberDistApp::mouseDown( MouseEvent event )
{
}

void randomNumberDistApp::update()
{
    
    int index = (int)(ci::randFloat()*NUM_BARS);
    blocks[index]->increase();
    
}

void randomNumberDistApp::draw()
{
   
	gl::clear( Color( 0, 0, 0 ) );
    for ( int i = 0; i < blocks.size(); i++){
        blocks[i] -> display();
    }
}



CINDER_APP( randomNumberDistApp, RendererGl, [&](App::Settings *settings)
           {
               settings->setWindowSize(720,480);
               
           }
           )
