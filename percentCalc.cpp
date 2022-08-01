#include<iostream>
#include<string>
#include<vector>

struct items
{
	std::string name;
	double amount;
};

std::vector<items> stuff;

int main()
{
	std::string dataName = "";
	std::string copy = "";
	std::string itemName = "";
	double num = 0;
	int itemNum = 0;
	std::cout << "please enter what you want to name this collection of percentage data: ";
	std::cin >> dataName;
	std::cout << "Please enter the amount of items you want to create a percentage from: ";
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		std::cout << std::endl << "Please enter the name of this item: ";
		std::cin >> itemName;
		copy = itemName;
		items itemName;
		itemName.name = copy;
		std::cout << std::endl << "Please enter the amount of this item: ";
		std::cin >> itemNum;
		itemName.amount = itemNum;
		stuff.push_back(itemName);
	}
	num = 0;
	for (auto s : stuff)
	{
		num += s.amount;
	}
	std::cout << std::endl << std::endl << dataName << std::endl << std::endl << "total amount of items: " << num << std::endl;
	for (auto s : stuff)
	{
		std::cout << "name: " << s.name << " amount: " << s.amount << " percentage: " << (s.amount/num)*100 << "%" << std::endl;
	}
}