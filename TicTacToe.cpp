#include "TicTacToe.h"

void TicTacToe::placePlayer(char player, int row, int column)
{
	//validation 
	if (row < 0 || row>2)
		throw 1; // invalid row 

	if (column < 0 || column>2)
		throw 2; // invalid column

	if (player != 'o' && player != 'x')
		throw 3;//invalid player symbol 

	if (board[row][column] !=' ')
		throw 4; // cell taken 

	board[row][column] = player;
}

void TicTacToe::resetGame()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void TicTacToe::printBoard()
{
	cout << "-------------\n";
	for (int i = 0; i < 3; i++)
	{
		
		for (int j = 0; j < 3; j++)
		{
			cout << "| " << board[i][j]<<" ";
		}
		cout << "|" << endl;
		cout << "-------------\n";

	}

}

TicTacToe::TicTacToe()
{
	resetGame();

	oWins = xWins = draws = 0; 
}
