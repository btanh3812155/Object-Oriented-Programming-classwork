#ifndef VECTOR_H
#define VECTOR_H

#include <string>

template<class T>
class MyVector {
private:
    T *arr;
    int size;

public:
    // empty array
    MyVector();

    // n zeros
    MyVector(int n);
    MyVector(T *a, int n);
    MyVector(const MyVector &v);

    ~MyVector();

    int getSize();
    T getItem(int index);
    void setItem(T value, int index);

    void add(T value);
    void addRange(T *a, int n);
    void clear();
    bool contains(T value);
    void toArray(T *arr, int &n);
    bool equals(const MyVector &v);
    int indexOf(T value);
    int lastIndexOf(T value);
    void insert(T value, int index);
    void remove(T value);
    void removeAt(int index);
    void reverse();
    std::string toString();

    int findMax();
    int findMin();
    void sortAsc();
    void sortDesc();
};

#endif // VECTOR_H