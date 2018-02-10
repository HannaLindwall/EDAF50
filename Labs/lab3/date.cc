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
	int i = 0;
	int flag = 0;
	if(n == 2) {
		std::stringstream ss(line);
		while(ss.good()) {
			string substr;
			getline(ss, substr, '-');
			int digit = std::stoi (substr);
			if(i == 0) {
				if(date.check_year(digit)) {
					date.year = digit;
				} else {
					flag = 1;
				}
			} else if(i == 1) {
				if(date.check_month(digit)) {
					date.month = digit;
				} else {
					flag = 1;
				}
			} else {
				if(date.check_day(digit, date.month)) {
					date.day = digit;
				} else {
					flag = 1;
				}
			}
			if(flag != 0) {
				ss.setstate(std::ios_base::failbit);
				is.setstate(std::ios_base::failbit);
			}
			i++;
		}
	} else {
		is.setstate(std::ios_base::failbit);
		cout << "wrong format: must contain two -> XXXX-XX-XX" << endl;
	}

	return is;
}

bool Date::check_year(const int year) {
	if(year >= 1000 && year <= 9999) {
		return true;
	}
	cout << "year input not valid" << endl;
	return false;
}

bool Date::check_month(const int month) {
	if(month > 0 && month <= 12) {
		return true;
	}
	cout << "month input not valid" << endl;
	return false;
}
bool Date::check_day(const int day, const int month) {
	if(day > 0 && day <= daysPerMonth[month - 1]) {
		return true;
	}
	cout << "day input not valid" << endl;
	return false;
}
