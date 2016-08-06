/*******************************************************************************
* Driver
*******************************************************************************/
#include <iostream>
#include "BigInt.h"

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	BigInt test1;
	cout << "Default constructor: " << test1 << endl;
	BigInt test2(102030405060708090);
	cout << "int constructor: " << test2 << endl;
	BigInt test3("59326");
	cout << "string constructor: " << test3 << endl;
	BigInt test4(test3);
	cout << "Copy constructor: " << test4 << endl;
	test4 = 11111111111;
	test3 = 11111111112;
	cout << (test4 < test3) << endl;
	test1 = BigInt(50) * BigInt(50);
	cout << test1 << endl;
	return 0;
}