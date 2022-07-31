#include"vars.h"
#include<fstream>

//restarts the game
void newGame()
{
	//black auto placement
	int a = 0;
	int px = 0;
	int py = 0;
	turn = 0;

	for (int i = 0; i < 16; i++)
	{
		px = bPiece[i]->x;
		py = bPiece[i]->y;
		bPiece[i]->death = 0;
		bPiece[i]->movesMade = 0;
		bPiece[i]->check = 0;
		bPiece[i]->enPassantCnt = 0;
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
			col(py, px, bPiece[i]->y, bPiece[i]->x, bPiece[i]->piece);
		}
		if (i > 7 && i < 10)
		{
			px = bPiece[i]->x;
			py = bPiece[i]->y;
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
			col(py, px, bPiece[i]->y, bPiece[i]->x, bPiece[i]->piece);
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
			col(py, px, bPiece[i]->y, bPiece[i]->x, bPiece[i]->piece);
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
			col(py, px, bPiece[i]->y, bPiece[i]->x, bPiece[i]->piece);
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
			col(py, px, bPiece[i]->y, bPiece[i]->x, bPiece[i]->piece);
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
			col(py, px, bPiece[i]->y, bPiece[i]->x, bPiece[i]->piece);
		}
	}
	//white auto placement
	a = 0;
	for (int i = 0; i < 16; i++)
	{
		px = wPiece[i]->x;
		py = wPiece[i]->y;
		wPiece[i]->death = 0;
		wPiece[i]->movesMade = 0;
		wPiece[i]->check = 0;
		wPiece[i]->enPassantCnt = 0;
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
			col(py, px, wPiece[i]->y, wPiece[i]->x, wPiece[i]->piece + 6);
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
			col(py, px, wPiece[i]->y, wPiece[i]->x, wPiece[i]->piece + 6);
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
			col(py, px, wPiece[i]->y, wPiece[i]->x, wPiece[i]->piece + 6);
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
			col(py, px, wPiece[i]->y, wPiece[i]->x, wPiece[i]->piece + 6);
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
			col(py, px, wPiece[i]->y, wPiece[i]->x, wPiece[i]->piece + 6);
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
			col(py, px, wPiece[i]->y, wPiece[i]->x, wPiece[i]->piece + 6);
		}
	}
	drawBoard();
}

//saves game to file
void save(std::string file)
{
	std::fstream File;
	File.open(file, std::ios::out);
	if (File.fail())
	{
		std::ofstream newFile(file);
		newFile.close();
		newFile.clear();
	}
	File.close();
	File.clear();

	File.open(file, std::ios::out);
	if (File.is_open())
	{
		for (auto& b : bPiece)
		{
			File << std::to_string(b->death).length() << b->death << std::to_string(b->movesMade).length() << b->movesMade << std::to_string(b->x).length() << b->x << std::to_string(b->y).length() << b->y << std::to_string(b->check).length() << b->check << std::to_string(b->piece).length() << b->piece << std::to_string(b->enPassantCnt).length() << b->enPassantCnt << std::to_string(win).length() << win << std::to_string(bDead).length() << bDead << std::to_string(wDead).length() << wDead << std::to_string(turn).length() << turn << "\n";
		}
		for (auto& w : wPiece)
		{
			File << std::to_string(w->death).length() << w->death << std::to_string(w->movesMade).length() << w->movesMade << std::to_string(w->x).length() << w->x << std::to_string(w->y).length() << w->y << std::to_string(w->check).length() << w->check << std::to_string(w->piece).length() << w->piece << std::to_string(w->enPassantCnt).length() << w->enPassantCnt << std::to_string(win).length() << win << std::to_string(bDead).length() << bDead << std::to_string(wDead).length() << wDead << std::to_string(turn).length() << turn << "\n";
		}
		File.close();
		File.clear();
		drawBoard();
		std::cout << "saved" << std::endl;
	}
}

//loads previously saved game
void load(std::string file)
{
	int px = 0;
	int py = 0;
	std::string p = "";
	std::string app = "";
	int size = 0;
	int cnt = 0;
	std::fstream File;
	std::string line = "";
	File.open(file, std::ios::in);
	if (File.fail())
	{
		File.close();
		File.clear();
		drawBoard();
		std::cout << "file cannot be opened " << std::endl;
	}
	if (File.is_open())
	{
		int ff = 0;
		for (auto& b : bPiece)
		{
			px = b->x;
			py = b->y;
			if (ff < 16)
			{
				getline(File, line);
			}
			else
			{
				break;
			}

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->death = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->movesMade = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->x = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->y = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->check = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->piece = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			b->enPassantCnt = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			win = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			bDead = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			wDead = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			turn = std::stoi(app);
			app = "";
			cnt = 0;

			if (px != b->x || py != b->y)
			{
				col(py, px, b->y, b->x, b->piece);
			}
			ff++;
		}
		for (auto& w : wPiece)
		{
			px = w->x;
			py = w->y;
			cnt = 0;
			app = "";

			if (ff < 32)
			{
				getline(File, line);
			}
			else
			{
				break;
			}
			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->death = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->movesMade = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->x = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->y = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->check = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->piece = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			w->enPassantCnt = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			win = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			bDead = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			wDead = std::stoi(app);
			app = "";

			p = line[cnt];
			size = std::stoi(p);
			cnt++;
			for (int i = 0; i < size; i++)
			{
				p = line[cnt];
				app.append(p);
				cnt++;
			}
			turn = std::stoi(app);
			app = "";
			cnt = 0;
			if (px != w->x || py != w->y)
			{
				col(py, px, w->y, w->x, w->piece + 6);
			}
			ff++;
		}
		File.close();
		File.clear();
		check();
		checkmate();
		stalemate();
		drawBoard();

		if (wking.check == 1)
		{
			std::cout << "white's in check" << std::endl;
			return;
		}
		if (king.check == 1)
		{
			std::cout << "black's in check" << std::endl;
			return;
		}
		std::cout << "loaded" << std::endl;
	}
}

//handles changes to saveslots
void saveSlot(std::string command)
{
	std::string fileName = "";
	std::vector<std::string> saveFiles;
	int size = 0;
	std::fstream File;
	int saveNum = 0;
	int newSave = 0;

	File.open("savefiles.txt", std::ios::in);
	if (File.fail())
	{
		std::ofstream newFile("saveFiles.txt");
		newFile.close();
	}
	if (File.is_open())
	{
		saveFiles.clear();
		while (getline(File, fileName))
		{
			saveFiles.push_back(fileName);
		}
		size = saveFiles.size();
		File.close();
		File.clear();
	}
	if (!saveFiles.empty())
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << " ____________________________________" << std::endl;
			std::cout << "|                                    |" << std::endl;
			int spaceOffset = 33 - saveFiles[i].length();

			std::cout << "| " << i + 1 << " " << saveFiles[i];
			for (int j = 0; j < spaceOffset; j++)
			{
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
			std::cout << "|____________________________________|" << std::endl;
		}

		if (command == "L")
		{
			std::cout << "Enter saveslot number: ";
			std::cin >> saveNum;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				drawBoard();
				std::cout << "cannot enter letter values" << std::endl;
				return;
			}
			if (saveNum <= size && saveNum > 0)
			{
				fileName = saveFiles[saveNum - 1];
			}
			else
			{
				drawBoard();
				std::cout << "saveslot number doesnt exist" << std::endl;
				return;
			}

			load(fileName);
		}
		if (command == "S")
		{
			std::cout << "To save to a previous save, enter 1. To create a new save press 2 ";
			std::cin >> newSave;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				drawBoard();
				std::cout << "cannot enter letter values" << std::endl;
				return;
			}

			switch (newSave)
			{
			case 1:
				std::cout << "Enter saveslot number: ";
				std::cin >> saveNum;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					drawBoard();
					std::cout << "cannot enter letter values" << std::endl;
					return;
				}
				if (saveNum <= size && saveNum > 0)
				{
					fileName = saveFiles[saveNum - 1];
				}
				else
				{
					drawBoard();
					std::cout << "saveslot number doesnt exist" << std::endl;
					return;
				}
				save(fileName);
				break;
			case 2:
				std::cout << "Enter the savefile name ";
				std::cin >> fileName;
				fileName.append(".txt");
				for (int i = 0; i < size; i++)
				{
					if (saveFiles[i] == fileName)
					{
						drawBoard();
						std::cout << "cannot enter the same name as another save" << std::endl;
						return;
					}
				}
				File.open("savefiles.txt", std::ios::app);
				File << fileName << "\n";
				File.close();
				File.clear();
				save(fileName);
				break;
			default:
				drawBoard();
				break;
			}
		}
		if (command == "D")
		{
			std::string temp = "";
			std::cout << "Enter saveslot number: ";
			std::cin >> saveNum;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				drawBoard();
				std::cout << "cannot enter letter values" << std::endl;
				return;
			}
			if (saveNum <= size && saveNum > 0)
			{
				fileName = saveFiles[saveNum - 1];
			}
			else
			{
				drawBoard();
				std::cout << "saveslot number doesnt exist" << std::endl;
				return;
			}
			std::cout << "Are you sure you want to delete " << fileName << "? y/n" << std::endl;
			std::cin >> temp;
			if (temp == "y")
			{
				saveFiles.erase(saveFiles.begin() + saveNum - 1);

				size = saveFiles.size();

				File.open("savefiles.txt", std::ios::out);
				if (File.is_open())
				{
					for (int i = 0; i < size; i++)
					{
						File << saveFiles[i] << "\n";
					}
				}
				File.close();
				File.clear();

				if (remove(fileName.c_str()) != 0)
				{
					drawBoard();
					std::cout << "Could not delete file" << std::endl;
					return;
				}
				drawBoard();
				std::cout << "File deleted successfully" << std::endl;
				return;
			}
		}
		return;
	}
	if (saveFiles.empty())
	{
		if (command == "S")
		{
			std::cout << "Enter the savefile name ";
			std::cin >> fileName;
			fileName.append(".txt");
			File.open("savefiles.txt", std::ios::app);
			File << fileName;
			File.close();
			File.clear();
			save(fileName);
			return;
		}
		drawBoard();
		std::cout << "no save files exist" << std::endl;
		return;
	}
}