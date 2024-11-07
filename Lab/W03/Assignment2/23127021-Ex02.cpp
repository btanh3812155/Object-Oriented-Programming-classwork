#include "pointArray.h"
#include <iostream>
using namespace std;

int main() {
    string fileName = "points.txt";
    PointArray pointArray(fileName);

    // print array
    cout << "Points in the array:" << endl;
    for (int i = 0; i < pointArray.GetCount(); ++i) {
        Point* p = pointArray.GetMember(i);
        if (p) {
            p->Output();
        }
    }

    // furthest point from (0, 0)
    Point testPoint(0, 0);
    Point* furthestPoint = pointArray.FindFurthest(&testPoint);
    if (furthestPoint) {
        cout << "Furthest point: ";
        furthestPoint->Output();
    }
    else
        cout << "empty array" << endl;

    return 0;
}
