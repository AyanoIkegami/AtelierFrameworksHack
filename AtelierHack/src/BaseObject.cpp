//
//  BaseMaterial.cpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/21.
//
//
#include "BaseObject.hpp"
void BaseObject::setup(string imageName,int index){
    mImg.load(imageName);
    mRadius = 50;
   // mPosition = position;
    mIndex = index;
    mVelocity = ofVec2f(ofRandom(-5,5),ofRandom(-5,5));
    mAmplitude = 25;
    mCycle = 1;
    mFirstPosition = mPosition;
    mTheta = 0;
    mRadian = (TWO_PI/60)/6;  //6秒１回転。
 
}

void BaseObject::setupRightPosition(ofVec2f RightPosition){
    mRightPosition = RightPosition;
    mPosition = RightPosition;
    if(mIndex!=0){
        move();
    }
}

void BaseObject::setupRangeOfTriangle(ofVec2f trianglePoints[NUM_TRIANGLE_POINT]){
    for(int i = 0; i < NUM_TRIANGLE_POINT; i++){
        mTrianglePoints[i] = trianglePoints[i];
    }
}

void BaseObject::setVelocity(ofVec2f velocity){
    mVelocity = velocity;
}

void BaseObject::update(){
  //  reflect();
    //stretch();
   // circularMotion();
  //  wave();
    mTime += 1 * mI;
    if(mIndex == 0){
        mPosition += mVelocity;
    }
}

void BaseObject::move(){
    float yLength = ofGetHeight()/2 -  mRightPosition.y;
    float xLength = mRightPosition.x - ofGetWidth()/2;
    float r = sqrt(pow(xLength, 2)+pow(yLength,2));
    float sinTheta = yLength / r;
    float cosTheta = xLength / r;
    float radian = acos(cosTheta) +((60 *  mIndex) * PI / 180);
    float cosRadian = cos(radian);
    float sinRadian = sin(radian);
    mPosition.x = ofGetWidth()/2 + r * cos(radian);
    mPosition.y = ofGetHeight()/2 + r * sin(radian);
}

void BaseObject::draw(){
    ofDrawCircle(mPosition, 10);
   // mImg.draw(mPosition, mPosition.y, mPosition.y);
    //mImg.draw(mPosition,mRadius,mRadius);
   // mImg.draw(mPosition.x, mPosition.y, 50,50);
}

void BaseObject::reflect(){
    mVelocity *= judgeInOrOut();
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
    mRadius = mAmplitude + mTime;//*sin(mTime) +100;
  //  mPosition = mFirstPosition - mRadius* 0.5;
    if (mTime > TWO_PI*6){
        mI = -1;
    }
    
    if(mTime == 0) {
        mI = 1;
    }
}

void BaseObject::wave(){
    mPosition.x = mTime*100;
    mPosition.y = mAmplitude* sin(mTime + mPosition.y);
    mImg.draw(mPosition.x+ofGetWidth()/4, mPosition.y + ofGetHeight()/2, 50);
    //time += rad;    //時間を進める
    mTime += mCycle * mRadian;
    if (mTime > TWO_PI) mCycle = -1;
    if(mTime <= 0) mCycle = 1;

}



