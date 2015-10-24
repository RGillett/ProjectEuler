#include <iostream>

using namespace std;

int pow(int base, int power);
long long int concatenateNumbers(int first, int second);
int findNumberOfDigits(int number);
bool checkPandigital(int number);
int findLargestPandigital();


int main()
{
    cout << "the largest pandigital number is: " << findLargestPandigital() << endl;
    return 0;
}

int pow(int base, int exponent)
{
    int power = 1;

    while(exponent > 0)
    {
        power *= base;
        exponent--;
    }

    return power;
}

long long int concatenateNumbers(int first, int second)
{
    for(int i = findNumberOfDigits(second); i > 0; i--)
    {
        first *= 10;
    }

    return (first + second);
}

int findNumberOfDigits(int number)
{
    int digitCount;

    for(digitCount = 0; number > 0; digitCount++)
        number /= 10;

    return digitCount;
}

bool checkPandigital(int number)
{
    bool hasDigit[9] = {false};
    int digit;

    if (findNumberOfDigits(number) != 9)
        return false;

    for (int i = 0; i < 9; i++)
    {
        digit = number / pow(10, i);
        digit = digit % 10;
        hasDigit[digit - 1] = true;
    }

    for(int i = 0; i < 9; i++)
    {
        if(hasDigit[i] == false)
            return false;
    }

    return true;
}

int findLargestPandigital()
{
    int numberOfDigits;
    int concatenatedNumber;
    int highestPandigital;

    for (int i = 1; i < 10000; i++)
    {
        concatenatedNumber = 0;
        numberOfDigits = 0;

        for (int j = 1; numberOfDigits < 9; j++)
        {
                concatenatedNumber = concatenateNumbers( concatenatedNumber, (i*j));
                numberOfDigits = findNumberOfDigits(concatenatedNumber);
        }

        if (checkPandigital(concatenatedNumber) && concatenatedNumber > highestPandigital)
            highestPandigital = concatenatedNumber;

    }

    return highestPandigital;
}

