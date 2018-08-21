#pragma once
/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   TicTacToe.h
* Author: Keith
*
* Created on March 25, 2016, 8:11 PM
*/

#ifndef TICTACTOE_H
#define TICTACTOE_H

namespace TTT {
	// TIC_TAC_TOE Constants ----------------------------------------------------------------------------
	const int NUM_COLS = 3;
	const int NUM_ROWS = 3;
	const int NUM_SPACES = NUM_COLS * NUM_ROWS;                   // Number of spaces on the tic tac toe board
	const char EMPTY_SPOT = '_';

	// TIC_TAC_TOE Variables ------------------------------------------------------------------------------
	extern char marks[NUM_SPACES];        // Array to hold the marks made by the player
										  // ----------------------------------------------------------------------------------------------------

	bool Play_TIC_TAC_TOE();
	void StartGame_TIC_TAC_TOE();
	void DrawBoard(bool);
	void DrawRow(int, bool);
	void DrawSpot(char, int, bool);
	bool MarkSpot(int, int);
	int DetermineGameOver();
	bool CheckRows();
	bool CheckCols();
	bool CheckDiags();
	void DisplayWinnerMessage(char);
}
#endif /* TICTACTOE_H */

