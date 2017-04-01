#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255, 255, 255);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    mSound.setup();
    mSoundData.clear();
  //  ofToggleFullscreen();
    ofSetFrameRate(10);
    bool isMirror = false;
    int mObjectNum = ofRandom(1,100);
    for(int i = 0; i < MAT_NUM; i ++){
        for (int j = 0; j < TRIANGLE_NUM; j++) {
             mTriangles[j+3*i].setup((MatTriangle::E_TRIANGLE_POSITION)j,isMirror);
        }
        isMirror = !isMirror;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
       if(mIsKeyPressed){
        mSound.update();
        mSoundData.push_back(mSound.SettingVariable());
        
    }else{
    for(int i = 0; i < TRIANGLE_NUM * MAT_NUM; i ++){
        mTriangles[i].update(mTriangles[0].mObjects);
    }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < MAT_NUM*TRIANGLE_NUM; i ++){
        mTriangles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f'){
        mIsKeyPressed = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'f'){
        mIsKeyPressed = false;
        if(mObjectNum > MAX_PARTICLE_NUM){
            mObjectNum = MAX_PARTICLE_NUM;
        }
        bool isMirror = false;
        for(int i = 0; i < MAT_NUM; i ++){
            for (int j = 0; j < TRIANGLE_NUM; j++) {
                mTriangles[j+3*i].setup((MatTriangle::E_TRIANGLE_POSITION)j,isMirror);
                if(i == 0 && j == 0){
                    mTriangles[0].setupRightObjects(mSoundData);
                }else{
                    mTriangles[j+3*i].setupObjects(mTriangles[0].mObjects);
                }
            }
            isMirror = !isMirror;
        }

    }
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
