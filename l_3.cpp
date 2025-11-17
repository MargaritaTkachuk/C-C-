#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


bool isEven(int n) {
    return n % 2 == 0;
}


bool isPowerOf3(int n) {
    if (n < 1) return false;
    while (n % 3 == 0) n /= 3;
    return n == 1;
}


bool isPerfectSquare(int n) {
    if (n < 0) return false;
    int r = (int)sqrt(n);
    return r * r == n;
}


bool isThreeDivisors(int n) {
    if (n < 4) return false;
    if (!isPerfectSquare(n)) return false;
    int r = (int)sqrt(n);
    // перевіряємо, чи r — просте
    if (r < 2) return false;
    for (int i = 2; i * i <= r; i++) {
        if (r % i == 0) return false;
    }
    return true;
}


bool isPalindrome(int n) {
    if (n < 0) return false;
    int orig = n, rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return orig == rev;
}


bool isFibonacci(int n) {
    if (n < 0) return false;
    long long x1 = 5LL * n * n + 4;
    long long x2 = 5LL * n * n - 4;
    long long r1 = (long long)sqrt(x1);
    long long r2 = (long long)sqrt(x2);
    return r1 * r1 == x1 || r2 * r2 == x2;
}


void writeConditionFile(const char *source, const char *dest, bool (*condition)(int)) {
    FILE *fIn = fopen(source, "r");
    FILE *fOut = fopen(dest, "w");
    if (!fIn || !fOut) {
        printf("Помилка відкриття файлу!\n");
        if (fIn) fclose(fIn);
        if (fOut) fclose(fOut);
        return;
    }

    int num;
    while (fscanf(fIn, "%d", &num) == 1) {
        if (condition(num)) {
            fprintf(fOut, "%d ", num);
        }
    }

    fclose(fIn);
    fclose(fOut);
}


void printFile(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Не вдалося відкрити %s\n", filename);
        return;
    }
    printf("%s: ", filename);
    int num;
    int first = 1;
    while (fscanf(f, "%d", &num) == 1) {
        if (!first) printf(", ");
        printf("%d", num);
        first = 0;
    }
    printf("\n");
    fclose(f);
}

int main() {
    const char *fileF = "F.txt";
    FILE *f = fopen(fileF, "w");
    if (!f) {
        printf("Помилка створення файлу F!\n");
        return 1;
    }

    printf("Вводьте цілі числа (0 — кінець вводу):\n");
    while (1) {
        int x;
        scanf("%d", &x);
        if (x == 0) break;
        fprintf(f, "%d ", x);
    }
    fclose(f);


    writeConditionFile(fileF, "G1_parni.txt", isEven);
    writeConditionFile(fileF, "G2_stepin3.txt", isPowerOf3);
    writeConditionFile(fileF, "G3_kvadraty.txt", isPerfectSquare);
    writeConditionFile(fileF, "G4_3dilnyky.txt", isThreeDivisors);
    writeConditionFile(fileF, "G5_palindromy.txt", isPalindrome);
    writeConditionFile(fileF, "G6_fibonacci.txt", isFibonacci);


    printf("\nФайл F (всі числа):\n");
    printFile(fileF);
    printf("\nРезультати:\n");
    printFile("G1_parni.txt");
    printFile("G2_stepin3.txt");
    printFile("G3_kvadraty.txt");
    printFile("G4_3dilnyky.txt");
    printFile("G5_palindromy.txt");
    printFile("G6_fibonacci.txt");

    return 0;
}
