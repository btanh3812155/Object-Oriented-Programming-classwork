#ifndef INTARRAY_CPP
#define INTARRAY_CPP

#include "intArray.h"

IntArray::IntArray()
{
    m_size = 0;
    m_array = new int[m_size];
}

IntArray::IntArray(int n)
{
    m_size = n;
    m_array = new int[m_size];
}

IntArray::IntArray(int a[], int n)
{
    m_size = n;
    m_array = new int[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = a[i];
    }
}

IntArray::~IntArray()
{
    delete[] m_array;
}

IntArray& IntArray::operator=(const IntArray &m)
{
    if (this != &m)
    {
        delete[] m_array;
        m_size = m.m_size;
        m_array = new int[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = m.m_array[i];
        }
    }
    return *this;
}

int& IntArray::operator[](int i)
{
    return m_array[i];
}

IntArray::operator int()
{
    return m_size;
}

istream& operator>>(istream &in, IntArray &m)
{
    cout << "input size: ";
    in >> m.m_size;
    cout << endl;
    m.m_array = new int[m.m_size];
    for (int i = 0; i < m.m_size; i++)
    {
        cout << "input element " << i << ": ";
        in >> m.m_array[i];
    }
    return in;
}

ostream& operator<<(ostream &out, IntArray &m)
{
    out << '{';
    for (int i = 0; i < m.m_size; i++)
    {
        out << m.m_array[i] << ", ";
    }
    out << '}' << endl;
    return out;
}

#endif // INTARRAY_CPP