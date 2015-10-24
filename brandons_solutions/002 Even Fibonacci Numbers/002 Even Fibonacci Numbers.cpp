#include <iostream>

using namespace std;

int addFibonacciNumbers(int targetValue);


int main()
{
    int targetValue = 4000000;

    cout << "The sum of all even fibonacci numbers below 4,000,000 is :"
         << addFibonacciNumbers(targetValue) << endl;
}

int addFibonacciNumbers(int targetValue)
{
    int a = 1;
    int b = 1;
    int c = 0;
    int sum = 0;

    while (c < targetValue)
    {
        if (c % 2 == 0)
            sum += c;

        c = a + b;
        a = b;
        b = c;
    }

    return sum;
}
