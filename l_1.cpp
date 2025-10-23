#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#include "chess.h"
#include "rect.h"
#include "poly.h"

void inputDate(Date *d) {
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

void printDate(Date d) {
    printf("%02d.%02d.%04d\n", d.day, d.month, d.year);
}


void inputChessField(ChessField *f) {
    scanf(" %c%d", &f->column, &f->row);
}

void printChessField(ChessField f) {
    printf("%c%d\n", f.column, f.row);
}

void inputPoint(Point *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

void printPoint(Point p) {
    printf("(%.2lf, %.2lf)", p.x, p.y);
}

void inputRectangle(Rectangle *r) {
    inputPoint(&r->A);
    inputPoint(&r->B);
}

void printRectangle(Rectangle r) {
    printPoint(r.A);
    printf(" ");
    printPoint(r.B);
    printf("\n");
}

void inputPolynomial(Polynomial *p) {
    scanf("%d", &p->degree);
    p->coef = (double *)malloc((p->degree + 1) * sizeof(double));
    for (int i = 0; i <= p->degree; i++)
        scanf("%lf", &p->coef[i]);
}

void printPolynomial(Polynomial p) {
    for (int i = 0; i <= p.degree; i++) {
        printf("%.2lf", p.coef[i]);
        if (p.degree - i > 0)
            printf("x^%d", p.degree - i);
        if (i != p.degree)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    Date d;
    ChessField f;
    Rectangle r;
    Polynomial p;

    inputDate(&d);
    printDate(d);

    inputChessField(&f);
    printChessField(f);

    inputRectangle(&r);
    printRectangle(r);

    inputPolynomial(&p);
    printPolynomial(p);

    free(p.coef);

    return 0;
}
