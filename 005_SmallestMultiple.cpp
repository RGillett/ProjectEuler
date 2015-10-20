/*******************************************************************************
* Smallest Multiple
* Authors: Ryan Gillett, Brandon Gillett
*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

//Prototypes
long long int lcm(long long int a, long long int b);
long long int multiLCM(vector<long long int>);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	vector<long long int> values;
	for (long long int i = 1; i <=20; i++)
	{
		values.push_back(i);
	}
	
	cout << "The smallest multiple of 1-20 is: " << multiLCM(values) << endl;
}

long long int multiLCM(vector<long long int> values)
{
	long long int runningLCM = 1;
	
	for (int i = 0; i < values.size(); i++)
	{
		runningLCM = lcm(runningLCM, values[i]);
	}
	
	return runningLCM;
}

long long int lcm(long long int a, long long int b)
{
	long long int x = a;
	long long int y = b;
	
	while (x != y)
	{
		if (x < y)
			x += a;
		else
			y += b;
	}
	
	return x;
}