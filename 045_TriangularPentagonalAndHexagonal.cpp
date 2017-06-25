/*******************************************************************************
* Triangular, Pentagonal, and Hexagonal
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	// Every hexagonal number is also triangular, so we don't need to look for triangular numbers
	unsigned long long int hexagonal = 1;
	unsigned long long int pentagonal = 1;
	unsigned long long int hexagon_adder = 1;
	unsigned long long int pentagon_adder = 1;

	while (true)
	{
		if (hexagonal < pentagonal)
		{
			hexagon_adder += 4;
			hexagonal += hexagon_adder;
		}
		else
		{
			pentagon_adder += 3;
			pentagonal += pentagon_adder;
		}

		if (hexagonal == pentagonal)
		{
			cout << hexagonal << endl;
		}
	}
}