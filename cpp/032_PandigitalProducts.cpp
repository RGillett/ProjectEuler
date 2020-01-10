/******************************************************************************
* Program: Pandigital Products
* Author: Ryan Gillett
******************************************************************************/
#include <iostream>
#include <set>

using namespace std;

//Prototypes
bool is9Pandigital(int op1, int op2, long product);
 
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	set<long> products;
	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 10000; j ++)
		{
			if (is9Pandigital(i, j, i*j))
			{
				products.insert(i*j);
			}
		}
	}

	long sum = 0;
	for (set<long int>::iterator it = products.begin(); it != products.end(); it++)
	{
		cout << *it << endl;
		sum += *it;
	}

	cout << sum << endl;

	return 0;
}

bool is9Pandigital(int op1, int op2, long product)
{
	bool digitExists[10] = {false};
	int values[3] = {op1, op2, product};

	for (int i = 0; i < 3; i++)
	{
		while (values[i] > 0)
		{
			if (digitExists[values[i] % 10] == true)
			{
				return false;
			}
			digitExists[values[i] % 10] = true;
			values[i] /= 10;
		}
	}

	if (digitExists[0] == true)
	{
		return false;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (!digitExists[i])
		{
			return false;
		}
	}
	
	return true;
}