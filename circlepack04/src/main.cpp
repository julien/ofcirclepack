#include "ofMain.h"
#include "ofApp.h"

int main( ){

    ofGLFWWindowSettings settings;
    settings.width = 1024;
    settings.height = 768;
    settings.title = " ";
    settings.resizable =  false;
    ofCreateWindow(settings);

    ofRunApp(new ofApp());
}
