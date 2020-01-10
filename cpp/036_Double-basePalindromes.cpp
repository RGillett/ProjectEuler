/******************************************************************************
* Program: Double-base Palindromes
* Author: Ryan Gillett
******************************************************************************/
#include <iostream>

using namespace std;

bool isPalindrome(int number);
bool isBinaryPalindrome(int number);
 
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	int max = 1000000;

	int sum = 0;
	for (int i = 0; i < max; i++)
	{
		if (isPalindrome(i) && isBinaryPalindrome(i))
		{
			sum += i;
		}
	}

	cout << sum;

	return 0;
}

bool isPalindrome(int number)
{
	int digits = 1;

	while (digits <= number)
	{
		digits *= 10;
	}

	for (int i = 10; i < digits; i*=10)
	{
		digits /= 10;
		
		if (number/digits%10 != number%i*10/i)
		{
			return false;
		}
	}

	return true;
}

bool isBinaryPalindrome(int number)
{
	int size = 1;
	int bitSize = sizeof(number) * 8;
	for (int i = 2; i <= number; i*=2, size++)
		;

	for (int i = 0; i < size / 2; i++)
	{
		if ((number<<(bitSize-size+i))>>(bitSize-1) != (number<<(bitSize-(i+1)))>>(bitSize-1))
		{
			return false;
		}
	}

	return true;
}