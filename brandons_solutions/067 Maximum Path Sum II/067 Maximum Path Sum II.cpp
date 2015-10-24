#include <iostream>
#include <fstream>

using namespace std;

void getNumbers(int numbers[][100]);
void findHighestSum(int numbers[][100]);

int main()
{
    int numbers[100][100];

    getNumbers(numbers);
    findHighestSum(numbers);
    cout << "The path with the largest sum adds up to: " << numbers[0][0] << endl;

    return 0;
}

void getNumbers(int numbers[][100])
{
    fstream fin;
    fin.open("numbers.txt");

    for(int i = 0; i < 100; i++)
    {
            for(int j = 0; j <= i; j++)
            {
                fin >> numbers[i][j];
            }
    }
    fin.close();
}

void findHighestSum(int numbers[][100])
{
    for(int i = 98; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            numbers[i][j] += (numbers[i+1][j] > numbers[i+1][j+1] ? numbers[i+1][j] : numbers[i+1][j+1]);
        }
    }
}
