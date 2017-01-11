#include "ofApp.h"

void ofApp::setup() {

    img.load("2017.png");

    ofPixels &pixels = img.getPixels();
    int w = img.getWidth();
    int h = img.getHeight();

    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            int i = x + y * w;
            int b = pixels[i];
            // std::cout << b << std::endl;
            if (b > 254) {
                points.push_back(ofVec2f(x, y));
            }
        }
    }
}

void ofApp::update() {

    int total = 10; // (int) ofRandom(3, 10);
    int count = 0;
    int attempts = 0;

    while (count < total) {
        Circle *c = addCircle();
        if (c != NULL) {
            circles.push_back(c);
            count++;
        }

        attempts++;
        if (attempts > MAX_ATTEMPTS) {
            count = total;
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
}

Circle * ofApp::addCircle() {
    int r = int(ofRandom(0, points.size()));
    // std::cout << r << std::endl;

    ofVec2f point = points.at(r);
    float x = point.x;
    float y = point.y;



    bool valid = true;

    for (unsigned int i = 0; i < circles.size(); i++) {
        Circle *c = circles.at(i);

        float d = ofDist(x, y, c->x, c->y);
        if (d < c->r + 2) {
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
    for (unsigned int i = 0; i < circles.size(); i++) {
        circles.erase(circles.begin() + i);
    }
}
