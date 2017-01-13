#include "ofApp.h"

void ofApp::setup() {
    min = 5;
    max = 100;
    checkmax = false;
}

void ofApp::update() {

    Circle *c = addCircle();
    int count = 0;
    while (!isValid(c)) {
        c->x = ofRandom(ofGetWidth());
        c->y = ofRandom(ofGetHeight());
        count++;
        if (count > 1000) {
            return;
        }
    }

    while (isValid(c)) {
        c->r += 0.2;
    }

    c->r -= 2;

    circles.push_back(c);
}

void ofApp::draw() {
    ofSetBackgroundColor(ofColor::black);
    drawCircles();

    if (saveScreen) {
        ofSaveScreen(ofToString(ofGetFrameNum()) + ".gif");
        saveScreen = false;
    }
}

void ofApp::keyPressed(int key) {
    if (key == 's') saveScreen = true;
}

void ofApp::windowResized(int w, int h) {
    for (unsigned int i = 0; i < circles.size(); i++) {
        circles.erase(circles.begin() + i);
    }
}

void ofApp::mousePressed(int x, int y, int button) {
    checkmax = !checkmax;
}

Circle * ofApp::addCircle() {
    float x = ofRandom(ofGetWidth());
    float y = ofRandom(ofGetHeight());
    return new Circle(x, y, (float) min);
}

void ofApp::drawCircles() {
    ofSetColor(ofColor::white);

    for (unsigned int i = 0; i < circles.size(); i++) {
        Circle *c = circles.at(i);

        // larger circles won't be drawn
        if (checkmax) {
            if (c->r > max * 0.9) {
            continue;
            }
        }

        ofDrawCircle(c->x, c->y, c->r);
    }

    ofFill();
}

bool ofApp::isValid(Circle *c) {

    if (c->r > max) {
        return false;
    }

    for (unsigned int i = 0; i < circles.size(); i++) {
        Circle *c2 = circles.at(i);
        float d = ofDist(c2->x, c2->y, c->x, c->y);
        if (d < c2->r + c->r) {
            return false;
        }
    }
    return true;
}
