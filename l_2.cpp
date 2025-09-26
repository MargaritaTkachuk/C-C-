#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main() {

    float x1 = 1e-4f, x2 = 24.33e5f, x3 = (float)M_PI, x4 = (float)M_E, x5 = sqrtf(5.0f), x6 = logf(100.0f);

    double y1 = 1e-4, y2 = 24.33e5, y3 = M_PI, y4 = M_E, y5 = sqrt(5.0), y6 = log(100.0);

    long double z1 = 1e-4L, z2 = 24.33e5L, z3 = M_PI, z4 = M_E, z5 = sqrtl(5.0L), z6 = logl(100.0L);

    printf("float: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", x1, x2, x3, x4, x5, x6);
    printf("double: %.2lf, %.2lf, %.2lf, %.2lf, %.2lf, %.2lf\n", y1, y2, y3, y4, y5, y6);
    printf("long double: %.2Lf, %.2Lf, %.2Lf, %.2Lf, %.2Lf, %.2Lf\n", z1, z2, z3, z4, z5, z6);

}