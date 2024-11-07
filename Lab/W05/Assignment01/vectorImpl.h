#ifndef VECTOR_IMPL-H
#define VECTOR_IMPL_H

#include "vector.h"

template<class T>
MyVector<T>::MyVector() {
    size = 0;
    arr = new T[size];
}

template<class T>
MyVector<T>::MyVector(int n) {
    size = n;
    arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

template<class T>
MyVector<T>::MyVector(T *a, int n) {
    size = n;
    arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = a[i];
    }
}

template<class T>
MyVector<T>::MyVector(const MyVector &v) {
    size = v.size;
    arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = v.arr[i];
    }
}

template<class T>
MyVector<T>::~MyVector() {
    delete[] arr;
}

template<class T>
int MyVector<T>::getSize() {
    return size;
}

template<class T>
T MyVector<T>::getItem(int index) {
    return arr[index];
}

template<class T>
void MyVector<T>::setItem(T value, int index) {
    arr[index] = value;
}

template<class T>
void MyVector<T>::add(T value) {
    T* newArr = new T[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = value;
    delete[] arr;
    arr = newArr;
    size++;
}

template<class T>
void MyVector<T>::addRange(T *a, int n) {
    T* newArr = new T[size + n];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        newArr[size + i] = a[i];
    }
    delete[] arr;
    arr = newArr;
    size += n;
}

template<class T>
void MyVector<T>::clear() {
    delete[] arr;
    size = 0;
    arr = new T[size];
}

template<class T>
bool MyVector<T>::contains(T value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

template<class T>
void MyVector<T>::toArray(T *a, int &n) {
    for (int i = 0; i < size; i++) {
        a[i] = arr[i];
    }
    n = size;
}

template<class T>
bool MyVector<T>::equals(const MyVector &v) {
    if (size != v.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] != v.arr[i]) {
            return false;
        }
    }
    return true;
}

template<class T>
int MyVector<T>::indexOf(T value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

template<class T>
int MyVector<T>::lastIndexOf(T value) {
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

template<class T>
void MyVector<T>::insert(T value, int index) {
    T* newArr = new T[size + 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    newArr[index] = value;
    for (int i = index; i < size; i++) {
        newArr[i + 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size++;
}

template<class T>
void MyVector<T>::remove(T value) {
    int index = indexOf(value);
    if (index != -1) {
        removeAt(index);
    }
}

template<class T>
void MyVector<T>::removeAt(int index) {
    T* newArr = new T[size - 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

template<class T>
void MyVector<T>::reverse() {
    T* newArr = new T[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[size - 1 - i];
    }
    delete[] arr;
    arr = newArr;
}

template<class T>
std::string MyVector<T>::toString() {
    string str = "[";
    for (int i = 0; i < size; i++) {
        str += to_string(arr[i]);
        if (i < size - 1) {
            str += ", ";
        }
    }
    str += "]";
    return str;
}

template<class T>
int MyVector<T>::findMax() {
    int max = arr[0], maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

template<class T>
int MyVector<T>::findMin() {
    int min = arr[0], minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

template<class T>
void MyVector<T>::sortAsc() {
    T* newArr = new T[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[findMin()];
        removeAt(findMin());
    }
    delete[] arr;
    arr = newArr;
}

template<class T>
void MyVector<T>::sortDesc() {
    T* newArr = new T[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[findMax()];
        removeAt(findMax());
    }
    delete[] arr;
    arr = newArr;
}

#endif // VECTOR_IMPL_H