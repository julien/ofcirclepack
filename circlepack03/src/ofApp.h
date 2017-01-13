#pragma once

#include "ofMain.h"
#include "circle.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    const int MAX_ATTEMPTS = 50;
    unsigned const MAX_CIRCLES = 5000;
    vector<Circle*> circles;
    Circle * addCircle();
    ofImage img;
    vector<ofVec2f> points;
    bool saveScreen;
};
