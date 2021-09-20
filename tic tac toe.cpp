#include<iostream>
#include<array>
#include<stdlib.h>

using namespace std;

//variables
array <string, 9> location{" ", " ", " ", " ", " ", " ", " ", " ", " "};
string x = " ",y = " ",z = " ",a = " ",b = " ",c = " ",d = " ",e = " ",f = " "; // change into array to be more optimized
int player = 0;
int currentMove;
array <int, 9> movesMade{};
int arraySize = sizeof(movesMade) / 4;

//guide to tic tac toe board placement
void mainBoard()
{
	system("cls");
	//reference board
	cout << endl << "        " << "|   " << "  |";
	cout << endl << "     " << "1" << "  |  " << "2" << "  |  " << "3" << endl;
	cout << "   " << "_____|" << "_____|_____" << endl;
	cout << "        " << "|   " << "  |" << endl;
	cout << "     " << "4" << "  |  " << "5" << "  |  " << "6" << endl;
	cout << "   " << "_____|" << "_____|_____" << endl;
	cout << "        " << "|   " << "  |" << endl;
	cout << "     " << "7" << "  |  " << "8" << "  |  " << "9";
	cout << endl << "        " << "|   " << "  |" << endl;

	//your board
	cout << endl << "        " << "|   " << "  |";
	cout << endl << "     " << x << "  |  " << y << "  |  " << z << endl;
	cout << "   " << "_____|" << "_____|_____" << endl;
	cout << "        " << "|   " << "  |" << endl;
	cout << "     " << a << "  |  " << b << "  |  " << c << endl;
	cout << "   " << "_____|" << "_____|_____" << endl;
	cout << "        " << "|   " << "  |" << endl;
	cout << "     " << d << "  |  " << e << "  |  " << f;
	cout << endl << "        " << "|   " << "  |" << endl;
}

//checks every turn whether player 1 or player 2 wins using switch and case method
void caseCheck()
{
	//when a player wins cout << endl << endl << "player " << player << " wins" << endl;
	if (x == "O" && y == "O" && z == "O" || a == "O" && b == "O" && c == "O" || d == "O" && e == "O" && f == "O" || x == "O" && a == "O" && d == "O" || y == "O" && b == "O" && e == "O" || z == "O" && c == "O" && f == "O" || x == "O" && b == "O" && f == "O" || z == "O" && b == "O" && d == "O")
	{
		mainBoard();
		cout << endl << "player 2 wins";
		player += 1;
	}
	if (x == "X" && y == "X" && z == "X" || a == "X" && b == "X" && c == "X" || d == "X" && e == "X" && f == "X" || x == "X" && a == "X" && d == "X" || y == "X" && b == "X" && e == "X" || z == "X" && c == "X" && f == "X" || x == "X" && b == "X" && f == "X" || z == "X" && b == "X" && d == "X")
	{
		mainBoard();
		cout << endl << "player 1 wins";
		player += 1;
	}
}

//compares currentMove input to movesMade array to see if the move was already played using exceptions
void prevMoveMadey()
{
	for (int j = 0; j < arraySize; j++)
	{
		if (currentMove == movesMade[j])
		{
			cout << "Move has already been made, try again";
			//oes();
		}
	}
}

//prints X to current players desired spot with user input
void exes()
{
	cout << endl << "Player 1: pick a number of where you would like to go ";
	cin >> currentMove;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		mainBoard();
		cout << endl << "cannot enter letter values" << endl;
		exes();
	}
	switch (currentMove)
	{
		case 1:
			if (movesMade[0] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				exes();
				break;
			}
			x = "X";
			movesMade[0] = 1;
			break;
		case 2:
			if (movesMade[1] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				exes();
				break;
			}
			y = "X";
			movesMade[1] = 2;
			break;
		case 3:
			if (movesMade[2] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				exes();
				break;
			}
			z = "X";
			movesMade[2] = 3;
			break;
		case 4:
			if (movesMade[3] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				exes();
				break;
			}
			a = "X";
			movesMade[3] = 4;
			break;
		case 5:
			if (movesMade[4] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				exes();
				break;
			}
			b = "X";
			movesMade[4] = 5;
			break;
		case 6:
			if (movesMade[5] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				exes();
				break;
			}
			c = "X";
			movesMade[5] = 6;
			break;
		case 7:
			if (movesMade[6] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				exes();
				break;
			}
			d = "X";
			movesMade[6] = 7;
			break;
		case 8:
			if (movesMade[7] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				exes();
				break;
			}
			e = "X";
			movesMade[7] = 8;
			break;
		case 9:
			if (movesMade[8] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				exes();
				break;
			}
			f = "X";
			movesMade[8] = 9;
			break;
		default:
			mainBoard();
			cout << endl << "number is not located on tic tac toe board, try again" << endl;
			exes();
			break;
	}
}

//prints O to current players desired spot with user input
void oes()
{
	cout << endl << "Player 2: pick a number of where you would like to go ";
	cin >> currentMove;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		mainBoard();
		cout << endl << "cannot enter letter values" << endl;
		oes();
	}
	switch (currentMove)
	{
		case 1:
			if (movesMade[0] == currentMove)
			{
					mainBoard();
					cout << endl << "Move has already been made, try again" << endl;
					oes();
					break;
			}
			x = "O";
			movesMade[0] = 1;
			break;
		case 2:
			if (movesMade[1] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				oes();
				break;
			}
			y = "O";
			movesMade[1] = 2;
			break;
		case 3:
			if (movesMade[2] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				oes();
				break;
			}
			z = "O";
			movesMade[2] = 3;
			break;
		case 4:
			if (movesMade[3] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				oes();
				break;
			}
			a = "O";
			movesMade[3] = 4;
			break;
		case 5:
			if (movesMade[4] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				oes();
				break;
			}
			b = "O";
			movesMade[4] = 5;
			break;
		case 6:
			if (movesMade[5] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				oes();
				break;
			}
			c = "O";
			movesMade[5] = 6;
			break;
		case 7:
			if (movesMade[6] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				oes();
				break;
			}
			d = "O";
			movesMade[6] = 7;
			break;
		case 8:
			if (movesMade[7] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				oes();
				break;
			}
			e = "O";
			movesMade[7] = 8;
			break;
		case 9:
			if (movesMade[8] == currentMove)
			{
				mainBoard();
				cout << endl << "Move has already been made, try again" << endl;
				oes();
				break;
			}
			f = "O";
			movesMade[8] = 9;
			break;
		default:
			mainBoard();
			cout << endl << "number is not located on tic tac toe board, try again" << endl;
			oes();
			break;
	}
}

int main()
{
	for (int i = 0; i < 4; i++)
	{	
		if (player == 0)
		{
			caseCheck();
		}
		if (player == 0)
		{ 
			mainBoard();
			exes();
		}
		if (player == 0)
		{
			caseCheck();
		}
		if (player == 0)
		{
			mainBoard();
			oes();
		}
		else
		{
			exit;
		}
	}
	if (player == 0)
	{
		mainBoard();
		exes();
		mainBoard();
		cout << "Tie game";
	}
}