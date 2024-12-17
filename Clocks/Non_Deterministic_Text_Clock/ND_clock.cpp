#include <iostream>
#include <string>
#include <thread>

//generates a fixed size block of random characters
std::string RandomBlockGenerator()
{
    //create seed for RNG
    srand(time(0));

    std::string charsAndNums = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890=";
    std::string randomStr = "";

    for (int row = 0; row < 7; row++)
    {
        for (int col = 0; col < 58; col++)
        {
            //pick random index from charsAndNums and add that char to randomStr
            int randomNumber = rand() % 37;
            randomStr.push_back(charsAndNums[randomNumber]);
        }
        randomStr.append("\n");
    }

    return randomStr;
}

void ExtractCurrentTime(int clockDigits[8])
{
    //get the current time
    time_t currTime = time(0);
    tm* localTime = localtime(&currTime);

    //get the hours, minutes, and seconds from localTime struct
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    int second = localTime->tm_sec;

    clockDigits[0] = hour / 10;
    clockDigits[1] = hour % 10;
    clockDigits[2] = 10;
    clockDigits[3] = minute / 10;
    clockDigits[4] = minute % 10;
    clockDigits[5] = 10;
    clockDigits[6] = second / 10;
    clockDigits[7] = second % 10;
}

void PrintClock(unsigned long int clock[11], int clockDigits[8], std::string &textBlock)
{
    textBlock.insert(0, "\033[38;5;244m");
    int strIndex = 0;

    for (int y = 0; y < 7; y++)
    {
        //skip first and last layers of text
        if (y == 0 || y == 6)
        {
            strIndex = 72;
            continue;
        }

        //coloring logic
        for (int j = 0; j < 8; j++)
        {
            bool color = 0;
            unsigned long int temp = (clock[clockDigits[j]] >> 5 * (y - 1)) & 31;

            for (int k = 0; k < 5; k++)
            {
                bool currBit = (temp << k) & 16;
                if (currBit == 1 && color == 0)
                {
                    textBlock.insert(strIndex, "\033[1;43;33m");
                    strIndex += 11;
                    color = 1;
                }
                else if (currBit == 0 && color == 1)
                {
                    textBlock.insert(strIndex, "\033[0m\033[38;5;244m");
                    strIndex += 16;
                    color = 0;
                }
                else
                {
                    strIndex++;
                }
            }

            textBlock.insert(strIndex, "\033[0m\033[38;5;244m");
            strIndex += 17;
        }

        strIndex += 3;
    }

    std::cout << textBlock << std::endl;
}

int main()
{
    //these numbers represent each digit/char possible in the clock including :
    unsigned long int clock[11] = {33080895, 32641676, 15862318, 32545855,
                                   4357780, 32570911, 33095199, 1082431, 
                                   33095231, 32570943, 131200
                                  };
    int clockDigits[8];
    bool exit = false;

    //ansi escape codes for clearing screen and setting console position respectively
    std::cout << "\033[2J";
    std::cout << "\033[0;0H";

    while (!exit)
    {
        std::cout << "\033[0;0H";

        std::string randomText = RandomBlockGenerator();
        ExtractCurrentTime(clockDigits);
        PrintClock(clock, clockDigits, randomText);
    
        std::cout << "\033[0;0H";

        //cross platform sleep for the current thread which is the main thread
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
