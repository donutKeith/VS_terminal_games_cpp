/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   main.cpp
* Author: Keith
*
* Created on March 19, 2016, 1:44 PM
*/

#include <iostream>
#include <string>
#include "GameVars.h"
#include "TicTacToe.h"
#include "ConnectFour.h"
#include "Tetris.h"

using namespace std;

/*
*
*/
// Functions used for:


// Rock Paper Scissors ==========================================

// ==============================================================

// Global Variables ===================================================================================
// Variables used in all games
// Rock_Paper_Scissors Constants ----------------------------------------------------------------------
const char ROCK_IMG[2] = { '[', ']' };
const char PAPER_IMG[2] = { '{', '}' };
const char SCISSORS_IMG[2] = { '>', '8' };

// Rock_Paper_Scissors Variables ----------------------------------------------------------------------
int player1Choice;
int player2Choice;

// ====================================================================================================

int main(int argc, char** argv) {
	int gameChoice;
	bool validGameChoice = false;
	bool donePlaying = false;

	while (!donePlaying) {
		cout << "Which game do you want to play: (type the number to the left of the game you would like to play)";
		cout << endl;

		// Get user input for what game they would like to play, loop until they select a valid value
		while (!validGameChoice) {
			// List options for the player
			cout << "0: Done Playing Games";
			cout << endl;
			cout << "1: Tic Tac Toe";
			cout << endl;
			cout << "2: Connect Four";
			cout << endl;
			cout << "3: Tetris";
			cout << endl;

			// Get player choice
			cin >> gameChoice;

			// Check if it was a valid choice
			if (gameChoice >= 0 && gameChoice <= 3) {
				validGameChoice = true;
			}
			else {
				cout << "Invalid selection! Please choose a valid selection.";
				cout << endl;
			}
		}

		// Handle the users input and determine what game we should play
		switch (gameChoice) {
		case 0:
			donePlaying = true;
			cout << "Okay bye, Have a nice day!";
			break;
		case 1:// Play tic tac toe
			TTT::Play_TIC_TAC_TOE();
			validGameChoice = false;
			break;
		case 2:// Play connect 4
			CtFr::Play_ConnectFour();
			validGameChoice = false;
			break;
		case 3:
			Tet::Play_Tetris();
			validGameChoice = false;
			break;
		default:
			cout << "Unexpected Input! This should never happen since we checked this above but if this code gets modified it is an extra check";
			donePlaying = true;
			break;
		}
	}


	return 0;
}

// FUNCTION DEFINITIONS FOR:
// ROCK PAPER SCISSORS DEFINED BELOW ====================================================
bool RockPaperScissors() {
	//bool validRPS_Choice = false;
	//while(){

	//}
	//cout << "";
	//cout << endl;
	//cin >> player1Choice;
	//cout << "";
	//cout << endl;
	//cin >> player2Choice;
	return true;
}

void StartGame_RPS() {
	//playerTurn = 0;
	//isGameOver = false;
}
// ======================================================================================
// FUNCTION DEFINITIONS FOR:
/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

