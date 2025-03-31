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

char TicTacToe::checkWin(char player)
{
	

	for (int i = 0; i < 3; i++)
	{   // check rows
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
			return player;
		// check columns
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
			return player;
	}

	// check diagonals 

	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		return player;

	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		return player;

	if (moveCount == 9)
		return 'd';

	return 'n';

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
	moveCount = 0;
}

void TicTacToe::play()
{
	
		char player = 'o';
		cout << "It is Os Turn:\n";
		char status; 
		while (true) // drive the game 
		{   
		
			moveCount += 1;
			// read the row and column from the user
			int r, c;
			cout << "Enter row (1-3):";
			cin >> r;
			cout << "Enter column (1-3):";
			cin >> c;
			try
			{
				placePlayer(player, r - 1, c - 1);
				printBoard();
				status = checkWin(player);
				if (status != 'n')
					break; // X won, or O, or a draw
				else
				{
					if (player == 'o')
					{
						player = 'x';
						cout << "It is X's turn:";
					}
					else
					{
						player = 'o';
						cout << "It is O's turn:";
					}
				}

			}
			catch (int errorCode)
			{

				switch (errorCode)
				{
				case 1:
					cout << "Invalid Row!\n";
					break;
				case 2:
					cout << "Invalid Column!\n";
					break;
				case 3:
					cout << "invalid player symbol!\n";
					break;
				case 4:
					cout << "Cell is not empty!\n";
					break;
				default:
					break;
				}


			}


		}

		if (status == 'o')
		{
			cout << "O won!\n";
			oWins += 1;
		}
		else if (status == 'x')
		{
			cout << "X won!\n";
			xWins += 1;
		}
		else
		{
			cout << "It is a draw!\n";
			draws += 1;
		}

		resetGame();

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
	moveCount = 0;
}
