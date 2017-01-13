#pragma once

#include "ofMain.h"
#include "circle.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void windowResized(int w, int h);
    void keyPressed(int key);

    const int MAX_ATTEMPTS = 100;
    vector<Circle*> circles;
    Circle * addCircle();
    bool saveScreen;
};
