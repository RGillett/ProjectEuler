#include <iostream>
using namespace std;

int nextDenominator();
int sumDigits(long int);

const int SEARCH = 100;

void main()
{
	long int a, n, d, temp;
	n = 1;
	d = nextDenominator();
	a = nextDenominator();
	for (int i = 0; i < SEARCH - 1; i++)
	{
		temp = d;
		d = a*d + n;
		n = temp;
		a = nextDenominator();
		cout << d << endl;
	}

	cout << sumDigits(d) << endl;
}

int nextDenominator()
{
	static int count = SEARCH + 1;
	count--;
	if (count < 1)
		return 0;

	if (count == 1)
		return 2;

	if (count % 3 == 0)
	{
		return (count / 3) * 2;
	}

	return 1;
}

int sumDigits(long int number)
{
	int sum = 0;

	while (number > 0)
	{
		sum += number % 10;
		number = number / 10;
	}

	return sum;
}