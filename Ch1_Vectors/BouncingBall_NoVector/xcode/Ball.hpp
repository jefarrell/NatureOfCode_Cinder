//
//  Ball.hpp
//  BouncingBall_NoVector
//
//  Created by John Farrell on 2/9/16.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>

#endif /* Ball_hpp */

typedef std::shared_ptr<class Ball> BallRef;

class Ball {
public:
    static BallRef create(){
        return BallRef(new Ball());
    }
    
    void update();
    void draw();
    
    float x_, y_, xSpeed_, ySpeed_;
    
private:
    Ball();
};
