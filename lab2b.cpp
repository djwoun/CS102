// lab2b.cpp
// 1. The program will first ask for a user input. 1a. After the input the program does error checking.
// 2. Checks if i is between 1-999 2. Checks if i is between 1-99 or 100-999(2a.checks if i%100 = 0). If it fails the not a valid interstate number will be outputted.
// 3. Checks if Number % 2 is 0 or 1 to determine even/odd and state the primary/auxiliary and direction. Each time an invalid is number is inputted, the not a valid statement gets outputted.
// Dong Jun Woun
// 09/19/2020
#include <iostream>
#include<string>
#include<sstream>
#include<limits>
using namespace std;
int main()
{

	// 1. i stores user input / Program asks user to input an interstate number
	// 1a. Error checking correct input (reasks number until correct user puts in correct input)
	int i;
	do {
		cout << "Enter an interstate number: ";
		while (!(cin >> i)) {
			// Clear the error flag
			cin.clear();
			// Clear user input in buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Not a valid integer, try again: ";
		}

		// 2. If i is between 1-999 
		if (i > 0 && i < 1000) {


			// 2. If i is between 1-99
			if (i >= 1 && i <= 99) {

				// 3. Checks if Number % 2 is 0 or 1 to determine even/odd and state the primary/auxiliary and direction.    
				int checkDirection;
				checkDirection = i % 2;

				if (checkDirection == 0) {
					cout << "I-" << i << " is a primary interstate, going east/west." << endl;
				}
				else if (checkDirection == 1) {
					cout << "I-" << i << " is a primary interstate, going north/south." << endl;
				}
			}
			// 2. If i is between 100-999
			else if (i >= 100 && i <= 999) {
				// 2a.checks if the number is divisible by 100
				int check100;
				check100 = i % 100;
				if (check100 == 0) {
					cout << i << " is not a valid interstate number." << endl;
				}

				// 3. Checks if Number % 2 is 0 or 1 to determine even/odd and state the primary/auxiliary and direction.
				else {
					int checkDirection;
					checkDirection = i % 2;
					// i % 100 results in the primary Interstate number
					int primaryInterstate;
					primaryInterstate = i % 100;

					if (checkDirection == 0) {
						cout << "I-" << i << " is an auxiliary highway, serving I-" << primaryInterstate << ", going east/west." << endl;
					}
					else if (checkDirection == 1) {
						cout << "I-" << i << " is an auxiliary highway, serving I-" << primaryInterstate << ", going north/south." << endl;
					}
				}
			}
		}
		// 2. Not a valid interstate number statement 
		else if (i != 0) {
			cout << i << " is not a valid interstate number." << endl;
		}


	} while (i != 0);
	return 0;
}
