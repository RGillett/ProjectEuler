/******************************************************************************
* Program:
*    1000 Digit Fibonacci Number
* Author:
*    Ryan Gillett
******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "BigInt.h"

using namespace std;
 
/******************************************************************************
* Driver
******************************************************************************/
int main(int argc, char** argv)
{
	clock_t t1,t2;
    t1=clock();

	int num;
	if (argc < 2)
	{
		cout << "Enter Number: ";
		cin >> num;
	}
	else
		num = atoi(argv[1]);

	BigInt a = 1;
	BigInt b = 0;
	BigInt c = 0;

	for (int i = 0; i < num; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	cout << c << endl;

	t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<endl<<diff<<endl;

	return 0;
}