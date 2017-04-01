//
//  GetSound.hpp
//  AtelierHack
//
//  Created by 飯野慎吾 on 2017/04/01.
//
//

#define GetSound_hpp

#include <stdio.h>
#include "ofApp.h"
#include "ofxProcessFFT.h"


class GetSound{

public:
    
    ProcessFFT mFft;
    int mLoudestBand;       //ラウドネスレベル
    float mMaxVol;          //最大音量
    float mSuperLowEqAvg;   //超低周波成分
    float mLowEqAvg;        //低周波成分
    float mMidEqAvg;        //中周波成分
    float mHighEqAvg;       //高周波成分
    float mDelta;           //変化量
    float mFreqPerBin;      //ラウドネスレベルにおける周波数
    
    void setup();
    void update();
    void SettingVariable(); //変数設定
    
};

