#include <string>
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

class PointArray {
private:
    Point* array;
    int count = 0;

public:
    PointArray();
    PointArray(PointArray* newArr);
    PointArray(string filePath);
    ~PointArray();

    int GetCount();
    Point* GetMember(int index);
    void Add (Point newPoint);
    void Add (int x, int y);
    void Input();
    Point* FindFurthest(Point* P);
};