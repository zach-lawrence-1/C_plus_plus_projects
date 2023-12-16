#include<iostream>
#include<vector>
#include<string>

std::vector<double> xtable;
std::vector<double> ytable;

void eulers(int numSteps, double stepLen, double x, double y)
{
	std::cout << "|___" << "X" << "___|____" << "Y" << "____|" << std::endl;
	xtable.push_back(x);
	ytable.push_back(y);
	for (int i = 0; i < numSteps; i++)
	{
		//eulers method newy = y + (dy/dx)*deltax
		double derivEq = (y) + (.5*(x+y))* stepLen;
		x += stepLen;
		y = derivEq;
		//stores x and y values to vector data type
		xtable.push_back(x);
		ytable.push_back(y);
	}
}

//counts number of digits after decimal point and outputs _ for formatting
int Count(double d)
{
	int count = 0;
	std::string s = std::to_string(d);

	bool b = false;

	for (int i = 0; i < s.length(); i++)
	{
		if (b == true)
		{
			count++;
			if (s[i] == '0' && s[i + 1] == '0')
			{
				count--;
			}
		}
		if (s[i] == '.')
		{
			b = true;
		}
	}

	if (s[s.length()] == 0)
	{
		count--;
	}

	while (count > 5)
	{
		s.pop_back();
		count--;
	}

	return count;
}

int main()
{
	//eulers function ran with these parameters
	eulers(6, 1, .2, 1.11);


	//prints out chart
	for (int i = 0; i < xtable.size(); i++)
	{
		std::cout << "|__" << xtable[i];

		if (Count(xtable[i]) == 1)
		{
			std::cout << "_";
		}
		if (Count(xtable[i]) == 0)
		{
			std::cout << "___";
		}

		std::cout << "_|_" << ytable[i];
		
		switch (Count(ytable[i]))
		{
		case 4:
			std::cout << "_";
			break;
		case 3:
			std::cout << "__";
			break;
		case 2:
			std::cout << "___";
			break;
		case 1:
			std::cout << "____";
			break;
		case 0:
			std::cout << "______";
			break;
		}

		std::cout << "_|" << std::endl;
	}
}