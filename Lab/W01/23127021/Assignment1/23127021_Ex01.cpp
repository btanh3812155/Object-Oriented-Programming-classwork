#include "fractionStruct.cpp"

int main () {
    Fraction testFraction(4, 7);

    testFraction.Output();
    testFraction.Add(Fraction(2));
    testFraction.Output();
    testFraction.Compare(Fraction(3, 8));
    testFraction.Output();
    testFraction.Divide(Fraction(0));
    testFraction.Output();
    std::cout << "Is negative: " << testFraction.isNegative() << '\n';
    testFraction.Reduce();
    testFraction.Output();

    return 0;
}