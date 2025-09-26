#include <stdio.h>

int main() {

    double m1, m2, r;
    const double G = 6.673e-11;
    double F;
    printf("Enter m1 m2 r: ");
    scanf("%lf %lf %lf", &m1, &m2, &r);
    /* printf("a = %lf, b = %lf, c = %lf\n", m1, m2, r); */
    F = G * m1 * m2 / (r * r);
    printf("%e\n", F);

}