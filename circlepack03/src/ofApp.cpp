#include "ofApp.h"

void ofApp::setup() {

    img.load("2017.png");
    img.draw(0, 0);

    // ofPixels &pixels = img.getPixels(); // NO!!!

    int w = img.getWidth();
    int h = img.getHeight();


    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            // int i = x + y * w;
            // int b = pixels[y * w + x]; // NO!!!
            ofColor c = img.getColor(x, y);
            if (c.r > 200 && c.g > 200 && c.b > 200) {
                points.push_back(ofVec2f(x, y));

            }
        }
    }
}

void ofApp::update() {

    int total = (int) ofRandom(10, 30);
    int count = 0;
    int attempts = 0;

    if (circles.size() > MAX_CIRCLES) {
        return;
    }

    while (count < total) {
        Circle *c = addCircle();
        if (c != NULL) {
            circles.push_back(c);
            count++;
        }

        attempts++;
        if (attempts > MAX_ATTEMPTS) {
            break;
        }
    }


}

void ofApp::draw() {
    ofSetBackgroundColor(ofColor::black);

    for (unsigned int i = 0; i < circles.size(); i++) {

        Circle *c = circles.at(i);

        if (c->growing) {
            if (c->edges()) {
                c->growing = false;
            } else {
                for (unsigned int j = 0; j < circles.size(); j++) {
                    Circle *other = circles.at(j);
                    if (c != other) {
                        float d = ofDist(c->x, c->y, other->x, other->y);
                        if (d - c->lineWidth < c->r + other->r) {
                            c->growing = false;
                            c->r -= 2;
                            break;
                        }
                    }
                }
            }
        }
        c->grow();
        c->draw();
    }

    if (saveScreen) {
        ofSaveScreen(ofToString(ofGetFrameNum()) + ".gif");
        saveScreen = false;
    }
}

void ofApp::keyPressed(int key) {
    if (key == 's') saveScreen = true;
}

Circle * ofApp::addCircle() {
    int r = int(ofRandom(0, points.size()));

    ofVec2f point = points.at(r);
    float x = point.x;
    float y = point.y;

    bool valid = true;

    for (unsigned int i = 0; i < circles.size(); i++) {
        Circle *c = circles.at(i);

        float d = ofDist(x, y, c->x, c->y);
        if (d < c->r - 2) {
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

