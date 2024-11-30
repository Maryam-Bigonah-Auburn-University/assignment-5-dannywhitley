#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function declaration, replaces all 4 letter words in a line with love
void loveLove(string& userString);

int main() {
	// Variable declaration
	string line;

	// Displays message and gets line
	cout << "Enter a line of text to be altered." << endl;
	getline(cin, line);

	// Calls the function
	loveLove(line);

	cout << line << endl;

	return 0;
}

void loveLove(string& userString) {
	// Local variable declaration
	int letterCount = 0;

	// Helps address if a 4 letter word appears at the end of the string
	userString += "\n";

	// Loops through all letters in the string
	for (int i = 0; i < userString.length(); i++) {
		// Counts the letters in each word
		if (isalpha(userString[i])) {
			letterCount += 1;
		}
		else {
			// Replaces a 4 letter word with love or Love
			if (islower(userString[i-4]) && (letterCount == 4)) {
				userString.replace(i-4, 4, "love");
			}
			if (isupper(userString[i - 4]) && (letterCount == 4)) {
				userString.replace(i-4, 4, "Love");
			}
			
			// Resets the letter count
			letterCount = 0;
		}
	}
}
