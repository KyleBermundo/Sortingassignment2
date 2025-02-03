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
//this is all to help make everything work without them we will be getting alot of errors.
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
		
private:
	bool merging = false; // Flag to track Merge Sort state
	void mergeSortStep(); // Function to perform one step of Merge Sort
	void mergeSortHelper(int left, int right); // Recursive helper for Merge Sort
	void merge(int left, int mid, int right); // Function to merge two halves

private:
	bool quickSorting = false; // Flag to track Quick Sort state
	void quickSortStep(); // Function to perform one step of Quick Sort
	void quickSortHelper(int low, int high); // Recursive helper for Quick Sort
	int partition(int low, int high); // Function to partition the array

	//from deepseek was asking how i would implement the delay for all the sorts (this includes the added step delay on the sort's code)
private:
	float stepDelay = 0.5f; // Delay in seconds between steps
	float lastStepTime = 0.0f; // Time of the last step

private:
	bool shuffling = false; // Flag to track shuffling state
	int shuffleIndex = 0;   // Index for Fisher-Yates Shuffle
	void fisherYatesShuffleStep(); // Function to perform one step of Fisher-Yates Shuffle
};
