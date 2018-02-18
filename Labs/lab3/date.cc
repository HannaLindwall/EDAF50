#include <ctime>  // time and localtime
#include <iomanip>
#include <algorithm>
#include <ios>
#include "date.h"
using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::setw;
using std::setfill;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day++;
	if(day > daysPerMonth[month - 1]) {
		day = 1;
		month++;
		if(month == 12) {
			month = 1;
			year++;
		}
	}
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.year << '-';
	stream << setw(2) << setfill('0') << date.month << '-';
	stream << setw(2) << setfill('0') << date.day << endl;
	return stream;
}

istream& operator>>(istream& is, Date& date) {
	string line;
	std::getline(is, line);
	size_t n = std::count(line.begin(), line.end(), '-');
	if(n == 2) {
		std::stringstream ss(line);
		int digit ;
		char dash;
		ss >> digit;
		if(!date.check_year(date, digit)) {
			is.setstate(std::ios_base::failbit);
			return is;
		}
		ss >> dash;
		if(dash != '-') {
			is.setstate(std::ios_base::failbit);
			return is;
		}
		ss >> digit;
		if(!date.check_month(date, digit)) {
			is.setstate(std::ios_base::failbit);
			return is;
		}
		ss >> dash;
		if(dash != '-') {
			is.setstate(std::ios_base::failbit);
			return is;
		}
		ss >> digit;
		if(!date.check_day(date, digit, date.month)) {
			is.setstate(std::ios_base::failbit);
			return is;
		}
	} else {
		is.setstate(std::ios_base::failbit);
	}

	return is;
}

bool Date::check_year(Date& date, const int year) {
	if(year >= 1000 && year <= 9999) {
		date.year = year;
		return true;
	}
	return false;
}

bool Date::check_month(Date& date, const int month) {
	if(month > 0 && month <= 12) {
		date.month = month;
		return true;
	}
	return false;
}
bool Date::check_day(Date& date, const int day, const int month) {
	if(day > 0 && day <= daysPerMonth[month - 1]) {
		date.day = day;
		return true;
	}
	return false;
}
