#include <iostream>
using namespace std;

bool chain(int);

void main()
{
	int count = 0;
	for (int i = 1; i < 10000000; i++)
	{
		if(chain(i))
			count++;
	}
	cout << count;
}

bool chain(int i)
{
	int sum = 0;
	while (i > 0)
	{
		sum = sum + (i % 10)*(i % 10);
		i = i / 10;
	}
	if (sum == 89)
		return true;
	else if (sum == 1)
		return false;
	else
		return chain(sum);
}