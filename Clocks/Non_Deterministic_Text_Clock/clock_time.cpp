#include <iostream>
#include <thread>

int main()
{
    //clear console output
    std::cout << "\033[2J";
    std::cout << "\033[0;0H";

    while (true)
    {
        //set console cursor position to (0, 0)
        std::cout << "\033[0;0H";
        
        //get current time
        time_t currTime = time(0);
        tm* localTime = localtime(&currTime);

        //get the hours, minutes, and seconds from localTime struct
        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;
        int second = localTime->tm_sec;

        std::cout << "Time: " << hour << ":" << minute << ":" << second << std::endl;
        std::cout << "\033[0;0H";

        //cross platform sleep method
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
