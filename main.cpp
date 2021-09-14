#include <iostream>
#include <conio.h>
#include <windows.h>
#include "C://colorwin-master/src/colorwin.hpp"
using namespace colorwin;
// to use colors do the path of colorwin.hpp and add using namespace colorwin;
using namespace std;
bool gameOver;
const int ESC = 27;
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
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
void Draw()
{
	//clears the console
	ClearScreen();
	cout << endl;
	cout << color(green) << " _______________________________________________________________" << endl;
	cout << color(green) << "| _____________________________________________________________ |" << endl;
	cout << color(green) << "||     _____    __    __      ____      __   ___    _____      ||   " << endl;
	cout << color(green) << "||    |   __|  |  \\  |  |    / __ \\    |  | /  /   |   __|     ||  " << endl;
	cout << color(green) << "||    |  |__   |   \\ |  |   / |__| \\   |  |/  /    |  |__      || " << endl;
	cout << color(green) << "||    |__   |  |  \\ \\|  |  |   __   |  |     |     |   __|     ||" << endl;
	cout << color(green) << "||     __|  |  |  |\\    |  |  /  \\  |  |  |\\  \\    |  |__      ||" << endl;
	cout << color(green) << "||    |_____|  |__| \\___|  |_|    |_|  |__| \\__\\   |_____|     ||" << endl;
	cout << color(green) << "||_____________________________________________________________||" << endl;
	cout << color(green) << "|_______________________________________________________________|" << endl;
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
				cout << color(green) << "O";
			else if (i == fruitY && j == fruitX)
			{
				cout << color(red) << "O";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << color(green) << "o";
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
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'ESC':
			gameOver = true;
			break;
		}
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
	//  gameOver = true;
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