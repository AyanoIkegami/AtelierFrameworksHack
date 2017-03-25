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
		
    ofEasyCam cam;
    ofImage img;
    
    float x, y;     //中心点の座標
    float R;        //半径
    float theta;    
    float rad;
    
    float position;　//初期位置
    float time;     //経過時間
    
    float A1, A2, A3;  //振幅
    float w1, w2;      //角周波数（周期）
    
    
   };
