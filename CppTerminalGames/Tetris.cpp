/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/


#include <iostream>
#include <cstdlib>
#include <string>
#include "Tetris.h"

using namespace std;
//int Tet::board[Tet::BOARD_HEIGHT][Tet::BOARD_WIDTH];
int Tet::board[Tet::BOARD_HEIGHT][Tet::BOARD_WIDTH] = {
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY, Tet::EMPTY },
	{ Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::EMPTY, Tet::BLOCK },
	{ Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::EMPTY, Tet::BLOCK },
	{ Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::EMPTY, Tet::BLOCK },
	{ Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::EMPTY, Tet::BLOCK },
	{ Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::BLOCK, Tet::EMPTY, Tet::BLOCK }
};
// Variables used for movement and collision detection of the current piece being dropped (aka curPiece)
// --------------------------------------------------------------------------------------------------------------------------------------------
// [**IMPORTANT NOTE**: These vars below should be updated every time a new piece is assigned to curPiece. This includes when curPiece is rotated.]
// --------------------------------------------------------------------------------------------------------------------------------------------
int Tet::curPiece[Tet::PEICE_MAX_HEIGHT][Tet::PEICE_MAX_WIDTH];		// Array which maps out what the current piece looks like
int Tet::curPiece_ShapeType;									// Current shape of the piece
int Tet::curPiece_Rotation;									// Current rotation of the piece
int Tet::curPiece_Row;										// The row on the board in which the top row of the piece is located (NOTE: top row of the piece may not actually contain a block of the actual piece itself)
int Tet::curPiece_Col;										// The column on the board  in which the left most row of the piece is located (NOTE: left column of the piece may not actually contain a block of the actual piece itself)

int Tet::curPiece_LeftMostIndex;								// The column in the curPiece array that contains the left most piece
int Tet::curPiece_RightMostIndex;							// The column in the curPiece array that contains the right most piece
int Tet::curPiece_TopMostIndex;								// The row in the curPiece array that contains the top of the piece
int Tet::curPiece_BottomMostIndex;							// The row in the curPiece array that contains the bottom of the piece

int Tet::indiciesOfActualPiece[Tet::MAX_NUM_BLOCKS_IN_PIECE][2];	// Array that contains the column and row of every block in the piece

int Tet::rowsToDelete[Tet::MAX_NUM_BLOCKS_IN_PIECE];

bool Tet::GAME_OVER;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Function Definitions =============================================================================================================
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int Tet::GetHorizontalLeftOffset() {
	int left = -1;
	// Loop through the columns from left to right until we hit our first NON-EMPTY block. This will be our left most block.
	bool offsetFount = false;

	// Check each column exit once a non-empty element is found or we have search all elements
	for (int curColCheck = 0; curColCheck < Tet::PEICE_MAX_WIDTH && !offsetFount; curColCheck++) {
		// Go down the column and check for Non-empty elements
		for (int curSpot = 0; curSpot < Tet::PEICE_MAX_HEIGHT && !offsetFount; curSpot++) {
			if (curPiece[curSpot][curColCheck] == BLOCK) {
				left = curColCheck; // Yes we could just return curColCheck instead of xOffset because we exit 
									//   the loop now but this is much more explicit
				offsetFount = true;
			}
		}
	}

	return left;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int Tet::GetHorizontalRightOffset() {
	int right = -1;
	// Loop through the columns from right to left until we hit our first NON-EMPTY block. This will be our right most block.
	bool offsetFount = false;
	// Check each column exit once a non-empty element is found or we have search all elements
	for (int curColCheck = Tet::PEICE_MAX_WIDTH - 1; curColCheck >= 0 && !offsetFount; curColCheck--) {
		// Go down the column and check for Non-empty elements
		for (int curSpot = 0; curSpot < Tet::PEICE_MAX_HEIGHT && !offsetFount; curSpot++) {
			if (Tet::curPiece[curSpot][curColCheck] == Tet::BLOCK) {
				right = curColCheck; // Yes we could just return curColCheck instead of xOffset because we exit 
									 //   the loop now but this is much more explicit
				offsetFount = true;
			}
		}
	}
	return right;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int Tet::GetVerticalTopOffset() {
	int top = -1;
	// Loop through the rows from top to bottom until we hit the first non-empty block. This will be our top most row of the piece.
	bool offsetFount = false;

	// Loop through the rows until we hit our first NON-EMPTY block. This will be our top most block
	for (int curRowCheck = 0; curRowCheck < Tet::PEICE_MAX_HEIGHT && !offsetFount; curRowCheck++) {
		for (int curSpot = 0; curSpot < Tet::PEICE_MAX_WIDTH && !offsetFount; curSpot++) {
			if (Tet::curPiece[curRowCheck][curSpot] == Tet::BLOCK) {
				top = curRowCheck;
				offsetFount = true;
			}
		}
	}
	return top;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int Tet::GetVerticalBottomOffset() {
	int bottom = -1;
	// Loop through the rows from bottom to top until we hit the first non-empty block. This will be our bottom most row of the piece.
	bool offsetFount = false;

	// Loop through the rows until we hit our first NON-EMPTY block. This will be our top most block
	for (int curRowCheck = Tet::PEICE_MAX_HEIGHT - 1; curRowCheck >= 0 && !offsetFount; curRowCheck--) {
		for (int curSpot = 0; curSpot < Tet::PEICE_MAX_WIDTH && !offsetFount; curSpot++) {
			if (Tet::curPiece[curRowCheck][curSpot] == Tet::BLOCK) {
				bottom = curRowCheck;
				offsetFount = true;
			}
		}
	}
	return bottom;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Tet::CollisionDetection(int amountMovedHorizontally, int amountMovedVertically) {
	// Assumes curPiece is populated, along with curPiece_Row and curPieceCol which determine board position of the top left of the array
	// Assumes that we are only moving in increments of 1 so amountMovedHorizontally is between -1 and 1
	// Assumes that amountMovedVertically is 1 or 0
	// Arguments:
	// amountMovedHorizontally - is assumed to be negative if we are moving to the left and positive if we are moving to the right
	// amountMovedVertically   - is assumed to be negative if we are moving up and positive if we are moving down
	// All movement is based off curPiece_Row and curPieceCol respectively
	// What this function does:
	//   It determines where the actually edges of the piece are since curPiece_Row and curPieceCol is the upper left position of the bounding box of this
	//	    piece but this is NOT where the piece actually resides.
	int row = Tet::curPiece_TopMostIndex;
	int col;
	bool collisionOccured = false;

	// Check if we hit the wall by moving horizontally by amountMovedHorizontally
	if (Tet::curPiece_Col + Tet::curPiece_LeftMostIndex + amountMovedHorizontally < 0 || Tet::curPiece_Col + Tet::curPiece_RightMostIndex + amountMovedHorizontally >= Tet::BOARD_WIDTH) {
		collisionOccured = true; // We hit a wall on the board
	}

	// Check if we hit the floor by moving vertically by amountMovedVertically
	if (Tet::curPiece_Row + Tet::curPiece_BottomMostIndex + amountMovedVertically >= Tet::BOARD_HEIGHT) {
		collisionOccured = true; // We hit the floor
	}

	// Check if we hit some other piece on the board
	for (int curRow = Tet::curPiece_Row + Tet::curPiece_TopMostIndex; curRow <= Tet::curPiece_Row + Tet::curPiece_BottomMostIndex && collisionOccured == false; curRow++) {
		col = Tet::curPiece_LeftMostIndex;
		for (int curCol = Tet::curPiece_Col + Tet::curPiece_LeftMostIndex; curCol <= Tet::curPiece_Col + Tet::curPiece_RightMostIndex && collisionOccured == false; curCol++) {
			if (Tet::curPiece[row][col] == Tet::BLOCK && Tet::board[curRow + amountMovedVertically][curCol + amountMovedHorizontally] == Tet::BLOCK) { // Check if this current block is colliding with the space this block will take up in the next turn
				if (curRow + amountMovedVertically >= 0) {// Don't need to check if we are still above the board
					collisionOccured = true;
					// DEBUGGING cout << "Block on the board is in the way" << endl;
				}
			}
			col++;
		}
		row++;
	}

	return collisionOccured;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
string Tet::ConvertFromIntToChar(int num) {
	string returnVal;

	switch (num) {
	case Tet::BLOCK:
		returnVal = "[]";
		break;
	case Tet::EMPTY:
		returnVal = "__";
		break;
	case Tet::DELETED:
		returnVal = "**";
		break;
	default:
		break;
	}

	return returnVal;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::PrintBoard(bool withInstructions, bool showNums) {
	// This function prints the current piece on the board in it's current position.

	// This function expects that curPiece_Row and curPieceCol variables are populated with valid positions. 
	// There is NO COLLISION DETECTION HAPPENING INSIDE THIS FUNTION. It just prints what it is told.
	bool shapePrintedOnThisRow = false; // Determines if we need to print part of the piece on the current row
										// Normally numRowsThatNeedToBePrinted and numColsThatNeedToBePrinted would be all rows but initially the piece is above the board. 
										//   So we only need to print the bottom row initially then the piece drops by 1 row, so we need to
										//   print 1 more bottom row until all rows are on the board
	int curPieceCol_Printing = 0; // When printing the piece, this variable keeps track of what column we are on.
	int curPieceRow_Printing;     // When printing the piece, this variable keeps track of what row we are on. 
								  //               NOTE: Rows are printed column by column

								  // First we need to handle the the fact that the piece initially prints above the board, so we need to know how many rows get printed on the board
								  // It will be all of the rows unless it is above the board (aka curPiece_Row is less than 0)
	if (Tet::curPiece_Row < 0) {
		curPieceRow_Printing = -Tet::curPiece_Row; // Again it looks like we are adding but curPiece_Row is < 0 so we are taking a negative number and adding 1
	}
	else {
		curPieceRow_Printing = 0;
	}
	// ROW PRINTING LOGIC ---------------------------------------------------------------------------------------------
	for (int curRow = 0; curRow < Tet::BOARD_HEIGHT; curRow++) {
		cout << "||";
		// The logic between the *s is used to determine if we have to print a row from the current piece on this row 
		// ********************************************************************************************************
		if (curRow >= Tet::curPiece_Row && curRow < Tet::curPiece_Row + Tet::PEICE_MAX_HEIGHT) { // We hit the first row that contains the current piece
			shapePrintedOnThisRow = true;
		}
		else {
			shapePrintedOnThisRow = false;
		}
		// ********************************************************************************************************

		// COLUMN PRINTING LOGIC --------------------------------------------------------------------------------------
		if (Tet::curPiece_Col < 0) {
			curPieceCol_Printing = -Tet::curPiece_Col;// We need to print the positive value 
		}
		else {
			curPieceCol_Printing = 0;
		}
		// Start printing the row column by column. Note we are only printing 1 element in what ultimately makes up a column
		for (int curCol = 0; curCol < Tet::BOARD_WIDTH; curCol++) {

			// If the following is true print the elements in the curPiece array.
			if (shapePrintedOnThisRow && curCol >= Tet::curPiece_Col && curCol < Tet::curPiece_Col + Tet::PEICE_MAX_WIDTH) {
				// Check if this element in the curPiece array is empty or not. If it is empty print the board element
				if (Tet::curPiece[curPieceRow_Printing][curPieceCol_Printing] == Tet::BLOCK) {
					// The current element in the curPiece array is full (aka NOT empty) 
					//    so we need to print something to represent the current block of this piece
					cout << ConvertFromIntToChar(Tet::curPiece[curPieceRow_Printing][curPieceCol_Printing]);
				}
				else {
					cout << ConvertFromIntToChar(Tet::board[curRow][curCol]);
				}
				curPieceCol_Printing++;
			}
			else {
				cout << ConvertFromIntToChar(Tet::board[curRow][curCol]);
			}
		}
		// If we printed a row of the current piece we need to increment to the next row
		if (shapePrintedOnThisRow) {
			curPieceRow_Printing++;
		}

		cout << "||";

		if (withInstructions == true) {
			if (curRow <= Tet::BOARD_HEIGHT - 1 && curRow >= Tet::BOARD_HEIGHT - 7) {
				if (showNums == true) {
					cout << curRow; // DEBUGGING ONLY
				}
				cout << "         "; // Space
			}
			else {
				if (showNums == true) {
					//DEBUGGING ONLY
					cout << curRow << endl;//DEBUGGING ONLY
										   //DEBUGGING ONLY
				}
			}

			switch (curRow) {
			case (Tet::BOARD_HEIGHT - 7):
				cout << "Please choose your move:" << endl;
				break;
			case (Tet::BOARD_HEIGHT - 6):
				cout << "KEYS:" << endl;
				break;
			case (Tet::BOARD_HEIGHT - 5):
				cout << " W - rotate" << endl;
				break;
			case (Tet::BOARD_HEIGHT - 4):
				cout << " A - Left" << endl;
				break;
			case (Tet::BOARD_HEIGHT - 3):
				cout << " S - Down" << endl;
				break;
			case (Tet::BOARD_HEIGHT - 2):
				cout << " D - Right" << endl;
				break;
			case (Tet::BOARD_HEIGHT - 1):
				cout << " G - GAME OVER" << endl;
				break;
			}
		}
		else {
			cout << endl;
		}
	}

	// Print the floor
	cout << "==";
	for (int i = 0; i < Tet::BOARD_WIDTH; i++) {
		cout << "==";
	}
	cout << "==" << endl;

	cout << "  ";
	for (int i = 0; i < Tet::BOARD_WIDTH; i++) {
		if (i < 10) {
			cout << " " << i;
		}
		else {
			cout << i;
		}
	}
	cout << endl;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::DEBUG_PrintCurPiece(bool showEmptySpaces) {
	for (int row = 0; row < Tet::PEICE_MAX_HEIGHT; row++) {
		for (int col = 0; col < Tet::PEICE_MAX_WIDTH; col++) {
			if (showEmptySpaces) {
				cout << Tet::curPiece[row][col];
			}
			else {
				if (Tet::curPiece[row][col] == 1) {
					cout << Tet::curPiece[row][col];
				}
				else {
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::UpdatePieceInfo() {
	int numFound = 0;     // Number of blocks (non-empty elements of the curPiece array) found in the shape

	Tet::curPiece_LeftMostIndex = Tet::GetHorizontalLeftOffset();
	Tet::curPiece_RightMostIndex = Tet::GetHorizontalRightOffset();
	Tet::curPiece_TopMostIndex = Tet::GetVerticalTopOffset();
	Tet::curPiece_BottomMostIndex = Tet::GetVerticalBottomOffset();

	// Populate the "indiciesOfActualPiece" array with the x, y (col, row) of all the block elements in the "curPiece" array
	for (int row = Tet::curPiece_TopMostIndex; row <= Tet::curPiece_BottomMostIndex; row++) {
		for (int col = Tet::curPiece_LeftMostIndex; col <= Tet::curPiece_RightMostIndex; col++) {
			if (Tet::curPiece[row][col] == Tet::BLOCK) {
				if (numFound < Tet::MAX_NUM_BLOCKS_IN_PIECE) {
					// Populate the cols and rows in the "indiciesOfActualPiece" array
					Tet::indiciesOfActualPiece[numFound][0] = col;
					Tet::indiciesOfActualPiece[numFound][1] = row;
					numFound++;
				}
				else {
					cout << "ERROR TO MANY BLOCKS" << endl;
				}
			}
		}
	}

	/*cout << "Left Index: " << curPiece_LeftMostIndex << endl;
	cout << "Right Index: " << curPiece_RightMostIndex << endl;
	cout << "Top Index: " << curPiece_TopMostIndex << endl;
	cout << "Bottom Index: " << curPiece_BottomMostIndex << endl;*/

}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::SetCurPeice(int pieceType, int rot, int xPos, int yPos) {
	// Arguments:
	// pieceType - should be the index for the piece you want to assign to the current piece (curPiece)
	//             condition:[ 0 <= pieceType < NUM_PIECES ]
	// rot - should be the index of the rotation type 
	//             condition:[ 0 <= rot < NUM_ROTATIONS ]
	// Output:
	// If the conditions listed above are NOT met no piece will be assigned to curPiece
	// Otherwise the piece specified by pieceType will be assigned to curPiece with the rotation of rot.

	if (pieceType < Tet::NUM_PIECES && pieceType >= 0 && rot >= 0 && rot < Tet::NUM_ROTATIONS) {
		for (int row = 0; row < Tet::PEICE_MAX_HEIGHT; row++) {
			for (int col = 0; col < Tet::PEICE_MAX_WIDTH; col++) {
				Tet::curPiece[row][col] = Tet::pieces[pieceType][rot][row][col];
			}

		}
		Tet::curPiece_ShapeType = pieceType;
		Tet::curPiece_Rotation = rot;
	}

	UpdatePieceInfo();

}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::NewPiece() {
	int randPiece;
	int randRot;
	randPiece = rand() % Tet::NUM_PIECES;
	randRot = rand() % Tet::NUM_ROTATIONS;
	SetCurPeice(randPiece, randRot, Tet::startCol, Tet::curPiece_Row);
	Tet::curPiece_Row = Tet::startRow;
	Tet::curPiece_Col = Tet::startCol;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::AddToBoard() {
	int row = Tet::curPiece_TopMostIndex;
	int col;
	cout << "AddToBoard was called!!!!!!!!!!" << endl;

	for (int curRow = Tet::curPiece_Row + Tet::curPiece_TopMostIndex; curRow <= Tet::curPiece_Row + Tet::curPiece_BottomMostIndex; curRow++) {
		col = Tet::curPiece_LeftMostIndex;
		for (int curCol = Tet::curPiece_Col + Tet::curPiece_LeftMostIndex; curCol <= Tet::curPiece_Col + Tet::curPiece_RightMostIndex; curCol++) {
			//DEBUGGING 	cout << "[" << curRow << "][" << curCol<< "]" << endl;
			if (Tet::curPiece[row][col] == Tet::BLOCK) {
				Tet::board[curRow][curCol] = 1;
			}
			col++;
		}
		row++;
	}
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::CreateBoard() {
	GAME_OVER = false;
	for (int i = 0; i < Tet::BOARD_HEIGHT; i++) {
		for (int j = 0; j < Tet::BOARD_WIDTH; j++) {
			Tet::board[i][j] = Tet::EMPTY;
		}
	}
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::DebugBoard() {

}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::DeleteRowsIfFull() {
	bool emptyFound;
	int rowsDeleted = 0;
	int rowsThatAreDeleted[Tet::MAX_NUM_BLOCKS_IN_PIECE];

	for (int i = 0; i < Tet::MAX_NUM_BLOCKS_IN_PIECE; i++) {
		rowsThatAreDeleted[i] = -1;
	}

	for (int row = Tet::BOARD_HEIGHT - 1; row >= 0 && rowsDeleted <= Tet::MAX_NUM_BLOCKS_IN_PIECE; row--) {// Start from the bottom up

		emptyFound = false;// Assume the row is full until we find an empty

		for (int col = 0; col < Tet::BOARD_WIDTH && emptyFound == false; col++) {
			if (Tet::board[row][col] == Tet::EMPTY) {
				emptyFound = true;
			}
		}

		// If empty found is still false after going through the entire row then this row is full and needs to be deleted
		if (emptyFound == false) {
			rowsThatAreDeleted[rowsDeleted] = row;
			rowsDeleted++;
		}
	}

	for (int row = 0; row < rowsDeleted; row++) {
		for (int col = 0; col < Tet::BOARD_WIDTH; col++) {
			Tet::board[rowsThatAreDeleted[row]][col] = Tet::DELETED;
		}
	}

	// Print the board with *s in the place of the pieces that are 
	// being removed
	if (rowsDeleted > 0) {
		PrintBoard(false, false);
	}

	// Go through and delete the full rows
	int row = Tet::BOARD_HEIGHT - 1, deletedRows = 0;
	int tempRow;
	while (row >= 0) {
		tempRow = row;
		// find the next row that does not need to be deleted
		// we need to have a loop because deleted rows will often
		// be immediately on top of one another
		// without the loop we would move bad rows down and keep them
		while (tempRow == rowsThatAreDeleted[deletedRows]) {
			deletedRows++;
			tempRow--;
		}

		// Now that we know how many bad rows are above this row we are deleting
		// we can move down the next good row.
		// Note this loop only moves down 1 row we are looping through COLUMNS not ROWS
		for (int col = 0; col < Tet::BOARD_WIDTH; col++) {
			if ((row - deletedRows) < 0) { // if we have reached number of rows deleted away from the top we need to add blank rows to the top
				Tet::board[row][col] = Tet::EMPTY;
			}
			else {
				Tet::board[row][col] = Tet::board[row - deletedRows][col];
			}
		}
		row--;
	}
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Tet::CheckForGameOver() {
	bool gg = false;

	for (int topCol = 0; topCol < Tet::BOARD_WIDTH && gg == false; topCol++) {
		if (Tet::board[0][topCol] == Tet::BLOCK) {
			gg = true;
		}
	}
	return gg;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::HandlePlayerInputAndGameMovement() {
	string playerInput;
	char input;
	int saveOrigRot = Tet::curPiece_Rotation;
	bool willPlayerMoveCauseCollision = false;
	bool willVertDropCauseCollision = false;
	bool newPieceWasAdded = false;
	int moveDown = 0;			// 1 means we move down 1 space which should happen every iteration but it can be 2 if the player gives that input
	int moveHorizontally = 0;   // -1 for left, 1 for right and 0 for no horizontal movement

								// Get player input and store the first character
	cin >> playerInput;
	input = playerInput[0];

	// Determine what should be done with player input
	switch (input) {
		// Rotate the piece
	case 'W':
	case 'w':
		Tet::curPiece_Rotation++;
		Tet::curPiece_Rotation = Tet::curPiece_Rotation % Tet::NUM_ROTATIONS; // Make sure it stays between 0 and NUM_ROTATIONS (NUM_ROTATIONS non-inclusive)
																			  // Actually Rotate the piece
		SetCurPeice(Tet::curPiece_ShapeType, Tet::curPiece_Rotation, Tet::curPiece_Col, Tet::curPiece_Row);
		break;
		// Move Left
	case 'A':
	case 'a':
		moveHorizontally = -1;
		break;
		// Move Down
	case 'S':
	case 's':
		moveDown = 1;
		break;
		// Move Right
	case 'D':
	case 'd':
		moveHorizontally = 1;
		break;
	case 'G':
	case 'g':
		Tet::GAME_OVER = true;
		break;
		// Do Nothing (Aka there is no player input, At least none that is valid)
	default:
		break;
	}

	if (saveOrigRot != Tet::curPiece_Rotation) { // If the piece was rotated we need to make sure that does not cause a collision
		willPlayerMoveCauseCollision = CollisionDetection(0, 0);
		if (willPlayerMoveCauseCollision == true) {// If rotating this piece causes us to collide unrotate
			Tet::curPiece_Rotation = saveOrigRot;
			SetCurPeice(Tet::curPiece_ShapeType, Tet::curPiece_Rotation, Tet::curPiece_Col, Tet::curPiece_Row);
		}

		willPlayerMoveCauseCollision = CollisionDetection(0, 1);
		if (willPlayerMoveCauseCollision == true) { // If we cannot move it down
													// So it becomes part of the board and we need a new piece
			AddToBoard();
			// Create a new piece
			NewPiece();
			newPieceWasAdded = true;
		}
		else {
			Tet::curPiece_Row += 1; // Move down
		}
	}
	else {
		willPlayerMoveCauseCollision = CollisionDetection(moveHorizontally, moveDown); // DECISION 1. Can we move where the player wants without moving down first? **(See OUTCOME 1A and OUTCOME 1B)**

		if (willPlayerMoveCauseCollision == false) {	// OUTCOME 1A : Yes, Player can make their move without colliding

														// IMPORTANT!!!! Keep in mind one of these (moveDown, or moveHorizontally) is actually 0 so nothing is being added since the player can only move left OR right OR down 
														// (Only 1 choice can be made. The player cannot move both vertically and horizontally in the same turn)
			Tet::curPiece_Row += moveDown;
			Tet::curPiece_Col += moveHorizontally;

			// DECISION 1A -> 2. Can we move down the normal 1 spot after moving where the player wanted  **(See OUTCOME 1A -> 2A and OUTCOME 1A -> 2B)**
			willVertDropCauseCollision = CollisionDetection(0, 1);

			if (willVertDropCauseCollision == false) {	// OUTCOME 1A -> 2A : Yes, we can and will move down the normal 1 spot after the player's move
				Tet::curPiece_Row += 1;
			}
			else {										// OUTCOME 1A -> 2B : No, piece cannot be moved down after the player's move
														// So it becomes part of the board and we need a new piece
				AddToBoard();
				// Create a new piece
				NewPiece();
				newPieceWasAdded = true;
			}
		}
		else {										// OUTCOME 1B : No, The player cannot make their move yet

													// DECISION 1B -> 2. Can we move down the normal 1 spot? **(See OUTCOME 1B -> 2A and OUTCOME 1B -> 2B)**
			willVertDropCauseCollision = CollisionDetection(0, 1);

			if (willVertDropCauseCollision == false) {		// OUTCOME 1B -> 2A : Yes, We can move down the normal 1 spot even though the player could not move
				Tet::curPiece_Row += 1;

				// DECISION 1B -> 2A -> 3. Can we move where the player wanted if we move down first? **(See OUTCOME 1B -> 2A -> 3A and OUTCOME 1B -> 2A -> 3B)**
				willPlayerMoveCauseCollision = CollisionDetection(moveHorizontally, moveDown);
				if (willPlayerMoveCauseCollision == false) {	// OUTCOME 1B -> 2A -> 3A : Yes, The player can move where they want if we move down first. 
																// Then move where the player wants 
					Tet::curPiece_Row += moveDown;
					Tet::curPiece_Col += moveHorizontally;
				}
				else {											// OUTCOME 1B -> 2A -> 3B : No, The player can not move where they want even after we moved down
																// Do nothing Ignore player input
				}
			}
			else {											// OUTCOME 1B -> 2B :No, We cannot move down the normal 1 spot AND the player could not move where they wanted either
															// So it becomes part of the board and we need a new piece
				AddToBoard();
				// Create a new piece
				NewPiece();
				newPieceWasAdded = true;
			}
		}
	}
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// MAIN : THIS IS THE STARTING POINT OF THE PROGRAM
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Tet::Play_Tetris() {
	int count = 0;

	//CreateBoard();
	NewPiece();

	while (!Tet::GAME_OVER) { // Play until GAME_OVER is true
		PrintBoard(true, true);
		HandlePlayerInputAndGameMovement();
		DeleteRowsIfFull();
		if (Tet::GAME_OVER == false) {// Player can end the game in HandlePlayerInputAndGameMovement we do not want to override that dicision here
			Tet::GAME_OVER = CheckForGameOver();
		}
		count++;
	}

	cout << "GAME OVER" << endl;
	// DEBUGGING
	/*for (int curPieceIndex = 0; curPieceIndex < 7; curPieceIndex++){
	for (int curPieceRotIndex = 0; curPieceRotIndex < 4; curPieceRotIndex++){
	SetCurPeice(curPieceIndex, curPieceRotIndex, 1, 1);
	}
	}*/
	// DEBUGGING 
}