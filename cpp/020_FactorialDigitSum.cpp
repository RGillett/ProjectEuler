/*******************************************************************************
* Factorial Digit Sum
* Authors: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <cassert>

using namespace std;

//Prototypes
long long int factorial(int);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	factorial(100);
	return 0;
}

long long int factorial(int value)
{
	assert (value >= 0);
	
	long long int product = 1;
	
	for (int i = value; i > 0; i--)
	{
		product *= i;
		cout << product << endl;
	}
	
	return product;
}