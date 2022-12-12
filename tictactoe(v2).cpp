#include<iostream>
#include<string>

std::string arr[] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

//displays board
void drawBoard()
{
	system("cls");
	//reference points
	std::cout << "      |     |     " << std::endl;
	std::cout << "   1  |  2  |  3  " << std::endl;
	std::cout << " _____|_____|_____" << std::endl;
	std::cout << "      |     |     " << std::endl;
	std::cout << "   4  |  5  |  6  " << std::endl;
	std::cout << " _____|_____|_____" << std::endl;
	std::cout << "      |     |     " << std::endl;
	std::cout << "   7  |  8  |  9  " << std::endl;
	std::cout << "      |     |     " << std::endl;
	std::cout << "\n\n\n";

	//main board
	std::cout << "      |     |     " << std::endl;
	std::cout << "   " << arr[0] << "  |  " << arr[1] << "  |  " << arr[2] << "  " << std::endl;
	std::cout << " _____|_____|_____" << std::endl;
	std::cout << "      |     |     " << std::endl;
	std::cout << "   " << arr[3] << "  |  " << arr[4] << "  |  " << arr[5] << "  " << std::endl;
	std::cout << " _____|_____|_____" << std::endl;
	std::cout << "      |     |     " << std::endl;
	std::cout << "   " << arr[6] << "  |  " << arr[7] << "  |  " << arr[8] << "  " << std::endl;
	std::cout << "      |     |     " << std::endl;
}

//takes in user input and only returns value if it is valid
int userInput(int turn)
{
	//maybe change to get int input and do try except on that, would take less memory and less code potentially
	int numVal = 0;
	while (true) {
		numVal = 0;
		std::string loc = "";
		std::cout << "Player " << turn + 1 << "s turn, enter a location on the board: ";
		std::cin >> loc;
		try
		{
			numVal = std::stoi(loc);
		}
		catch (const std::invalid_argument& ia)
		{
			drawBoard();
			std::cout << "Invalid input" << std::endl;
			continue;
		}
		if (numVal > 9)
		{
			drawBoard();
			std::cout << "Cannot enter a value above 9" << std::endl;
			continue;
		}
		if (arr[numVal - 1] != " ")
		{
			drawBoard();
			std::cout << "Location already taken" << std::endl;
			continue;
		}
		return numVal - 1;
	}
}

//determines which player won
int endGame()
{
	//row checks
	for (int i = 0; i < 9; i += 3)
	{
		if (arr[i] == arr[i+1] && arr[i+1] == arr[i+2] && arr[i] != " ")
		{
			return 1;
		}
	}

	//column checks
	for (int i = 0; i < 3; i += 1)
	{
		if (arr[i] == arr[i + 3] && arr[i + 3] == arr[i + 6] && arr[i] != " ")
		{
			return 1;
		}
	}

	//diagonal checks
	if (arr[0] == arr[4] && arr[4] == arr[8] && arr[0] != " ")
	{
		return 1;
	}
	else if (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] != " ")
	{
		return 1;
	}
	return 0;
}

//runs main game loop
int main() 
{
	int turn = 0;
	while (true) 
	{
		if (turn == 1)
		{
			drawBoard();
			int numVal = userInput(turn);
			arr[numVal] = "O";
			if (endGame() == 1)
			{
				drawBoard();
				std::cout << "player " << turn + 1 << " won";
				return 0;
			}
			turn = 0;
			continue;
		}
		drawBoard();
		int numVal = userInput(turn);
		arr[numVal] = "X";
		if (endGame() == 1)
		{
			drawBoard();
			std::cout << "player " << turn + 1 << " won";
			return 0;
		}
		turn = 1;
	}
}