#include "ofMain.h"
#include "ofApp.h"

int main() {

    ofGLWindowSettings settings;
    settings.width = 1024;
    settings.height = 768;
    settings.title = " ";
    ofCreateWindow(settings);

	ofRunApp(new ofApp());

}
