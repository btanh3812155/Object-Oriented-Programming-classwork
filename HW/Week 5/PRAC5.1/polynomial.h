#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
private:
    int degree;
    double *coefficients;

public:
    Polynomial();
    Polynomial(int degree);
    Polynomial(const Polynomial &p);
    ~Polynomial();

    void setCoefficient(int degree, double coefficient);
    double getCoefficient(int degree) const;
    int getDegree() const;
    void setDegree(int degree);
    
    Polynomial operator +(const Polynomial &p);
    Polynomial operator +(double k);
    Polynomial operator -(const Polynomial &p);
    Polynomial operator -(double k);
    Polynomial operator *(const Polynomial &p);
    Polynomial operator *(double k);
    Polynomial operator /(const Polynomial &p);
    Polynomial operator /(double k);
    Polynomial &operator =(const Polynomial &p);

    bool operator ==(const Polynomial &p) const;
    bool operator !=(const Polynomial &p) const;
    bool operator >(const Polynomial &p) const;
    bool operator <(const Polynomial &p) const;
    bool operator >=(const Polynomial &p) const;
    bool operator <=(const Polynomial &p) const;

    Polynomial operator !();
    Polynomial operator ~();

    friend std::ostream &operator <<(std::ostream &out, const Polynomial &p);
    friend std::istream &operator >>(std::istream &in, Polynomial &p);
};

#endif // POLYNOMIAL_H