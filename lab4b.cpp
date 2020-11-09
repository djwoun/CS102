// lab4b.cpp
// The program asks the user for a text file input. The program attempts to open the file that was specified. The user is than asked for an option input. The user can get the number of words, number of non-whitespace characters, replace a character, or quit. The progarm quits with either q or ctrl D
// Dong Jun Woun
// 10/20/2020
#include <iostream>
#include<string>
#include<sstream>
#include<limits>
#include<fstream>
#include<vector>
using namespace std;
int NumWords(const string&);
int NumNonWSCharacters(const string&);
void CharReplace(string&, char, char);
char PrintMenu();



int main()
{

	vector<string> words;
	// string textFile, ask user for text file name and attempts to open the file
	string textFile;
	cout << "Enter a text file to read: ";
	getline(cin, textFile);
	ifstream in(textFile);

	// if the program fails to open the file, the program exits
	if (!in) {
		cerr << "Unable to open file: " << textFile << endl;;
		return 1;
	}
	cout << endl;


	// using string word(no s) to load vector words with the text from the text file
	string word;
	while (getline(in, word))
	{
		if (word.size() > 0) {
			words.push_back(word);
		}
	}
	in.close();



	// out puts what was read from the text file
	cout << textFile << " contains:" << endl;
	for (unsigned int i = 0; i < words.size(); ++i) {
		cout << words.at(i) << endl;;
	}




	char option;
	// prints option menu
	PrintMenu();
	// allows the program to exit when user presses ctrl D and q and allows the user enter option
	while ((cin >> option) && !(option == 'q')) {


		// if one of the available options was not provided, the program asks for another option
		if (!((option == 'r') || (option == 'c') || (option == 'w'))) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			PrintMenu();
			continue;
		}


		// using switch statement to check the user's menu option choice
		switch (option) {
			case 'w':
				{
					cout << endl;

					// NumWords(words.at(i)) returns the number of words per line. So netWords can add up all the words for every line.
					int netWords = 0;
					for (unsigned int i = 0; i < words.size(); ++i) {
						netWords = netWords + NumWords(words.at(i));
					}
					cout << "Number of words: " << netWords;
					cout << endl;
				}
				break;
			case 'c':
				{
					cout << endl;
					int NumTotalNonWhite = 0;

					//NumNonWSCharacters(words.at(i)) returns the number of non whitespace characters. So NumTotalNonWhite can add up all the non whitespace characters for every line.
					for (unsigned int i = 0; i < words.size(); ++i) {
						NumTotalNonWhite = NumTotalNonWhite + NumNonWSCharacters(words.at(i));
					}
					cout << "Number of non-whitespace characters: " << NumTotalNonWhite << endl;
				}
				break;

			case 'r':
				{
					char replace;
					char replaced;

					//user is asked for a character to replace and replace with

					cout << "Enter a character to find: ";
					cin >> replace;

					cout << "Enter a character to replace: ";
					cin >> replaced;

					cout << endl;
					for (unsigned int i = 0; i < words.size(); ++i) {
						CharReplace(words.at(i), replace, replaced);
					}
					cout << "New contents: " << endl;
					for (unsigned int i = 0; i < words.size(); ++i) {
						cout << words.at(i) << endl;
					}
				}
				break;

		}

		PrintMenu();

	}



	// tries to open output.txt and write the words on to output.txt
	ofstream ofs("output.txt");
	if (!ofs) {
		cerr << "Unable to open output.txt.\n";
		return 1;
	}

	for (unsigned int i = 0; i < words.size(); ++i) {
		ofs << words.at(i) << endl;
	}
	ofs.close();
	return 0;
}



int NumWords(const string& words) {
	//  create stringstream ss, put the original text into ss, and then extracted only text from ss into noSpace , each time a word is extracted the wordcounter goes up by 1
	stringstream ss;
	ss.str(words);
	string noSpace;
	int wordCounter = 0;
	while (ss >> noSpace) {
		wordCounter++;
	}

	return wordCounter;
}

int NumNonWSCharacters(const string& words) {
	//  create stringstream ss, put the original text into ss, and then extracted only text from ss into noSpace , each time a word is extracted the whiteSpaceCounter goes up by 1
	// Using this method counts the end of the last word as an white space as well, so whiteSpaceCounter starts at -1
	stringstream ss;

	ss.str(words);
	string noSpace;
	int whiteSpaceCounter = -1;
	while (ss >> noSpace) {
		whiteSpaceCounter++;
	}
	int NumNonWhite = 0;
	NumNonWhite = words.size() - whiteSpaceCounter;

	return NumNonWhite;
}

void CharReplace(string& words, char replace, char replaced) {
	// replaces anywhere there needs to be replaced
	for (unsigned int i = 0; i < words.size(); ++i) {
		if ((words.at(i) == replace)) {
			words.at(i) = replaced;
		}
	}

}

//option menu
char PrintMenu() {
	cout << endl;
	cout << "Options " << endl;
	cout << "w - Number of words " << endl;
	cout << "c - Number of non-whitespace characters" << endl;
	cout << "r - Replace a character" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
	cout << "Choose an option: ";



	return 0;
}

