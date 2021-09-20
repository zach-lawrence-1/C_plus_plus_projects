#include<iostream>
#include<array>

using namespace std;

//variables
array <string, 9> location{" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 0;
int currentMove;
array <int, 9> movesMade{};

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
	cout << endl << "     " << location[0] << "  |  " << location[1] << "  |  " << location[2] << endl;
	cout << "   " << "_____|" << "_____|_____" << endl;
	cout << "        " << "|   " << "  |" << endl;
	cout << "     " << location[3] << "  |  " << location[4] << "  |  " << location[5] << endl;
	cout << "   " << "_____|" << "_____|_____" << endl;
	cout << "        " << "|   " << "  |" << endl;
	cout << "     " << location[6] << "  |  " << location[7] << "  |  " << location[8];
	cout << endl << "        " << "|   " << "  |" << endl;
}

//checks every turn whether player 1 or player 2 wins using switch and case method
void caseCheck()
{
	//when a player wins cout << endl << endl << "player " << player << " wins" << endl;
	if (location[0] == "O" && location[1] == "O" && location[2] == "O" || location[3] == "O" && location[4] == "O" && location[5] == "O" || location[6] == "O" && location[7] == "O" && location[8] == "O" || location[0] == "O" && location[3] == "O" && location[6] == "O" || location[1] == "O" && location[4] == "O" && location[7] == "O" || location[2] == "O" && location[5] == "O" && location[8] == "O" || location[0] == "O" && location[4] == "O" && location[8] == "O" || location[2] == "O" && location[4] == "O" && location[6] == "O")
	{
		mainBoard();
		cout << endl << "player 2 wins";
		player += 1;
	}
	if (location[0] == "X" && location[1] == "X" && location[2] == "X" || location[3] == "X" && location[4] == "X" && location[5] == "X" || location[6] == "X" && location[7] == "X" && location[8] == "X" || location[0] == "X" && location[3] == "X" && location[6] == "X" || location[1] == "X" && location[4] == "X" && location[7] == "X" || location[2] == "X" && location[5] == "X" && location[8] == "X" || location[0] == "X" && location[4] == "X" && location[8] == "X" || location[2] == "X" && location[4] == "X" && location[6] == "X")
	{
		mainBoard();
		cout << endl << "player 1 wins";
		player += 1;
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
			location[0] = "X";
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
			location[1] = "X";
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
			location[2] = "X";
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
			location[3] = "X";
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
			location[4] = "X";
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
			location[5] = "X";
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
			location[6] = "X";
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
			location[7] = "X";
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
			location[8] = "X";
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
			location[0] = "O";
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
			location[1] = "O";
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
			location[2] = "O";
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
			location[3] = "O";
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
			location[4] = "O";
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
			location[5] = "O";
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
			location[6] = "O";
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
			location[7] = "O";
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
			location[8] = "O";
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