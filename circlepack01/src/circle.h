#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "ofGraphics.h"

class Circle {
public:
    float x;
    float y;
    float r;
    bool growing;

    Circle(float x, float y) : x(x), y(y), r(ofRandom(1, 3)), growing(true) {}

    bool edges() {
        float w = (float) ofGetWidth();
        float h = (float) ofGetHeight();
        return (x + r > w || x - r < 0 || y + r > h || y - r < 0);
    }

    void grow() {
        if (growing) {
            r += 1;
        }
    }

    void draw() {
        ofNoFill();
        ofSetColor(ofColor::white);
        ofDrawCircle(x, y, r * 2);
    }
};

#endif
