//
//  Mat.hpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/20.
//
//
#pragma once
#include <stdio.h>
#include "ofMain.h"
#include "MatTriangle.hpp"

class Mat {
public:
    void setup(bool isMirror);
    void update();
    void draw();
    void rotateX();
    static const int TRIANGLE_NUM = 3;
private:
    MatTriangle mTriangles[TRIANGLE_NUM];
    ofVec2f mMatPosition; //台紙の基準となる位置
    bool mIsMirror;
};
