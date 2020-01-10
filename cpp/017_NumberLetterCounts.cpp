/*******************************************************************************
* Number Letter Count
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <cassert>

using namespace std;

//Prototypes
int numLetterCount(int);

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int sum = 0;
	
	for (int i = 1; i <= 1000; i++)
	{
		sum += numLetterCount(i);
	}
	
	cout << sum << endl;

	return 0;
}

int numLetterCount(int value)
{
	if (value == 1000)
	{
		return 11;
	}
	int count = 0;
	
	switch (value % 100)
	{
		case 0:
			count = 0;
			break;
		case 1:
			count = 3;
			break;
		case 2:
			count = 3;
			break;
		case 3:
			count = 5;
			break;
		case 4:
			count = 4;
			break;
		case 5:
			count = 4;
			break;
		case 6:
			count = 3;
			break;
		case 7:
			count = 5;
			break;
		case 8:
			count = 5;
			break;
		case 9:
			count = 4;
			break;
		case 10:
			count = 3;
			break;
		case 11:
			count = 6;
			break;
		case 12:
			count = 6;
			break;
		case 13:
			count = 8;
			break;
		case 14:
			count = 8;
			break;
		case 15:
			count = 7;
			break;
		case 16:
			count = 7;
			break;
		case 17:
			count = 9;
			break;
		case 18:
			count = 8;
			break;
		case 19:
			count = 8;
			break;
		default:
		{
			switch ((value % 100) / 10)
			{
				case 2:
					count = 6;
					break;
				case 3:
					count = 6;
					break;
				case 4:
					count = 5;
					break;
				case 5:
					count = 5;
					break;
				case 6:
					count = 5;
					break;
				case 7:
					count = 7;
					break;
				case 8:
					count = 6;
					break;
				case 9:
					count = 6;
					break;
				default:
					cout << value << "\n" << ((value % 100) / 10) << endl;
					assert (false);
					break;
			}
			switch (value % 10)
			{
				case 0:
					count += 0;
					break;
				case 1:
					count += 3;
					break;
				case 2:
					count += 3;
					break;
				case 3:
					count += 5;
					break;
				case 4:
					count += 4;
					break;
				case 5:
					count += 4;
					break;
				case 6:
					count += 3;
					break;
				case 7:
					count += 5;
					break;
				case 8:
					count += 5;
					break;
				case 9:
					count += 4;
					break;
				default:
					cout << value << "\n" << (value % 10) << endl;
					assert (false);
					break;
			}
		}
		break;
	}
	switch ((value % 1000) / 100)
	{
		case 0:
			count -= 10;
			break;
		case 1:
			count += 3;
			break;
		case 2:
			count += 3;
			break;
		case 3:
			count += 5;
			break;
		case 4:
			count += 4;
			break;
		case 5:
			count += 4;
			break;
		case 6:
			count += 3;
			break;
		case 7:
			count += 5;
			break;
		case 8:
			count += 5;
			break;
		case 9:
			count += 4;
			break;
		default:
			cout << value << "\n" << ((value % 1000) / 100) << endl;
			assert (false);
			break;
	}
	count += 10;
	if (value % 100 == 0)
	{
		count -= 3;
	}

	return count;
}