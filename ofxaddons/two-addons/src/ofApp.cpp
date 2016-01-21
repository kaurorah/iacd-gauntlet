#include "ofApp.h"

void ofApp::setup()
{
    
    
    ofSetWindowPosition(0, 0);

    
    isGravity = false;
    
    
    box2d.init();
    box2d.setGravity(10, 10);
    box2d.setFPS(60.0);
    box2d.registerGrabbing();
    
    anchor.setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, 4);
    
    // first we add just a few circles
    for (int i=0; i<3; i++) {
        shared_ptr<ofxBox2dCircle> circle = shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle);
        circle.get()->setPhysics(3.0, 0.53, 0.1);
        circle.get()->setup(box2d.getWorld(), ofGetWidth()/2, 100+(i*20), 8);
        circles.push_back(circle);
    }
    
    // now connect each circle with a joint
    for (int i=0; i<circles.size(); i++) {
        
        shared_ptr<ofxBox2dJoint> joint = shared_ptr<ofxBox2dJoint>(new ofxBox2dJoint);
        
        // if this is the first point connect to the top anchor.
        if(i == 0) {
            joint.get()->setup(box2d.getWorld(), anchor.body, circles[i].get()->body);
        }
        else {
            joint.get()->setup(box2d.getWorld(), circles[i-1].get()->body, circles[i].get()->body);
        }
        
        joint.get()->setLength(25);
        joints.push_back(joint);
    }

    toggle = new ofxDatGuiToggle("TOGGLE GRAVITY", false);
    
    toggle->setTheme(new ofxDatGuiThemeCandy());
    
    positionButtons();
    
    toggle->onButtonEvent(this, &ofApp::onButtonEvent);
}

void ofApp::update(){
    box2d.update();
    toggle->update();

}

void ofApp::draw(){
//    ofSetHexColor(0xf2ab01);
    anchor.draw();
    toggle->draw();

    

    for(int i=0; i<circles.size(); i++) {
//        ofFill();
//        ofSetHexColor(0x01b1f2);
        circles[i].get()->draw();
    }
    
    for(int i=0; i<joints.size(); i++) {
        ofSetHexColor(0x444342);
        joints[i].get()->draw();
    }
    
    string info = "";
    info += "Press [n] to add a new joint\n";
    info += "click and pull the chain around\n";
    info += "FPS: "+ofToString(ofGetFrameRate(), 1)+"\n";
    ofSetHexColor(0x444342);
    ofDrawBitmapString(info, ofGetWidth()/2 - toggle->getWidth()/2, ofGetHeight()/2+(ofGetHeight()/4 + 100) - toggle->getHeight());

}

void ofApp::keyPressed(int key){
    if(key == 'n') {
        
        // add a new circle
        shared_ptr<ofxBox2dCircle> circle = shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle);
        circle.get()->setPhysics(3.0, 0.53, 0.1);
        circle.get()->setup(box2d.getWorld(), circles.back().get()->getPosition().x+ofRandom(-30, 30), circles.back().get()->getPosition().y-30, 8);
        circles.push_back(circle);
        
        // get this cirlce and the prev cirlce
        int a = (int)circles.size()-2;
        int b = (int)circles.size()-1;
        
        // now connect the new circle with a joint
        shared_ptr<ofxBox2dJoint> joint = shared_ptr<ofxBox2dJoint>(new ofxBox2dJoint);
        joint.get()->setup(box2d.getWorld(), circles[a].get()->body, circles[b].get()->body);
        joint.get()->setLength(25);
        joints.push_back(joint);
    }

}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{

    if(e.target->getLabel() == "TOGGLE GRAVITY"){
        isGravity =!isGravity;
        box2d.setGravity(0, 0);
        if (!isGravity) {
            box2d.setGravity(10, 10);
            isGravity == true;
        }
        positionButtons();
    }
}

void ofApp::positionButtons()
{
    toggle->setPosition(ofGetWidth()/2 - toggle->getWidth()/2, ofGetHeight()/2+(ofGetHeight()/4) - toggle->getHeight());
    
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::resized(int w, int h){
}