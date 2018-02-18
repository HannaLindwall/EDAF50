#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::string;
using std::ostream;
using std::istream;
using std::endl;

class Date {
public:
	Date();                    // today's date
	Date(int y, int m, int d); // yyyy-mm-dd
	int getYear() const;       // get the year
	int getMonth() const;      // get the month
	int getDay() const;        // get the day
	void next();               // advance to next day
	friend istream& operator>>(istream& is, Date& obj);
	friend ostream& operator<<(ostream& os, const Date& obj);
private:
	int year;  // the year (four digits)
	int month; // the month (1-12)
	int day;   // the day (1-..)
	static int daysPerMonth[12]; // number of days in each month
	bool check_year(Date& date, const int year);
	bool check_month(Date& date, const int month);
	bool check_day(Date& date, const int day, const int month);
};

#endif
