#include <iostream>
#include "Calc.h"
/*#include statements allow you to reference code located in other files. 
Sometimes, you may see a filename surrounded by angle brackets (<>); 
other times, it's surrounded by quotes (" "). In general, angle brackets 
are used when referencing the C++ Standard Library, while quotes are used for other files.*/
using namespace std;
/*using namespcae std tells the compiler to expect stuff from the C++ Standard Library 
to be used in this file. */
/*All C++ statements must end with semicolons and all C++ applications must contain a main() function. 
This function is what the program runs at the start. All code must be accessible from main() 
in order to be used.*/
int main()
{
    //variables
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';

    cout << "This is a claculator in C++" << endl;
    //cout tells the compiler to expect stuff from the C++ Standard Library to be used in this file.
    cout << "Please enter calculation with the format of: a+b | a-b | a*b | a/b" << endl;

    Calc c;
    //The Calculator c; line declares an object named 'c' as an instance of the Calculator class.
    while (true)
    {
        //cin waits for user input
        cin >> x >> oper >> y;
        if (oper == '/' && y == '0')
        {
            cout << "Division by 0" << endl;
            continue;
        }
        else
        {
            result = c.Calculate(x, oper, y);
        }
        // the red dot on the side is a breakpoint that pauses the execution if dividing by 0
        //result is a variable that calls the calculate function so you can use it later
        cout << "Result is: " << result << endl;
    }

    return 0;
}