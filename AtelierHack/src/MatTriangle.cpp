//
//  MatTriangle.cpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/20.
//
//

#include "MatTriangle.hpp"

float CENTER_Y;
float CENTER_X;
MatTriangle::MatTriangle(){
    
}
void MatTriangle::setup(E_TRIANGLE_POSITION ePosition,bool isMirror, int objNum){
    for(int i = 0;i < objNum;i++){
        BaseObject obj = *new BaseObject();
        mObjects.push_back(obj);
    }
    
    CREATE_RADIUS = LENGTH / 6 *sqrt(3);
    mIsMirror = isMirror;
    mEPosition = ePosition;
    CENTER_X = ofGetWidth()/2;
    CENTER_Y = ofGetHeight()/2;
    setupPosition();

}

void MatTriangle::setupPosition(){
    //台紙の中心の座標(全三角形共通の座標)
    mPositions[0] = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    float x1,x2,y1,y2;
    switch (mEPosition) {
            //六角形左上の三角形の位置
        case LEFT:
            //左端の頂点
            x1 = - LENGTH;
            y1 = 0;
            //上の頂点
            x2 = - LENGTH / 2;
            y2 = - LENGTH /2 * sqrt(3);
            break;
            //六角形中央上の三角形の位置
        case CENTER:
            //左上の頂点
            x1 =  - LENGTH / 2;
            y1 =  - LENGTH /2 * sqrt(3);
            //右上の頂点
            x2 = LENGTH/2;
            y2 = - LENGTH /2 * sqrt(3);
            break;
            //六角形右上の三角形の位置
        case RIGHT:
            //上の頂点
            x1 = LENGTH/2;
            y1 = - LENGTH /2 * sqrt(3);
            //右下の頂点
            x2 = LENGTH;
            y2 = 0;
            break;
        default:
            break;
    }
    
    if(mIsMirror){
        y1 *= -1;
        y2 *= -1;
    }
    mPositions[1] = ofVec2f(mPositions[0].x + x1, mPositions[0].y + y1);
    mPositions[2] = ofVec2f(mPositions[0].x + x2, mPositions[0].y + y2);
    ofVec2f lineCenterPoint1 = linearFunction(mPositions[0], mPositions[1], 0);
    ofVec2f lineCenterPoint2 = linearFunction(mPositions[0], mPositions[2], 1);
    ofVec2f lineCenterPoint3 = linearFunction(mPositions[1], mPositions[2], 2);
    //三角形の重心
    mGravityPoint = ofVec2f((lineCenterPoint1.x+lineCenterPoint2.x+lineCenterPoint3.x)/3,(lineCenterPoint1.y+lineCenterPoint2.y+lineCenterPoint3.y)/3);
    
}
void MatTriangle::setupObjects(std::vector<BaseObject> rightObj){
 if(mEPosition == RIGHT && !mIsMirror) {
    for (int i = 0;i < mObjects.size(); i++) {
        float x = ofRandom(mGravityPoint.x - CREATE_RADIUS / 2,mGravityPoint.x + CREATE_RADIUS / 2);
        float y = ofRandom(mGravityPoint.y - CREATE_RADIUS / 2,mGravityPoint.y + CREATE_RADIUS / 2);
        ofVec2f position = ofVec2f(x,y);
        
           mObjects.at(i).setup("particle32.png",mEPosition);
           mObjects.at(i).setupRangeOfTriangle(mPositions);
        
        float vX = ofRandom(-5,5);
        float vY = ofRandom(-5,5);
        ofVec2f velocity = ofVec2f(vX,vY);
        mObjects.at(i).setVelocity(velocity);
        mObjects.at(i).setupRightPosition(position);
        }
    }else{
        for(int i = 0; i < mObjects.size(); i++){
            int j = 0;
            int w = 1;
            if(mIsMirror){
                j = 5;
                w *= -1;
            }
            mObjects.at(i).setup("particle32.png",w * mEPosition + j);
            mObjects.at(i).setupRangeOfTriangle(mPositions);
            mObjects.at(i).setVelocity(rightObj.at(i).getVelocity());
            mObjects.at(i).setupRightPosition(rightObj.at(i).mPosition);
        }
    }
}

ofVec2f MatTriangle::linearFunction(ofVec2f firstPosition,ofVec2f secondPosition,int index){
    //この線における最大最小のy座標
    float minY,maxY;
    if(firstPosition.y > secondPosition.y){
        minY = secondPosition.y;
        maxY = firstPosition.y;
    }else{
        minY = firstPosition.y;
        maxY = secondPosition.y;
    }
    //この線における最大最小のx座標
    float minX,maxX;
    if(firstPosition.x > secondPosition.x){
        minX = secondPosition.x;
        maxX = firstPosition.x;
    }else{
        minX = firstPosition.x;
        maxX = secondPosition.x;
    }
    
    //一次関数 y = ax + b に基づく変数名の定義
    float x,y;
    x = firstPosition.x - secondPosition.x;
    y = firstPosition.y - secondPosition.y;
    mA[index] = y / x;
    mB[index] = firstPosition.y - firstPosition.x * mA[index];
    ofVec2f lineCenterPoint = ofVec2f((firstPosition.x + secondPosition.x)/2, (firstPosition.y + secondPosition.y)/2);
    
    return lineCenterPoint;
}

void MatTriangle::update(std::vector<BaseObject> rightObj){//std::vector<BaseObject>rObjs){
       for(int i = 0 ; i < mObjects.size(); i++){
        if(mEPosition == RIGHT && !mIsMirror){
        }else{
    //        mObjects.at(i).setupRightPosition(rightObj.at(i).mPosition);

        }
        mObjects.at(i).update();

        }
       
}

void MatTriangle::draw(){
    ofSetColor(255, 255, 255);
    ofNoFill();
    ofDrawTriangle(mPositions[0],mPositions[1],mPositions[2]);
    for(int i = 0; i < mObjects.size();i++){
            mObjects.at(i).draw();
    }
  
}

