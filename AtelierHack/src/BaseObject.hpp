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
    virtual void setup(string imageName);
    virtual void update();
    virtual void draw();
    //エフェクト数
    static const int NUM_EFFECT = 4;
     //エフェクト適用するかどうかのフラグ配列
    bool isUseEffects[NUM_EFFECT];
protected:
    //反射
    virtual void reflect();
    //円運動
    virtual void circularMotion();
    //明滅
    virtual void blink();
    //伸縮
    virtual void stretch();
    
    
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
    float mRadious;
    //位相
    float mPhase;
    //経過時間
    float mTime;
  
    
   
};
