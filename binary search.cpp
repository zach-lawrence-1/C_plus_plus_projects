#include<iostream>
#include<vector>

std::vector<int> Nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int size = Nums.size();

int binarySearch(std::vector<int>& vec, int target)
{
	int first = 0;
	int last = (size - 1);

	while (first <= last)
	{
		int midpoint = (first + last) / 2;

		if (vec[midpoint] == target)
		{
			return midpoint;
		}
		else if (vec[midpoint] < target)
		{
			first = midpoint + 1;
		}
		else
		{
			last = midpoint - 1;
		}
	}
	return 0;
}

void verify(int location)
{
	if (location != 0)
	{
		std::cout << "target was found at: " << location;
	}
	if (location == 0)
	{
		std::cout << "target was not found";
	}
}

int main()
{
	int result = binarySearch(Nums, 5);
	verify(result);
}