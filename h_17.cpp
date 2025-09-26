#include <stdio.h>

int main() {

    long double x, x_2, x_4, x_8;
    printf("enter a number: ");
    scanf("%Lf", &x);
    x_2 = x * x; /* 1 */
    x_4 = x_2 * x_2; /* 2 done*/
    x_8 = x_4 * x_4; /* 3 */
    printf("x^8 = %025.4Lf\n", x_8);

}