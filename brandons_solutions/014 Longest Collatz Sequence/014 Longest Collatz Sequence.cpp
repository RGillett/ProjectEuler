#include <iostream>

using namespace std;

int findLengthOfCollatz(long long int startingNumber);
int findLongestCollatzChain(int upperLimit);


int main()
{
   cout << "The longest chain produced by the collatz sequence starting with a number under 1 million is: "
        << findLongestCollatzChain(1000000) << endl;
}

int findLongestCollatzChain(int upperLimit)
{
    int highestChain = 1;
    int highestNumber = 1;

    for (int i = 1; i < upperLimit; i++)
    {
        if(findLengthOfCollatz(i) > highestChain)
        {
            highestChain = findLengthOfCollatz(i);
            highestNumber = i;
        }
    }

    return highestNumber;
}

int findLengthOfCollatz(long long int startingNumber)
{
    long long int currentNumber = startingNumber;
    int counter = 1;

    while (currentNumber != 1)
    {
            if (currentNumber % 2 == 0)
                currentNumber = currentNumber / 2;
            else
                currentNumber = (currentNumber * 3) + 1;

            counter++;
    }

    return counter;
}
