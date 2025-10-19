#include <stdio.h>
#include <stdlib.h>

double** create_matrix_2d(int n) {
    double** mat = (double**)calloc(n, sizeof(double*));
    for (int i = 0; i < n; i++)
        mat[i] = (double*)calloc(n, sizeof(double));
    return mat;
}

void delete_matrix_2d(double** mat, int n) {
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

void input_matrix_2d(double** mat, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("mat[%d][%d] = ", i+1, j+1);
            scanf("%lf", &mat[i][j]);
        }
}

void print_matrix_2d(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%.2lf ", mat[i][j]);
        printf("\n");
    }
}

double** multiply_matrix_2d(double** A, double** B, int n) {
    double** C = create_matrix_2d(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Лінійний масив
double* create_matrix_lin(int n) {
    return (double*)calloc(n*n, sizeof(double));
}

void delete_matrix_lin(double* mat) {
    free(mat);
}

void input_matrix_lin(double* mat, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("mat[%d][%d] = ", i+1, j+1);
            scanf("%lf", &mat[i*n + j]);
        }
}

void print_matrix_lin(double* mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%.2lf ", mat[i*n + j]);
        printf("\n");
    }
}

double* multiply_matrix_lin(double* A, double* B, int n) {
    double* C = create_matrix_lin(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i*n + j] += A[i*n + k] * B[k*n + j];
    return C;
}

int main() {
    int n, choice;
    printf("Enter size n of square matrices: ");
    scanf("%d", &n);

    printf("Choose representation (1 = 2D array, 2 = linear array): ");
    scanf("%d", &choice);

    if (choice == 1) {
        double** A = create_matrix_2d(n);
        double** B = create_matrix_2d(n);

        printf("Enter matrix A:\n");
        input_matrix_2d(A, n);
        printf("Enter matrix B:\n");
        input_matrix_2d(B, n);

        double** C = multiply_matrix_2d(A, B, n);

        printf("\nProduct matrix C:\n");
        print_matrix_2d(C, n);

        delete_matrix_2d(A, n);
        delete_matrix_2d(B, n);
        delete_matrix_2d(C, n);
    } else if (choice == 2) {
        double* A = create_matrix_lin(n);
        double* B = create_matrix_lin(n);

        printf("Enter matrix A:\n");
        input_matrix_lin(A, n);
        printf("Enter matrix B:\n");
        input_matrix_lin(B, n);

        double* C = multiply_matrix_lin(A, B, n);

        printf("\nProduct matrix C:\n");
        print_matrix_lin(C, n);

        delete_matrix_lin(A);
        delete_matrix_lin(B);
        delete_matrix_lin(C);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
