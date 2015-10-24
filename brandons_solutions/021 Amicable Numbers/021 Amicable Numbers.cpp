#include <iostream>
#include <math.h>

using namespace std;

int sumOfFactors(int number);
int sumAmicableNumbers(int limit);

int main()
{
    cout << sumAmicableNumbers(10000) << endl;
}


int sumAmicableNumbers(int limit)
{
    int sum = 0;

    for(int i = 1; i <= limit; i++)
    {
        if(sumOfFactors(sumOfFactors(i)) == i && sumOfFactors(i) != i)
            sum += i;
    }

    return sum;
}

int sumOfFactors(int number)
{

    int sum = 0;
    int limit = sqrt(number);

    for(int i = 1; i <= limit; i++)
    {
        if(number % i == 0)
                sum += (i + (number / i));
    }

    if(limit * limit == number)
        sum -= limit;

    return sum - number;
}
