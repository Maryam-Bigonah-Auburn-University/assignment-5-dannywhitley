#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

// Function declaration, takes the file streams as arguments
void sortData(ifstream& input1, ifstream& input2, ofstream& output);

int main() {
	// Declares file streams
	ifstream inStream1, inStream2;
	ofstream outStream;

	// Opens the file streams
	inStream1.open("file1.txt");
	inStream2.open("file2.txt");
	outStream.open("file3.txt");

	// Makes sure that the files can be opened
	if (inStream1.fail() || inStream2.fail()) {
		cout << "Input files failed to open. Program terminated." << endl;
		exit(1);
	}

	if (outStream.fail()) {
		cout << "output file failed to open. Program terminated." << endl;
		exit(1);
	}

	// Calls the function
	sortData(inStream1, inStream2, outStream);

	// Closes the file streams 
	inStream1.close();
	inStream2.close();
	outStream.close();

	// Displays the message
	cout << "The data from file1.txt and file2.txt have been sorted into file3.txt. The file streams have been closed. Program terminated." << endl;
	
	return 0;
}

// Function definition, sorts integers in ascending order 
// from the input and puts them in the output
void sortData(ifstream& input1, ifstream& input2, ofstream& output) {
	// Local variable declarations
	vector<int> nums;
	int max, index, val;

	// Reads in data from the input files into the vector
	while (!input1.eof()) {
		input1 >> val;
		nums.push_back(val);
	}

	while (!input2.eof()) {
		input2 >> val;
		nums.push_back(val);
	}

	// Sorts the data in the vector by moving the max value to the end
	// then looking at one less number of elements
	for (int i = nums.size() - 1; i >= 1; i--) {
		max = nums[0];
		index = 0;
		for (int j = 0; j <= i; j++) {
			if (nums[j] > max) {
				max = nums[j];
				index = j;
			}
		}
		// Moves the max to the end of the vector
		nums[index] = nums[i];
		nums[i] = max;
	}

	// Sends the sorted data to the output
	for (int i = 0; i < nums.size(); i++) {
		output << nums[i] << " ";
	}
}
