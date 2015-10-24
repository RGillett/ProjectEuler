#include <iostream>
#include <fstream>
#include "../../Classes/RomanNumerals.h"

using namespace std;

int CharactersSaved();

int main()
{
   cout << CharactersSaved() << endl;
}

int CharactersSaved()
{
    fstream fin;

    fin.open("List Of Roman Numerals.txt");

    RomanNumeral shortFormat;
    string next;
    string word;
    int spaceSaved = 0;

    while(!fin.eof())
    {
        fin >> next;
        spaceSaved += next.length();
        shortFormat.setNumeral(next);
        word = shortFormat.getNumeral();
        spaceSaved -= word.length();
    }

    fin.close();

    return spaceSaved;
}
