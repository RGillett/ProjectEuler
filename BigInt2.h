/*******************************************************************************
* BigInt Class
* Author: Ryan Gillett
*******************************************************************************/
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

#ifdef DEBUG
#include <cassert>
#endif

// If string library doesn't provide to_string, implement my own
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
	template <typename T> BigInt& operator -= (const T& rightSide);
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
	friend BigInt operator - (const BigInt& leftSide, const BigInt& rightSide);
	template <typename T> friend BigInt operator - (const T& leftSide, const T& rightSide);
	friend BigInt operator * (const BigInt& leftSide, const BigInt& rightSide); //TODO
	template <typename T> friend BigInt operator * (const T& leftSide, const T& rightSide);
	friend BigInt operator / (const BigInt& leftSide, const BigInt& rightSide); //TODO
	template <typename T> friend BigInt operator / (const T& leftSide, const T& rightSide); //TODO
	friend BigInt operator % (const BigInt& leftSide, const BigInt& rightSide); //TODO
	template <typename T> friend BigInt operator % (const T& leftSide, const T& rightSide); //TODO
	friend BigInt operator ^ (const BigInt& leftSide, const BigInt& rightSide); //TODO
	template <typename T> friend BigInt operator ^ (const T& leftSide, const T& rightSide); //TODO
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
	reverse(rightSide.begin(), rightSide.end());
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
	string sum;
	string shorter;
	string longer;
	int carry = 0;

	if (leftSide.integer.size() > rightSide.integer.size())
	{
		shorter = rightSide.integer;
		longer  = leftSide.integer;
	}
	else
	{
		longer = rightSide.integer;
		shorter  = leftSide.integer;
	}

	for (int i = 0; i < longer.size(); i++)
	{
		if (i < shorter.size())
		{
			short tempSum = (longer[i] - '0') + (shorter[i] - '0') + carry;
			carry = tempSum / 10;
			tempSum %= 10;
			sum += to_string(tempSum);
		}
		else
		{
			short tempSum = (longer[i] - '0') + carry;
			carry = tempSum / 10;
			tempSum %= 10;
			sum += to_string(tempSum);
		}
	}

	sum += (carry != 0 ? to_string(carry) : "");

	reverse(sum.begin(), sum.end());

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
	long long n = 0;
	for (int i = rightSide.integer.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < pow(10, i); ++j)
		{
			n += (rightSide.integer[i] - '0');
		}
	}

	BigInt returnInt(leftSide);

	for (long long i = 1; i < n; ++i)
	{
		returnInt += leftSide;
	}

	return returnInt;
}

/******************************************************************************
* BigInt: *
******************************************************************************/
template <typename T> BigInt operator * (const T& leftSide, const T& rightSide)
{
	return BigInt(leftSide) + BigInt(rightSide);
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
		for (int i = leftSide.integer.size() - 1; i >= 0; --i)
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
	if (leftSide.integer.size() == rightSide.integer.size())
	{
		for (int i = leftSide.integer.size() - 1; i >= 0; --i)
		{
			if (leftSide.integer[i] != rightSide.integer[i])
			{
				return false;
			}
		}

		return true;
	}

	return false;
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
ostream& operator << (ostream& out, const BigInt& displayInt)
{
	for (int i = displayInt.integer.size() - 1; i >= 0; --i)
	{
		out << displayInt.integer[i];
	}

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