#include "date.h"

// Put your constructor implementation HERE. 
Date::Date(int year, int month, int day) : year{year}, month{month}, day{day} {}

// https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Corresponding_days
DayOfWeek Date::getDay() const {
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	int year_ = year - (month < 3);
	return static_cast<DayOfWeek>( 
		(year_ + year_/4 - year_/100 + year_/400 + t[month-1] + day) % 7 );
}

bool Date::operator==(Date other) const {
	return (year == other.year && month == other.month && day == other.day);
}

bool Date::operator<(Date other) const {
	if (year > other.year) {
		return false;
	} else if (year == other.year){
		if (month > other.month){
			return false;
		} else if (month == other.month){
			if (day >= other.day){
				return false;
			} else {
				return true;
			}
		} else {
			return true;
		}
	} else {
		return true;
	}
}

// Put your member and non-member functions HERE.
std::istream & operator>>(std::istream & in, Date & date){
	int y, m, d;
	in >> y;
	in.ignore();
	in >> m;
	in.ignore();
	in >> d;
	date = Date{y,m,d};
	return in;
}

std::ostream & operator<<(std::ostream & out, Date date){
	out << std::setfill('0') << std::setw(4);
	out << date.year << '/';
	out << std::setfill('0') << std::setw(2);
	out << date.month << '/';
	out << std::setfill('0') << std::setw(2);
	out << date.day;
	return out;
}

