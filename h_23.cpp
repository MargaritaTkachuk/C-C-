#include <stdio.h>
#include <math.h>

int main() {
    unsigned n;
    printf("n = ");
    scanf("%u", &n);

    double y, z;
    printf("y1 = ");
    scanf("%lf", &y);

    if(fabs(y) >= 1.0) {
        z = y;
    } else {
        z = 2.0;
    }

    double min_abs = fabs(z);

    for(unsigned i = 2; i <= n; i++) {
        printf("y%u = ", i);
        scanf("%lf", &y);

        if(fabs(y) >= 1.0) {
            z = y;
        } else {
            z = 2.0;
        }

        if(fabs(z) < min_abs) {
            min_abs = fabs(z);
        }
    }

    printf("min(|z_i|) = %lf\n", min_abs);

}
