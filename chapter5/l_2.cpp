#include <stdio.h>

unsigned long long fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    unsigned long long F0 = 0, F1 = 1, F;
    for (int i = 2; i <= n; i++) {
        F = F0 + F1;
        F0 = F1;
        F1 = F;
    }
    return F;
}

int max_fib_le_a(unsigned long long a) {
    int n = 0;
    while (fib(n) <= a) {
        n++;
    }
    return n - 1;
}

int first_fib_gt_a(unsigned long long a) {
    int n = 0;
    while (fib(n) <= a) {
        n++;
    }
    return n;
}

unsigned long long sum_fib_1000() {
    unsigned long long sum = 0;
    int n = 0;
    while (fib(n) <= 1000) {
        sum += fib(n);
        n++;
    }
    return sum;
}

int main() {
    int n;
    unsigned long long a;

    printf("Enter n for F(n): ");
    scanf("%d", &n);
    printf("a) F(%d) = %llu\n", n, fib(n));

    printf("Enter a: ");
    scanf("%llu", &a);
    printf("b) Max Fibonacci <= %llu is F(%d) = %llu\n", a, max_fib_le_a(a), fib(max_fib_le_a(a)));
    printf("c) First Fibonacci > %llu is F(%d) = %llu\n", a, first_fib_gt_a(a), fib(first_fib_gt_a(a)));

    printf("d) Sum of Fibonacci numbers <= 1000: %llu\n", sum_fib_1000());

    return 0;
}
