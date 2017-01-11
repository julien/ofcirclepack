#pragma once

#include "ofMain.h"
#include "circle.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void windowResized(int w, int h);

    vector<Circle*> circles;
    Circle * addCircle();
};
