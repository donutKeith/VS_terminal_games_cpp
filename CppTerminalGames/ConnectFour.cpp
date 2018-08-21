/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/
// C++ defined includes
#include <iostream>
// User defined includes
#include "ConnectFour.h"
#include "GameVars.h"

using namespace std;

int CtFr::botPos[CtFr::NUM_COLS];
char CtFr::marks[CtFr::NUM_SPACES];

void CtFr::Play_ConnectFour() {
	int lastMove;
	// Initialize the game, Get the player symbols, set up game etc.
	CtFr::StartGame_ConnectFour();

	while (!isGameOver) {
		// Show board before player's turn
		CtFr::DrawBoard(CtFr::NUM_COLS, CtFr::NUM_ROWS);
		// Player makes a move, store the position the player chose in lastMove 
		//    (Note this is not the column the player chose, this is the actual index of the move))
		lastMove = CtFr::GetPlayerChoice(playerTurn);
		// Show board after player's turn
		CtFr::DrawBoard(CtFr::NUM_COLS, CtFr::NUM_ROWS);
		// Determine if the game is over
		if (!CtFr::DetermineGameState(lastMove)) {// If the game is  NOT over make it the next player's turn
			playerTurn = (playerTurn + 1) % NUM_PLAYERS;
		}
	}
}
void CtFr::StartGame_ConnectFour() {
	isGameOver = false;

	// Fill the marks array with empty spaces
	for (int i = 0; i < CtFr::NUM_SPACES; i++) {
		CtFr::marks[i] = CtFr::EMPTY_SPACE;
	}

	// Fill the botPos array with the bottom positions of all the columns (aka 1 - Number of columns on the board))
	for (int i = 0; i < CtFr::NUM_COLS; i++) {
		CtFr::botPos[i] = i;
	}

	GetPlayerSymbols();
}

int CtFr::GetPlayerChoice(int player) {
	bool validChoice = false;
	int choice;
	int pos = -1; // The index in which the last symbol was added

				  // We need to validate the user's choice
	while (!validChoice) {
		cout << "Please choose a column:";
		cout << endl;

		// Get the player's choice
		cin >> choice;

		//Check if the player's choice was valid ------------------------------------------
		// Did the user pick a valid column (aka a column that exists))
		if (choice < 0 || choice >= CtFr::NUM_COLS) {
			cout << "Invalid Column Choice Please select again!" << endl;
		}
		// Did the user pick a full column
		else if (CtFr::botPos[choice] == CtFr::FULL_COL) {
			cout << "That column is full please choose another column" << endl;
		}
		// If none of the above are true then it is a valid column and we can continue
		else {
			// Determine what player is making the choice
			pos = CtFr::botPos[choice];
			if (player == 0) {
				CtFr::marks[pos] = player1Mark;
			}
			else {
				CtFr::marks[pos] = player2Mark;
			}

			CtFr::UpdateCol(choice);
			validChoice = true;
		}
		// --------------------------------------------------------------------------------
	}
	return pos;
}

bool CtFr::UpdateCol(int colNum) {
	// Assumes that initially not columns are full
	// FULL_COL should not be a number between 0 and NUM_SPACES
	bool worked = false;
	if (colNum < CtFr::NUM_COLS) {
		// Check if the column is about to be full after this update if so set it to FULL_COL
		if (CtFr::botPos[colNum] == colNum + (CtFr::NUM_COLS * (CtFr::NUM_ROWS - 1))) {
			CtFr::botPos[colNum] = CtFr::FULL_COL; //Set to -1 to show that this column is full
		}
		else { // If it is not about to be full just update like normal
			CtFr::botPos[colNum] = CtFr::botPos[colNum] + CtFr::NUM_COLS;
		}
		worked = true;
	}
	return worked;
}

void CtFr::DrawBoard(int width, int height) {
	int colCount;
	int spot = CtFr::NUM_SPACES - 1;

	int rowCount = 0;
	bool firstTime = true;
	while (rowCount < height) {
		colCount = 0;
		while (colCount < width) {
			if (firstTime) {
				cout << " ";
				cout << ((CtFr::NUM_COLS - 1) - colCount);
				cout << " ";
				colCount = colCount + 1;
				if (colCount == width) {
					colCount = 0;
					cout << endl;
					firstTime = false;
				}
			}
			else {
				cout << "[";
				cout << marks[spot];//marks[colCount + (rowCount * CtFr::NUM_COLS)];
				cout << "]";
				colCount = colCount + 1;
				spot--;
			}
		}
		cout << endl;
		rowCount = rowCount + 1;
	}
}

bool CtFr::WinCheck(int move) {
	int row;
	int col;
	int curSpotCheck;
	int numInLine = 0;
	bool winOccured = false;

	// Get the row and the column that the move was 
	row = move / CtFr::NUM_COLS;
	col = move % CtFr::NUM_COLS;

	// Check left and right
	curSpotCheck = move;
	// Check Left
	while (curSpotCheck / CtFr::NUM_COLS == row && CtFr::marks[curSpotCheck] == CtFr::marks[move] && numInLine < CtFr::NUM_IN_ROW_TO_WIN) {
		numInLine = numInLine + 1;
		curSpotCheck = curSpotCheck + 1;
	}

	if (numInLine == CtFr::NUM_IN_ROW_TO_WIN) {
		winOccured = true;
	}
	else {
		curSpotCheck = move - 1;
		// Check right
		while (curSpotCheck / CtFr::NUM_COLS == row && CtFr::marks[curSpotCheck] == CtFr::marks[move] && numInLine < CtFr::NUM_IN_ROW_TO_WIN) {
			numInLine = numInLine + 1;
			curSpotCheck = curSpotCheck - 1;
		}
	}

	if (numInLine == CtFr::NUM_IN_ROW_TO_WIN) {
		winOccured = true;
	}
	else {
		// Check up and down
		curSpotCheck = move;
		numInLine = 0;
		// Check up
		while (curSpotCheck < CtFr::NUM_SPACES && curSpotCheck % CtFr::NUM_COLS == col && CtFr::marks[curSpotCheck] == CtFr::marks[move] && numInLine < CtFr::NUM_IN_ROW_TO_WIN) {
			numInLine = numInLine + 1;
			curSpotCheck = curSpotCheck + CtFr::NUM_COLS;
		}
		if (numInLine == CtFr::NUM_IN_ROW_TO_WIN) {
			winOccured = true;
		}
		else {
			curSpotCheck = move - CtFr::NUM_COLS;
			// Check down
			while (curSpotCheck >= 0 && curSpotCheck % CtFr::NUM_COLS == col && CtFr::marks[curSpotCheck] == CtFr::marks[move] && numInLine < CtFr::NUM_IN_ROW_TO_WIN) {
				numInLine = numInLine + 1;
				curSpotCheck = curSpotCheck - CtFr::NUM_COLS;
			}
		}
	}

	// Check Diagonals
	if (!winOccured) {
		curSpotCheck = move;
		numInLine = 0;
		// Check Top left
		while (curSpotCheck >= 0 && curSpotCheck < CtFr::NUM_SPACES && CtFr::marks[curSpotCheck] == CtFr::marks[move] && numInLine < CtFr::NUM_IN_ROW_TO_WIN) {

			numInLine = numInLine + 1;
			curSpotCheck = curSpotCheck + CtFr::NUM_COLS + 1;
		}
		curSpotCheck = move - CtFr::NUM_COLS - 1;

		// Check Bottom Right
		while (curSpotCheck >= 0 && curSpotCheck < CtFr::NUM_SPACES && CtFr::marks[curSpotCheck] == CtFr::marks[move] && numInLine < CtFr::NUM_IN_ROW_TO_WIN) {

			numInLine = numInLine + 1;
			curSpotCheck = curSpotCheck - CtFr::NUM_COLS - 1;
		}
		if (numInLine == CtFr::NUM_IN_ROW_TO_WIN) {
			winOccured = true;
		}
		else {
			curSpotCheck = move;
			numInLine = 0;
			// Check Top Right
			while (curSpotCheck >= 0 && curSpotCheck < CtFr::NUM_SPACES && CtFr::marks[curSpotCheck] == CtFr::marks[move] && numInLine < CtFr::NUM_IN_ROW_TO_WIN) {
				numInLine = numInLine + 1;
				curSpotCheck = curSpotCheck + CtFr::NUM_COLS - 1;
			}

			curSpotCheck = move - CtFr::NUM_COLS + 1;
			// Check Bottom Left
			while (curSpotCheck >= 0 && curSpotCheck < CtFr::NUM_SPACES && CtFr::marks[curSpotCheck] == CtFr::marks[move] && numInLine < CtFr::NUM_IN_ROW_TO_WIN) {
				numInLine = numInLine + 1;
				curSpotCheck = curSpotCheck - CtFr::NUM_COLS + 1;
			}

			if (numInLine == CtFr::NUM_IN_ROW_TO_WIN) {
				winOccured = true;
			}
		}

	}


	if (numInLine == CtFr::NUM_IN_ROW_TO_WIN) {
		winOccured = true;
	}
	else {

	}

	if (winOccured) {
		if (playerTurn == 0) {
			cout << "Player 1 WON!!" << endl;
		}
		else {
			cout << "Player 2 WON!!" << endl;
		}
	}

	return winOccured;
}

bool CtFr::DetermineGameState(int lastMove) {
	int count = 0;
	bool boardFull = true;
	while (boardFull && count < CtFr::NUM_COLS) {
		if (CtFr::botPos[count] != CtFr::FULL_COL) {
			boardFull = false;
		}
		count = count + 1;
	}

	if (boardFull || WinCheck(lastMove)) {
		isGameOver = true;
	}

	return isGameOver;
}
