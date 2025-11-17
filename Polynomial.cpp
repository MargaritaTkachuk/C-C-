#include "Polynomial.h"

Polynomial::Polynomial(int n) : n(n) {
    a = new double[n];
}

Polynomial::Polynomial(const Polynomial& other) : n(other.n) {
    a = new double[n];
    for (int i = 0; i < n; i++) a[i] = other.a[i];
}

Polynomial::~Polynomial() {
    delete[] a;
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this == &other) return *this;
    delete[] a;
    n = other.n;
    a = new double[n];
    for (int i = 0; i < n; i++) a[i] = other.a[i];
    return *this;
}

void Polynomial::fill(const double* arr) {
    for (int i = 0; i < n; i++) a[i] = arr[i];
}

void Polynomial::set(int index, double value) {
    if (index >= 0 && index < n) a[index] = value;
}

void Polynomial::print() const {
    for (int i = n - 1; i >= 0; i--) {
        std::cout << a[i];
        if (i > 1) std::cout << "x^" << i;
        else if (i == 1) std::cout << "x";

        if (i > 0) std::cout << " + ";
    }
    std::cout << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    for (int i = 0; i < p.n; i++) os << p.a[i] << " ";
    return os;
}

std::istream& operator>>(std::istream& is, Polynomial& p) {
    for (int i = 0; i < p.n; i++) is >> p.a[i];
    return is;
}

void writeBinary(std::ofstream& out, const Polynomial& p) {
    out.write((char*)&p.n, sizeof(int));
    out.write((char*)p.a, sizeof(double) * p.n);
}

void readBinary(std::ifstream& in, Polynomial& p) {
    int newN;
    in.read((char*)&newN, sizeof(int));
    delete[] p.a;
    p.n = newN;
    p.a = new double[p.n];
    in.read((char*)p.a, sizeof(double) * p.n);
}
