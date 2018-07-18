/*******************************************************************************
* Lychrel Numbers
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <string>
#include "BigInt2.h"

using namespace std;

bool isLychrelNumber(int number);
/******************************************************************************
* Main
******************************************************************************/
int main()
{
    int lychrelNumberCount = 0;
    for (int i = 0; i < 10000; ++i)
    {
        lychrelNumberCount += isLychrelNumber(i);
    }

    cout << lychrelNumberCount << endl;

    return 0;
}

bool isLychrelNumber(int number)
{
    BigInt lychrelNumber(number);
    for (int i = 0; i < 50; i++)
    {
        lychrelNumber = lychrelNumber + BigInt(lychrelNumber).reverseNumber();
        if (lychrelNumber.isPalindrome())
        {
            return false;
        }
    }

    return true;
}

