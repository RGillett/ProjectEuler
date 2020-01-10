/*******************************************************************************
* Date Class
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <cassert>

/******************************************************************************
* Class: Date
******************************************************************************/
class Date
{
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	const static int MINYEAR = 1900;
	const static int MAXYEAR = 3000;
	const static int DAYS_IN_MONTH(const int& i)
	{
		const static int array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		return array[i-1];
	}
	bool isLeapYear(const int& year) const;

public:
	Date(const unsigned int& day, const unsigned int& month, const unsigned int& year);
	Date(const Date &dateToCopy);
	Date& operator = (const Date &rightSide);
	int operator -(const Date &rightSide) const;
	friend std::ostream& operator << (std::ostream& out, const Date& displayDate);
	Date& addDays(const int& days);
	int getDay() const {return day;}
	int getMonth() const {return month;}
	int getYear() const {return year;}
};

/******************************************************************************
* Date: day/month/year constructor
******************************************************************************/
Date::Date(const unsigned int& day, const unsigned int& month, const unsigned int& year)
{
	if (MINYEAR <= year && year <= MAXYEAR)
	{
		this->year = year;
	}
	else
	{
		this->year = MINYEAR;
	}
	
	if (1 <= month && month <= 12)
	{
		this->month = month;
	}
	else
	{
		this->month = 1;
	}
	
	if (1 <= day && day <= DAYS_IN_MONTH(this->month))
	{
		this->day = day;
	}
	else if (day == 29 && month == 2 && isLeapYear(year))
	{
		this->day = day;
	}
	else
	{
		this->day = 1;
	}
}

/******************************************************************************
* Date: Copy Constructor
******************************************************************************/
Date::Date(const Date &dateToCopy)
{
	*this = dateToCopy;
}

/******************************************************************************
* Date: = (Date)
******************************************************************************/
Date& Date::operator =(const Date &rightSide)
{
	this->day   = rightSide.day;
	this->month = rightSide.month;
	this->year  = rightSide.year;
	
	return *this;
}

/******************************************************************************
* Date: -
******************************************************************************/
int Date::operator -(const Date &rightSide) const
{
	//int days = 
	
	return 0;
}

/******************************************************************************
* Date: <<
******************************************************************************/
std::ostream& operator << (std::ostream& out, const Date& displayDate)
{
	switch (displayDate.month)
	{
		case 1:
			out << "January";
			break;
		case 2:
			out << "February";
			break;
		case 3:
			out << "March";
			break;
		case 4:
			out << "April";
			break;
		case 5:
			out << "May";
			break;
		case 6:
			out << "June";
			break;
		case 7:
			out << "July";
			break;
		case 8:
			out << "August";
			break;
		case 9:
			out << "September";
			break;
		case 10:
			out << "October";
			break;
		case 11:
			out << "November";
			break;
		case 12:
			out << "December";
			break;
		default:
			assert (false);
			break;
	}
	
	out << " " << displayDate.day << ", " << displayDate.year;
	
	return out;
}

/******************************************************************************
* Date: isLeapYear
*	Determines whether a year is a leap year
******************************************************************************/
bool Date::isLeapYear(const int& year) const
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

/******************************************************************************
* Date: addDay
*	Takes an int and adds that many days to the date.
******************************************************************************/
Date& Date::addDays(const int& days)
{
	day += days;
	while (day > DAYS_IN_MONTH(month) + (month == 2 && isLeapYear(year)))
	{
		day -= (DAYS_IN_MONTH(month) + (month == 2 && isLeapYear(year)));
		month++;
		if (month == 13)
		{
			month = 1;
			year++;
			if (year > MAXYEAR)
			{
				year = MINYEAR;
			}
		}
	}

	return *this;
}