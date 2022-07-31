#include"vars.h"
int turn = 0;
int win = 0;
int bDead = 0;
int wDead = 0;

std::string BlackPawnCol = "\033[100;47;30mP\033[0m";
std::string BlackRookCol = "\033[100;47;30mR\033[0m";
std::string BlackBishopCol = "\033[100;47;30mB\033[0m";
std::string BlackHorseCol = "\033[100;47;30mH\033[0m";
std::string BlackQueenCol = "\033[100;47;30mQ\033[0m";
std::string BlackKingCol = "\033[100;47;30mK\033[0m";

std::string whitePawnCol = "\033[100;47;93mP\033[0m";
std::string whiteRookCol = "\033[100;47;93mR\033[0m";
std::string whiteBishopCol = "\033[100;47;93mB\033[0m";
std::string whiteHorseCol = "\033[100;47;93mH\033[0m";
std::string whiteQueenCol = "\033[100;47;93mQ\033[0m";
std::string whiteKingCol = "\033[100;47;93mK\033[0m";

std::string whiteTile = "\033[100;47;10m       \033[0m";

std::string board[8][12] = {
	{"\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"," ", "\033[100;47;10m \033[0m", " "},   // row 1
	{" ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"},   // row 2
	{"\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"," ", "\033[100;47;10m \033[0m", " "},   // row 3
	{" ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"},   // row 4
	{"\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"," ", "\033[100;47;10m \033[0m", " "},   // row 5
	{" ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"},   // row 6
	{"\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"," ", "\033[100;47;10m \033[0m", " "},   // row 7
	{" ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m", " ", "\033[100;47;10m \033[0m"}	  // row 8
};

//an array that stores color data of square
std::string tileColor[8][12] = {
	{"w", "b", "w", "b", "w", "b", "w", "b", "w", "b", "w", "b"},
	{"b", "w", "b", "w", "b", "w", "b", "w", "b", "w", "b", "w"},
	{"w", "b", "w", "b", "w", "b", "w", "b", "w", "b", "w", "b"},
	{"b", "w", "b", "w", "b", "w", "b", "w", "b", "w", "b", "w"},
	{"w", "b", "w", "b", "w", "b", "w", "b", "w", "b", "w", "b"},
	{"b", "w", "b", "w", "b", "w", "b", "w", "b", "w", "b", "w"},
	{"w", "b", "w", "b", "w", "b", "w", "b", "w", "b", "w", "b"},
	{"b", "w", "b", "w", "b", "w", "b", "w", "b", "w", "b", "w"},
};

void bPieces::dead(int numDead)
	{
		if (death == 1)
		{
			if (numDead < 9)
			{
				if (tileColor[y][x] == "w")
				{
					board[y][x] = "\033[100;47;10m \033[0m";
				}
				else
				{
					board[y][x] = " ";
				}
				x = 8;
				y = 8 - numDead;

				switch (piece)
				{
				case PAWN:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackPawnCol;
						return;
					}
					board[y][x] = "\033[10;1;30mP\033[0m";
					break;
				case ROOK:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackRookCol;
						return;
					}
					board[y][x] = "\033[10;1;30mR\033[0m";
					break;
				case HORSE:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackHorseCol;
						return;
					}
					board[y][x] = "\033[10;1;30mH\033[0m";
					break;
				case BISHOP:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackBishopCol;
						return;
					}
					board[y][x] = "\033[10;1;30mB\033[0m";
					break;
				case QUEEN:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackQueenCol;
						return;
					}
					board[y][x] = "\033[10;1;30mQ\033[0m";
					break;
				default:
					break;
				}
			}
			if (numDead > 8)
			{
				if (tileColor[y][x] == "w")
				{
					board[y][x] = "\033[100;47;10m \033[0m";
				}
				else
				{
					board[y][x] = " ";
				}
				x = 9;
				y = 16 - numDead;

				switch (piece)
				{
				case PAWN:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackPawnCol;
						return;
					}
					board[y][x] = "\033[10;1;30mP\033[0m";
					break;
				case ROOK:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackRookCol;
						return;
					}
					board[y][x] = "\033[10;1;30mR\033[0m";
					break;
				case HORSE:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackHorseCol;
						return;
					}
					board[y][x] = "\033[10;1;30mH\033[0m";
					break;
				case BISHOP:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackBishopCol;
						return;
					}
					board[y][x] = "\033[10;1;30mB\033[0m";
					break;
				case QUEEN:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = BlackQueenCol;
						return;
					}
					board[y][x] = "\033[10;1;30mQ\033[0m";
					break;
				default:
					break;
				}
			}
		}
	}

bPieces pawn1, pawn2, pawn3, pawn4, pawn5, pawn6, pawn7, pawn8, rook1, rook2, bishop1, bishop2, horse1, horse2, queen, king;

std::vector<bPieces*> bPiece;

void wPieces::dead(int numDead)
	{
		//edit for white pieces
		if (death == 1)
		{
			if (numDead < 9)
			{
				if (tileColor[y][x] == "w")
				{
					board[y][x] = "\033[100;47;10m \033[0m";
				}
				else
				{
					board[y][x] = " ";
				}
				x = 10;
				y = 8 - numDead;

				switch (piece)
				{
				case PAWN:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whitePawnCol;
						return;
					}
					board[y][x] = "\x1B[93mP\033[0m";
					break;
				case ROOK:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whiteRookCol;
						return;
					}
					board[y][x] = "\x1B[93mR\033[0m";
					break;
				case HORSE:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whiteHorseCol;
						return;
					}
					board[y][x] = "\x1B[93mH\033[0m";
					break;
				case BISHOP:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whiteBishopCol;
						return;
					}
					board[y][x] = "\x1B[93mB\033[0m";
					break;
				case QUEEN:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whiteQueenCol;
						return;
					}
					board[y][x] = "\x1B[93mP\033[0m";
					break;
				default:
					break;
				}
			}
			if (numDead > 8)
			{
				if (tileColor[y][x] == "w")
				{
					board[y][x] = "\033[100;47;10m \033[0m";
				}
				else
				{
					board[y][x] = " ";
				}
				x = 11;
				y = 16 - numDead;

				switch (piece)
				{
				case PAWN:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whitePawnCol;
						return;
					}
					board[y][x] = "\x1B[93mP\033[0m";
					break;
				case ROOK:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whiteRookCol;
						return;
					}
					board[y][x] = "\x1B[93mR\033[0m";
					break;
				case HORSE:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whiteHorseCol;
						return;
					}
					board[y][x] = "\x1B[93mH\033[0m";
					break;
				case BISHOP:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whiteBishopCol;
						return;
					}
					board[y][x] = "\x1B[93mB\033[0m";
					break;
				case QUEEN:
					if (tileColor[y][x] == "w")
					{
						board[y][x] = whiteQueenCol;
						return;
					}
					board[y][x] = "\x1B[93mP\033[0m";
					break;
				default:
					break;
				}
			}
		}
	}

wPieces wpawn1, wpawn2, wpawn3, wpawn4, wpawn5, wpawn6, wpawn7, wpawn8, wrook1, wrook2, wbishop1, wbishop2, whorse1, whorse2, wqueen, wking;

std::vector<wPieces*> wPiece;

int main()
{
	defaultLocations();
	drawBoard();

	while (true)
		switch (win)
		{
		case 0:
			if (turn == 0)
			{
				bMove();
			}
			if (turn == 1)
			{
				wMove();
			}
			break;
		case 1:
			drawBoard();
			std::cout << "black wins" << std::endl;
			return 0;
		case 2:
			drawBoard();
			std::cout << "white wins" << std::endl;
			return 0;
		case 3:
			drawBoard();
			std::cout << "draw white can't move" << std::endl;
			return 0;
		case 4:
			drawBoard();
			std::cout << "draw black can't move" << std::endl;
			return 0;
		default:
			drawBoard();
			std::cout << "stalemate" << std::endl;
			return 0;
		}
}