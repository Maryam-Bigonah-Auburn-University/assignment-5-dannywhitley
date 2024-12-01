#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

// Function declaration, takes a string argument and fixes spacing and capitalization
string fixSentence(string userString);

int main() {
	// Variable declarations
	string sentence;

	// Displays message
	cout << "Enter a sentence up to 100 characters terminated by a period." << endl;
	// Gets the sentence
	getline(cin, sentence, '.');
	cout << endl;

	// Calls the function
	sentence  = fixSentence(sentence);

	// Displays the corrected sentence
	cout << "Your corrected sentence is:" << endl;
	cout << sentence << endl;

	return 0;

}

// Function definition
string fixSentence(string userString) {
	// Local variable declarations
	string newString, anotherNewString;
	bool isWord = false, isSpace = false;

	// Control loop
	while (userString.length() > 100) {
		cout << "Your sentence was too long. Try again." << endl;
		getline(cin, userString, '.');
	}

	// Used to remove all the extra spaces 
	for (int i = 0; i < userString.length(); i++) {
		// Triggers if a letter is detected
		if (isalpha(userString[i])) {
			isWord = true;
			isSpace = false;
			newString += userString[i];
		}
		// Triggers if punctuation is detected
		if (ispunct(userString[i])) {
			newString += userString[i];
			isWord = false;
			isSpace = false;
		}
		// Triggers if a space is detected and the previous element was not a space
		if (isspace(userString[i]) && !isSpace) {
			isWord = false;
			isSpace = true;
			newString += userString[i];
		}
	}

	// Corrects capitalization in the sentence
	for (int i = 0; i < newString.length(); i++) {
		if (i == 0) {
			anotherNewString += toupper(newString[i]);
		}
		else {
			anotherNewString += tolower(newString[i]);
		}
	}

	// Adds a period
	anotherNewString += '.';

	// returns the corrected sentence
	return anotherNewString;
}
