#include <iostream>

using namespace std;

bool checkPandigital(int number);
int addPandigitalProducts();
bool checkPandigitalProduct(int number);

int main()
{
    cout << "the sum of all pandigital Products is: " << addPandigitalProducts() << endl;
    return 0;
}

bool checkPandigital(int number)
{
    bool hasDigit[9] = {false};
    int digit;

    while(number > 0)
    {
        digit = number % 10;

        if(digit == 0)
            return false;

        if(hasDigit[digit-1])
            return false;
        else
            hasDigit[digit-1] = true;

        number /= 10;
    }

    return true;
}

bool checkPandigitalProduct(int number)
{
    int concatenatedNumbers;

    for(int i = 1; i < 100; i++)
    {
        if(number % i == 0 && i < 10)
        {
            concatenatedNumbers = number;
            concatenatedNumbers += i * 10000;
            concatenatedNumbers += (number / i) * 100000;
        }

        if(number % i == 0 && i > 10)
        {
            concatenatedNumbers = number;
            concatenatedNumbers += i * 10000;
            concatenatedNumbers += (number / i) * 1000000;
        }

        if(concatenatedNumbers > 100000000 && concatenatedNumbers < 1000000000)
        {
            if(checkPandigital(concatenatedNumbers))
                return true;
        }
    }

    return false;
}

int addPandigitalProducts()
{
    int sum = 0;

    for(int i = 1000; i < 10000; i++)
    {
        if(checkPandigital(i) && checkPandigitalProduct(i))
            sum += i;
    }

    return sum;
}
