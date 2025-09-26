#include <stdio.h>
#include <math.h>

int main() {

    double x, y;
    printf("enter x: ");
    scanf("%lf", &x);
    y = cos(x);
    printf("cos(x) = %lf\n", y);

}