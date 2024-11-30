#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

// Function declaration, takes input stream as an argument
void askQuestion(ifstream& input);

int main() {
	// Declares file stream and opens the file
	ifstream inStream;
	inStream.open("answers.txt");

	// Makes sure that the file can be read
	if (inStream.fail()) {
		cout << "File failed to open." << endl;
		exit(1);
	}

	askQuestion(inStream);

	// Displays the message
	inStream.close();
	cout << "The file stream has been closed and the program has been terminated." << endl;

	return 0;
}

// Function definition
void askQuestion(ifstream& input) {
	// Local variable declarations
	char ans;
	string question, answer;

	// Displays message and sets loop control
	cout << "Would you like to ask a question? (yes/no): ";
	cin.get(ans);

	// Repeats taking user questions
	while ((ans == 'Y') || (ans == 'y')) {
		// Prompts the user to enter a question
		cout << "What is your question?" << endl;
		cin.ignore();
		getline(cin, question, '?');

		// Gets an answer from the input stream
		getline(input, answer);

		// Displays the answer 
		cout << answer << endl;

		// Makes sure the end of file isn't reached
		if (input.eof()) {
			input.close();
			input.open("answers.txt");
		}

		// Prompts the user for the loop control
		cout << "Would you like to ask another question? (yes/no): ";
		cin.ignore();
		cin.get(ans);
	}
}
