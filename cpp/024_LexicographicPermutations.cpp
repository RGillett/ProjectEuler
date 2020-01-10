/******************************************************************************
* Program:
*    Lexicographic Permutations
* Author:
*    Ryan Gillett
******************************************************************************/
#include <iostream>
#include <cassert>

using namespace std;

//Prototypes
bool isPandigital(unsigned long int);
 
/******************************************************************************
* Driver
******************************************************************************/
int main()
{
	int count = 0;
	for (unsigned long int i = 123456789; i < 10000000000; i++)
	{
		if (isPandigital(i))
		{
			cout << count << "\n";
			count++;
			if (count == 1000000)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	
	assert (false);
	return 0;
}

bool isPandigital(unsigned long int value)
{
	bool digitExists[10] = {false};
	
	if (value < 1000000000)
	{
		digitExists[0] = true;
	}
	
	while (value > 0)
	{
		digitExists[value % 10] = true;
		value /= 10;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (!digitExists[i])
		{
			return false;
		}
	}
	
	return true;
}