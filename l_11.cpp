#include <stdio.h>
#include <math.h>

int main() {
    double n, sum = 0.0, prod = 1.0;
    unsigned k = 0;
    while (n != 0.0) {
        printf("a[%u] = ", k);
        scanf("%lf", &n);
        sum += n;
        if (n != 0.0) {
            prod *= n;
            k++;
        }

    }
    printf("sum = %lf\n", sum);
    printf("arith = %lf\n", sum/(double)k);
    printf("geo = %lf\n", pow(prod, 1.0/(double)k));

}