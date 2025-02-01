#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void generateRandomNumbers();  // Function to generate random numbers

private:
	std::vector<int> numbers;      // Stores the random numbers (circle radii)
	std::vector<ofVec2f> positions; // Stores circle positions

	bool sorting = false; // Flag to track sorting state
	int currentStep = 0;  // Step counter for sorting
	void bubbleSortStep(); // Function to perform one step of Bubble Sort

private:
	bool inserting = false; // Flag to track sorting state
	int insertIndex = 1;  // Step counter for Insertion Sort
	void insertionSortStep(); // Function to perform one step of Insertion Sort
		
};
