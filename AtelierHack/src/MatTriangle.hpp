//
//  MatTriangle.hpp
//  AtelierHack
//
//  Created by 池上綾乃 on 2017/03/20.
//
//
#pragma once
#include <stdio.h>
#include "ofMain.h"
#include "BaseObject.hpp"

class MatTriangle{
public:
    enum E_TRIANGLE_POSITION {LEFT,CENTER,RIGHT};
    void setup(E_TRIANGLE_POSITION e_position, bool isMirror);
    void update();
    void draw();
    void rotateX();
private:
    //頂点の位置（三角形なので３つ用意する）
    ofVec2f mPositions[3];
    bool mIsMirror;
    constexpr static const float LENGTH = 300;
};
