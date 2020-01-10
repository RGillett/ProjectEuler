/*******************************************************************************
* Path Sum: Three Ways
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
	char filename[] = "p082_matrix.txt";
	int input[80][80];
	int pathSum[80][80];

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

	int minimumDistance = 100000000;

	for (int x = 0; x < 80; x++)
	{
		int pathDistance = Dijkstra().dijkstra80x80(input, x, 0, -1, 79, false, true, true, true);
		if (pathDistance < minimumDistance)
		{
			minimumDistance = pathDistance;
		}
	}

	cout << minimumDistance << endl;

	return 0;
}