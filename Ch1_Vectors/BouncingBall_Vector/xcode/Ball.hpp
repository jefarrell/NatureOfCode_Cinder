//
//  Ball.hpp
//  BouncingBall_Vector
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
    
private:
    Ball();
};