#include "fractionArray.cpp"

int main () {
    FractionArray testArray;

    testArray.Add (2, 5);
    Fraction testFraction (3);
    testArray.Add(testFraction);

    testArray.Sum().Output();
    testArray.Min()->Output();
    testArray.Max()->Output();
    testArray.Sort();
    for (int i = 0; i < testArray.GetCount(); ++i) {
        testArray.GetMember(i).Output();
    }

    return 0;
}