/*******************************************************************************
* Path Sum: Two Ways
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <fstream>
#include "graphs.h"

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	char filename[] = "p081_matrix.txt";
	int input[80][80];

	ifstream fin;
	fin.open(filename);

	for (int i = 0; i < 80; i++)
	{
		for(int j = 0; j < 80; j++)
		{
			fin >> input[i][j];
			fin.ignore();
		}
	}

	fin.close();

	cout << Dijkstra().dijkstra80x80(input, 0, 0, 79, 79, false, false, true, true) << endl;

	return 0;
}