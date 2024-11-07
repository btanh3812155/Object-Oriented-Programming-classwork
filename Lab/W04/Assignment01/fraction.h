#ifndef FRACTION
#define FRACTION

#include <string>
#include <iostream>
#include <fstream>

class Fraction {
private:
    // Attributes
    int numerator;
    int denominator;
    
public:
    // Constructors and destructor
    Fraction ();
    Fraction (int value);
    Fraction (Fraction &newFraction);
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

    Fraction& operator + (Fraction fraction);
    Fraction& operator + (int value);
    Fraction& operator - (Fraction fraction);
    Fraction& operator - (int value);
    Fraction& operator * (Fraction fraction);
    Fraction& operator * (int value);
    Fraction& operator / (Fraction fraction);
    Fraction& operator / (int value);

    bool operator == (Fraction fraction);
    bool operator != (Fraction fraction);
    bool operator >= (Fraction fraction);
    bool operator > (Fraction fraction);
    bool operator <= (Fraction fraction);
    bool operator < (Fraction fraction);

    Fraction& operator = (Fraction fraction);
    Fraction& operator += (Fraction fraction);
    Fraction& operator -= (Fraction fraction);
    Fraction& operator *= (Fraction fraction);
    Fraction& operator /= (Fraction fraction);

    Fraction& operator ++ ();
    Fraction& operator -- ();
    Fraction operator ++ (int);
    Fraction operator -- (int);
    
    operator float ();
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