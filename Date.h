#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date
{
    private:
        int month,day,year;
    public:
        Date();
        Date(int month, int day, int year);
        void setDate(void);
        bool setDate(int month, int day, int year);
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        bool isEqual(const Date& d) const;
        bool isLess( const Date& d) const;
        bool isLeapYear(int year);
        const string& asString() const;
        void print(void) const;
        void userInput();
};
#endif //DATE_H