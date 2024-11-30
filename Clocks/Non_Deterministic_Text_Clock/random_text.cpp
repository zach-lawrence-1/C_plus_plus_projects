#include <random>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <stdlib.h>
#include <windows.h>

//generates a fixed size block of random characters
std::string randomBlockGenerator()
{
    //create seed for RNG
    srand(time(0));

    std::string charsAndNums = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890=";
    std::string randomStr = "";

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 56; col++)
        {
            //pick random index from charsAndNums and add that char to randomStr
            int randomNumber = rand() % 37;
            randomStr.push_back(charsAndNums[randomNumber]);
        }
        randomStr.append("\n");
    }

    return randomStr;
}

int main()
{
    //TODO: cross platform - make this stuff able to run cross platform

    //windows only stuff
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = {0, 0};
    system("cls");
    
    //change this later
    while (true)
    {
        //works for now, may need a better way of doing this
        SetConsoleCursorPosition(consoleHandler, topLeft);
        std::string temp = randomBlockGenerator();
        std::cout << temp;
        SetConsoleCursorPosition(consoleHandler, topLeft);
        //cross platform sleep method
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}