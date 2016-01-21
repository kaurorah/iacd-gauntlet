
#pragma once

#include "ofMain.h"

#include "ofxAssimpModelLoader.h"
#include "ofxFirstPersonCamera.h"
#include "ofxManipulator.h"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void draw();
    void keyPressed(ofKeyEventArgs&);
    void mousePressed(ofMouseEventArgs&);
    
    ofLight m_light;
    ofImage m_matcapImage;
    ofShader m_matcapShader;
    ofMatrix4x4 m_modelMatrix;
    ofxAssimpModelLoader m_model;
    ofxFirstPersonCamera m_cam;
    ofxManipulator m_gizmo;
    
};
