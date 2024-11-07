#ifndef TRIANGLEARRAY_H
#define TRIANGLEARRAY_H

#include <string>
#include <vector>

using namespace std;

class Point {
private:
    double m_x, m_y;

public:
    Point();
    Point(int x, int y);
    ~Point() {};

    double GetX();
    double GetY();
    void Input();
    void Output();
    static double Distance(Point a, Point b);
    double DistanceOx();
    double DistanceOy();
};

class Triangle {
private:
    Point A;
    Point B;
    Point C;

public:
    Triangle();
    Triangle(Point newA, Point newB, Point newC);

    void Input();
    void Output();
    bool IsValid();
    string Type();
    double Perimeter();
    double Area();
    Point CenterG();
};

class TriangleArray : public Triangle {
private:
    vector<Triangle> array {};
    int count = 0;

public:
    TriangleArray();
    TriangleArray(string filePath);
    TriangleArray(TriangleArray& arr);
    ~TriangleArray();

    int GetCount();
    Triangle* GetMember(int index);
    void RemoveInvalidTriangles(int &invalidCount);
    int CountInvalidTriangles();
    int ClassifyTriangles(string type);
};

#endif // TRIANGLEARRAY_H
