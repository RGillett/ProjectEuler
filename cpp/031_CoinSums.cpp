/*******************************************************************************
* Coin Sums
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>

using namespace std;

//Prototypes

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	const int TARGET = 200;
	
	const int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
	
	int waysToMake[TARGET + 1] = {0};
	waysToMake[0] = 1;
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j <= TARGET - coins[i]; j++)
		{
			waysToMake[ j + coins[i] ] += waysToMake[j];
		}
	}
	
	cout << waysToMake[TARGET] << endl;
	
	return 0;
}