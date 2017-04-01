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

soundDataModel GetSound::SettingVariable(){
    soundDataModel model = *new soundDataModel();
    //変数取得
    model.mLoudestBand = mFft.getLoudBand();
    model.mMaxVol= mFft.getUnScaledLoudestValue();
    model.mSuperLowEqAvg = mFft.getSuperLowVal();
    model.mLowEqAvg = mFft.getLowVal();
    model.mMidEqAvg = mFft.getMidVal();
    model.mHighEqAvg = mFft.getHighVal();
    model.mDelta = mFft.getDelta();
    model.mFreqPerBin = (ofMap(mFft.getExponent(), 0, 0.23, 0, 5000)/ mFft.getNumFFTbins()) * model.mLoudestBand;
    return model;
}
