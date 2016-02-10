//
//  Walker.hpp
//  PerlinWalker
//
//  Created by John Farrell on 2/8/16.
//
//

#ifndef Walker_hpp
#define Walker_hpp

#include <stdio.h>
#include "cinder/Perlin.h"

#endif /* Walker_hpp */


typedef std::shared_ptr<class Walker> WalkerRef;

class Walker {
public:
    static WalkerRef create(){
        return WalkerRef(new Walker());
    }
    
    void update();
    void draw();
    
    float x_, y_;
    float tx_, ty_;
    cinder::Perlin perlin_;
    
    
private:
    Walker();
};