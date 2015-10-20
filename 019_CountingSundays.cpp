/*******************************************************************************
* Counting Sundays
* Author: Ryan Gillett
*******************************************************************************/
#include "Date.h"

using namespace std;

//Prototypes

/*******************************************************************************
* Main
*******************************************************************************/
int main()
{
	int sundayTotal = 0;
	
	for (Date date(6, 1, 1901); date.getYear() <= 2000; date.addDays(7))
	{
		if (date.getDay() == 1)
		{
			sundayTotal++;
		}
	}
	
	cout << "Sundays the 1st in the 20th century: " << sundayTotal << endl;

	return 0;
}