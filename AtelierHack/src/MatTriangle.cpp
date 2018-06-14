//
//  MatTriangle.cpp
//  AtelierHack
//
//  Created by Ê±†‰∏äÁ∂æ‰πÉ on 2017/03/20.
//
//

#include "MatTriangle.hpp"

float CENTER_Y;
float CENTER_X;
MatTriangle::MatTriangle(){
    
}
void MatTriangle::setup(E_TRIANGLE_POSITION ePosition,bool isMirror){
    IMG_NAMES ={"bubble.png","clock.png","clover.png","crystal.png","crystal2.png","crystal3.png","fillsquare.png","flower.png","gear.png","lace.png","lace2.png","moon.png","nofillsquare.png","particle32.png","rect.png","sakura.png","snow.png","square.png","star.png"} ;
    CREATE_RADIUS = LENGTH / 6 *sqrt(3);
    mIsMirror = isMirror;
    mEPosition = ePosition;
    CENTER_X = ofGetWidth()/2;
    CENTER_Y = ofGetHeight()/2;
    mObjects.clear();
    setupPosition();

}

void MatTriangle::setupPosition(){
    //Âè∞Á¥ô„ÅÆ‰∏≠ÂøÉ„ÅÆÂ∫ßÊ®ô(ÂÖ®‰∏âËßíÂΩ¢ÂÖ±ÈÄö„ÅÆÂ∫ßÊ®ô)
    mPositions[0] = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    float x1,x2,y1,y2;
    switch (mEPosition) {
            //ÂÖ≠ËßíÂΩ¢Â∑¶‰∏ä„ÅÆ‰∏âËßíÂΩ¢„ÅÆ‰ΩçÁΩÆ
        case LEFT:
            //Â∑¶Á´Ø„ÅÆÈ†ÇÁÇπ
            x1 = - LENGTH;
            y1 = 0;
            //‰∏ä„ÅÆÈ†ÇÁÇπ
            x2 = - LENGTH / 2;
            y2 = - LENGTH /2 * sqrt(3);
            break;
            //ÂÖ≠ËßíÂΩ¢‰∏≠Â§Æ‰∏ä„ÅÆ‰∏âËßíÂΩ¢„ÅÆ‰ΩçÁΩÆ
        case CENTER:
            //Â∑¶‰∏ä„ÅÆÈ†ÇÁÇπ
            x1 =  - LENGTH / 2;
            y1 =  - LENGTH /2 * sqrt(3);
            //Âè≥‰∏ä„ÅÆÈ†ÇÁÇπ
            x2 = LENGTH/2;
            y2 = - LENGTH /2 * sqrt(3);
            break;
            //ÂÖ≠ËßíÂΩ¢Âè≥‰∏ä„ÅÆ‰∏âËßíÂΩ¢„ÅÆ‰ΩçÁΩÆ
        case RIGHT:
            //‰∏ä„ÅÆÈ†ÇÁÇπ
            x1 = LENGTH/2;
            y1 = - LENGTH /2 * sqrt(3);
            //Âè≥‰∏ã„ÅÆÈ†ÇÁÇπ
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
    //‰∏âËßíÂΩ¢„ÅÆÈáçÂøÉ
    mGravityPoint = ofVec2f((lineCenterPoint1.x+lineCenterPoint2.x+lineCenterPoint3.x)/3,(lineCenterPoint1.y+lineCenterPoint2.y+lineCenterPoint3.y)/3);
    
}
void MatTriangle::setupObjects(std::vector<BaseObject> rightObj){
    for(int i = 0;i < rightObj.size();i++){
        BaseObject obj = *new BaseObject();
        mObjects.push_back(obj);
    }
        for(int i = 0; i < mObjects.size(); i++){
            int j = 0;
            int w = 1;
            if(mIsMirror){
                j = 5;
                w *= -1;
            }
            mObjects.at(i).setup(rightObj.at(i).mImgName,w * mEPosition + j,rightObj.at(i).mColor,rightObj.at(i).mIsStrech,rightObj.at(i).mRadius);
            mObjects.at(i).setupRangeOfTriangle(mPositions);
            mObjects.at(i).setVelocity(rightObj.at(i).getVelocity());
            mObjects.at(i).setupRightPosition(rightObj.at(i).mPosition);
        }
}

void MatTriangle::setupRightObjects(std::vector<soundDataModel> sounds){
    for (int i = 0;i < sounds.size(); i++) {
        BaseObject obj = *new BaseObject();
        mObjects.push_back(obj);
        //ÁîüÊàê‰ΩçÁΩÆ
        float x = ofRandom(mGravityPoint.x - CREATE_RADIUS / 2 , mGravityPoint.x + CREATE_RADIUS / 2);
        float y = ofRandom(mGravityPoint.y - CREATE_RADIUS / 2 , mGravityPoint.y + CREATE_RADIUS / 2);
        ofVec2f position = ofVec2f(x,y);
        //ÈÄüÂ∫¶
        float vX = sounds.at(i).mDelta /100 * ofRandom(-1.1,1.1);
        float vY = sounds.at(i).mDelta/100 * ofRandom(-1.1,1.1);
        
        ofVec2f velocity = ofVec2f(vX,vY);
        mObjects.at(i).setVelocity(velocity);
        mObjects.at(i).setupRightPosition(position);
        //ÁîªÂÉèÂêç
        int imgIndex = (int)sounds.at(i).mMaxVol % IMG_NUM;
        string imgName = IMG_NAMES[imgIndex];
        //Ëâ≤
        int h = (sounds.at(i).mLoudestBand * (int)sounds.at(i).mMaxVol) % 255;
      //  int s = (sounds.at(i).mLoudestBand * (int)sounds.at(i).mMaxVol) % 100;
      //  int v = (sounds.at(i).mLoudestBand * (int)sounds.at(i).mMaxVol) % 100;*/
      /*  int r = sounds.at(i).mLoudestBand+1 * ofRandom(1,8);
        int g = sounds.at(i).mLoudestBand+1 * ofRandom(1,8);
        int b = sounds.at(i).mLoudestBand+1 * ofRandom(1,8);*/
        //‰º∏Á∏Æ„Åô„Çã„Åã
        int strechFlag = (int)(sounds.at(i).mFreqPerBin * sounds.at(i).mDelta * sounds.at(i).mMaxVol)%2;
        bool isStrech;
        if(strechFlag == 0){
            isStrech = true;
        }else{
            isStrech = false;
        }
        ofColor color = ofColor();
        color.setHsb(h, 255, 255);
        //初期サイズ
        int size = (int)( sounds.at(i).mLoudestBand * sounds.at(i).mMaxVol + sounds.at(i).mFreqPerBin) % 35+ 10;
        mObjects.at(i).setup(imgName,mEPosition,color,isStrech,size);
        mObjects.at(i).setupRangeOfTriangle(mPositions);
    }

}

ofVec2f MatTriangle::linearFunction(ofVec2f firstPosition,ofVec2f secondPosition,int index){
    //„Åì„ÅÆÁ∑ö„Å´„Åä„Åë„ÇãÊúÄÂ§ßÊúÄÂ∞è„ÅÆyÂ∫ßÊ®ô
    float minY,maxY;
    if(firstPosition.y > secondPosition.y){
        minY = secondPosition.y;
        maxY = firstPosition.y;
    }else{
        minY = firstPosition.y;
        maxY = secondPosition.y;
    }
    //„Åì„ÅÆÁ∑ö„Å´„Åä„Åë„ÇãÊúÄÂ§ßÊúÄÂ∞è„ÅÆxÂ∫ßÊ®ô
    float minX,maxX;
    if(firstPosition.x > secondPosition.x){
        minX = secondPosition.x;
        maxX = firstPosition.x;
    }else{
        minX = firstPosition.x;
        maxX = secondPosition.x;
    }
    
    //‰∏ÄÊ¨°Èñ¢Êï∞ y = ax + b „Å´Âü∫„Å•„ÅèÂ§âÊï∞Âêç„ÅÆÂÆöÁæ©
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
  /*  ofSetColor(0, 0, 0);
    ofNoFill();
    ofDrawTriangle(mPositions[0],mPositions[1],mPositions[2]);*/
    for(int i = 0; i < mObjects.size();i++){
            mObjects.at(i).draw();
    }
  
}

