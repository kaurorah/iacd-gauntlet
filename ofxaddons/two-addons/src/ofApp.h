
#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxDatGui.h"



class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    
    ofxDatGuiButton* toggle;

    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void resized(int w, int h);
    
    ofxBox2d box2d;
    ofxBox2dCircle anchor;
    vector <shared_ptr<ofxBox2dCircle> > circles;
    vector <shared_ptr<ofxBox2dJoint> > joints;
    
    int numClicks;
    bool isGravity;
//    ofxDatGuiButton* button;
    void positionButtons();
    void onButtonEvent(ofxDatGuiButtonEvent e);
    
};
