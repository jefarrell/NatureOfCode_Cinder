//
//  block.hpp
//  randomNumberDist
//
//  Created by John Farrell on 1/29/16.
//
//

#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"

#endif /* block_hpp */

typedef std::shared_ptr<class Block> BlockRef;

class Block {
public:
    static BlockRef create(float x1, float x2, float y1, float y2){
        return BlockRef(new Block(x1,x2,y1,y2));
        
    }
    

    
    void display();
    void increase();
    float x1_, y1_, x2_, y2_;
    
private:
    Block(float x1, float x2, float y1, float y2);
    int randomNum = 0;

    //Block(float x1, float x2, float y1, float y2);
};