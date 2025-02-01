#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    generateRandomNumbers();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (sorting) {
        bubbleSortStep();
    }
    if (inserting) {
        insertionSortStep();
    }
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
//this will randomize the numbners that have been made when initializing the program.
void ofApp::keyPressed(int key){
    if (key == 'r') {
        generateRandomNumbers();
    }
    else if (key == 'b' && !sorting) { //bubblesort button
        sorting = true;
        currentStep = 0; //to reset sorting progress
    }
    else if (key == 'i' && !inserting) {
        inserting = true;
        insertIndex = 1; //same thing as the previous sort it resets the progress
    }
    
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
//--------------------------------------------------------------
void ofApp::generateRandomNumbers() {
    numbers.clear();
    positions.clear();

    int spacing = ofGetWidth() / 6; // it creates spacing between each circle that is generated

    for (int i = 0; i < 5; i++) {
        int randNum = ofRandom(10, 100); // Generate random number
        numbers.push_back(randNum);

        // Calculate x position and keep circles centered vertically
        positions.push_back(ofVec2f((i + 1) * spacing, ofGetHeight() / 2));
    }
}
//----------------------------------------------------------------
void ofApp::bubbleSortStep() {
    if (sorting) {
        bool swapped = false;

        for (int j = 0; j < numbers.size() - 1 - currentStep; j++) {
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }

        currentStep++; //moves on to the next step

        if (!swapped || currentStep >= numbers.size()) {
            
            sorting = false; //to stop if its done
        }
    }
}
//-----------------------------------------------------------------
void ofApp::insertionSortStep() {
    if (inserting) {
        if (insertIndex < numbers.size()) {
            int key = numbers[insertIndex];
            int j = insertIndex - 1;

            while (j >= 0 && numbers[j] > key) {
                numbers[j + 1] = numbers[j]; //this will shift the largest numbers to the right
                j--;
            }
            numbers[j + 1] = key; //places the key at the right position

            insertIndex++; //moves on to the next step
        }
        else {
            inserting = false; //stops the sorting when done
        }
    }
}
