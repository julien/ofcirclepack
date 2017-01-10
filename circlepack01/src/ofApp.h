#pragma once

#include "ofMain.h"
#include "circle.h"

class ofApp : public ofBaseApp {

    vector<Circle*> circles;

public:
    void setup();
    void update();
    void draw();
    void windowResized(int w, int h);
    Circle * addCircle();
};
