#include "Date.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this-> year = 1;
}
Date::Date(int month,int day,int year)
{
    if (!setDate(month,day,year))
        this->month = this->day = this->year = 1;
}
void Date::setDate()
{
    struct tm *dur;
    time_t sec;

    time(&sec);
    dur = localtime(&sec);

    day = dur->tm_mday;
    month = dur->tm_mon + 1;
    year = dur->tm_year + 1900;
}
bool Date::setDate(int mn,int da,int yr)
{
    if ( mn < 1 || mn > 12) return false;
    if ( da < 1 || da > 31) return false;
    switch (mn)
    {
        case 2: if (Date::isLeapYear(yr))
                {
                    if ( da > 29 )
                        return false;
                }
                else if ( da > 28 )
                    return false;
                break;
        case 4:
        case 6:
        case 9:
        case 11:
                    if ( da > 30 )  return false;
    }
    month = mn;
    day = da;
    year = yr;
    return true;
}
void Date::userInput()
{
    int month,day,year;
    cin>>month>>day>>year;
    setDate(month,day,year);
}
void Date::print(void) const
{
    cout<< asString() << endl;
}
const string& Date::asString() const
{
    static string dateString;
    stringstream iostream;

    iostream<< setfill('0')
            << setw(2) << month << '-'
            << setw(2) << day << '-' << year;
    iostream>> dateString;
    return dateString;
}
int Date::getMonth() const
{
	return this->month;
}
int Date::getDay() const
{
	return this->day;
}
int Date::getYear() const
{
	return this->year;
}
bool Date::isLeapYear(int year) {
    return true;
}