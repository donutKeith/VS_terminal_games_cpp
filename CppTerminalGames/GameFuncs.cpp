/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/
#include <iostream>
#include "GameVars.h"
#include <String>

using namespace std;

bool isGameOver;               // Determines game state (it either is being played or it is over)
int playerTurn;                // Determines which players turn it is

char player1Mark;              // The character player 1 uses to mark his/her spot
char player2Mark;              // The character player 2 uses to mark his/her spot

void GetPlayerSymbols() {
	bool validChar = false;
	string playerCharHold;

	cout << "Player 1 please enter the character you would like to use to mark the board:" << endl;
	cin >> playerCharHold;
	player1Mark = playerCharHold[0];
	playerCharHold = "";
	while (!validChar) {
		cout << "Player 2 please enter the character you would like to use to mark the board:" << endl;
		cin >> playerCharHold;
		player2Mark = playerCharHold[0];

		if (player2Mark == player1Mark) {
			cout << "Player 1 picked that symbol you should pick a different one." << endl;
		}
		else {
			validChar = true;
		}
	}
}