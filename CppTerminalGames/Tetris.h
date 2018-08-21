#pragma once
/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   Tetris.h
* Author: Keith
*
* Created on April 6, 2016, 7:54 PM
*/

#ifndef TETRIS_H
#define TETRIS_H

namespace Tet {
	// CONSTANT DECLARATIONS =================================================================================================================================
	const int BLOCK = 1;
	const int EMPTY = 0;
	const int DELETED = -1;

	const int NUM_PIECES = 7;
	const int NUM_ROTATIONS = 4;

	const int PEICE_MAX_WIDTH = 5;
	const int PEICE_MAX_HEIGHT = 5;

	const int MAX_NUM_BLOCKS_IN_PIECE = 4;
	// Array of shapes 0 - 6
	// 0 -> Line
	// 1 -> Square
	// 2 -> T-Shape
	// 3 -> L-Shape
	// 4 -> Reverse L-Shape
	// 5 -> S-Shape
	// 6 -> Reverse S-Shape
	const int pieces[NUM_PIECES][NUM_ROTATIONS][PEICE_MAX_HEIGHT][PEICE_MAX_WIDTH] =
	{// List of all shapes and their rotations (Rotations go from 0 - 3 in a clockwise rotation except for the square which does not rotate)
		{ // SHAPE INDEX[0]: Line 
			{ // Rotation: 0
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ BLOCK, BLOCK, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 1
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 2
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, BLOCK, BLOCK },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 3
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY }
			}
		},
		{// SHAPE INDEX[1]: Square
			{ // Rotation: 0
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 1
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 2
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 3
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			}
		},
		{// SHAPE INDEX[2]: T-Shape
			{ // Rotation: 0
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 1
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 2
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 3
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			}
		},
		{// SHAPE INDEX[3]: L-Shape
			{ // Rotation: 0
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 1
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, BLOCK, EMPTY },
				{ EMPTY, BLOCK, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 2
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 3
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, BLOCK, EMPTY },
				{ EMPTY, BLOCK, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			}
		},
		{// SHAPE INDEX[4]: Reverse L-Shape
			{ // Rotation: 0
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 1
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 2
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 3
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			}
		},
		{// SHAPE INDEX[5]: S-Shape
			{ // Rotation: 0
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, BLOCK, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 1
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 2
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, BLOCK, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 3
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			}
		},
		{// SHAPE INDEX[6]: Reverse S-Shape
			{ // Rotation: 0
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 1
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, EMPTY, EMPTY },
				{ EMPTY, BLOCK, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 2
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, BLOCK, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			},
			{ // Rotation: 3
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, BLOCK, EMPTY },
				{ EMPTY, EMPTY, BLOCK, BLOCK, EMPTY },
				{ EMPTY, EMPTY, BLOCK, EMPTY, EMPTY },
				{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
			}
		}
	};

	const int BOARD_WIDTH = 15;
	const int BOARD_HEIGHT = 20;

	const int CENTER_OF_PIECE_INDEX = 12;

	const int startCol = (BOARD_WIDTH / 2) - (PEICE_MAX_WIDTH / 2); // According to current values makes this => (15 / 2 = 7) - (5 / 2 = 2) == 7 - 2 == 5
	const int startRow = -PEICE_MAX_HEIGHT;
	// END OF CONSTANT DECLARATIONS ============================================================================================================
	// VARIABLE DECLARATIONS ===================================================================================================================
	extern int board[BOARD_HEIGHT][BOARD_WIDTH];

	// Variables used for movement and collision detection of the current piece being dropped (aka curPiece)
	// --------------------------------------------------------------------------------------------------------------------------------------------
	// [**IMPORTANT NOTE**: These vars below should be updated every time a new piece is assigned to curPiece. This includes when curPiece is rotated.]
	// --------------------------------------------------------------------------------------------------------------------------------------------
	extern int curPiece[PEICE_MAX_HEIGHT][PEICE_MAX_WIDTH];		// Array which maps out what the current piece looks like
	extern int curPiece_ShapeType;									// Current shape of the piece
	extern int curPiece_Rotation;									// Current rotation of the piece
	extern int curPiece_Row;										// The row on the board in which the top row of the piece is located (NOTE: top row of the piece may not actually contain a block of the actual piece itself)
	extern int curPiece_Col;										// The column on the board  in which the left most row of the piece is located (NOTE: left column of the piece may not actually contain a block of the actual piece itself)

	extern int curPiece_LeftMostIndex;								// The column in the curPiece array that contains the left most piece
	extern int curPiece_RightMostIndex;							// The column in the curPiece array that contains the right most piece
	extern int curPiece_TopMostIndex;								// The row in the curPiece array that contains the top of the piece
	extern int curPiece_BottomMostIndex;							// The row in the curPiece array that contains the bottom of the piece

	extern int indiciesOfActualPiece[MAX_NUM_BLOCKS_IN_PIECE][2];	// Array that contains the column and row of every block in the piece

	extern int rowsToDelete[MAX_NUM_BLOCKS_IN_PIECE];

	extern bool GAME_OVER;


	// Function Definitions =====================================================================================================================================
	int GetHorizontalLeftOffset();
	int GetHorizontalRightOffset();
	int GetVerticalTopOffset();
	int GetVerticalBottomOffset();
	bool CollisionDetection(int, int);
	std::string ConvertFromIntToChar(int);
	void PrintBoard(bool, bool);
	void UpdatePieceInfo();
	void SetCurPeice(int, int, int, int);
	void NewPiece();
	void AddToBoard();
	void CreateBoard();
	void DebugBoard();
	void DeleteRowsIfFull();
	bool CheckForGameOver();
	void HandlePlayerInputAndGameMovement();
	void Play_Tetris();

	void DEBUG_PrintCurPiece(bool showEmptySpaces);
	// ==========================================================================================================================================================
}
#endif /* TETRIS_H */

