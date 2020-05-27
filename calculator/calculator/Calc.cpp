#include "Calc.h"

double Calc::Calculate(double x, char oper, double y)
{
	switch (oper)
	//checks which operator was provided
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	default:
		return 0.0;
	}
}
