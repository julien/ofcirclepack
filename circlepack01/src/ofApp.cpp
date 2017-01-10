#include "ofApp.h"

void ofApp::setup() {

}

void ofApp::update() {

}

void ofApp::draw() {
    ofSetBackgroundColor(ofColor::black);

    int total = 10;
    int count = 0;
    int attempts = 0;


    while (count < total) {
        Circle *c = addCircle();
        if (c != NULL) {
            circles.push_back(c);
            count++;
        }
        attempts++;
        if (attempts > 1000) {
            break;
            return;
        }
    }

    for (int i = 0; i < circles.size(); i++) {
        Circle *c = circles.at(i);
        if (c->growing) {
            if (c->edges()) {
                c->growing = false;
            } else {
                for (int j = 0; j < circles.size(); j++) {
                    Circle *other = circles.at(j);
                    if (c != other) {
                        float d = ofDist(c->x, c->y, other->x, other->y);
                        if (d < c->r + other->r) {
                            c->growing = false;
                            break;
                        }
                    }
                }
            }
        }
        c->grow();
        c->draw();
    }
}

Circle * ofApp::addCircle() {
    float x = ofRandom(ofGetWidth());
    float y = ofRandom(ofGetHeight());

    bool valid = true;

    for (int i = 0; i < circles.size(); i++) {
        Circle *c = circles.at(i);
        float d = ofDist(x, y, c->x, c->y);
        if (d < c->r + c->r) {
            valid = false;
            break;
        }
    }

    if (valid) {
        return new Circle(x, y);
    } else {
        return NULL;
    }
}

void ofApp::windowResized(int w, int h) {

    for (int i = 0; i < circles.size(); i++) {
        circles.erase(circles.begin() + i);
    }
}
