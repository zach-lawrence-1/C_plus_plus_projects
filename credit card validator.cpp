#include<iostream>
#include <array>

using namespace std;

long long creditcard = 379354508162306;
int type;
int valid = 0;
array <int, 19> cardbits{};
int digits;
int length = log10(creditcard) + 1;
int sum;
int sum1;

void validate()
{
	if (valid == 1)
	{
		cout << "card is valid" << endl;
	}
	if (valid == 0)
	{
		cout << "card is invalid" << endl;
	}
	return;
}

void cardbreakup()
{
	if (length < 13)
	{
		valid = 0;
		cout << "card number is too short" << endl;
	}
	cout << "card number: " << creditcard << endl;
	for (int i = 0; i < length; i++)
	{
		digits = creditcard % 10;
		creditcard /= 10;
		cardbits[i] = digits;
	}
}

// not sure which card check yet
void cardcheck()
{
	//break card number up into array or other data type and then run luhn algorithm to validate card
	for (int j = 1; j < length; j += 2)
	{
		cardbits[j] *= 2;
		if (cardbits[j] > 9)
		{
			int c = cardbits[j] % 10;
			int d = cardbits[j] /= 10;
			cardbits[j] = c + d;
		}
		sum += cardbits[j];
	}
	for (int k = 0; k < length; k += 2)
	{
		sum1 += cardbits[k];
	}
	sum += sum1;
	sum %= 10;
	if (sum == 0)
	{
		valid = 1;
	}
}

void cardtype()
{
	// do switch case instead
	if (cardbits[length - 1] == 4)
	{
		cout << "type: Visa Card" << endl;
		cardcheck();
	}
	if ((cardbits[length - 1] == 3) && (cardbits[length - 2] == 7))
	{
		cout << "type: American Express" << endl;
		cardcheck();
	}
	if (cardbits[length - 1] == 5)
	{
		cout << "type: Master Card" << endl;
		cardcheck();
	}
	if (cardbits[length - 1] == 6)
	{
		cout << "type: Discover Card" << endl;
		cardcheck();
	}
}

int main()
{
	cardbreakup();
	cardtype();
	validate();
}