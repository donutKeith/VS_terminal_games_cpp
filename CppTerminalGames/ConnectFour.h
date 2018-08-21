#pragma once
/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   ConnectFour.h
* Author: Keith
*
* Created on March 25, 2016, 11:55 PM
*/

#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include <string>

namespace CtFr {
	// Constants - Connect Four -------------------
	const int NUM_COLS = 7;
	const int NUM_ROWS = 6;
	const int NUM_SPACES = NUM_COLS * NUM_ROWS;
	const char EMPTY_SPACE = ' ';
	const int FULL_COL = -1;
	const int NUM_IN_ROW_TO_WIN = 4;
	// --------------------------------------------


	extern int botPos[];
	extern char marks[];

	void Play_ConnectFour();
	void StartGame_ConnectFour();
	void DrawBoard(int, int);
	bool UpdateCol(int);
	int GetPlayerChoice(int);
	bool WinCheck(int);
	bool DetermineGameState(int);
}
#endif /* CONNECTFOUR_H */

