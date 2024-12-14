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

    std::cout << "Time: " << clockDigits[0] << clockDigits[1] << ":" << clockDigits[3] << clockDigits[4] << ":" << clockDigits[6] << clockDigits[7] << std::endl;
}

void PrintClock(unsigned long int clock[11], int clockDigits[8], std::string textBlock)
{
    textBlock.insert(0, "\033[38;5;244m");
    int strIndex = 0;

    for (int y = 0; y < 7; y++)
    {
        //skip first and last layers of text
        if (y == 0 || y == 6)
        {
            strIndex = 70;
            continue;
        }

        for (int j = 0; j < 8; j++)
        {
            //std::cout << "curr Y: " << y << std::endl;
            //std::cout << "curr j: " << j << std::endl;
            //std::cout << "index: " << strIndex << " size: " << textBlock.length() << std::endl;

            bool color = 0;
            unsigned long int temp = (clock[clockDigits[j]] >> 5 * (y - 1)) & 31;

            for (int k = 0; k < 5; k++)
            {
                bool currBit = (temp << k) & 16;
                if (currBit == 1 && color == 0)
                {
                    textBlock.insert(strIndex, "\033[1;33m");
                    strIndex += 8;
                    color = 1;
                }
                else if (currBit == 0 && color == 1)
                {
                    textBlock.insert(strIndex, "\033[38;5;244m");
                    strIndex += 12;
                    color = 0;
                }
                else
                {
                    strIndex++;
                }
            }
            textBlock.insert(strIndex, "\033[38;5;244m");
            strIndex += 13;
        }
    }

    //std::cout << "tetetete" << std::endl;
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
    
    std::string randomText = RandomBlockGenerator();
    std::cout << randomText << std::endl;
    ExtractCurrentTime(clockDigits);
    PrintClock(clock, clockDigits, randomText);
}