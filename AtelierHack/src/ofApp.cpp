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
    R = 100;  //軌跡を描く円の半径
    theta = 0;  //角度
    rad = (TWO_PI/60)/6;  //1秒で3回転。
    
    //八の字で使用する変数
    A1 = 100;  //振幅を設定
    w1 = 1;    //角周波数を設定
    position = 0;    //初期位相を設定
    time = 0;    //経過時間を初期化
  
    //トロコイドで使用する変数
    A1 = 100;   //振幅
    A2 = 10;
    A3 = 20;
    w1 = 1;     //周期
    w2 = 1;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    //色が変わる
    ofSetColor(ofColor::fromHsb(ofGetFrameNum()%255, 255, 255) ,255);
    img.draw(0,0,50);
    cam.end();
    
    //伸縮
    y = A1*sin(w1*time + position) + 100;
    img.draw(ofGetWidth()/2, ofGetHeight()/2, y, y);  //円を描く
    time += rad;    //時間を進める
    if (time > TWO_PI) time = 0;
    
    //円を描くように
    x = R*cos(theta);
    y = -R*sin(theta);
    img.draw(x + ofGetWidth()/2, y + ofGetHeight()/2, 50);
    theta += rad; //時間を進める
    if (theta >= TWO_PI) theta = 0;
    
    //八の字
    x = A1*sin(w1*time - position);
    y = -A1*sin(w1*time*2 - position);
    img.draw(x + ofGetWidth()/2, y + ofGetHeight()/2, 50);  //円を描く
    //time += rad;    //時間をさらに進める

    //トロコイド
    x = (A1 + A2)*cos(w1*time) - A3*cos(((A1 + A2)/A2)*time);
    y = (A1 + A2)*sin(w2*time) - A3*sin(((A1 + A2)/A2)*time);
    img.draw(x + ofGetWidth()/2, y + ofGetHeight()/2,  50);
    //time += rad;    //時間をさらに進める

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
