//
//  Mat.cpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/20.
//
//

#include "Mat.hpp"
void Mat::setup(bool isMirror,std::vector<BaseObject> objs){
    mObjects = objs;
     for(int i = 0 ; i < TRIANGLE_NUM; i++){
         mTriangles[i].setup((MatTriangle::E_TRIANGLE_POSITION)i,isMirror,mObjects);
     }
}

void Mat::update(){
     for(int i = 0 ; i < TRIANGLE_NUM; i++){
         mTriangles[i].update();
     }
}

void Mat::draw(){
    for(int i = 0 ; i < TRIANGLE_NUM; i++){
        mTriangles[i].draw();
    }
}

