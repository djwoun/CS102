// lab3b.cpp
// The program asks the user for a seed. Then the program asks for a bet. Depending on the random numbers, the program decides if you win the bet or not. The Winning is added to the user's # of coins. The game takes track of the player's wagers and winnings. The player's wager and winning informations are posted at the end.
// Dong Jun Woun
// 09/24/2020
#include <iostream>
#include <random>
#include<vector>
using namespace std;
int main()
{
	// Created variable seed / Ask for user input for seed
	int seed;
	cout << "Input a seed: ";
	// Checks if input was a valid integer
	while (!(cin >> seed)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Input a seed: ";
	}
	cout << endl;


	// created variable betCoinm coin, gamesPlayed. Coin = # of coin of user/ betCoin = # of coin user bet/ gamesPlayed = # of games played
	int betCoin;
	int coin;
	int gamesPlayed = 0;
	coin = 100;

	// Create random number generator
	default_random_engine rng(seed);
	uniform_int_distribution<int> rand_int(2, 7);

	//created vector wager and wonCoins
	vector<int> wager;
	vector<int> wonCoins;

	do {


		// states how much coin the user has and asks the user to bet
		cout << "You currently possess " << coin << " coins." << endl;
		cout << "Bet how many coins? ";

		// error checking if the user inputed a correct bet
		while (!(cin >> betCoin) || !(betCoin >= 0) || !(betCoin <= coin)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bet how many coins? ";
		}

		 	// adds amount wagered to vector
		wager.push_back(betCoin);


		// if the user bet more than 0 and if the uesr bet less or equal to the number of coins they had
		if ((betCoin > 0) && (betCoin <= coin)) {


			// counts the number of coins after the user's bet
			coin = coin - betCoin;
			// tracks # of games played
			gamesPlayed = gamesPlayed + 1;


			// tracks the amount won for the single round
			int won;

			// out puts the 3 randomly generated #s
			int array[3] = { rand_int(rng), rand_int(rng), rand_int(rng) };
			for (int i = 0; i < 3; i++) {
				cout << ' ' << array[i] ;
			}
			cout << endl;


			// if 1=2, 2=3 , 1=3, is 1=2=3
			if (array[0] == array[1] && array[1] == array[2]) {
				int jackpot = 7;
				// if the three digits were identical but if the numbers were not 7
				if (!(jackpot == array[0])) {

					won = betCoin * 5;
					coin = coin + won;
					cout << "You won " << won << " coins!" << endl;
					cout << endl;
				}
				// if the three digits were identical and if the digits  were 7
				else if (jackpot == array[0]) {

					won = betCoin * 10;
					coin = coin + won;
					cout << "You won " << won << " coins!" << endl;
					cout << endl;
				}
			}
			else {
				// if the digits 0=1 or 0=1 or 1=2 (if there were two identical digits)
				if ((array[0] == array[1]) || (array[0] == array[2]) || (array[1] == array[2])) {
					won = betCoin * 2;
					coin = coin + won;
					cout << "You won " << won << " coins!" << endl;
					cout << endl;
				}
				// if the digits  0!= 1 ,  1!=2 => 0!=2 (if none of the digits match each other)
				else if (array[0] != array[1] && array[1] != array[2]) {
					won = 0;
					cout << "You did not win." << endl;
					cout << endl;
				}
			}


			wonCoins.push_back(won);

		}
		
		// game exits when user has 0 coins
		if (coin == 0) {
			betCoin = 0;
		}

		// game exits when user bets 0
	} while (betCoin != 0);
	cout << endl;


	// if the first bet input was 0 the program exits right away, but if the first was not 0 and a valid input the program states information about the game
	if (!(wager.at(0) == 0)) {
		cout << "Play Summary:" << endl;

		// the max/min wager and prize is set to the first game's results
		int maxW = wager.at(0);
		int minW = wager.at(0);
		int maxP = wonCoins.at(0);
		int minP = wonCoins.at(0);
		for (int k = 0; k < gamesPlayed; k++) {

			// states the game record
			cout << "You wagered " << wager.at(k) << " coins and won " << wonCoins.at(k) << " coins." << endl;

			// compares games to find the min/max wager and prize
			if (maxW < wager.at(k)) {
				maxW = wager.at(k);
			}
			if (minW > wager.at(k)) {
				minW = wager.at(k);
			}
			if (maxP < wonCoins.at(k)) {
				maxP = wonCoins.at(k);
			}
			if (minP > wonCoins.at(k)) {
				minP = wonCoins.at(k);
			}
		}
		cout << endl;

		// states the results of the comparison 
		cout << "Your minimum wager was " << minW << " coins." << endl;
		cout << "Your maximum wager was " << maxW << " coins." << endl;
		cout << "Your minimum prize was " << minP << " coins." << endl;
		cout << "Your maximum prize was " << maxP << " coins." << endl;
	}

	return 0;
}
