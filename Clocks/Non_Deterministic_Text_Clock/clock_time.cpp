#include <ctime>
#include <iostream>
#include <thread>
#include <windows.h>

int main()
{
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = {0, 0};
    system("cls");

    //change this later
    while (true)
    {
        SetConsoleCursorPosition(consoleHandler, topLeft);
        //get current time
        time_t currTime = time(0);
        tm* localTime = localtime(&currTime);

        //get the hours, minutes, and seconds from localTime struct
        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;
        int second = localTime->tm_sec;

        std::cout << "Time: " << hour << ":" << minute << ":" << second << std::endl;
        SetConsoleCursorPosition(consoleHandler, topLeft);
        //cross platform sleep method
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}