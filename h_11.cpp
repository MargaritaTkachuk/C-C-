#include <stdio.h>
#include <math.h>

double V_xc(double r, double h) {
    return M_PI * pow(r, 2.0) * h;
}

int main() {
    double r, h;
    printf("enter R and H: ");
    scanf("%lf %lf", &r, &h);
    double V = V_xc(r, h);
    printf("V = %lf\n", V);

}