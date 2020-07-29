#include <bits/stdc++.h>
using namespace std;

bool stillOn(char arr[][3], int* win, bool* tie) // Checks if Game is Over
{
	for (int i=0; i<3; ++i)
	{
		if (arr[i][0] == arr[i][1] and arr[i][1] == arr[i][2]) // Checking the ith Row
		{
			if (arr[i][0] == 'X' or arr[i][0] == 'O')
			{
				*win = (arr[i][0] == 'X' ? 1 : 2);
				return false;
			}
		}
		
		if (arr[0][i] == arr[1][i] and arr[1][i] == arr[2][i]) // Checking the ith Column
		{
			if (arr[0][i] == 'X' or arr[0][i] == 'O')
			{
				*win = (arr[0][i] == 'X' ? 1 : 2);
				return false;
			}
		}
	}
	if ((arr[0][0] == arr[1][1] and arr[0][0] == arr[2][2]) or (arr[0][2] == arr[1][1] and arr[0][2] == arr[2][0])) // Checking the Two Diagonals
		{
			if (arr[1][1] == 'X' || arr[1][1] == 'O')
			{
				*win = (arr[1][1] == 'X' ? 1 : 2);
				return false;
			}
		}
	for (int i=0; i<3; ++i) // Checking if There's a move Possible
		for (int j=0; j<3; ++j)
			if (arr[i][j] == ' ')
				return true;
	*tie = true; // if it's a Tie
	return false;
}

void showMatrix(char arr[][3]) // prints the Board
{
	printf("\t1.  %c | %c | %c\n",arr[0][0], arr[0][1], arr[0][2]);
	printf("\t    ---------\n");
	printf("\t2.  %c | %c | %c\n",arr[1][0], arr[1][1], arr[1][2]);
	printf("\t    ---------\n");
	printf("\t3.  %c | %c | %c\n\n",arr[2][0], arr[2][1], arr[2][2]);
	printf("\t    1.  2.  3.\n\n");
}

void makeChange(char *m, int row, int col, int* player) // Changes the Board after every Move
{
	*(m + row*3 + col) = (*player==1 ? 'X' : 'O');
	*player = (*player==1 ? 2 : 1);
}

void playGame() // Starts the Game
{
	bool ifTie = false;
	int winner, curr = 1, row, col, inp;
	char matrix[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	while (stillOn(matrix, &winner, &ifTie))
	{
		system("CLS");
		cout << "Player 1 : X\n";
		cout << "Player 2 : O\n\n\n";
		showMatrix(matrix);
		Input:
			cout << "\n\nPlayer " << curr <<  ", Enter your Row and Column :\n\n";
			cout << "Row : ";        cin >> row;   --row;
			cout << "Column : ";     cin >> col;   --col;
		if ((row<0 or row>2) or (col<0 or col>2) or matrix[row][col]!= ' ')
		{
			cout << "\nEnter Valid Choice.\n";
			goto Input;
		}
		makeChange(&matrix[0][0], row, col, &curr);
	}
	system("CLS");
	cout << "Player 1 : X\n";
	cout << "Player 2 : O\n\n\n";
	showMatrix(matrix);
	if (ifTie)
		cout << "\n\n\tIT'S A TIE!\n";
	else
	{
		cout << "\n\n\tGAME OVER!\n";
		cout << "\tWINNER : PLAYER " << winner << "\n";
	}
	cout << "\n\nPress 1 to Restart Game.\n";
	cout << "Press any other key to Exit\n";
	cout << "Response : ";
	cin >> inp;
	if (inp == 1)
		playGame();
	else exit(0);
}

void runGame() // Starts the Program
{
	cout << "TIC TAC TOE\n\n";
	int res;
	cout << "Press 1 to Start\n";
	cout << "Press any other key to Exit\n";
	cout << "Response : ";
	cin >> res;
	if (res == 1)
		playGame();
	exit(0);
}
int main()
{
	runGame();
}
