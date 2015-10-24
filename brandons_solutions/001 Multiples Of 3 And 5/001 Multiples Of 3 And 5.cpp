#include <iostream>

using namespace std;

//prototype
int findSum(int x);


int main()
{
    int targetValue = 1000;
    cout << "The sum of all numbers below 1,000 that are divisible by 3 and 5 is: " << findSum(targetValue) << endl;
}

int findSum(int x)
{
    int sum = 0;
    for (int i = 2; i < x; i++)
    {
        if((i % 3 == 0) || (i % 5 == 0))
            sum += i;
    }
    return sum;
}
