//
//  Mat.cpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/20.
//
//

#include "Mat.hpp"

void Mat::setup(bool isMirror){
     for(int i = 0 ; i < TRIANGLE_NUM; i++){
         mTriangles[i].setup((MatTriangle::E_TRIANGLE_POSITION)i,isMirror);
     }
}

void Mat::update(){
    
}

void Mat::draw(){
    for(int i = 0 ; i < TRIANGLE_NUM; i++){
        mTriangles[i].draw();
    }
}

void Mat::rotateX(){
    
}
