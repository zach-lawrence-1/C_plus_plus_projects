#include <iostream>
#include <bitset>

int main()
{
    //these are going to represent the clock digits in clock array
    //0: 11111 10001 10001 10001 11111 -> 11111 10001 10001 10001 11111
    //1: 01100 10100 00100 00100 11111 -> 11111 00100 00100 10100 01100
    //2: 01110 10001 00010 00100 01111 -> 01111 00100 00010 10001 01110
    //3: 11111 00001 00111 00001 11111 -> 11111 00001 00111 00001 11111
    //4: 10100 10100 11111 00100 00100 -> 00100 00100 11111 10100 10100
    //5: 11111 10000 11111 00001 11111 -> 11111 00001 11111 10000 11111
    //6: 11111 10000 11111 10001 11111 -> 11111 10001 11111 10000 11111
    //7: 11111 00001 00001 00001 00001 -> 00001 00001 00001 00001 11111
    //8: 11111 10001 11111 10001 11111 -> 11111 10001 11111 10001 11111
    //9: 11111 10001 11111 00001 11111 -> 11111 00001 11111 10001 11111
    //:: 00000 00100 00000 00100 00000 -> 00000 00100 00000 00100 00000

    unsigned long int clock[11] = {33080895, 32641676, 15862318, 32545855,
                                   4357780, 32570911, 33095199, 1082431, 
                                   33095231, 32570943, 131200
                                  };
    
    //display all numbers
    std::cout << "\033[38;5;244m###############################################################################" << std::endl;
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\033[38;5;244m##";

        for (int j = 0; j < 11; j++)
        {
            std::string numberSlice = "";
            bool color = 0;
            
            //shift out each group of 5 bits which are the clock digits from
            //top to bottom
            unsigned long int temp = (clock[j] >> 5 * i) & 31;

            for (int k = 0; k < 5; k++)
            {
                //shift out each bit from the group so we know when to color
                bool currBit = (temp << k) & 16;
                
                if (currBit == 1 && color == 0)
                {
                    numberSlice.append("\033[1;33m#");
                    color = 1;
                }
                else if (currBit == 1 && color == 1)
                {
                    numberSlice.append("#");
                }
                else if (currBit == 0 && color == 1)
                {
                    numberSlice.append("\033[38;5;244m#");
                    color = 0;
                }
                else
                {
                    numberSlice.append("#");
                }
            }
            std::cout << numberSlice << "\033[38;5;244m##";
        }
        std::cout << std::endl;
    }
    std::cout << "\033[38;5;244m###############################################################################" << std::endl;
}