/*******************************************************************************
* BigInt Class
* Author: Ryan Gillett
*******************************************************************************/
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

/******************************************************************************
* Class: BigInt
*	Represents an arbitrarily large integer
******************************************************************************/
class BigInt
{
private:
	string integer;
	bool negative; //TODO

public:
	BigInt();
	BigInt(string value);
	BigInt(long long value);
	BigInt(const BigInt &intToCopy);
	BigInt& operator = (const BigInt &rightSide);
	BigInt& operator = (long long rightSide);
	BigInt& operator = (string rightSide);
	template <typename T> BigInt& operator += (const T& rightSide);
	template <typename T> BigInt& operator -= (const T& rightSide); //TODO
	template <typename T> BigInt& operator *= (const T& rightSide);
	template <typename T> BigInt& operator /= (const T& rightSide); //TODO
	template <typename T> BigInt& operator %= (const T& rightSide); //TODO
	template <typename T> BigInt& operator ^= (const T& rightSide); //TODO
	BigInt& operator ++ ();
	BigInt operator ++ (int postfix);
	BigInt& operator -- (); //TODO
	BigInt& operator -- (int postfix); //TODO
	friend BigInt operator + (const BigInt& leftSide, const BigInt& rightSide);
	template <typename T> friend BigInt operator + (const T& leftSide, const T& rightSide);
	friend BigInt operator - (const BigInt& leftSide, const BigInt& rightSide); //TODO
	template <typename T> friend BigInt operator - (const T& leftSide, const T& rightSide); //TODO
	friend BigInt operator * (const BigInt& leftSide, const BigInt& rightSide);
	template <typename T> friend BigInt operator * (const T& leftSide, const T& rightSide);
	friend BigInt operator / (const BigInt& leftSide, const BigInt& rightSide); //TODO
	template <typename T> friend BigInt operator / (const T& leftSide, const T& rightSide); //TODO
	friend BigInt operator % (const BigInt& leftSide, const BigInt& rightSide); //TODO
	template <typename T> friend BigInt operator % (const T& leftSide, const T& rightSide); //TODO
	friend BigInt operator ^ (const BigInt& leftSide, const BigInt& rightSide);
	template <typename T> friend BigInt operator ^ (const T& leftSide, const T& rightSide);
	friend ostream& operator << (ostream& out, const BigInt& displayInt);
	friend istream& operator >> (istream& in, const BigInt& inputInt); //TODO
	friend bool operator <  (const BigInt& leftSide, const BigInt& rightSide);
	friend bool operator <= (const BigInt& leftSide, const BigInt& rightSide);
	friend bool operator >  (const BigInt& leftSide, const BigInt& rightSide);
	friend bool operator >= (const BigInt& leftSide, const BigInt& rightSide);
	friend bool operator == (const BigInt& leftSide, const BigInt& rightSide);
	friend bool operator != (const BigInt& leftSide, const BigInt& rightSide);

    BigInt& reverseNumber();
    bool isPalindrome();
    BigInt digitSum();
	BigInt digitCount();
};

/******************************************************************************
* BigInt: Default Constructor
*	Initializes integer to 0
******************************************************************************/
BigInt::BigInt()
{
	integer = "0";
}

/******************************************************************************
* BigInt: string Constructor
*	Initializes integer from a string value
******************************************************************************/
BigInt::BigInt(string value)
{
	*this = value;
}

/******************************************************************************
* BigInt: long long int Constructor
*	Initializes integer from an int value
******************************************************************************/
BigInt::BigInt(long long value)
{
	*this = value;
}

/******************************************************************************
* BigInt: Copy Constructor
******************************************************************************/
BigInt::BigInt(const BigInt &intToCopy)
{
	*this = intToCopy;
}

/******************************************************************************
* BigInt: = (BigInt)
******************************************************************************/
BigInt& BigInt::operator = (const BigInt &rightSide)
{
	this->integer = rightSide.integer;
	return *this;
}

/******************************************************************************
* BigInt: = (int)
******************************************************************************/
BigInt& BigInt::operator = (long long rightSide)
{
	return *this = to_string(rightSide);
}

/******************************************************************************
* BigInt: = (string)
******************************************************************************/
BigInt& BigInt::operator = (string rightSide)
{
	integer = rightSide;

	return *this;
}

/******************************************************************************
* BigInt: +=
******************************************************************************/
template <typename T> BigInt& BigInt::operator += (const T &rightSide)
{
	return *this = *this + rightSide;
}

/******************************************************************************
* BigInt: *=
******************************************************************************/
template <typename T> BigInt& BigInt::operator *= (const T &rightSide)
{
	return *this = *this * rightSide;
}

/******************************************************************************
* BigInt: ++ [prefix]
******************************************************************************/
BigInt& BigInt::operator ++ ()
{
	return *this = *this + 1;
}

/******************************************************************************
* BigInt: ++ [postfix]
******************************************************************************/
BigInt BigInt::operator ++ (int postfix)
{
    BigInt thisToReturn(*this);
    ++*this;
	return thisToReturn;
}

/******************************************************************************
* BigInt: +
******************************************************************************/
BigInt operator + (const BigInt& leftSide, const BigInt& rightSide)
{
	string sum = "";
	int carry = 0;

	string::const_reverse_iterator lrit = leftSide.integer.rbegin();
	string::const_reverse_iterator rrit = rightSide.integer.rbegin();
	for (/*lrit && rrit*/; lrit < leftSide.integer.rend() || rrit < rightSide.integer.rend() || carry > 0; ++lrit, ++rrit)
	{
		int digitSum = (lrit < leftSide.integer.rend() ? *lrit - '0' : 0) + (rrit < rightSide.integer.rend() ? *rrit - '0' : 0) + carry;
		carry = digitSum / 10;
		digitSum %= 10;
		sum = to_string(digitSum) + sum;
	}
	
	return BigInt(sum);
}

/******************************************************************************
* BigInt: +
******************************************************************************/
template <typename T> BigInt operator + (const T& leftSide, const T& rightSide)
{
	return BigInt(leftSide) + BigInt(rightSide);
}

/******************************************************************************
* BigInt: *
******************************************************************************/
BigInt operator * (const BigInt& leftSide, const BigInt& rightSide)
{
	BigInt returnInt = 0;
	const BigInt* counter = (rightSide < leftSide ? &rightSide : &leftSide);
	const BigInt* adder   = (rightSide > leftSide ? &rightSide : &leftSide);

	for (BigInt i = 0; i < *counter; ++i)
	{
		returnInt += *adder;
	}

	return returnInt;
}

/******************************************************************************
* BigInt: *
******************************************************************************/
template <typename T> BigInt operator * (const T& leftSide, const T& rightSide)
{
	return BigInt(leftSide) * BigInt(rightSide);
}

/******************************************************************************
* BigInt: ^
******************************************************************************/
BigInt operator ^ (const BigInt& leftSide, const BigInt& rightSide)
{
	const BigInt* counter    = (rightSide < leftSide ? &rightSide : &leftSide);
	const BigInt* multiplier = (rightSide > leftSide ? &rightSide : &leftSide);
    BigInt returnInt = *multiplier;

	for (BigInt i = 1; i < *counter; ++i)
	{
		returnInt *= *multiplier;
	}

	return returnInt;
}

/******************************************************************************
* BigInt: ^
******************************************************************************/
template <typename T> BigInt operator ^ (const T& leftSide, const T& rightSide)
{
    return BigInt(leftSide) ^ BigInt(rightSide);
}

/******************************************************************************
* BigInt: <
******************************************************************************/
bool operator < (const BigInt& leftSide, const BigInt& rightSide)
{
	if (leftSide.integer.size() < rightSide.integer.size())
	{
		return true;
	}
	if (leftSide.integer.size() == rightSide.integer.size())
	{
		for (int i = 0; i < leftSide.integer.size(); ++i)
		{
			if (leftSide.integer[i] < rightSide.integer[i])
			{
				return true;
			}
			else if (leftSide.integer[i] > rightSide.integer[i])
			{
				return false;
			}
		}
	}

	return false;
}

/******************************************************************************
* BigInt: <=
******************************************************************************/
bool operator <= (const BigInt& leftSide, const BigInt& rightSide)
{
	return !(leftSide > rightSide);
}

/******************************************************************************
* BigInt: >
******************************************************************************/
bool operator > (const BigInt& leftSide, const BigInt& rightSide)
{
	return rightSide < leftSide;
}

/******************************************************************************
* BigInt: >=
******************************************************************************/
bool operator >= (const BigInt& leftSide, const BigInt& rightSide)
{
	return !(leftSide < rightSide);
}

/******************************************************************************
* BigInt: ==
******************************************************************************/
bool operator == (const BigInt& leftSide, const BigInt& rightSide)
{
	return leftSide.integer == rightSide.integer;
}

/******************************************************************************
* BigInt: !=
******************************************************************************/
bool operator != (const BigInt& leftSide, const BigInt& rightSide)
{
	return !(leftSide == rightSide);
}

/******************************************************************************
* BigInt: <<
******************************************************************************/
ostream& operator << (ostream& out, const BigInt& outputInt)
{
	out << outputInt.integer;

	return out;
}

/******************************************************************************
* BigInt: reverseNumber ()
******************************************************************************/
BigInt& BigInt::reverseNumber()
{
	reverse(integer.begin(), integer.end());
	return *this;
}

/******************************************************************************
* BigInt: isPalindrome ()
******************************************************************************/
bool BigInt::isPalindrome()
{
    BigInt reversed = *this;
    reversed.reverseNumber();
	return *this == reversed;
}

/******************************************************************************
* BigInt: digitSum ()
******************************************************************************/
BigInt BigInt::digitSum()
{
    BigInt sum;
    for(std::string::iterator it = integer.begin(); it != integer.end(); ++it)
    {
        sum += *it - '0';
    }

	return sum;
}

/******************************************************************************
* BigInt: digitCount ()
******************************************************************************/
BigInt BigInt::digitCount()
{
	return BigInt(integer.size());
}