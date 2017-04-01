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
    virtual void setup(string imageName,int index);
    virtual void setupRangeOfTriangle(ofVec2f trianglePoints[NUM_TRIANGLE_POINT]);
    virtual void setupRightPosition(ofVec2f rightPosition);
    virtual void update();
    virtual void draw();
    virtual void setVelocity(ofVec2f vector);
    virtual void setRightVector(ofVec2f vector);
    virtual ofVec2f getVelocity();
       //エフェクト数
    static const int NUM_EFFECT = 4;
     //エフェクト適用するかどうかのフラグ配列
    static const int LENGTH = 300;
    bool isUseEffects[NUM_EFFECT];
    bool mIsMirror = true;
    //画像名
    string mImgName;
    //２次元座標(ランダムでもいいかも）
    ofVec2f mPosition;
    ofVec2f mRightPosition;
    ofVec2f mRightVector;
protected:
    //ポジション移動
    void move();
    //ベクトル向き変更
    void changeVector();
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
    //波
    virtual void wave();
    
    int mIndex;
    //自身が属する三角形の頂点
    ofVec2f mTrianglePoints[NUM_TRIANGLE_POINT];
    //経過時間
    int mTime = 0 ;
    int mI = 1;
    //以下音から取るもの
    //初期位置
    ofVec2f mFirstPosition;
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
    
  
    
   
};
