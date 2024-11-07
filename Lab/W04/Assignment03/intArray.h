#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>

using namespace std;

class IntArray {
private:
    int* m_array;
    int m_size;

public:
    IntArray();
    IntArray(int n);
    IntArray(int a[], int n);
    ~IntArray();

    IntArray& operator=(const IntArray &m);
    
    int& operator[](int i);

    operator int();

    friend istream& operator>>(istream &in, IntArray &m);
    friend ostream& operator<<(ostream &out, IntArray &m);
};

#endif // INTARRAY_H