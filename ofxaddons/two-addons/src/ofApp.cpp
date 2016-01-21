#include "ofApp.h"

void ofApp::setup()
{
    ofSetWindowPosition(
                        ( ofGetScreenWidth() -  ofGetWidth()) / 2.0f,
                        (ofGetScreenHeight() - ofGetHeight()) / 2.0f
                        );
    
    ofDisableArbTex();
    ofEnableLighting();
    ofSetBackgroundColor(28, 28, 38);
    
    m_cam.movespeed = 3.0f;
    m_cam.setNearClip(5.0f);
    m_cam.setFarClip(10000);
    m_cam.move(120, 120, 250);
    m_cam.lookAt(ofVec3f(0, 120, 0));
    
    m_light.setDirectional();
    m_light.rotate(180, 0, 1, 0);
    
    m_modelMatrix.scale(30, 30, 30);
    m_modelMatrix.rotate( 90, 1, 0, 0);
    m_modelMatrix.rotate(165, 0, 1, 0);
    m_modelMatrix.translate(0, 140, 0);
    
    m_matcapImage.load("MatCap.png");
    m_matcapShader.load("MatCap.vs", "MatCap.fs");
    
    m_model.loadModel("Edward_Joseph_Snowden.obj");
}

void ofApp::draw()
{
    m_cam.begin();
    
    m_light.enable();
    
    m_matcapShader.begin();
    m_matcapShader.setUniformTexture("litsphereTexture", m_matcapImage, 1);
    ofPushMatrix();
    ofMultMatrix(m_modelMatrix * m_gizmo.getMatrix());
    m_model.getMesh("").drawFaces();
    ofPopMatrix();
    m_matcapShader.end();
    
    m_light.disable();
    
    ofDisableLighting();
    ofDrawGrid(50, 10, false, true, true, false);
    m_gizmo.draw(m_cam);
    ofEnableLighting();
    
    m_cam.end();
}

void ofApp::keyPressed(ofKeyEventArgs &key)
{
    switch (key.keycode)
    {
        case (GLFW_KEY_1): m_gizmo.toggleScale(); break;
        case (GLFW_KEY_2): m_gizmo.toggleRotation(); break;
        case (GLFW_KEY_3): m_gizmo.toggleTranslation(); break;
    }
}

void ofApp::mousePressed(ofMouseEventArgs &mouse)
{
    switch (mouse.button)
    {
        case (OF_MOUSE_BUTTON_RIGHT): m_cam.toggleControl(); break;
    }
}