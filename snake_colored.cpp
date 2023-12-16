#include <iostream>
#include <windows.h>

using namespace std;
bool gameOver = false;
const int Width = 63;
const int Height = 13;
int X, Y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	X = Width / 2;
	Y = Height / 2;
	fruitX = rand() % Width;
	fruitY = rand() % Height;
	score = 0;
}

//clears the screen without flickering
void ClearScreen()
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Draw()
{
	//clears the console
	ClearScreen();
	cout << endl;
	//using ansi escape codes for coloring
	cout << "\033[0;32;40m _______________________________________________________________\033[0m" << endl;
	cout << "\033[0;32;40m| _____________________________________________________________ |\033[0m" << endl;
	cout << "\033[0;32;40m||     _____    __    __      ____      __   ___    _____      ||   \033[0m" << endl;
	cout << "\033[0;32;40m||    |   __|  |  \\  |  |    / __ \\    |  | /  /   |   __|     ||  \033[0m" << endl;
	cout << "\033[0;32;40m||    |  |__   |   \\ |  |   / |__| \\   |  |/  /    |  |__      || \033[0m" << endl;
	cout << "\033[0;32;40m||    |__   |  |  \\ \\|  |  |   __   |  |     |     |   __|     ||\033[0m" << endl;
	cout << "\033[0;32;40m||     __|  |  |  |\\    |  |  /  \\  |  |  |\\  \\    |  |__      ||\033[0m" << endl;
	cout << "\033[0;32;40m||    |_____|  |__| \\___|  |_|    |_|  |__| \\__\\   |_____|     ||\033[0m" << endl;
	cout << "\033[0;32;40m||_____________________________________________________________||\033[0m" << endl;
	cout << "\033[0;32;40m|_______________________________________________________________|\033[0m" << endl;
	cout << endl;

	for (int i = 0; i < Width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == Y && j == X)
				cout << "\033[0;32;40mO\033[0m";
			else if (i == fruitY && j == fruitX)
			{
				cout << "\033[0;31;40mO\033[0m";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "\033[0;32;40mo\033[0m";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}


			if (j == Width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < Width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}

void Input()
{
	//key is pressed
	if (GetKeyState('W') < 0)
	{
		dir = UP;
	}
	else if (GetKeyState('A') < 0)
	{
		dir = LEFT;
	}
	else if (GetKeyState('S') < 0)
	{
		dir = DOWN;
	}
	else if (GetKeyState('D') < 0)
	{
		dir = RIGHT;
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = X;
	tailY[0] = Y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		X--;
		break;
	case RIGHT:
		X++;
		break;
	case UP:
		Y--;
		break;
	case DOWN:
		Y++;
		break;
	default:
		break;
	}
	//add this if I want the edges to kill the snake
	//if (x > width || x < 0 || y > height || y < 0)
	//gameOver = true;
	if (X >= Width) X = 0; else if (X < 0) X = Width - 1;
	if (Y >= Height) Y = 0; else if (Y < 0) Y = Height - 1;

	for (int i = 0; i < nTail; i++)
		if (tailX[i] == X && tailY[i] == Y)
			gameOver = true;

	if (X == fruitX && Y == fruitY)
	{
		score += 10;
		fruitX = rand() % Width;
		fruitY = rand() % Height;
		nTail++;
	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		if (dir == LEFT || dir == RIGHT)
		{
			Sleep(15);
		}
	
		Sleep(20);
	
		if (dir == UP || dir == DOWN)
		{
			Sleep(80);
		}
		Input();
		Logic();
	}
	return 0;
}
