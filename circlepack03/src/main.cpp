#include "ofMain.h"
#include "ofApp.h"

int main( ){

    ofGLFWWindowSettings settings;
    settings.width = 800;
    settings.height = 600;
    settings.title = " ";
    ofCreateWindow(settings);

    ofRunApp(new ofApp());
}
