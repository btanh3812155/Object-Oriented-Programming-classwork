#ifndef FRACTION_STRUCT_IMPL
#define FRACTION_STRUCT_IMPL

#include <iostream>

#include "fractionStruct.h"

// lowest common multiple
int LCM (int a, int b) {
    int greater = std::max(a, b);
    int lesser = std::min(a, b);
    for (int i = greater; ; i += greater) {
        if (!(i % lesser))
            return i;
    }
}

// greatest common denominator 
int GCD (int a, int b) {
    if (!a)
        return b;
    if (!b)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return GCD (a - b, b);
    return (a, b - a);
}

// initialize fraction with given values
Fraction::Fraction (int num, int denom) {
    numerator = num;
    if (!denom) {
        std::cout << "Denominator can't be zero, defaulting to 1\n";
        denominator = 1;
    }
    else
        denominator = denom;
}

// overwrites value with input
void Fraction::Input () {
    int temp, temp2;
    std::cout << "Input numerator: ";
    std::cin >> temp;
    std::cout << "\nInput denominator: ";
    std::cin >> temp2;
    if (temp2) {
        numerator = temp;
        denominator = temp2;
    }
    else
        std::cout << "\nDenominator can't be zero\n";
}

// print fraction to console
void Fraction::Output () {
    std::cout << "Fraction is: "
              << numerator
              << '/'
              << denominator
              << '\n';
}

// add argument's value to fraction
void Fraction::Add (Fraction fraction) {
    if (denominator == fraction.denominator)
        numerator += fraction.numerator;
    else {
        numerator *= LCM(denominator, fraction.denominator) / denominator;
        numerator += fraction.numerator * (LCM(denominator, fraction.denominator) / fraction.denominator);
        denominator = LCM(denominator, fraction.denominator);
    }
}

// subtract argument's value from fraction
void Fraction::Subtract (Fraction fraction) {
    if (denominator == fraction.denominator)
        numerator += fraction.numerator;
    else {
        numerator *= LCM(denominator, fraction.denominator) / denominator;
        numerator -= fraction.numerator * (LCM(denominator, fraction.denominator) / fraction.denominator);
        denominator = LCM(denominator, fraction.denominator);
    }
}

// multiply fraction by another fraction
void Fraction::Multiply (Fraction fraction) {
    numerator *= fraction.numerator;
    denominator *= fraction.denominator;
}

// divide fraction by another fraction
void Fraction::Divide (Fraction fraction) {
    if (!fraction.numerator) {
        std::cout << "Can't divide by zero\n";
        return;
    }
    numerator *= fraction.denominator;
    denominator *= fraction.numerator;
}

// reduce fraction
void Fraction::Reduce () {
    int gcd = GCD (numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

// compare fraction to another fraction
std::string Fraction::Compare (Fraction fraction) {
    if ((float(numerator) / float(fraction.numerator)) == (float(denominator) / float(fraction.denominator)))
        return "Equal";
    if ((float(numerator) / float(fraction.numerator)) > (float(denominator) / float(fraction.denominator)))
        return "Larger";
    if ((float(numerator) / float(fraction.numerator)) < (float(denominator) / float(fraction.denominator)))
        return "Smaller";
    
}

// print whether fraction is positive
bool Fraction::isPositive () {
    if (numerator * denominator > 0)
        return true;
    return false;
}

// print whether fraction is negative
bool Fraction::isNegative () {
    return !isPositive();
}

// print whether fraction is zero
bool Fraction::isZero () {
    return (numerator == 0);
}

#endif