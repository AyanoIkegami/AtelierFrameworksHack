#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofToggleFullscreen();
    ofSetFrameRate(60);
    
    //画像の読み込み
    img.load("particle32.png");
    
    //円運動で使用する変数
    mR = 100;  //軌跡を描く円の半径
    mTheta = 0;  //角度
    mRad = (TWO_PI/60)/6;  //1秒で3回転。
    
    //八の字で使用する変数
    mA1 = 100;  //振幅を設定
    mW1 = 1;    //角周波数を設定
    mPosition = 0;    //初期位相を設定
    mTime = 0;    //経過時間を初期化
  
    //トロコイドで使用する変数
    mA1 = 100;   //振幅
    mA2 = 10;
    mA3 = 20;
    mW1 = 1;     //周期
    mW2 = 1;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //色が変わる
    ofSetColor(ofColor::fromHsb(ofGetFrameNum()%255, 255, 255) ,255);
    img.draw(ofGetWidth()/2,ofGetHeight()/2,50);
    
    //伸縮
    mY = mA1*sin(mW1*mTime + mPosition) + 100;
    img.draw(ofGetWidth()/2, ofGetHeight()/2, mY, mY);  //円を描く
    mTime += mRad;    //時間を進める
    if (mTime > TWO_PI) mTime = 0;
    
    //円を描くように
    mX = mR*cos(mTheta);
    mY = -mR*sin(mTheta);
    img.draw(mX + ofGetWidth()/2, mY + ofGetHeight()/2, 50);
    mTheta += mRad; //時間を進める
    if (mTheta >= TWO_PI) mTheta = 0;
    
    //八の字
    mX = mA1*sin(mW1*mTime - mPosition);
    mY = -mA1*sin(mW1*mTime*2 - mPosition);
    img.draw(mX + ofGetWidth()/2, mY + ofGetHeight()/2, 50);  //円を描く
    //time += rad;    //時間をさらに進める

    //トロコイド
    mX = (mA1 + mA2)*cos(mW1*mTime) - mA3*cos(((mA1 + mA2)/mA2)*mTime);
    mY = (mA1 + mA2)*sin(mW2*mTime) - mA3*sin(((mA1 + mA2)/mA2)*mTime);
    img.draw(mX + ofGetWidth()/2, mY + ofGetHeight()/2,  50);
    //time += rad;    //時間をさらに進める
    
    //波
     mX = mTime*100;
     mY= mA1*sin(mW1*mTime + mPosition);
     img.draw(mX+ofGetWidth()/4, mY + ofGetHeight()/2, 50);
    //time += rad;    //時間を進める
    if (mTime > TWO_PI) mTime = 0;    //1周期分終わったら原点に
    
    /*//おまけ:DNAっぽい螺旋
    for (x = 0; x <= ofGetWidth(); x += 10)
    {
        y = ofGetHeight()/2 + 100 * sin(ofGetFrameNum() * 0.04 + x * 0.02);
        img.draw(x, y, 50);
    }
*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
