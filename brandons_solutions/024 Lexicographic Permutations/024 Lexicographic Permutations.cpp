#include <iostream>

using namespace std;

long long int factorial(int number);
void lexicographicalPermutation();
void sorter(int arg[10], int sizeOfArg, int startingPoint);
void nextHighest(int arg[], int sizeOfArg, int startingIndex);

int main()
{
   lexicographicalPermutation();

}

void lexicographicalPermutation()
{
    int sum = 0;
    int digit[10];

    for(int i = 0; i < 10; i++)
    {
        digit[i] = i;

    }


    for(int i = 0; i < 10; i++)
    {
        while(sum + factorial(9 - i) < 1000000)
        {
            sum += factorial(9 - i);
            cout << digit[i] << " ";
            nextHighest(digit, 10, i);
            sorter(digit, 10, i + 1);
            cout << digit[i] << endl;

        }
        cout << endl;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << digit[i] << ", ";
    }
}

long long int factorial(int number)
{

    long long int product = 1;

    while(number > 1)
    {
        product *= number;
        number--;
    }

    return product;
}

void sorter(int arg[10], int sizeOfArg, int startingPoint)
{
    int a = 0;

    for(int i = sizeOfArg; i > startingPoint; i--)
    {
        for(int j = startingPoint; j < sizeOfArg - 1; j++)
        {
            if(arg[j] > arg[j+1])
            {
                a = arg[j];
                arg[j] = arg[j+1];
                arg[j+1] = a;
            }
        }
    }
}

void nextHighest(int arg[], int sizeOfArg, int startingIndex)
{

    int a = 0;

    for(int i = 1; i == i; i++)
    {
        for(int j = startingIndex + 1; j < sizeOfArg; j++)
        {
            if(arg[startingIndex] == arg[j] - i)
            {
                a = arg[startingIndex];
                arg[startingIndex] = arg[j];
                arg[j] = a;
                return;
            }
        }
    }
}
