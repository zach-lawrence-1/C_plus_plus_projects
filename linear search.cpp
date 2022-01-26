#include<iostream>

using namespace std;

int Nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int linearSearch(int array[10], int target)
{
	for (int i = 0; i < 10; i++)
	{
		if (array[i] == target)
		{
			return i;
		}
	}
	return 0;
}

void verify(int location)
{
	if (location != 0)
	{
		cout << "target was found at: " << location;
	}
	if (location == 0)
	{
		cout << "target was not found";
	}
}

int main()
{
	int result = linearSearch(Nums, 5);
	verify(result);
}