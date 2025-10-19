#include <stdio.h>
#include <stdlib.h>

double* input_vector(int n) {
    double* vect = (double*)calloc(n, sizeof(double));
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        scanf("%lf", &vect[i]);
    }
    return vect;
}

void delete_vector(double* vect) {
    free(vect);
}

void print_vector(const double* vect, int n) {
    printf("(");
    for (int i = 0; i < n; i++) {
        printf("%.2lf", vect[i]);
        if (i < n - 1) printf(", ");
    }
    printf(")\n");
}

int subtract_vector(const double* vect_1, const double* vect_2, double* result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = vect_1[i] - vect_2[i];
    }
    return 0;
}

int main() {
    int n1, n2;
    printf("Enter dimensions of two vectors: ");
    scanf("%d %d", &n1, &n2);

    double* v1 = input_vector(n1);
    double* v2 = input_vector(n2);

    printf("Vector 1: ");
    print_vector(v1, n1);
    printf("Vector 2: ");
    print_vector(v2, n2);

    if (n1 == n2) {
        double* v3 = (double*)malloc(n1 * sizeof(double));
        subtract_vector(v1, v2, v3, n1);
        printf("Difference: ");
        print_vector(v3, n1);
        free(v3);
    } else {
        printf("Cannot subtract vectors of different dimensions.\n");
    }

    delete_vector(v1);
    delete_vector(v2);

    return 0;
}
