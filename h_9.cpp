#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double** create_matrix(int N, int M) {
    double** mat = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++)
        mat[i] = (double*)malloc(M * sizeof(double));
    return mat;
}

void delete_matrix(double** mat, int N) {
    for (int i = 0; i < N; i++)
        free(mat[i]);
    free(mat);
}

void print_matrix(double** mat, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%.2lf ", mat[i][j]);
        printf("\n");
    }
}

void fill_matrix_console(double** mat, int N, int M) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            printf("mat[%d][%d] = ", i+1, j+1);
            scanf("%lf", &mat[i][j]);
        }
}

void fill_matrix_random(double** mat, int N, int M) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            mat[i][j] = ((double)rand() / RAND_MAX) * 100.0; // випадкові числа 0..100
}

void remove_row_col(double*** mat_ptr, int* N, int* M) {
    double** mat = *mat_ptr;
    if (*N == 0 || *M == 0) return;

    int max_i = 0, max_j = 0;
    double max_val = mat[0][0];

    for (int i = 0; i < *N; i++)
        for (int j = 0; j < *M; j++)
            if (mat[i][j] > max_val) {
                max_val = mat[i][j];
                max_i = i;
                max_j = j;
            }

    // Створюємо нову матрицю розміром (N-1) x (M-1)
    double** new_mat = create_matrix(*N - 1, *M - 1);
    int ni = 0;
    for (int i = 0; i < *N; i++) {
        if (i == max_i) continue;
        int nj = 0;
        for (int j = 0; j < *M; j++) {
            if (j == max_j) continue;
            new_mat[ni][nj] = mat[i][j];
            nj++;
        }
        ni++;
    }

    delete_matrix(mat, *N);
    *mat_ptr = new_mat;
    (*N)--;
    (*M)--;
}

int main() {
    srand((unsigned int)time(NULL));

    int N, M, choice;
    printf("Enter number of rows N: ");
    scanf("%d", &N);
    printf("Enter number of columns M: ");
    scanf("%d", &M);

    double** mat = create_matrix(N, M);

    printf("Fill matrix (1 = console, 2 = random): ");
    scanf("%d", &choice);

    if (choice == 1)
        fill_matrix_console(mat, N, M);
    else
        fill_matrix_random(mat, N, M);

    printf("\nOriginal matrix:\n");
    print_matrix(mat, N, M);

    remove_row_col(&mat, &N, &M);

    printf("\nMatrix after removing row and column of max element:\n");
    print_matrix(mat, N, M);

    delete_matrix(mat, N);

    return 0;
}
