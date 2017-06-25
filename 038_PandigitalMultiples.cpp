/******************************************************************************
* Program: Pandigital Multiples
* Author: Ryan Gillett
******************************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

bool isPandigital(unsigned int value);

#ifndef to_string
#include <sstream>
string to_string(long long i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}
#endif
 
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	unsigned answer = 0;

	for (int i = 1; i < 10000; i++)
	{
		string concatination = "";
		for (int j = 1; concatination.size() < 9; j++)
		{
			concatination += to_string(i * j);
		}
		unsigned numberToCheck = atoi(concatination.c_str());
		if (isPandigital(numberToCheck))
		{
			if (numberToCheck > answer)
			{
				answer = numberToCheck;
			}
		}
	}

	cout << answer << endl;

	return 0;
}

bool isPandigital(unsigned int value)
{
	bool digitExists[10] = {false};
	
	int numDigits = 0;

	while (value > 0)
	{
		digitExists[value % 10] = true;
		value /= 10;
		numDigits++;
	}

	if (numDigits != 9)
	{
		return false;
	}

	for (int i = 1; i <= numDigits; i++)
	{
		if (!digitExists[i])
		{
			return false;
		}
	}
	
	return true;
}