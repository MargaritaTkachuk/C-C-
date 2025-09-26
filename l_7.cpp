#include <stdio.h>
#include <math.h>

int main() {

    double x, frac_part;
    int int_part, r2;
    printf("enter x = ");
    scanf("%lf", &x);
    int_part = (int)x;
    frac_part = x - int_part;
    int ceil_val = (int)ceil(x);
    int floor_val = (int)floor(x);
    int round_val = (int)round(x);
    printf("1 part = %d, 2 part = %lf\n", int_part, frac_part);
    printf("ceil = %d, round = %d, floor = %d\n", ceil_val, round_val, floor_val);

}