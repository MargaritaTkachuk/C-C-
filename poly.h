#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct {
    int degree;
    double *coef;
} Polynomial;

void inputPolynomial(Polynomial *p);
void printPolynomial(Polynomial p);

#endif
