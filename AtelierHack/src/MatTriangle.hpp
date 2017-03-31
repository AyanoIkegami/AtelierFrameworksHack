//
//  MatTriangle.hpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/20.
//
//
#pragma once
#include <stdio.h>
#include "ofMain.h"
#include "BaseObject.hpp"
#include <vector>

class Mat;
class MatTriangle{
public:
    MatTriangle();
    enum E_TRIANGLE_POSITION {RIGHT,CENTER,LEFT};
    void setup(E_TRIANGLE_POSITION ePosition, bool isMirror,int objCount);
    void update(std::vector<BaseObject> rightObj);//std::vector<BaseObject> rObjs);
    void draw();    constexpr static const float LENGTH = 300;
    void setupObjects(std::vector<BaseObject> rightObj);

    float CREATE_RADIUS;
     std::vector<BaseObject> mObjects;

private:
    //頂点の位置（三角形なので３つ用意する）
    void setupPosition();
    float createRadious();
    float getA();
    float getB();
    ofVec2f linearFunction(ofVec2f firstPosition, ofVec2f secondPosition,int index);
   
    //方程式変数
    float mA[3],mB[3];
    ofVec2f mPositions[3];
    ofVec2f mGravityPoint;
    E_TRIANGLE_POSITION mEPosition;
    bool mIsMirror;
    bool mIsCenterY;
    int mParticleNum;
    //BaseObject mParticles[1];
};
