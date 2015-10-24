#include <iostream>
#include "../../classes/BigInt.h"

using namespace std;
BigInt timesTwo(BigInt &number);
BigInt power();
int addDigits(BigInt number);

int main()
{
    cout << power() << endl;
}

BigInt timesTwo(BigInt &number)
{
    number = number + number;
    return number;
}

BigInt power()
{
    BigInt multipleOfTwo = 1;

    for(int i = 1; i <= 1000; i++)
        timesTwo(multipleOfTwo);

   return addDigits(multipleOfTwo);
}

int addDigits(BigInt number)
{
    int digitTotal = 0;

    for(int i = 1; i <= number.size(); i++)
    {
        digitTotal += number.digit(i);
    }

    return digitTotal;
}
