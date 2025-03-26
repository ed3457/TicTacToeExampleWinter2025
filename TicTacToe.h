#pragma once
#include <string>
using namespace std; 
class TicTacToe
{
private:
	char board[3][3];
	int xWins;
	int oWins;

public:
	void placePlayer(char player, int row, int column);
	char checkWin();
	void resetGame();
	void play();
	void printBoard();

};

