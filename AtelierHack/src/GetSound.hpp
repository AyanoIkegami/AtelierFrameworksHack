//
//  GetSound.hpp
//  AtelierHack
//
//  Created by 飯野慎吾 on 2017/04/01.
//
//

#define GetSound_hpp

#include <stdio.h>
#include "ofxProcessFFT.h"
#include <vector>
#include "soundDataModel.hpp"
class GetSound{

public:
    
    ProcessFFT mFft;
    void setup();
    void update();
    soundDataModel SettingVariable(); //変数設定
    
};

