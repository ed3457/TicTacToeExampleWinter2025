#pragma once
#include <string>
#include <iostream>
using namespace std; 
class TicTacToe
{
private:
	char board[3][3];
	int xWins;
	int oWins;
	int draws;

public:
	void placePlayer(char player, int row, int column);
	char checkWin(char player);
	void resetGame();
	void play();
	void printBoard();
	TicTacToe();

};

