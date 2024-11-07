#ifndef DATE
#define DATE

#include <iostream>

class Date {
private:
    // Attributes
    int day;
    int month;
    int year;

public:
    Date ();
    Date (int year);
    Date (int year, int month);
    Date (int year, int month, int day);
    Date (Date &newDate);
    ~Date () {};

    Date Tomorrow  ();
    Date Yesterday ();

    void FixDate ();

    Date& operator +  (int value);
    Date& operator -  (int value);

    bool  operator == (Date date);
    bool  operator != (Date date);
    bool  operator >= (Date date);
    bool  operator >  (Date date);
    bool  operator <= (Date date);
    bool  operator <  (Date date);

    Date& operator =  (Date date);
    Date& operator += (int value);
    Date& operator -= (int value);

    Date& operator ++ ();
    Date& operator -- ();
    Date  operator ++ (int);
    Date  operator -- (int);

    friend std::ostream& operator << (std::ostream &out, Date date);
    friend std::istream& operator >> (std::istream &in, Date &date);

    operator int ();
    operator long ();
};

#endif