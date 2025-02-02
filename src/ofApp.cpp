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
    if (merging) {
        mergeSortStep();
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
    else if (key == 'm' && !merging) { // Merge Sort
        merging = true;
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
//-------------------------------------------------------------------
// merge sort step
void ofApp::mergeSortStep() {
    if (merging) {
        mergeSortHelper(0, numbers.size() - 1); // Start Merge Sort
        merging = false; // Stop sorting when done
    }
}
//--------------------------------------------------------------------
//sort helper for merge
void ofApp::mergeSortHelper(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point
        mergeSortHelper(left, mid); // Sort the first half
        mergeSortHelper(mid + 1, right); // Sort the second half
        merge(left, mid, right); // Merge the sorted halves
    }
}
//---------------------------------------------------------------------
//merge function
void ofApp::merge(int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // create temporary arrays
    std::vector<int> leftArray(n1), rightArray(n2);

    // copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArray[i] = numbers[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = numbers[mid + 1 + i];
    }
    // merge the temporary arrays back into numbers[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            numbers[k] = leftArray[i];
            i++;
        }
        else {
            numbers[k] = rightArray[j];
            j++;
        }
        k++;
    }
    // copy remaining elements of leftArray, if any
    while (i < n1) {
        numbers[k] = leftArray[i];
        i++;
        k++;
    }

    // copy remaining elements of rightArray, if any
    while (j < n2) {
        numbers[k] = rightArray[j];
        j++;
        k++;
    }
}
//------------------------------------------------------------------------
