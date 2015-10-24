#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
	string str;
	ifstream fin;
	fin.open("change.txt");
	ofstream fout;
	fout.open("numbers.txt");
	
	while (!fin.eof())
	{
		fin >> str;
		for (int i = 0; i < str.length(); i++)
			if (str[i] < 48 || str[i] > 57)
				str[i] = ' ';
		fout << str << endl;
	}

	fin.close();
	fout.close();
}