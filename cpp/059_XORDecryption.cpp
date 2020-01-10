/*******************************************************************************
* XOR Decryption
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	vector<char> letters;

	ifstream fin;
	fin.open("p059_cipher.txt");

	while (!fin.eof())
	{
		static string input;
		getline(fin, input, ',');
		letters.push_back(stoi(input));
	}

	fin.close();

	for (char a = 'a'; a <= 'z'; a++)
	{
		for (char b = 'a'; b <= 'z'; b++)
		{
			for (char c = 'a'; c <= 'z'; c++)
			{
				string decipheredText = "";

				for (int i = 0; i < letters.size(); i++)
				{
					static char* cipher;
					switch (i % 3)
					{
						case 0: cipher = &a; break;
						case 1: cipher = &b; break;
						case 2: cipher = &c; break;
					}
					
					decipheredText += (char)(letters[i] ^ *cipher);
				}

				if (decipheredText.find(" the ") != string::npos)
				{
					int sum = 0;
					for (int i = 0; i < decipheredText.size(); i++)
					{
						sum += decipheredText[i];
					}
					cout << sum << endl;
				}
			}
		}
	}

	return 0;
}