#pragma once
#pragma once 
#include <iostream>
#include <string>
using namespace std;

class BigInt
{
public:
	void TEST();
	BigInt();
	BigInt(BigInt&);
	BigInt& operator=(const BigInt&);
private:
	string convertNumberToString(int);
	string number;
	bool negative;
};

