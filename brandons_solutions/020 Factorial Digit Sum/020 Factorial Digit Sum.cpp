#include <iostream>
#include "../../classes/BigInt.h"

using namespace std;

int sumDigits(BigInt number);
int factorial();

int main()
{
    cout << factorial() << endl;
    return 0;
}

int factorial()
{
    BigInt product = 1;
    BigInt temporary1 = 1;

    for(BigInt i = 1; i <= 100; i = (i + temporary1))
    {
        product = product * i;
    }

    return sumDigits(product);
}

int sumDigits(BigInt number)
{
    int sum = 0;

    for(int i = number.size(); i > 0; i--)
    {
        sum += number.digit(i);
    }

    return sum;
}
