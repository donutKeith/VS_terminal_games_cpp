/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/
#include <iostream>
#include "GameVars.h"
#include "TicTacToe.h"

using namespace std;

char TTT::marks[TTT::NUM_SPACES];        // Array to hold the marks made by the player

										 // TIC TAC TOE DEFINED BELOW ============================================================
bool TTT::Play_TIC_TAC_TOE() {// Returns true when the game is over 
	int spot;       // holder for player input as far as which spot on the board they would like to mark as their own
	bool validSpot; // Flag to determine if the player has picked a valid spot

					// Initialize the game , Sets up board and player symbols
	TTT::StartGame_TIC_TAC_TOE();

	// MAIN GAME LOOP - Loop while the game is being played
	while (!isGameOver) {
		// This loop should run once per player's turn
		validSpot = false;// Set to false originally because the player has not picked their spot yet
		while (!validSpot) {
			// 1. Draw the board for the player. The argument is what decides if 
			//    we draw the instructions showing what number corresponds to what spot
			TTT::DrawBoard(true);

			// 2. Specify who's turn it is and ask them where they would like to go
			if (playerTurn == 0) {
				cout << "Player 1: ";
			}
			else {
				cout << "Player 2: ";
			}

			cout << endl;
			cout << "Where would you like to go?";
			cout << endl;

			// 3. Read in the player's choice and validate that choice
			cin >> spot;
			validSpot = MarkSpot(playerTurn, spot);
		}

		// End this players turn. Switch to the next player and repeat the previous steps
		playerTurn = (playerTurn + 1) % NUM_PLAYERS;
		// Check if a player has won or all the spots are filled now that their turn is over
		DetermineGameOver();
	}
	return isGameOver;
}
// -----------------------------------------------------------------------------------------------

// Sets some default parameters for the game to start
void TTT::StartGame_TIC_TAC_TOE() {
	int counter = 0;
	isGameOver = false; // Set game state to true since we are starting a new game

						// Fill the marks array with default (EMPTY spaces))
	while (counter < TTT::NUM_SPACES) {
		TTT::marks[counter] = TTT::EMPTY_SPOT;
		counter = counter + 1;
	}

	// Prompt player to pick their character
	GetPlayerSymbols();

	// Set which player goes first [player1 = 0, player2 = 1]
	playerTurn = 0; //Player 1 gets to go first
}
// -----------------------------------------------------------------------------------------------
// Draw the board to the screen.
void TTT::DrawBoard(bool drawWithHelp) {
	// drawWithHelp is a flag to determine if you want to just draw the game board
	//  or if you want to draw the game board along with the board that shows which 
	//  spot corresponds to which number 0-8   
	int rowNum = 0;
	while (rowNum < TTT::NUM_ROWS) {
		TTT::DrawRow(rowNum, false);
		if (drawWithHelp == true) {
			cout << "         ";
			TTT::DrawRow(rowNum, true);
		}
		cout << endl;
		rowNum = rowNum + 1;
	}
}
// -----------------------------------------------------------------------------------------------

void TTT::DrawRow(int row, bool drawHelp) {
	int colCounter = row * TTT::NUM_ROWS;
	int counter = 0;
	while (counter < TTT::NUM_COLS) {
		if (row == TTT::NUM_ROWS - 1) { // If this is the last row do not draw the "_"s
			TTT::DrawSpot(' ', colCounter, drawHelp);
		}
		else {
			TTT::DrawSpot(TTT::EMPTY_SPOT, colCounter, drawHelp);
		}
		counter = counter + 1;
		if (counter < TTT::NUM_COLS) {
			cout << '|';
		}
		colCounter = colCounter + 1;

	}
}
// -----------------------------------------------------------------------------------------------

void TTT::DrawSpot(char boardCharacter, int spotNum, bool drawHelp) {
	cout << boardCharacter;
	if (drawHelp) {
		cout << spotNum;
	}
	else {
		// If this is the last row and there are no marks do not draw anything 
		//   else draw whatever is populated in marks[spotNum]
		// (We have do to this check or else _s will be drawn as player marks
		//  in the last row since marks is populated with "_" by default)
		if (boardCharacter == ' ' && TTT::marks[spotNum] == TTT::EMPTY_SPOT) {
			cout << " ";
		}
		else {
			cout << TTT::marks[spotNum];
		}
	}
	cout << boardCharacter;
}
// -----------------------------------------------------------------------------------------------

bool TTT::MarkSpot(int player, int spot) {
	bool isChoiceAllowed = false;

	if (spot >= 0 && spot < TTT::NUM_SPACES) {
		if (TTT::marks[spot] == TTT::EMPTY_SPOT) {
			isChoiceAllowed = true;

			if (player == 0) {
				TTT::marks[spot] = player1Mark;
			}
			else {
				TTT::marks[spot] = player2Mark;
			}
		}
		else {
			cout << "You Cannot go there. It is already marked!";
			cout << endl;
		}
	}
	return isChoiceAllowed;
}
// -----------------------------------------------------------------------------------------------

int TTT::DetermineGameOver() {
	bool isBoardFull = true;
	bool winnerFound = false;

	// Determine if the board is full
	int counter = 0;
	while (counter < TTT::NUM_SPACES && isBoardFull == true) {
		// Check each space until we find an empty space (aka marks[counter] is equal to "_" )
		// Once we have found a blank space we know it is not full and we exit the loop
		// Otherwise we keep checking and if we check all the spaces without hitting
		//   a blank space we know it is full
		if (TTT::marks[counter] == TTT::EMPTY_SPOT) {
			isBoardFull = false;
		}
		counter = counter + 1;
	}

	// Check if there is a winner ==============================================================
	// Check the rows 
	winnerFound = TTT::CheckRows();

	// Check the columns if we did not find a winner by rows
	if (winnerFound == false) {
		winnerFound = TTT::CheckCols();
	}

	// Check the diagonals if we still did not find a winner
	if (winnerFound == false) {
		winnerFound = TTT::CheckDiags();
	}
	// =========================================================================================

	if (isBoardFull || winnerFound) {
		isGameOver = true;
		TTT::DrawBoard(false);
		cout << "GAME OVER!";
		cout << endl;
	}
	return 0;
}
// -----------------------------------------------------------------------------------------------

bool TTT::CheckRows() {
	bool winnerFound = false;
	int startIndex;
	int counter;
	char firstChar;

	int rowNum = 0;
	while (rowNum < TTT::NUM_ROWS && winnerFound == false) {
		startIndex = rowNum * TTT::NUM_COLS;

		firstChar = TTT::marks[startIndex];

		if (firstChar != TTT::EMPTY_SPOT) {//First spot is blank no need to check for a winner

			winnerFound = true;
			counter = startIndex;
			while (counter < startIndex + TTT::NUM_COLS) {
				if (firstChar != TTT::marks[counter]) {
					winnerFound = false;
				}
				counter = counter + 1;
			}
		}
		else {// This means that the first spot in the row is blank
			winnerFound = false;
		}
		rowNum = rowNum + 1;
	}
	if (winnerFound == true) {
		cout << "Win by row:";
		TTT::DisplayWinnerMessage(firstChar);
	}
	return winnerFound;
}
// -----------------------------------------------------------------------------------------------

bool TTT::CheckCols() {
	int curCol = 0;
	int curRow;
	int spot;
	bool winnerFoundByCols = false;
	char firstChar;

	while (curCol < TTT::NUM_COLS && winnerFoundByCols == false) {
		spot = curCol;
		firstChar = TTT::marks[spot];

		if (firstChar != TTT::EMPTY_SPOT) {
			winnerFoundByCols = true;
			curRow = 0;
			while (curRow < TTT::NUM_ROWS && winnerFoundByCols == true) {

				if (firstChar != TTT::marks[spot]) {
					winnerFoundByCols = false;
				}
				spot = spot + TTT::NUM_COLS;
				curRow = curRow + 1;
			}
		}
		curCol = curCol + 1;
	}
	if (winnerFoundByCols == true) {
		cout << "Win by column:";
		DisplayWinnerMessage(firstChar);
	}
	return winnerFoundByCols;
}
// -----------------------------------------------------------------------------------------------

bool TTT::CheckDiags() {
	bool winnerFoundOnDiag;
	char middle = TTT::marks[4];// Both diagonals need the middle to win so we will check the corners against the middle to determine victory

								// We do not need to check anything if the middle is empty
	if (middle != TTT::EMPTY_SPOT) {
		if ((middle == TTT::marks[0] && middle == TTT::marks[8]) || (middle == TTT::marks[2] && middle == TTT::marks[6])) {
			winnerFoundOnDiag = true;
		}
		else {
			winnerFoundOnDiag = false;
		}
	}

	if (winnerFoundOnDiag) {
		cout << "Diagonal Win!:";
		TTT::DisplayWinnerMessage(middle);
	}
	return winnerFoundOnDiag;
}
// -----------------------------------------------------------------------------------------------

void TTT::DisplayWinnerMessage(char winningChar) {
	cout << endl;
	cout << "WINNER IS: Player ";
	if (winningChar == player1Mark) {
		cout << "1";
	}
	else {
		cout << "2";
	}
	cout << endl;
}
// END OF TIC TAC TOE FUNCTION DEFINITIONS ========================================================