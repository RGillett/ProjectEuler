/*******************************************************************************
* Coded Triangle Numbers
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

//Prototypes
bool isCodedTriangleNumber(const char* word);
bool isTriangleNumber(int number);
/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	char filename[] = "p042_words.txt";
	char input[50];
	int triangleCount = 0;

	ifstream fin;
	fin.open(filename);
	if (fin.fail())
	{
		cout << "Error opening file \"" << filename <<"\" for reading." << endl;
		fin.close();
		return false;
	}

	while(!fin.eof())
	{
		fin.getline(input, 50, ',');
		string word = input;
		word = word.substr(1, word.size() - 2);
		if (isCodedTriangleNumber(word.c_str()))
		{
			triangleCount++;
		}
	}

	fin.close();

	cout << triangleCount << endl;

	return 0;
}

bool isCodedTriangleNumber(const char* word)
{
	int letterSum = 0;
	for (int i = 0; word[i] != '\0'; i++)
	{
		letterSum += (word[i] - 'A') + 1;
	}

	return isTriangleNumber(letterSum);
}

bool isTriangleNumber(int number)
{
	for (int i = 1; i <= number; i++)
	{
		int triangle = (i * (i + 1)) / 2;
		if (triangle == number)
		{
			return true;
		}
	}

	return false;
}