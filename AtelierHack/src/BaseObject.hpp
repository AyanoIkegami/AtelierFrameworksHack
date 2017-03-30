//
//  BaseMaterial.hpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/21.
//
//
#pragma once
#include <stdio.h>
#include "ofMain.h"

class BaseObject{
public:
    static const int NUM_TRIANGLE_POINT = 3;
    virtual void setup(string imageName,ofVec2f position);
    virtual void setupRangeOfTriangle(ofVec2f trianglePoints[NUM_TRIANGLE_POINT],float linearA[NUM_TRIANGLE_POINT],float linearB[NUM_TRIANGLE_POINT],ofVec2f gravityPoint);
    virtual void update();
    virtual void draw();
       //エフェクト数
    static const int NUM_EFFECT = 4;
     //エフェクト適用するかどうかのフラグ配列
    static const int LENGTH = 300;
    bool isUseEffects[NUM_EFFECT];
    bool mIsMirror;
protected:
    //反射
    virtual void reflect();
    //反射を実装するための一次関数
    ofVec2f judgeInOrOut();
    float crossProduct(int index,int index2);
    //円運動
    virtual void circularMotion();
    //明滅
    virtual void blink();
    //伸縮
    virtual void stretch();
    //自身が属する三角形の頂点
    ofVec2f mTrianglePoints[NUM_TRIANGLE_POINT];
    //自身が属する三角形の辺を表す方程式に用いる変数
    float mLinearA[NUM_TRIANGLE_POINT];
    float mLinearB[NUM_TRIANGLE_POINT];
    //重心からの最大の距離
    static int MAX_LENGTH;
    //重心の位置
    ofVec2f mGravityPoint;
    //以下音から取るもの
    //２次元座標(ランダムでもいいかも）
    ofVec2f mPosition;
    //速度
    ofVec2f mVelocity;
    //色
    ofColor mColor;
    //画像
    ofImage mImg;
    //振幅
    float mAmplitude;
    //周期
    float mCycle;
    //角度
    float mTheta;
    //ラジアン
    float mRadian;
    //半径
    float mRadius;
    //位相
    float mPhase;
    //経過時間
    float mTime;
    
  
    
   
};
