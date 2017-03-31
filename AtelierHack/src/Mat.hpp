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
#include "BaseObject.hpp"
#include <vector>
#include "MatTriangle.hpp"
class MatTriangle;
class Mat {
public:
    Mat();
    void setup(bool isMirror, std::vector<BaseObject> objs);
    void update();
    void draw();
    void rotateX();
    static const int TRIANGLE_NUM = 3;
    std::vector<BaseObject> mObjects;
private:
      ofVec2f mMatPosition; //台紙の基準となる位置
    bool mIsMirror;
  };
