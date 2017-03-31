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

void MatTriangle::setup(E_TRIANGLE_POSITION ePosition,bool isMirror, std::vector<BaseObject> objs){
    mObjects = objs;
    mLeftObjects = objs;
    CREATE_RADIUS = LENGTH / 6 *sqrt(3);
    mIsMirror = isMirror;
    mEPosition = ePosition;
    CENTER_X = ofGetWidth()/2;
    CENTER_Y = ofGetHeight()/2;
    setupPosition();
    setupObjects();
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
void MatTriangle::setupObjects(){
    for (int i = 0;i < mObjects.size(); i++) {
        float x = ofRandom(mGravityPoint.x - CREATE_RADIUS / 2,mGravityPoint.x + CREATE_RADIUS / 2);
        float y = ofRandom(mGravityPoint.y - CREATE_RADIUS / 2,mGravityPoint.y + CREATE_RADIUS / 2);
        ofVec2f position = ofVec2f(x,y);
        if(mEPosition == LEFT && !mIsMirror){
            mLeftObjects.at(i).setupLeftPosition(position);
            mLeftObjects.at(i).setup("particle32.png",0);
            mLeftObjects.at(i).setupRangeOfTriangle(mPositions, mGravityPoint);
        }else{
            mObjects.at(i).setupLeftPosition(mLeftObjects.at(i).mLeftPosition);
            int j = 0;
            if(mIsMirror){
                j = 3;
            }
            mObjects.at(i).setup("particle32.png",mEPosition + j);
            mObjects.at(i).setupRangeOfTriangle(mPositions, mGravityPoint);
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

void MatTriangle::update(){
    if(mEPosition == LEFT && !mIsMirror){
    for(int i = 0; i < mObjects.size();i++){
               mLeftObjects.at(i).update();
        }
    }else{
        for(int i = 0 ; i < mObjects.size(); i++){
        mObjects.at(i).setupLeftPosition(mLeftObjects.at(i).mPosition);
        mObjects.at(i).update();
        }
    }
}

void MatTriangle::draw(){
    ofSetColor(255, 255, 255);
    ofNoFill();
    ofDrawTriangle(mPositions[0],mPositions[1],mPositions[2]);
    ofDrawCircle(mGravityPoint, CREATE_RADIUS);
    for(int i = 0;i < mObjects.size();i++){
        if(mEPosition == LEFT && !mIsMirror){
            mLeftObjects.at(i).draw();
        }else{
          mObjects.at(i).draw();
        }
    }
  
}

