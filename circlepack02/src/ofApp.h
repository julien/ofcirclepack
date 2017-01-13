#pragma once

#include "ofMain.h"
#include "circle.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();
    void windowResized(int w, int h);
    void mousePressed(int x, int y, int button);
    void keyPressed(int key);

    vector<Circle*> circles;
    int min = 5;
    int max = 80;
    bool checkmax;
    Circle* addCircle();
    void drawCircles();
    bool isValid(Circle *c);
    bool saveScreen;
};
