#pragma once
#include<iostream>
#include<string>
#include<vector>

//special variable, and replaces doing macros bc it is a precompiled constant
//because it is processed before runtime, it is more efficient to your program
constexpr int PAWN = 1;
constexpr int ROOK = 2;
constexpr int HORSE = 3;
constexpr int BISHOP = 4;
constexpr int QUEEN = 5;
constexpr int KING = 6;

extern int turn;
extern int win;
extern int bDead;
extern int wDead;

extern std::string BlackPawnCol;
extern std::string BlackRookCol;
extern std::string BlackBishopCol;
extern std::string BlackHorseCol;
extern std::string BlackQueenCol;
extern std::string BlackKingCol;

extern std::string whitePawnCol;
extern std::string whiteRookCol;
extern std::string whiteBishopCol;
extern std::string whiteHorseCol;
extern std::string whiteQueenCol;
extern std::string whiteKingCol;

extern std::string whiteTile;

extern std::string board[8][12];

//an array that stores color data of square
extern std::string tileColor[8][12];

class bPieces
{
public:
	int death;
	int movesMade;
	int x;
	int y;
	int check;
	int piece;
	int enPassantCnt;
	void dead(int numDead);
};
extern bPieces pawn1, pawn2, pawn3, pawn4, pawn5, pawn6, pawn7, pawn8, rook1, rook2, bishop1, bishop2, horse1, horse2, queen, king;

extern std::vector<bPieces*> bPiece;

class wPieces
{
public:
	int death;
	int movesMade;
	int x;
	int y;
	int check;
	int piece;
	int enPassantCnt;
	void dead(int numDead);
};
extern wPieces wpawn1, wpawn2, wpawn3, wpawn4, wpawn5, wpawn6, wpawn7, wpawn8, wrook1, wrook2, wbishop1, wbishop2, whorse1, whorse2, wqueen, wking;

extern std::vector<wPieces*> wPiece;

void defaultLocations();
void drawBoard();
void col(int selecty, int selectx, int curry, int currx, int piece);
void check();
int locAlg(int wx, int wy, int chngx, int chngy);
void checkmate();
void stalemate();
void newGame();
void save(std::string file);
void load(std::string file);
void saveSlot(std::string command);
void bMove();
void wMove();