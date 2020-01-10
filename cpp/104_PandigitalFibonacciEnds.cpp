/******************************************************************************
* Program:
*    Pandigital Fibonacci Ends
* Author:
*    Ryan Gillett
******************************************************************************/
#include <iostream>

using namespace std;

//Prototypes
bool is9Pandigital(int value);
 
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	int a = 1;
	int b = 0;
	int c = 0;
	
	unsigned long long int x = 1;
	unsigned long long int y = 0;
	unsigned long long int z = 0;
	
	bool found = false;
	
	for (int i = 1; !found; i++)
	{
		//Calculate last 9 digits
		c = a + b;
		c %= 1000000000;
		a = b;
		b = c;
		
		//Calculate first 9 digits (with room for error)
		if (y >= 10000000000000000000)
		{
			x /= 10;
			y /= 10;
		}
		z = x + y;
		x = y;
		y = z;
		
		//Check if pandigital
		if (is9Pandigital(c))
		{
			while (z >= 1000000000)
			{
				z /= 10;
			}
			if (is9Pandigital(z))
			{
				cout << "Double Pandigital Fibonacci Number: " << i << endl;
				found = true;
			}
		}
	}

	return 0;
}

bool is9Pandigital(int value)
{
	bool digitExists[10] = {false};
	
	while (value > 0)
	{
		digitExists[value % 10] = true;
		value /= 10;
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