/*******************************************************************************
* Smallest Multiple
* Authors: Ryan Gillett, Brandon Gillett
*******************************************************************************/
#include <iostream>

using namespace std;

//Prototypes
long long int lcm(long long int a, long long int b);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	long long int runningLCM = 1;

	for (int i = 1; i <= 20; i++)
	{
		runningLCM = lcm(runningLCM, i);
	}

	cout << "The smallest multiple of 1-20 is: " << runningLCM << endl;

	return 0;
}

long long int lcm(long long int a, long long int b)
{
	long long int x = a;
	long long int y = b;

	while (x != y)
	{
		if (x < y)
			x += a;
		else
			y += b;
	}

	return x;
}