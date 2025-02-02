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
    if (quickSorting) {
        quickSortStep();
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
    else if (key == 'b' && !sorting) { // Bubble Sort
        sorting = true;
        currentStep = 0;
        lastStepTime = ofGetElapsedTimef(); // Reset the timer
    }
    else if (key == 'i' && !inserting) { // Insertion Sort
        inserting = true;
        insertIndex = 1;
        lastStepTime = ofGetElapsedTimef(); // Reset the timer
    }
    else if (key == 'm' && !merging) { // Merge Sort
        merging = true;
        lastStepTime = ofGetElapsedTimef(); // Reset the timer
    }
    else if (key == 'q' && !quickSorting) { // Quick Sort
        quickSorting = true;
        lastStepTime = ofGetElapsedTimef(); // Reset the timer
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
        float currentTime = ofGetElapsedTimef(); // Get the current time
        if (currentTime - lastStepTime >= stepDelay) { // Check if delay has passed
            bool swapped = false;

            for (int j = 0; j < numbers.size() - 1 - currentStep; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    std::swap(numbers[j], numbers[j + 1]);
                    swapped = true;
                }
            }

            currentStep++; // Move to the next step
            lastStepTime = currentTime; // Update the last step time

            if (!swapped || currentStep >= numbers.size()) {
                sorting = false; // Stop sorting if done
            }
        }
    }
}
//-----------------------------------------------------------------
void ofApp::insertionSortStep() {
    if (inserting) {
        float currentTime = ofGetElapsedTimef(); // Get the current time
        if (currentTime - lastStepTime >= stepDelay) { // Check if delay has passed
            if (insertIndex < numbers.size()) {
                int key = numbers[insertIndex];
                int j = insertIndex - 1;

                while (j >= 0 && numbers[j] > key) {
                    numbers[j + 1] = numbers[j]; // Shift elements to the right
                    j--;
                }
                numbers[j + 1] = key; // Place the key in the correct position

                insertIndex++; // Move to the next step
                lastStepTime = currentTime; // Update the last step time
            }
            else {
                inserting = false; // Stop sorting if done
            }
        }
    }
}

//-------------------------------------------------------------------
// merge sort step
void ofApp::mergeSortStep() {
    if (merging) {
        float currentTime = ofGetElapsedTimef(); // Get the current time
        if (currentTime - lastStepTime >= stepDelay) { // Check if delay has passed
            mergeSortHelper(0, numbers.size() - 1); // Start Merge Sort
            merging = false; // Stop sorting when done
            lastStepTime = currentTime; // Update the last step time
        }
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

    // Create temporary arrays
    std::vector<int> leftArray(n1), rightArray(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArray[i] = numbers[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = numbers[mid + 1 + i];
    }

    // Merge the temporary arrays back into numbers[left..right]
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

    // Copy remaining elements of leftArray, if any
    while (i < n1) {
        numbers[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray, if any
    while (j < n2) {
        numbers[k] = rightArray[j];
        j++;
        k++;
    }
}
//------------------------------------------------------------------------
// Quick Sort Step
void ofApp::quickSortStep() {
    if (quickSorting) {
        float currentTime = ofGetElapsedTimef(); // Get the current time
        if (currentTime - lastStepTime >= stepDelay) { // Check if delay has passed
            quickSortHelper(0, numbers.size() - 1); // Start Quick Sort
            quickSorting = false; // Stop sorting when done
            lastStepTime = currentTime; // Update the last step time
        }
    }
}
//-------------------------------------------------------------------------
// Recursive Quick Sort Helper
void ofApp::quickSortHelper(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high); // Partition the array
        quickSortHelper(low, pivotIndex - 1); // Sort the left subarray
        quickSortHelper(pivotIndex + 1, high); // Sort the right subarray
    }
}
//----------------------------------------------------------------------------
// Partition Function
int ofApp::partition(int low, int high) {
    int pivot = numbers[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (numbers[j] < pivot) {
            i++;
            std::swap(numbers[i], numbers[j]); // Swap elements
        }
    }
    std::swap(numbers[i + 1], numbers[high]); // Place the pivot in the correct position
    return i + 1; // Return the pivot index
}