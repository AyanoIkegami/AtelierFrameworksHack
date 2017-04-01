#pragma once
#define NUM 100
#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofImage img;
    
    float mX, mY;     //中心点の座標
    float mR;        //半径
    float mTheta;
    float mRad;
    
    float mPosition; //初期位置
    float mTime;     //経過時間
    
    float mA1, mA2, mA3;  //振幅
    float mW1, mW2;      //角周波数（周期）
    
    
   };
