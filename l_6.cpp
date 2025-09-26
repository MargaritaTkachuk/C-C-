#include <stdio.h>
#include <math.h>

double line(double x_1, double x_2, double y_1, double y_2) {
    return sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));
}

double s(double a, double b, double c){
    double p;
    p = (a + b + c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {
    double x1, y1, x2, y2, x3, y3, AB, BC, AC, S;
    printf("enter x y A: ");
    scanf("%lf %lf", &x1, &y1);
    printf("enter x y B: ");
    scanf("%lf %lf", &x2, &y2);
    printf("enter x y C: ");
    scanf("%lf %lf", &x3, &y3);
    AB = line(x1, x2, y1, y2);
    BC = line(x2, x3, y2, y3);
    AC = line(x3, x1, y3, y1);
    S = s(AB, BC, AC);
    printf("S = %lf\n", S);

}