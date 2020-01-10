/******************************************************************************
* Program: Integer Right Triangles
* Author: Ryan Gillett
******************************************************************************/
#include <iostream>

using namespace std;
 
/******************************************************************************
* Main
******************************************************************************/
int main()
{
	int pWithMostSolutions = 1;
	int mostSolutions = 0;
	for (int p = 1; p <= 1000; p++)
	{
		cout << p << endl;
		int solutions = 0;
		for (int c = 1; c < p; c++)
		{
			for (int b = 1; b < c; b++)
			{
				for (int a = 1; a < b; a++)
				{
					if ((a+b+c==p) && (((a*a)+(b*b))==(c*c)))
					{
						solutions++;
					}
				}
			}
		}

		if (solutions > mostSolutions)
		{
			mostSolutions = solutions;
			pWithMostSolutions = p;
		}
	}

	cout << pWithMostSolutions << endl;

	return 0;
}