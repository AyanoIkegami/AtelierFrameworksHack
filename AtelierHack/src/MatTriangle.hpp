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
class MatTriangle{
public:
    enum E_TRIANGLE_POSITION {LEFT,CENTER,RIGHT};
    void setup(E_TRIANGLE_POSITION ePosition, bool isMirror,std::vector<BaseObject> objs);
    void update();
    void draw();
    constexpr static const float LENGTH = 300;
    float CREATE_RADIUS;

private:
    //頂点の位置（三角形なので３つ用意する）
    void setupPosition();
    void setupObjects();
    float createRadious();
    float getA();
    float getB();
    ofVec2f linearFunction(ofVec2f firstPosition, ofVec2f secondPosition,int index);
    std::vector<BaseObject> mLeftObjects;
    std::vector<BaseObject> mObjects;
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
