#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
  //  ofToggleFullscreen();
    ofSetFrameRate(10);
    bool isMirror = false;
    int mObjectNum = ofRandom(1,20);
    for(int i = 0; i < MAT_NUM; i ++){
        for (int j = 0; j < TRIANGLE_NUM; j++) {
            mTriangles[j+3*i].setup((MatTriangle::E_TRIANGLE_POSITION)j,isMirror,mObjectNum);
            mTriangles[j+3*i].setupObjects(mTriangles[0].mObjects);
        }
        isMirror = !isMirror;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < TRIANGLE_NUM * MAT_NUM; i ++){
        mTriangles[i].update(mTriangles[0].mObjects);
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
