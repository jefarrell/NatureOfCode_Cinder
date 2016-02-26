//
//  Liquid.hpp
//  FluidResistance
//
//  Created by John Farrell on 2/24/16.
//
//

#ifndef Liquid_hpp
#define Liquid_hpp

#include <stdio.h>

#endif /* Liquid_hpp */
using namespace ci::app;

typedef std::shared_ptr<class Liquid> LiquidRef;

class Liquid {
public:
    static LiquidRef create(float x1_, float y1_, float x2_, float y2_, float c_){
        return LiquidRef(new Liquid(x1_, y1_, x2_, y2_, c_));
    }
                         
    void update();
    void draw();
    float x1,y1,x2,y2,c;
    ci::Rectf boundary_;
    bool contains(ci::vec2 point) { return boundary_.contains(point); }
    
    private:
        Liquid(float x1_, float y1_, float x2_, float y2_, float c_);
};