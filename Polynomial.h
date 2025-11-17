#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <fstream>

class Polynomial {
    int n;
    double* a;

public:
    Polynomial(int n);
    Polynomial(const Polynomial& other);
    ~Polynomial();

    void fill(const double* arr);
    void set(int index, double value);
    void print() const;

    Polynomial& operator=(const Polynomial& other);

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
    friend std::istream& operator>>(std::istream& is, Polynomial& p);

    friend void writeBinary(std::ofstream& out, const Polynomial& p);
    friend void readBinary(std::ifstream& in, Polynomial& p);
};

#endif
