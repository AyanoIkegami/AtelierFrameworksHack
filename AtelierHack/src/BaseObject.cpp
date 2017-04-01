//
//  BaseMaterial.cpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/21.
//
//
#include "BaseObject.hpp"
void BaseObject::setup(string imageName,ofVec2f position){
    mImg.load(imageName);
    mRadius = 50;
    mPosition = position;
    mVelocity = ofVec2f(ofRandom(-5,5),ofRandom(-5,5));
    mAmplitude = 25;
    mCycle = 1;
    mFirstPosition = position;
    mTheta = 0;
    mRadian = (TWO_PI/60)/6;  //6秒１回転。
 
}

void BaseObject::setupRangeOfTriangle(ofVec2f trianglePoints[NUM_TRIANGLE_POINT],float linearA[NUM_TRIANGLE_POINT],float linearB[NUM_TRIANGLE_POINT], ofVec2f gravityPoint){
    for(int i = 0; i < NUM_TRIANGLE_POINT; i++){
        mTrianglePoints[i] = trianglePoints[i];
    }
}

void BaseObject::update(){
    reflect();
    stretch();
   // circularMotion();
    mTime += 1 * mI;
}

void BaseObject::draw(){
   // ofDrawCircle(mPosition, 10);
   // mImg.draw(mPosition, mPosition.y, mPosition.y);
    mImg.draw(mPosition,mRadius,mRadius);
   // mImg.draw(mPosition.x, mPosition.y, 50,50);
}

void BaseObject::reflect(){
    mVelocity *= judgeInOrOut();
   /* if(judgeInOrOut() == ofVec2f(-1,-1)){
        float valueX = mVelocity.x / abs(mVelocity.x);
        float valueY = mVelocity.y / abs(mVelocity.y);
        Velocity.x = (mPosition.x + 30 * cos(ofRandom(180)))/ofGetFrameRate() * valueX;
      　mVelocity.y = (mPosition.y + 30 * sin(ofRandom(180)))/ofGetFrameRate() * valueY;
       // mVelocity.x = ofRandom(3) * valueX;
       // mVelocity.y = ofRandom(3) * valueY;
    }*/
    
    mPosition += mVelocity;
}


ofVec2f BaseObject::judgeInOrOut(){
    bool isPlus[3];
    int minusCount = 0;
    for(int i = 0; i < 3; i++){
        float crossVector;
        if(i != 2){
            crossVector = crossProduct(i, i+1);
        }else{
            crossVector = crossProduct(i, 0);
        }
        if(crossVector >= 0){
            isPlus[i] = true;
        }else{
            isPlus[i] = false;
            minusCount ++;
        }
    }
    if((minusCount ==3 && mIsMirror) || (minusCount == 0 && !mIsMirror)) {
        //直進、中側にある
        return ofVec2f(1,1);
    }else{
        return ofVec2f(-ofRandom(0.8,1.2),-ofRandom(0.8,1.2));
    }
    
}

float BaseObject::crossProduct(int index,int index2){
    ofVec2f v0 = mTrianglePoints[index2] - mTrianglePoints[index];
    ofVec2f v1 = mPosition - mTrianglePoints[index];
    float valueOfCrossProduct = v0.x * v1.y - v0.y * v1.x;
    return valueOfCrossProduct;
}
void BaseObject::circularMotion(){
    //円を描くように
    mPosition.x = mRadius*cos(mTheta) + mFirstPosition.x;
    mPosition.y = -mRadius*sin(mTheta) + mFirstPosition.y;
    mTheta += mRadian; //時間を進める
    if (mTheta >= TWO_PI) mTheta = 0;

}

void BaseObject::blink(){
    mRadius = mAmplitude*sin(mCycle*mTime) +100;
    mPosition = mFirstPosition - mRadius* 0.5;
    if (mTime > TWO_PI) mTime = 0;
}

void BaseObject::stretch(){
    //伸縮
    mRadius = mAmplitude + mTime ;//*sin(mTime) +100;
  //  mPosition = mFirstPosition - mRadius* 0.5;
    if (mTime > TWO_PI*6){
        mI = -1;
    }
    
    if(mTime == 0) {
        mI = 1;
    }
}


