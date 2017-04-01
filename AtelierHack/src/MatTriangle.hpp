//
//  MatTriangle.hpp
//  AtelierHack
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/03/20.
//
//
#pragma once
#include <stdio.h>
#include "ofMain.h"
#include "BaseObject.hpp"
#include <vector>
#include "soundDataModel.hpp"
#include <array>
class MatTriangle{
public:
    MatTriangle();
    enum E_TRIANGLE_POSITION {RIGHT,CENTER,LEFT};
    void setup(E_TRIANGLE_POSITION ePosition, bool isMirror);
    void update(std::vector<BaseObject> rightObj);//std::vector<BaseObject> rObjs);
    void draw();    constexpr static const float LENGTH = 400;
    void setupObjects(std::vector<BaseObject> rightObj);
    void setupRightObjects(std::vector<soundDataModel> sounds);

    float CREATE_RADIUS;
     std::vector<BaseObject> mObjects;

private:
    //È†ÇÁÇπ„ÅÆ‰ΩçÁΩÆÔºà‰∏âËßíÂΩ¢„Å™„ÅÆ„ÅßÔºì„Å§Áî®ÊÑè„Åô„ÇãÔºâ
    void setupPosition();
    float createRadious();
    float getA();
    float getB();
      ofVec2f linearFunction(ofVec2f firstPosition, ofVec2f secondPosition,int index);
   
    //ÊñπÁ®ãÂºèÂ§âÊï∞
    float mA[3],mB[3];
    ofVec2f mPositions[3];
    ofVec2f mGravityPoint;
    E_TRIANGLE_POSITION mEPosition;
    bool mIsMirror;
    bool mIsCenterY;
    int mParticleNum;
    static const int IMG_NUM =19;
    std::array<string,IMG_NUM> IMG_NAMES;   //BaseObject mParticles[1];
};
