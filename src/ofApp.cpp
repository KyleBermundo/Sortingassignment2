#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    generateRandomNumbers();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30); // this is for a dark backround

    for (int i = 0; i < numbers.size(); i++) {
        ofSetColor(0, 150, 255); // for blue circles
        ofDrawCircle(positions[i].x, positions[i].y, numbers[i]); // Draw circles

        // this is to draw inside the circle
        ofSetColor(255); // for white text for the numbers
        ofDrawBitmapString(ofToString(numbers[i]), positions[i].x - 10, positions[i].y + 5);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::generateRandomNumbers() {
    numbers.clear();
    positions.clear();

    int spacing = ofGetWidth() / 6; // Divide width into 6 sections for spacing

    for (int i = 0; i < 5; i++) {
        int randNum = ofRandom(10, 100); // Generate random number
        numbers.push_back(randNum);

        // Calculate x position and keep circles centered vertically
        positions.push_back(ofVec2f((i + 1) * spacing, ofGetHeight() / 2));
    }
}
