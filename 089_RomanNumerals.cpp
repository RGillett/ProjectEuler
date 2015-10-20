/*******************************************************************************
* Roman Numerals
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Prototypes
string reduceRomanNumeral(const string& numeral);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int reductionCount = 0;
	char filename[] = "p089_roman.txt";
	char input[50];
	
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
		fin.getline(input, 50);
		string numeral = input;
		reductionCount += numeral.size() - (reduceRomanNumeral(numeral)).size();
	}
	
	fin.close();
	
	cout << reductionCount << " characters saved" << endl;
	return 0;
}

/*******************************************************************************
* ReduceRomanNumeral
* M: 1000
* D:  500
* C:  100
* L:   50
* X:   10
* V:    5
* I:    1
* DD -> M
* DCD -> CM
* CCCC -> CD
* CCCCC -> D
* LL -> C
* LXL -> XC
* XXXX -> XL
* XXXXX -> L
* VV -> X
* VIV -> IX
* IIII -> IV
* IIIII -> V
*******************************************************************************/
string reduceRomanNumeral(const string& numeral)
{
	string returnString;
	
	for (int i = 0; i < numeral.size(); i++)
	{
		switch (numeral[i])
		{
			case 'I':
				if (numeral.size() - i >= 4)
				{
					if (numeral[i+1] == 'I' && numeral[i+2] == 'I' && numeral[i+3] == 'I')
					{
						returnString += "IV";
						i += 3;
					}
					else
					{
						returnString += 'I';
					}
				}
				else
				{
					returnString += 'I';
				}
				break; //"IIIII" case not in file
			case 'V':
				if (numeral.size() - i >= 3)
				{
					if (numeral[i+1] == 'I' && numeral[i+2] == 'V')
					{
						returnString += "IX";
						i += 2;
					}
					else
					{
						returnString += 'V';
					}
				}
				else
				{
					returnString += 'V';
				}
				break; //"VV" case not in file
			case 'X':
				if (numeral.size() - i >= 4)
				{
					if (numeral[i+1] == 'X' && numeral[i+2] == 'X' && numeral[i+3] == 'X')
					{
						returnString += "XL";
						i += 3;
					}
					else
					{
						returnString += 'X';
					}
				}
				else
				{
					returnString += 'X';
				}
				break; //"XXXXX" case not in file
			case 'L':
				if (numeral.size() - i >= 3)
				{
					if (numeral[i+1] == 'X' && numeral[i+2] == 'L')
					{
						returnString += "XC";
						i += 2;
					}
					else
					{
						returnString += 'L';
					}
				}
				else
				{
					returnString += 'L';
				}
				break; //"LL" case not in file
			case 'C':
				if (numeral.size() - i >= 4)
				{
					if (numeral[i+1] == 'C' && numeral[i+2] == 'C' && numeral[i+3] == 'C')
					{
						returnString += "CD";
						i += 3;
					}
					else
					{
						returnString += 'C';
					}
				}
				else
				{
					returnString += 'C';
				}
				break; //"CCCCC" case not in file
			case 'D':
				if (numeral.size() - i >= 3)
				{
					if (numeral[i+1] == 'C' && numeral[i+2] == 'D')
					{
						returnString += "CM";
						i += 2;
					}
					else
					{
						returnString += 'D';
					}
				}
				else
				{
					returnString += 'D';
				}
				break; //"DD" case not in file
			case 'M':
				returnString += 'M';
				break;
			default:
				cout << "Error: character \'" << numeral[i] << "\' not identified: " << numeral << endl;
				return numeral;
		}
	}
	if (returnString == numeral)
	{
		return numeral;
	}
	else
	{
		return reduceRomanNumeral(returnString);
	}
}