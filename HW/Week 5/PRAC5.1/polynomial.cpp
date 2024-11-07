#ifndef POLYNOMIAL_CPP
#define POLYNOMIAL_CPP

#include "polynomial.h"

Polynomial::Polynomial() {
    degree = 0;
    coefficients = new double[1];
    coefficients[0] = 0;
}

Polynomial::Polynomial(int degree) {
    this->degree = degree;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        coefficients[i] = 0;
    }
}

Polynomial::Polynomial(const Polynomial &p) {
    degree = p.degree;
    delete[] coefficients;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = p.coefficients[i];
    }
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

void Polynomial::setCoefficient(int degree, double coefficient) {
    if (degree > this->degree) {
        double *temp = new double[degree + 1];
        for (int i = 0; i <= this->degree; i++) {
            temp[i] = coefficients[i];
        }
        for (int i = this->degree + 1; i <= degree; i++) {
            temp[i] = 0;
        }
        delete[] coefficients;
        coefficients = temp;
        this->degree = degree;
    }
    coefficients[degree] = coefficient;
}

double Polynomial::getCoefficient(int degree) const {
    if (degree > this->degree) {
        return 0;
    }
    return coefficients[degree];
}

int Polynomial::getDegree() const {
    return degree;
}

void Polynomial::setDegree(int degree) {
    if (degree > this->degree) {
        double *temp = new double[degree + 1];
        for (int i = 0; i <= this->degree; i++) {
            temp[i] = coefficients[i];
        }
        for (int i = this->degree + 1; i <= degree; i++) {
            temp[i] = 0;
        }
        delete[] coefficients;
        coefficients = temp;
        this->degree = degree;
    }

    if (degree < this->degree) {
        double *temp = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            temp[i] = coefficients[i];
        }
        delete[] coefficients;
        coefficients = temp;
        this->degree = degree;
    }
}

Polynomial Polynomial::operator +(const Polynomial &p) {
    Polynomial result;
    int maxDegree;
    if (degree > p.degree) {
        maxDegree = degree;
    }
    else {
        maxDegree = p.degree;
    }
    result.setDegree(maxDegree);
    for (int i = 0; i <= maxDegree; i++) {
        double j = p.getCoefficient(i);
        result.setCoefficient(i, getCoefficient(i) + (p.getCoefficient(i)));
    }
    return result;
}

Polynomial Polynomial::operator +(double k) {
    this->setCoefficient(0, this->getCoefficient(0) + k);
    return *this;
}

Polynomial Polynomial::operator -(const Polynomial &p) {
    Polynomial result;
    int maxDegree;
    if (degree > p.degree) {
        maxDegree = degree;
    }
    else {
        maxDegree = p.degree;
    }
    result.setDegree(maxDegree);
    for (int i = 0; i <= maxDegree; i++) {
        result.setCoefficient(i, getCoefficient(i) - (p.getCoefficient(i)));
    }
    return result;
}

Polynomial Polynomial::operator -(double k) {
    this->setCoefficient(0, this->getCoefficient(0) - k);
    return *this;
}

Polynomial Polynomial::operator *(const Polynomial &p) {
    Polynomial result;
    result.setDegree(degree + p.degree);
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= p.degree; j++) {
            result.setCoefficient(i + j, result.getCoefficient(i + j) + (getCoefficient(i) * p.getCoefficient(j)));
        }
    }
    return result;
}

Polynomial Polynomial::operator *(double k) {
    for (int i = 0; i <= degree; i++) {
        this->setCoefficient(i, this->getCoefficient(i) * k);
    }
    return *this;
}

Polynomial Polynomial::operator /(const Polynomial &p) {
    Polynomial result;
    if (degree < p.degree) {
        return result;
    }
    result.setDegree(degree - p.degree);
    Polynomial temp;
    temp.setDegree(degree);
    for (int i = 0; i <= degree; i++) {
        temp.setCoefficient(i, getCoefficient(i));
    }
    while (temp.getDegree() >= p.degree) {
        int currentDegree = temp.getDegree() - p.degree;
        double currentCoefficient = temp.getCoefficient(temp.getDegree()) / p.getCoefficient(p.degree);
        result.setCoefficient(currentDegree, currentCoefficient);
        Polynomial temp2;
        temp2.setDegree(currentDegree);
        for (int i = 0; i <= currentDegree; i++) {
            temp2.setCoefficient(i, p.getCoefficient(i) * currentCoefficient);
        }
        temp = temp - (temp2 * p);
    }
    return result;
}

Polynomial Polynomial::operator /(double k) {
    for (int i = 0; i <= degree; i++) {
        this->setCoefficient(i, this->getCoefficient(i) / k);
    }
    return *this;
}

Polynomial &Polynomial::operator =(const Polynomial &p) {
    degree = p.degree;
    delete[] coefficients;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = p.coefficients[i];
    }
    return *this;
}

bool Polynomial::operator ==(const Polynomial &p) const {
    if (degree != p.degree) {
        return false;
    }
    for (int i = 0; i <= degree; i++) {
        if (coefficients[i] != p.coefficients[i]) {
            return false;
        }
    }
    return true;
}

bool Polynomial::operator !=(const Polynomial &p) const {
    return !(*this == p);
}

bool Polynomial::operator >(const Polynomial &p) const {
    if (degree > p.degree) {
        return true;
    }
    if (degree < p.degree) {
        return false;
    }
    for (int i = degree; i >= 0; i--) {
        if (coefficients[i] > p.coefficients[i]) {
            return true;
        }
        if (coefficients[i] < p.coefficients[i]) {
            return false;
        }
    }
    return false;
}

bool Polynomial::operator <(const Polynomial &p) const {
    if (degree < p.degree) {
        return true;
    }
    if (degree > p.degree) {
        return false;
    }
    for (int i = degree; i >= 0; i--) {
        if (coefficients[i] < p.coefficients[i]) {
            return true;
        }
        if (coefficients[i] > p.coefficients[i]) {
            return false;
        }
    }
    return false;
}

bool Polynomial::operator >=(const Polynomial &p) const {
    return !(*this < p);
}

bool Polynomial::operator <=(const Polynomial &p) const {
    return !(*this > p);
}

Polynomial Polynomial::operator !() {
    Polynomial result;
    result.setDegree(degree-1);
    for (int i = 0; i <= degree-1; i++) {
        result.setCoefficient(i, coefficients[i+1] * (i+1));
    }
    this->setDegree(degree-1);
    for (int i = 0; i <= degree; i++) {
        this->setCoefficient(i, result.getCoefficient(i));
    }
    return *this;
}

Polynomial Polynomial::operator ~() {
    Polynomial result;
    result.setDegree(degree+1);
    for (int i = 0; i <= degree; i++) {
        result.setCoefficient(i+1, coefficients[i] / (i+1));
    }
    this->setDegree(degree+1);
    for (int i = 0; i <= degree; i++) {
        this->setCoefficient(i, result.getCoefficient(i));
    }
    return *this;
}

std::ostream &operator <<(std::ostream &out, const Polynomial &p) {
    for (int i = p.degree; i >= 0; i--) {
        if (p.coefficients[i] != 0) {
            if (i == 0) {
                out << p.coefficients[i];
            }
            else {
                if (p.coefficients[i] == 1) {
                    out << "x";
                }
                else if (p.coefficients[i] == -1) {
                    out << "-x";
                }
                else {
                    out << p.coefficients[i] << "x";
                }
                if (i != 1) {
                    out << "^" << i;
                }
            }
            if (i != 0) {
                if (p.coefficients[i-1] > 0) {
                    out << " + ";
                }
                else if (p.coefficients[i-1] < 0) {
                    out << " - ";
                }
            }
        }
    }
    return out;
}

std::istream &operator >>(std::istream &in, Polynomial &p) {
    int degree;
    in >> degree;
    p.setDegree(degree);
    for (int i = degree; i >= 0; i--) {
        double coefficient;
        in >> coefficient;
        p.setCoefficient(i, coefficient);
    }
    return in;
}

#endif // POLYNOMIAL_CPP