#include <iostream>
#include <fstream>
#include <string>
#include "../../classes/BigInt.h"

using namespace std;

int countNames();
void getNames(string *names);
void alphebetise(string *names, int first, int last);
bool compareStrings(string first, string second);
long long int findNameScore(string *names, int numberOfNames);

int main()
{
    int numberOfNames = countNames();

    string *names;
    names = new string[numberOfNames];

    getNames(names);
    alphebetise(names, 0, numberOfNames-1);
    cout << "The Total of all the name scores in the file is: " << findNameScore(names, numberOfNames);

    delete[] names;
    return 0;
}

int countNames()
{
    char comma;
    int nameCount = 1;

    ifstream fin;
    fin.open("Names.txt");

    if(!fin)
        cout << "Error opening file" << endl;

    while(!fin.eof())
    {
        fin >> comma;
        if(comma == ',')
            nameCount++;
    }

    fin.close();

    return nameCount;

}

void getNames(string *names)
{
    int i = -1;
    bool isLetter = false;
    char nextChar;
    ifstream fin;
    fin.open("Names.txt");

    if(!fin)
        cout << "Error opening file" << endl;

    while(!fin.eof())
    {
        fin >> nextChar;
        if(nextChar > 64 && nextChar < 91)
        {
            if(isLetter == false)
                i++;

            isLetter = true;
        }
        else
            isLetter = false;

        if(isLetter)
            names[i] += nextChar;

    }

    fin.close();
}

void alphebetise(string *words, int first, int last)
{
      int i = first, j = last;
      string tmp;
      string pivot = words[(first + last) / 2];

      while(i <= j)
        {
            while(compareStrings(words[i], pivot))
                i++;

            while(compareStrings(pivot, words[j]))
                j--;

            if(i <= j)
                {
                    tmp = words[i];
                    words[i] = words[j];
                    words[j] = tmp;

                    i++;
                    j--;
                }
        }

      if(first < j)
            alphebetise(words, first, j);

      if(i < last)
            alphebetise(words, i, last);
}

bool compareStrings(string first, string second)
{
    int longerWord;

    if(first.length() < second.length())
        longerWord = second.length();
    else
        longerWord = first.length();

    for(int i = 0; i < longerWord ; i++)
    {
        if(first[i] < second[i])
            return true;

        if(second[i] < first[i])
            return false;
    }

    return false;
}

long long int findNameScore(string *names, int numberOfNames)
{
    long long int total = 0;
    int nameScore;
    int letterScore;

    for(int i = 1; i <= numberOfNames; i++)
    {

        nameScore = 0;

        for(int j = 0; j < names[i-1].length(); j++)
        {
            letterScore = names[i-1][j] - 64;
            nameScore += letterScore;
        }

        nameScore *= i;
        total = total + nameScore;
    }

    return total;
}
