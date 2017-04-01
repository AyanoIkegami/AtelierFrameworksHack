//
//  GetSound.cpp
//  AtelierHack
//
//  Created by 飯野慎吾 on 2017/04/01.
//
//

#include "GetSound.hpp"

void GetSound::setup(){
    mFft.setup();
}

void GetSound::update(){
    mFft.update();
}

void GetSound::SettingVariable(){
    
    //変数取得
    mLoudestBand = mFft.getLoudBand();
    mMaxVol= mFft.getUnScaledLoudestValue();
    mSuperLowEqAvg = mFft.getSuperLowVal();
    mLowEqAvg = mFft.getLowVal();
    mMidEqAvg = mFft.getMidVal();
    mHighEqAvg = mFft.getHighVal();
    mDelta = mFft.getDelta();
    mFreqPerBin = (ofMap(mFft.getExponent(), 0, 0.23, 0, 5000)/ mFft.getNumFFTbins()) * mLoudestBand;
    
    
}
