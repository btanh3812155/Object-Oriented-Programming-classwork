#include <iostream>
#include <fstream>
#include <cmath>
#include "triangleArray.h"

Point::Point() {
    m_x = 0;
    m_y = 0;
}

Point::Point(int x, int y) {
    m_x = x;
    m_y = y;
}

double Point::GetX() {
    return m_x;
}

double Point::GetY() {
    return m_y;
}

void Point::Input() {
    cin >> m_x >> m_y;
}

void Point::Output() {
    cout << '{' << m_x << ',' << m_y << '}' << endl;
}

double Point::Distance(Point a, Point b) {
    double res = sqrt((a.m_x - b.m_x) * (a.m_x - b.m_x) + (a.m_y - b.m_y) * (a.m_y - b.m_y));
    return res;
}

double Point::DistanceOx() {
    return m_y;
}

double Point::DistanceOy() {
    return m_x;
}

//----------------------------------------------

Triangle::Triangle() : A(Point()), B(Point()), C(Point()) {}

Triangle::Triangle(Point newA, Point newB, Point newC) {
    A = newA;
    B = newB;
    C = newC;
}

void Triangle::Input() {
    cout << "input point A: ";
    A.Input();
    cout << "input point B: ";
    B.Input();
    cout << "input point C: ";
    C.Input();
}

void Triangle::Output() {
    A.Output();
    cout << ", ";
    B.Output();
    cout << ", ";
    C.Output();
    cout << '\n';
}

bool Triangle::IsValid() {
    return !((A.GetX() - B.GetX()) / (A.GetX() - C.GetX())
          == (A.GetY() - B.GetY()) / (A.GetY() - C.GetY()));
}

string Triangle::Type() {
    double AB = Point::Distance(A, B);
    double BC = Point::Distance(B, C);
    double CA = Point::Distance(A, C);
    if (AB == BC && BC == CA) return "Equilateral";
    if (AB == BC || BC == CA || CA == AB) return "Isosceles";
    return "Scalene";
}

double Triangle::Perimeter() {
    return Point::Distance(A, B) 
         + Point::Distance(B, C)
         + Point::Distance(A, C);
}

double Triangle::Area() {
    double s = Perimeter() / 2;
    double AB = Point::Distance(A, B);
    double BC = Point::Distance(B, C);
    double CA = Point::Distance(A, C);
    return sqrt(s * (s - AB) * (s - BC) * (s - CA));
}

Point Triangle::CenterG() {
    double x = (A.GetX() + B.GetX() + C.GetX()) / 3;
    double y = (A.GetY() + B.GetY() + C.GetY()) / 3;
    return Point(x, y);
}

//----------------------------------------------

TriangleArray::TriangleArray() {}

TriangleArray::TriangleArray(string filePath) {
    ifstream fin(filePath);
    fin >> count;
    while (!fin.eof()) {
        Point tmpA, tmpB, tmpC;
        int tmpX, tmpY;
        char tmp;
        fin >> tmpX >> tmp >> tmpY >> tmp;
        tmpA = Point(tmpX, tmpY);
        tmpB = Point(tmpX, tmpY);
        tmpC = Point(tmpX, tmpY);
        Triangle tmpTriangle(tmpA, tmpB, tmpC);
        array.push_back(tmpTriangle);
    }
    fin.close();
}

TriangleArray::TriangleArray(TriangleArray& arr) {
    count = arr.count;
    for (int i = 0; i < count; ++i) {
        array[i] = arr.array[i];
    }
}

TriangleArray::~TriangleArray() {
    array.clear();
}

int TriangleArray::GetCount() {
    return count;
}

Triangle* TriangleArray::GetMember(int index) {
    if (index < 0 || index >= count) return nullptr;
    return &array[index];
}

void TriangleArray::RemoveInvalidTriangles(int &invalidCount) {
    int validCount = 0;
    for (int i = 0; i < count; ++i) {
        if (array[i].IsValid()) {
            array[validCount++] = array[i];
        }
    }
    for (int i = validCount; i < count; ++i) {
        array.pop_back();
    }
    invalidCount = count - validCount;
    count = validCount;
}

int TriangleArray::CountInvalidTriangles() {
    int invalidCount = 0;
    for (int i = 0; i < count; ++i) {
        if (!array[i].IsValid()) {
            ++invalidCount;
        }
    }
    return invalidCount;
}

int TriangleArray::ClassifyTriangles(string type) {
    int res = 0;
    for (int i = 0; i < count; ++i) {
        if (array[i].Type() == type) {
            res++;
        }
    }
    return res;
}