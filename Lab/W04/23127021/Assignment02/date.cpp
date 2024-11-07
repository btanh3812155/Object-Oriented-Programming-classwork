#ifndef DATE_IMPL
#define DATE_IMPL

#include "date.h"

Date::Date () {
    day         = 2;
    month       = 11;
    year        = 2012;
}

Date::Date (int year) {
    day         = 1;
    month       = 1;
    this->year  = year;
}

Date::Date (int year, int month) {
    day         = 1;
    this->month = month;
    this->year  = year;
    this->FixDate();
}

Date::Date (int year, int month, int day) {
    this->day   = day;
    this->month = month;
    this->year  = year;
    this->FixDate();
}

Date::Date (Date &newDate) {
    day         = newDate.day;
    month       = newDate.month;
    year        = newDate.year;
    this->FixDate();
}

Date Date::Tomorrow () {
    Date tomorrow = *this;
    tomorrow.day++;
    this->FixDate();
    return tomorrow;
}

Date Date::Yesterday () {
    Date yesterday = *this;
    yesterday.day--;
    this->FixDate();
    return yesterday;
}

void Date::FixDate () {
    while (day > 30 && (month == 4
                     || month == 6
                     || month == 9
                     || month == 11)
       || (day > 31 && (month == 1 
                     || month == 3
                     || month == 5
                     || month == 7
                     || month == 8
                     || month == 10))
       || (day > 28 &&  month == 2)
       || (day > 31 &&  month == 12)) {
        switch (month) {
            case 2:
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                    day -= 29;
                } else {
                    day -= 28;
                }
                month++;
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                day  -= 31;
                month++;
                break;
            case 12:
                day  -= 31;
                month = 1;
                year++;
                break;
            default:
                day  -= 30;
                month++;
        }
    }

    while (day < 1) {
        switch (month) {
            case 3:
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                    day += 29;
                } else {
                    day += 28;
                }
                month--;
                break;
            case 1:
                day  += 31;
                month = 12;
                year--;
                break;
            case 5:
            case 7:
            case 10:
            case 12:
                day  += 30;
                month--;
                break;
            default:
                day  += 31;
                month--;
        }
    }
}

Date& Date::operator + (int value) {
    day += value;
    this->FixDate();
    return *this;
}

Date& Date::operator - (int value) {
    day -= value;
    this->FixDate();
    return *this;
}

bool Date::operator == (Date date) {
    return day   == date.day
        && month == date.month
        && year  == date.year;
}

bool Date::operator != (Date date) {
    return day   != date.day
        || month != date.month
        || year  != date.year;
}

bool Date::operator >= (Date date) {
    return *this == date
        || *this > date; 
}

bool Date::operator > (Date date) {
    return year  >  date.year 
       || (year  == date.year &&
          (month >  date.month 
       || (month == date.month &&
           day   >  date.day)));
}

bool Date::operator <= (Date date) {
    return *this == date
        || *this <  date;
}

bool Date::operator < (Date date) {
    return year  <  date.year
       || (year  == date.year &&
          (month <  date.month
       || (month == date.month &&
           day   <  date.day)));
}

Date& Date::operator = (Date date) {
    day   = date.day;
    month = date.month;
    year  = date.year;
    this->FixDate();
    return *this;
}

Date& Date::operator += (int value) {
    day += value;
    this->FixDate();
    return *this;
}

Date& Date::operator -= (int value) {
    day -= value;
    this->FixDate();
    return *this;
}

Date& Date::operator ++ () {
    day++;
    this->FixDate();
    return *this;
}

Date& Date::operator -- () {
    day--;
    this->FixDate();
    return *this;
}

Date Date::operator ++ (int) {
    Date temp = *this;
    day++;
    this->FixDate();
    return temp;
}

Date Date::operator -- (int) {
    Date temp = *this;
    day--;
    this->FixDate();
    return temp;
}

std::ostream& operator << (std::ostream &out, Date date) {
    out << date.day   << "/"
        << date.month << "/"
        << date.year  << '\n';
    return out;
}

std::istream& operator >> (std::istream &in, Date &date) {
    in >> date.day;
    in.ignore(1);
    in >> date.month;
    in.ignore(1);
    in >> date.year;
    date.FixDate();
    return in;
}

Date::operator int () {
    switch (month) {
        int secondMonthDays;
        if (year % 4   == 0 && 
           (year % 100 != 0
         || year % 400 == 0)) {
            secondMonthDays = 29;
        } else {
            secondMonthDays = 28;
        }
        case 1:
            return day + 0   + year * 365;
        case 2:
            return day + 31  + year * 365;
        case 3:
            return day + 31  + secondMonthDays + year * 365;
        case 4:
            return day + 62  + secondMonthDays + year * 365;
        case 5:
            return day + 92  + secondMonthDays + year * 365;
        case 6:
            return day + 123 + secondMonthDays + year * 365;
        case 7:
            return day + 153 + secondMonthDays + year * 365;
        case 8:
            return day + 184 + secondMonthDays + year * 365;
        case 9:
            return day + 215 + secondMonthDays + year * 365;
        case 10:
            return day + 245 + secondMonthDays + year * 365;
        case 11:
            return day + 276 + secondMonthDays + year * 365;
        case 12:
            return day + 306 + secondMonthDays + year * 365;
    }
}

Date::operator long () {
    switch (month) {
        long secondMonthDays;
        if (year % 4   == 0 && 
           (year % 100 != 0
         || year % 400 == 0)) {
            secondMonthDays = 29;
        } else {
            secondMonthDays = 28;
        }
        case 1:
            return day + 0   + year * 365;
        case 2:
            return day + 31  + year * 365;
        case 3:
            return day + 31  + secondMonthDays + year * 365;
        case 4:
            return day + 62  + secondMonthDays + year * 365;
        case 5:
            return day + 92  + secondMonthDays + year * 365;
        case 6:
            return day + 123 + secondMonthDays + year * 365;
        case 7:
            return day + 153 + secondMonthDays + year * 365;
        case 8:
            return day + 184 + secondMonthDays + year * 365;
        case 9:
            return day + 215 + secondMonthDays + year * 365;
        case 10:
            return day + 245 + secondMonthDays + year * 365;
        case 11:
            return day + 276 + secondMonthDays + year * 365;
        case 12:
            return day + 306 + secondMonthDays + year * 365;
    }
}

#endif