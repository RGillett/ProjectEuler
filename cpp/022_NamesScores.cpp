/******************************************************************************
* Program:
*    Names Scores
* Author:
*    Ryan Gillett
******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

//Prototypes
bool readFile(list<string>&);
int scoreName(const string&);

/******************************************************************************
* Driver
******************************************************************************/
int main()
{
	list<string> names;
	int score = 0;
	
	if (!readFile(names))
	{
		return 0;
	}
	
	names.sort();
	
	int i = 1;
	
	for (list<string>::iterator it = names.begin(); it != names.end(); it++)
	{
		score += scoreName(*it) * i;
		i++;
	}
	
	cout << score << endl;

	return 0;
}

bool readFile(list<string>& names)
{
	char filename[] = "p022_names.txt";
	char name[50];
	
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
		fin.getline(name, 50, ',');
		string namestr = name;
		namestr.erase(namestr.begin());
		namestr.erase(namestr.end() - 1);
		names.push_back(namestr);
	}
	
	fin.close();
	
	return true;
}

int scoreName(const string& name)
{
	int score = 0;
	for (int i = name.size() - 1; i >= 0; i--)
	{
		score += name[i] - '@';
	}

	return score;
}