#ifndef FRACTION_ARRAY_IMPL
#define FRACTION_ARRAY_IMPL

#include <iostream>
#include <fstream>

#include "fractionArray.h"

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

//---------------------------------------------------------------------------------------------------------------------------------------------------

FractionArray::FractionArray () {
    array = new Fraction[0];
}

FractionArray::FractionArray (FractionArray* newArray) {
    array = new Fraction[newArray->GetCount()];
    for (int i = 0; i < newArray->GetCount(); ++i) {
        array[i] = newArray->GetMember(i);
    }
}

FractionArray::FractionArray (std::string filePath) {
    std::ifstream fin(filePath);
    char numBuf, denBuf, tmp;
    while (fin >> numBuf) {
        fin >> tmp;
        fin >> denBuf;
        fin >> tmp;
        Add (numBuf, denBuf);
    }
}

FractionArray::~FractionArray() {
    delete []array;
}

int FractionArray::GetCount () {
    return count;
}

Fraction FractionArray::GetMember (int index) {
    return array[index];
}

void FractionArray::Add (int num, int den) {
    Fraction tmp (num, den);
    array[count] = tmp;
    count++;
}

void FractionArray::Add (Fraction newFraction) {
    array[count] = newFraction;
    count++;
}

Fraction FractionArray::Sum () {
    Fraction sum (0);
    for (int i = 0; i < count; ++i) {
        sum.Add (array[i]);
    }
    return sum;
}

Fraction* FractionArray::Min () {
    Fraction* min = &array[0];
    for (int i = 1; i < count; ++i) {
        Fraction temp = *min;
        temp.Subtract (array[i]);
        if (temp.isPositive()) {
            min = &array[i];
        }
    }
    return min;
}

Fraction* FractionArray::Max () {
    Fraction* max = &array[0];
    for (int i = 1; i < count; ++i) {
        Fraction temp = *max;
        temp.Subtract (array[i]);
        if (temp.isNegative()) {
            max = &array[i];
        }
    }
    return max;
}

void FractionArray::Sort () {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if(array[i].Compare(array[j]) == "Larger") {
                Fraction tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

#endif