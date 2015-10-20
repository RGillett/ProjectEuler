/*******************************************************************************
* Special Pythagorean Triplet
* Authors: Ryan Gillett, Brandon Gillett
*******************************************************************************/
#include <iostream>

using namespace std;

//Prototypes
long long int pythTripletProduct(int);
bool isTriplet(int, int, int);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int targetValue = 1000;
	
	cout << "The product of the special Pythagorean triplet is: " << pythTripletProduct(targetValue);
}

/*******************************************************************************
* 
*******************************************************************************/
long long int pythTripletProduct(int targetValue)
{
	for (int c = 334; c < 500; c++)
	{
		int b = c - 1;
		int a = 1000 - (b + c);
		while (a < b)
		{
			if (isTriplet(a, b, c))
			{
				return a * b * c;
			}
			a++;
			b--;
		}
	}
}

/*******************************************************************************
* 
*******************************************************************************/
bool isTriplet(int a, int b, int c)
{
	if ((a * a) + (b * b) == (c * c))
		return true;
	return false;
}