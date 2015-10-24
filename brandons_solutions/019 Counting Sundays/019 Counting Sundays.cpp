#include <iostream>
#include "../../Classes/Date.h"

using namespace std;

int SundayCounter();

int main()
{
    cout << endl << SundayCounter() << endl;

}

int SundayCounter()
{
    Date date;
    date.setMonth(1);
    date.setYear(1901);
    date.setDay(6);

    int numberOfSundays = 0;

    while(date.getYear() < 2001)
    {
        date.addDay(7);

        if(date.getDay() == 1)
           numberOfSundays++;
    }

    return numberOfSundays;
}
