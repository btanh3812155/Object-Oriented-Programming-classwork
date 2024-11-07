#ifndef FRACTION_STRUCT
#define FRACTION_STRUCT

#include <string>

struct Fraction {
    // Attributes
    int numerator;
    int denominator;

    // Constructors and destructor
    Fraction () :
        numerator (0),
        denominator (1) {}
    Fraction (int value) :
        numerator (value),
        denominator (0) {}
    Fraction (int numerator, int denominator);
    ~Fraction () {};
    
    // Functions
    void Input ();
    void Output ();
    void Add (Fraction fraction);
    void Subtract (Fraction fraction);
    void Multiply (Fraction fraction);
    void Divide (Fraction fraction);
    void Reduce ();
    std::string Compare (Fraction fraction);
    bool isPositive ();
    bool isNegative ();
    bool isZero ();
};

#endif