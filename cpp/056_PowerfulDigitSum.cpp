/*******************************************************************************
* Powerful Digit Sum
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <string>
#include "BigInt2.h"

using namespace std;

/******************************************************************************
* Main
******************************************************************************/
int main()
{
    BigInt maxDigitSum = 0;
    for (BigInt i = 90; i < 100; ++i)
    {
        for (BigInt j = 90; j < 100; ++j)
        {
            BigInt digitSum = (i ^ j).digitSum();
            if (digitSum > maxDigitSum)
            {
                maxDigitSum = digitSum;
            }
        }
    }

    cout << maxDigitSum << endl;

    return 0;
}