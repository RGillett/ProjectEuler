#include "BigInt.h"

void BigInt::TEST()
{
	string str = convertNumberToString(199340);
	cout << str;
	
}

BigInt::BigInt()
{
	number = "0";
	negative = false;
}

BigInt::BigInt(BigInt& source)
{
	number = source.number;
	negative = source.negative;
}

BigInt& BigInt::operator=(const BigInt& source)
{
	return *this;
}

string BigInt::convertNumberToString(int n)
{
	string str = "";
	char digit;

	if (n == 0)
		str = "0";
	while (n > 0)
	{
		digit = n % 10 + 48;
		n /= 10;
		str.insert(str.begin(), digit);
	}
	return str;
}

void main()
{
	BigInt h;
	h.TEST();
}