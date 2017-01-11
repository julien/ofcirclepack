#pragma once

#include "ofMain.h"
#include "circle.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void windowResized(int w, int h);

    unsigned const MAX_ATTEMPTS = 100;
    vector<Circle*> circles;
    Circle * addCircle();
    ofImage img;
    vector<ofVec2f> points;
};
