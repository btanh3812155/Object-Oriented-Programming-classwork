#include "pointArray.h"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

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

//------------------------------------------------------------------------

PointArray::PointArray() {
    array = new Point[0];
}

PointArray::PointArray(PointArray* newArr) {
    array = new Point[newArr->GetCount()];
    for (int i = 0; i < newArr->GetCount(); ++i) {
        array[i] = *newArr->GetMember(i);
    }
}

PointArray::PointArray(string filePath) {
    ifstream fin(filePath);
    char x, y, tmp;
    while (fin >> x) {
        fin >> tmp;
        fin >> y;
        fin >> tmp;
        Add(x,y);
    }
    fin.close();
}

PointArray::~PointArray() {
    delete []array;
}

int PointArray::GetCount() {
    return count;
}

Point* PointArray::GetMember(int index) {
    if (index < 0 || index >= count)
        return nullptr;
    return &array[index];
}

void PointArray::Add (Point newPoint) {
    array[count] = newPoint;
    ++count;
}

void PointArray::Add (int x, int y) {
    array[count] = Point(x,y);
    ++count;
}

void PointArray::Input() {
    int x, y;
    cin >> x, y;
    Add(x, y);
}

Point* PointArray::FindFurthest(Point* P) {
    double maxDistance = 0;
    Point* res = nullptr;
    for(int i = 0; i < count; ++i) {
        if(Point::Distance(array[i],*P) >= maxDistance) {
            res = &array[i];
            maxDistance = Point::Distance(array[i],*P);
        }
    }
    return res;
}
