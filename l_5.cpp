#include <stdio.h>

int main() {

    double x, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10, x_12, x_14, x_15, x_16, x_28, x_32, x_64;
    printf("Enter x: ");
    scanf("%lf", &x);
    x_2 = x * x; /* 1 */
    x_3 = x_2 * x; /* 2 */
    x_4 = x_2 * x_2; /* 2 done*/
    x_5 = x_4 * x; /* 3 */
    x_6 = x_3 * x_3; /* 3 done*/
    x_7 = x_6 * x; /* 4 */
    x_8 = x_4 * x_4; /* 3 */
    x_9 = x_8 * x; /* 4 done*/
    x_10 = x_5 * x_5; /* 4 */
    x_12 = x_6 * x_6; /* 4 */
    x_14 = x_7 * x_7; /* 5 */
    x_15 = x_5 * x_5 * x_5; /* 5 done*/
    x_16 = x_8 * x_8; /* 4 */
    x_28 = x_14 * x_14; /* 6 done*/
    x_32 = x_16 * x_16; /* 5 */
    x_64 = x_32 * x_32; /* 6 done*/
    printf("x_4 = %lf\nx_6 = %lf\nx_9 = %lf\nx_15 = %lf\nx_28 = %lf\nx_64 = %lf\n", x_4, x_6, x_9, x_15, x_28, x_64);

}