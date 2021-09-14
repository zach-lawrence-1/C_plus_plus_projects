#include<iostream>

using namespace std;

int x = 0;
int y = 1;
int sum;

void num1()
{
	sum = x + y;
	x = sum;
	cout << sum << endl;
}
void num2()
{
	sum = x + y;
	y = sum;
	cout << sum << endl;
}

int main()
{
	cout << x << endl << y << endl;
	for (int i = 0; i < 10; i++)
	{
		num1();
		num2();
	};
}