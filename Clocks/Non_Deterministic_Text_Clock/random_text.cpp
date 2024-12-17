#include <random>
#include <iostream>
#include <string>
#include <thread>

//generates a fixed size block of random characters
std::string randomBlockGenerator()
{
    //create seed for RNG
    srand(time(0));

    std::string charsAndNums = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890=";
    std::string randomStr = "";

    for (int row = 0; row < 7; row++)
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
    //clear console output
    std::cout << "\033[2J";
    std::cout << "\033[0;0H";
    
    while (true)
    {
        //set console cursor position to (0, 0)
        std::cout << "\033[0;0H";
        std::string temp = randomBlockGenerator();
        std::cout << temp << std::endl;
        std::cout << temp.substr(0, 5);
        std::cout << "\033[0;0H";

        //cross platform sleep method
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
