//
//  soundDataModel.hpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/04/01.
//
//
#pragma once
#ifndef soundDataModel_hpp
#define soundDataModel_hpp

#include <stdio.h>

#endif /* soundDataModel_hpp */
class soundDataModel{
public:
    int mLoudestBand;       //ラウドネスレベル
    float mMaxVol;          //最大音量
    float mSuperLowEqAvg;   //超低周波成分
    float mLowEqAvg;        //低周波成分
    float mMidEqAvg;        //中周波成分
    float mHighEqAvg;       //高周波成分
    float mDelta;           //変化量
    float mFreqPerBin;      //ラウドネスレベルにおける周波数

};
