#pragma once

#include "ofMain.h"
#include "vec.h"
#include "circle.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    unsigned const MAX_ATTEMPTS = 50;
    unsigned const MAX_CIRCLES = 20000;
    vector<Circle*> circles;
    Circle * addCircle();
    ofImage img;
    vector<vec> points;
};
