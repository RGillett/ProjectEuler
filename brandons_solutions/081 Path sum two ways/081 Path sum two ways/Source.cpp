#include <iostream>
#include <fstream>

using namespace std;

void getNumbers(int numbers[][80]);
void findLowestSum(int numbers[][80]);

void main()
{
	int numbers[80][80];

	getNumbers(numbers);
	findLowestSum(numbers);
	cout << "The path with the largest sum adds up to: " << numbers[79][79] << endl;
}

void getNumbers(int numbers[][80])
{
	fstream fin;
	fin.open("numbers.txt");

	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			fin >> numbers[i][j];
		}
	}
	fin.close();
}

void findLowestSum(int numbers[][80])
{
	for (int i = 1; i < 80; i++)
	{
		numbers[0][i] += numbers[0][i - 1];
	}

	for (int i = 1; i < 80; i++)
	{
		numbers[i][0] += numbers[i-1][0];
	}

	for (int j = 1; j < 80; j++)
	{
		for (int i = j; i < 80; i++)
		{
				numbers[j][i] += numbers[j][i] + numbers[j][i-1] < numbers[j][i] + numbers[j-1][i] ? numbers[j][i-1] : numbers[j-1][i];
		}

		for (int i = j + 1; i < 80; i++)
		{
			numbers[i][j] += numbers[i][j] + numbers[i-1][j] < numbers[i][j] + numbers[i][j-1] ? numbers[i-1][j] : numbers[i][j-1];
		}
	}
}