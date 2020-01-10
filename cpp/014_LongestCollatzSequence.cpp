/*******************************************************************************
* Largest Collatz Sequence
* Authors: Ryan Gillett
*******************************************************************************/
#include <iostream>

using namespace std;

//Prototypes
void nextCollatz(long long int &number);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int highestChainNum = 1;
	int highestChainCount = 1;
	for (int i = 1000000; i > 0; i--)
	{
		int count = 0;
		long long int collatz = i;
		while (collatz > 1)
		{
			nextCollatz(collatz);
			count++;
		}
		if (count > highestChainCount)
		{
			highestChainCount = count;
			highestChainNum = i;
		}
	}
	
	cout << highestChainNum << endl;
	
	return 0;
}

void nextCollatz(long long int &number)
{
	if (number % 2 == 0)
		number /= 2;
	else
	{
		number *= 3;
		number++;
	}
}