//
//  MatTriangle.cpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/20.
//
//

#include "MatTriangle.hpp"
void MatTriangle::setup(E_TRIANGLE_POSITION e_position,bool isMirror){
    mIsMirror = isMirror;
    //台紙の中心の座標(全三角形共通の座標)
    mPositions[0] = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    float x1,x2,y1,y2;
    switch (e_position) {
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
}

void MatTriangle::update(){
    
}

void MatTriangle::draw(){
    ofSetColor(255, 255, 255);
    ofNoFill();
    ofDrawTriangle(mPositions[0],mPositions[1],mPositions[2]);    
}

void MatTriangle::rotateX(){
    
}
