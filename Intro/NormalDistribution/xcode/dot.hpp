//
//  dot.hpp
//  NormalDistribution
//
//  Created by John Farrell on 2/4/16.
//
//

#ifndef dot_hpp
#define dot_hpp

#include <stdio.h>

#endif /* dot_hpp */

typedef std::shared_ptr<class dot> dotRef;

class dot {
public:
    static dotRef create(){
        return dotRef(new dot());
    }
    
    void update();
    void draw();
    
    float x_, y_;


private:
    dot();
    
};