#pragma once
/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   GameVars.h
* Author: Keith
*
* Created on March 20, 2016, 8:52 PM
*/

#ifndef GAMEVARS_H
#define GAMEVARS_H


const int NUM_PLAYERS = 2;            // This should not be changed

extern bool isGameOver;               // Determines game state (it either is being played or it is over)
extern int playerTurn;                // Determines which players turn it is

extern char player1Mark;              // The character player 1 uses to mark his/her spot
extern char player2Mark;              // The character player 2 uses to mark his/her spot

void GetPlayerSymbols();

#endif /* GAMEVARS_H */

