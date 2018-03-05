/*
 * class Date: describes dates with year, month, and day. Doesn't
 * handle leap years.
 */

#ifndef DATE_H
#define DATE_H

class Date {
public:
	Date();                    // today's date
	Date(int y, int m, int d); // yyyy-mm-dd
	int get_year() const;      // get the year
	int get_month() const;     // get the month
	int get_day() const;       // get the day
	void next();               // advance to next day
private:
	int year;  // the year (four digits)
	int month; // the month (1-12)
	int day;   // the day (1-..)
	static int daysPerMonth[12]; // number of days in each month
};

/*
 * Prints a date in the format yyyy-mm-dd. The function is intended to
 * show an example of a global function; it would be better to overload
 * the output operator <<.
 */
void print(const Date& d);

/*
 * This function is an overloaded operator <. It makes it possible
 * to compare two dates d1 and d2 with 'd1 < d2'.
 */
bool operator<(const Date& d1, const Date& d2);

/*
 * A function to compute the number of days between two dates.
 */
int distance(const Date& d1, const Date& d2);

#endif
