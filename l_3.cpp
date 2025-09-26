#include <stdio.h>
#include <math.h>

double s(double a, double b, double c){
    double p;
    p = (a + b + c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {

    double a, b, c, sq;
    printf("enter a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    sq = s(a, b, c);
    printf("%lf\n", sq);

}