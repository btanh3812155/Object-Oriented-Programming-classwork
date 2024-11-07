#ifndef FRACTION_ARRAY
#define FRACTION_ARRAY

#include <string>

class Fraction {
private:
    // Attributes
    int numerator;
    int denominator;
    
public:
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

class FractionArray {
private:
    Fraction* array;
    int count = 0;

public:
    // constructors and destructor
    FractionArray ();
    FractionArray (FractionArray* newArray);
    FractionArray (std::string filePath);
    ~FractionArray ();

    // functions
    int GetCount ();
    Fraction GetMember (int index);
    void Add (int num, int den);
    void Add (Fraction newFraction);
    Fraction Sum ();
    Fraction* Min ();
    Fraction* Max ();
    void Sort ();
};

#endif