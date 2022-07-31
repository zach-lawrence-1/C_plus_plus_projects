#include"vars.h"

void defaultLocations()
{
	bPiece.push_back(&pawn1);
	bPiece.push_back(&pawn2);
	bPiece.push_back(&pawn3);
	bPiece.push_back(&pawn4);
	bPiece.push_back(&pawn5);
	bPiece.push_back(&pawn6);
	bPiece.push_back(&pawn7);
	bPiece.push_back(&pawn8);
	bPiece.push_back(&rook1);
	bPiece.push_back(&rook2);
	bPiece.push_back(&bishop1);
	bPiece.push_back(&bishop2);
	bPiece.push_back(&horse1);
	bPiece.push_back(&horse2);
	bPiece.push_back(&queen);
	bPiece.push_back(&king);

	wPiece.push_back(&wpawn1);
	wPiece.push_back(&wpawn2);
	wPiece.push_back(&wpawn3);
	wPiece.push_back(&wpawn4);
	wPiece.push_back(&wpawn5);
	wPiece.push_back(&wpawn6);
	wPiece.push_back(&wpawn7);
	wPiece.push_back(&wpawn8);
	wPiece.push_back(&wrook1);
	wPiece.push_back(&wrook2);
	wPiece.push_back(&wbishop1);
	wPiece.push_back(&wbishop2);
	wPiece.push_back(&whorse1);
	wPiece.push_back(&whorse2);
	wPiece.push_back(&wqueen);
	wPiece.push_back(&wking);

	//black auto placement
	int a = 0;
	for (int i = 0; i < 16; i++)
	{
		if (i < 8)
		{
			bPiece[i]->piece = PAWN;
			bPiece[i]->y = 6;
			bPiece[i]->x = a;
			a++;
			//check for tile color and change background based on that
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "w")
			{
				board[bPiece[i]->y][bPiece[i]->x] = BlackPawnCol;
			}
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "b")
			{
				board[bPiece[i]->y][bPiece[i]->x] = "\033[10;1;30mP\033[0m";
			}
		}
		if (i > 7 && i < 10)
		{
			bPiece[i]->piece = ROOK;
			bPiece[i]->y = 7;
			a = 0;
			if (i == 9)
			{
				a = 7;
			}
			bPiece[i]->x = a;
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "w")
			{
				board[bPiece[i]->y][bPiece[i]->x] = BlackRookCol;
			}
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "b")
			{
				board[bPiece[i]->y][bPiece[i]->x] = "\033[10;1;30mR\033[0m";
			}
		}
		if (i > 9 && i < 12)
		{
			a = 1;
			bPiece[i]->piece = HORSE;
			bPiece[i]->y = 7;
			if (i == 11)
			{
				a = 6;
			}
			bPiece[i]->x = a;
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "w")
			{
				board[bPiece[i]->y][bPiece[i]->x] = BlackHorseCol;
			}
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "b")
			{
				board[bPiece[i]->y][bPiece[i]->x] = "\033[10;1;30mH\033[0m";
			}
		}
		if (i > 11 && i < 14)
		{
			a = 2;
			bPiece[i]->piece = BISHOP;
			bPiece[i]->y = 7;
			if (i == 13)
			{
				a = 5;
			}
			bPiece[i]->x = a;
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "w")
			{
				board[bPiece[i]->y][bPiece[i]->x] = BlackBishopCol;
			}
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "b")
			{
				board[bPiece[i]->y][bPiece[i]->x] = "\033[10;1;30mB\033[0m";
			}
		}
		if (i == 14)
		{
			bPiece[i]->piece = QUEEN;
			bPiece[i]->y = 7;
			a = 4;
			bPiece[i]->x = a;
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "w")
			{
				board[bPiece[i]->y][bPiece[i]->x] = BlackQueenCol;
			}
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "b")
			{
				board[bPiece[i]->y][bPiece[i]->x] = "\033[10;1;30mQ\033[0m";
			}
		}
		if (i == 15)
		{
			bPiece[i]->piece = KING;
			bPiece[i]->y = 7;
			a = 3;
			bPiece[i]->x = a;
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "w")
			{
				board[bPiece[i]->y][bPiece[i]->x] = BlackKingCol;
			}
			if (tileColor[bPiece[i]->y][bPiece[i]->x] == "b")
			{
				board[bPiece[i]->y][bPiece[i]->x] = "\033[10;1;30mK\033[0m";
			}
		}
	}

	//white auto placement
	a = 0;
	for (int i = 0; i < 16; i++)
	{
		if (i < 8)
		{
			wPiece[i]->piece = PAWN;
			wPiece[i]->y = 1;
			wPiece[i]->x = a;
			a++;

			//check for tile color and change background based on that
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "w")
			{
				board[wPiece[i]->y][wPiece[i]->x] = whitePawnCol;
			}
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "b")
			{
				board[wPiece[i]->y][wPiece[i]->x] = "\x1B[93mP\033[0m";
			}
		}
		if (i > 7 && i < 10)
		{
			wPiece[i]->piece = ROOK;
			wPiece[i]->y = 0;
			a = 0;
			if (i == 9)
			{
				a = 7;
			}
			wPiece[i]->x = a;
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "w")
			{
				board[wPiece[i]->y][wPiece[i]->x] = whiteRookCol;
			}
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "b")
			{
				board[wPiece[i]->y][wPiece[i]->x] = "\x1B[93mR\033[0m";
			}
		}
		if (i > 9 && i < 12)
		{
			a = 1;
			wPiece[i]->piece = HORSE;
			wPiece[i]->y = 0;
			if (i == 11)
			{
				a = 6;
			}
			wPiece[i]->x = a;
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "w")
			{
				board[wPiece[i]->y][wPiece[i]->x] = whiteHorseCol;
			}
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "b")
			{
				board[wPiece[i]->y][wPiece[i]->x] = "\x1B[93mH\033[0m";
			}
		}
		if (i > 11 && i < 14)
		{
			a = 2;
			wPiece[i]->piece = BISHOP;
			wPiece[i]->y = 0;
			if (i == 13)
			{
				a = 5;
			}
			wPiece[i]->x = a;
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "w")
			{
				board[wPiece[i]->y][wPiece[i]->x] = whiteBishopCol;
			}
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "b")
			{
				board[wPiece[i]->y][wPiece[i]->x] = "\x1B[93mB\033[0m";
			}
		}
		if (i == 14)
		{
			wPiece[i]->piece = QUEEN;
			wPiece[i]->y = 0;
			a = 4;
			wPiece[i]->x = a;
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "w")
			{
				board[wPiece[i]->y][wPiece[i]->x] = whiteQueenCol;
			}
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "b")
			{
				board[wPiece[i]->y][wPiece[i]->x] = "\x1B[93mQ\033[0m";
			}
		}
		if (i == 15)
		{
			wPiece[i]->piece = KING;
			wPiece[i]->y = 0;
			a = 3;
			wPiece[i]->x = a;
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "w")
			{
				board[wPiece[i]->y][wPiece[i]->x] = whiteKingCol;
			}
			if (tileColor[wPiece[i]->y][wPiece[i]->x] == "b")
			{
				board[wPiece[i]->y][wPiece[i]->x] = "\x1B[93mK\033[0m";
			}
		}
	}
}

void drawBoard()
{
	system("cls");

	//your board
	std::cout << "       0      1      2      3      4      5      6      7             killed black pieces        killed white pieces" << std::endl << std::endl;
	std::cout << "    " << whiteTile << "    " << "   " << whiteTile << "   " << "    " << whiteTile << "   " << "    " << whiteTile << "   " << "                  " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << " 0 " << " " << "\033[100;47;10m   \033[0m" << board[0][0] << "\033[100;47;10m   \033[0m" << "   " << board[0][1] << "   " << "\033[100;47;10m   \033[0m" << board[0][2] << "\033[100;47;10m   \033[0m" << "   " << board[0][3] << "   " << "\033[100;47;10m   \033[0m" << board[0][4] << "\033[100;47;10m   \033[0m" << "   " << board[0][5] << "   " << "\033[100;47;10m   \033[0m" << board[0][6] << "\033[100;47;10m   \033[0m" << "   " << board[0][7] << "              1  " << "\033[100;47;10m   \033[0m" << board[0][8] << "\033[100;47;10m   \033[0m" << "   " << board[0][9] << "   " << "          1  " << "\033[100;47;10m   \033[0m" << board[0][10] << "\033[100;47;10m   \033[0m" << "   " << board[0][11] << std::endl;
	std::cout << "    " << whiteTile << "    " << "   " << whiteTile << "    " << "   " << whiteTile << "    " << "   " << whiteTile << "    " << "                 " << whiteTile << "       " "             " << whiteTile << std::endl;
	std::cout << "    " << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << " 1 " << "    " << board[1][0] << "   " << "\033[100;47;10m   \033[0m" << board[1][1] << "\033[100;47;10m   \033[0m" << "   " << board[1][2] << "   " << "\033[100;47;10m   \033[0m" << board[1][3] << "\033[100;47;10m   \033[0m" << "   " << board[1][4] << "   " << "\033[100;47;10m   \033[0m" << board[1][5] << "\033[100;47;10m   \033[0m" << "   " << board[1][6] << "   " << "\033[100;47;10m   \033[0m" << board[1][7] << "\033[100;47;10m   \033[0m" << "           2  " << "   " << board[1][8] << "   " << "\033[100;47;10m   \033[0m" << board[1][9] << "\033[100;47;10m   \033[0m" << "          2  " << "   " << board[1][10] << "   " << "\033[100;47;10m   \033[0m" << board[1][11] << "\033[100;47;10m   \033[0m" << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << " 2 " << " " << "\033[100;47;10m   \033[0m" << board[2][0] << "\033[100;47;10m   \033[0m" << "   " << board[2][1] << "   " << "\033[100;47;10m   \033[0m" << board[2][2] << "\033[100;47;10m   \033[0m" << "   " << board[2][3] << "   " << "\033[100;47;10m   \033[0m" << board[2][4] << "\033[100;47;10m   \033[0m" << "   " << board[2][5] << "   " << "\033[100;47;10m   \033[0m" << board[2][6] << "\033[100;47;10m   \033[0m" << "   " << board[2][7] << "              3  " << "\033[100;47;10m   \033[0m" << board[2][8] << "\033[100;47;10m   \033[0m" << "   " << board[2][9] << "   " << "          3  " << "\033[100;47;10m   \033[0m" << board[2][10] << "\033[100;47;10m   \033[0m" << "   " << board[2][11] << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << " 3 " << "    " << board[3][0] << "   " << "\033[100;47;10m   \033[0m" << board[3][1] << "\033[100;47;10m   \033[0m" << "   " << board[3][2] << "   " << "\033[100;47;10m   \033[0m" << board[3][3] << "\033[100;47;10m   \033[0m" << "   " << board[3][4] << "   " << "\033[100;47;10m   \033[0m" << board[3][5] << "\033[100;47;10m   \033[0m" << "   " << board[3][6] << "   " << "\033[100;47;10m   \033[0m" << board[3][7] << "\033[100;47;10m   \033[0m" << "           4  " << "   " << board[3][8] << "   " << "\033[100;47;10m   \033[0m" << board[3][9] << "\033[100;47;10m   \033[0m" << "          4  " << "   " << board[3][10] << "   " << "\033[100;47;10m   \033[0m" << board[3][11] << "\033[100;47;10m   \033[0m" << std::endl;
	std::cout << "           " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << " 4 " << " " << "\033[100;47;10m   \033[0m" << board[4][0] << "\033[100;47;10m   \033[0m" << "   " << board[4][1] << "   " << "\033[100;47;10m   \033[0m" << board[4][2] << "\033[100;47;10m   \033[0m" << "   " << board[4][3] << "   " << "\033[100;47;10m   \033[0m" << board[4][4] << "\033[100;47;10m   \033[0m" << "   " << board[4][5] << "   " << "\033[100;47;10m   \033[0m" << board[4][6] << "\033[100;47;10m   \033[0m" << "   " << board[4][7] << "   " << "           5  " << "\033[100;47;10m   \033[0m" << board[4][8] << "\033[100;47;10m   \033[0m" << "   " << board[4][9] << "   " << "          5  " << "\033[100;47;10m   \033[0m" << board[4][10] << "\033[100;47;10m   \033[0m" << "   " << board[4][11] << "   " << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << " 5 " << "    " << board[5][0] << "   " << "\033[100;47;10m   \033[0m" << board[5][1] << "\033[100;47;10m   \033[0m" << "   " << board[5][2] << "   " << "\033[100;47;10m   \033[0m" << board[5][3] << "\033[100;47;10m   \033[0m" << "   " << board[5][4] << "   " << "\033[100;47;10m   \033[0m" << board[5][5] << "\033[100;47;10m   \033[0m" << "   " << board[5][6] << "   " << "\033[100;47;10m   \033[0m" << board[5][7] << "\033[100;47;10m   \033[0m" << "           6  " << "   " << board[5][8] << "   " << "\033[100;47;10m   \033[0m" << board[5][9] << "\033[100;47;10m   \033[0m" << "          6  " << "   " << board[5][10] << "   " << "\033[100;47;10m   \033[0m" << board[5][11] << "\033[100;47;10m   \033[0m" << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << " 6 " << " " << "\033[100;47;10m   \033[0m" << board[6][0] << "\033[100;47;10m   \033[0m" << "   " << board[6][1] << "   " << "\033[100;47;10m   \033[0m" << board[6][2] << "\033[100;47;10m   \033[0m" << "   " << board[6][3] << "   " << "\033[100;47;10m   \033[0m" << board[6][4] << "\033[100;47;10m   \033[0m" << "   " << board[6][5] << "   " << "\033[100;47;10m   \033[0m" << board[6][6] << "\033[100;47;10m   \033[0m" << "   " << board[6][7] << "   " << "           7  " << "\033[100;47;10m   \033[0m" << board[6][8] << "\033[100;47;10m   \033[0m" << "   " << board[6][9] << "   " << "          7  " << "\033[100;47;10m   \033[0m" << board[6][10] << "\033[100;47;10m   \033[0m" << "   " << board[6][11] << std::endl;
	std::cout << "    " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << "              " << whiteTile << "       " << "             " << whiteTile << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
	std::cout << " 7 " << "    " << board[7][0] << "   " << "\033[100;47;10m   \033[0m" << board[7][1] << "\033[100;47;10m   \033[0m" << "   " << board[7][2] << "   " << "\033[100;47;10m   \033[0m" << board[7][3] << "\033[100;47;10m   \033[0m" << "   " << board[7][4] << "   " << "\033[100;47;10m   \033[0m" << board[7][5] << "\033[100;47;10m   \033[0m" << "   " << board[7][6] << "   " << "\033[100;47;10m   \033[0m" << board[7][7] << "\033[100;47;10m   \033[0m" << "           8  " << "   " << board[7][8] << "   " << "\033[100;47;10m   \033[0m" << board[7][9] << "\033[100;47;10m   \033[0m" << "          8  " << "   " << board[7][10] << "   " << "\033[100;47;10m   \033[0m" << board[7][11] << "\033[100;47;10m   \033[0m" << std::endl;
	std::cout << "         " << "  " << whiteTile << "       " << whiteTile << "       " << whiteTile << "       " << whiteTile << "                     " << whiteTile << "             " << "       " << whiteTile << std::endl;
}

//displays new piece position
void col(int selecty, int selectx, int curry, int currx, int piece)
{
	if (tileColor[selecty][selectx] == "w")
	{
		board[selecty][selectx] = "\033[100;47;10m \033[0m";
	}
	if (tileColor[selecty][selectx] == "b")
	{
		board[selecty][selectx] = " ";
	}

	//black
	switch (piece)
	{
		//pawn
	case 1:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = BlackPawnCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\033[10;1;30mP\033[0m";
		}
		break;
		//rook
	case 2:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = BlackRookCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\033[10;1;30mR\033[0m";
		}
		break;
		//horse
	case 3:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = BlackHorseCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\033[10;1;30mH\033[0m";
		}
		break;
		//bishop
	case 4:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = BlackBishopCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\033[10;1;30mB\033[0m";
		}
		break;
		//queen
	case 5:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = BlackQueenCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\033[10;1;30mQ\033[0m";
		}
		break;
		//king
	case 6:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = BlackKingCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\033[10;1;30mK\033[0m";
		}
		break;

		//white

		//pawn
	case 7:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = whitePawnCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\x1B[93mP\033[0m";
		}
		break;
		//rook
	case 8:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = whiteRookCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\x1B[93mR\033[0m";
		}
		break;
		//horse
	case 9:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = whiteHorseCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\x1B[93mH\033[0m";
		}
		break;
		//bishop
	case 10:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = whiteBishopCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\x1B[93mB\033[0m";
		}
		break;
		//queen
	case 11:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = whiteQueenCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\x1B[93mQ\033[0m";
		}
		break;
		//king
	case 12:
		if (tileColor[curry][currx] == "w")
		{
			board[curry][currx] = whiteKingCol;
		}
		if (tileColor[curry][currx] == "b")
		{
			board[curry][currx] = "\x1B[93mK\033[0m";
		}
		break;
	}
}