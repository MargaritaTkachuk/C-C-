#include <stdio.h>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();

int main() {
    int task_index;
    printf("task index: ");
    scanf("%d", &task_index);

    if (task_index == 1) {
        task1();
    }
    else if (task_index == 2) {
        task2();
    }
    else if (task_index == 3) {
        task3();
    }
    else if (task_index == 4) {
        task4();
    }
    else if (task_index == 5) {
        task5();
    }
    else if (task_index == 6) {
        task6();
    }
    else if (task_index == 7) {
        task7();
    }
    else {
        printf("incorrect task index\n");
    }
}

void task1() {
    unsigned char n;
    printf("n = ");
    scanf("%hhu", &n);
    if (n < 64) {
        unsigned long long m = 1 << n;
        printf("%llx", m);
    }


}

void task2() {
    int k;
    unsigned n , m;
    printf("k = ");
    scanf("%d", &k);
    printf("n = ");
    scanf("%u", &n);

    m = n | (1 << k);
    printf("m = %u\n", m);
}

void task3() {
    int k;
    unsigned long long n , m;
    printf("k = ");
    scanf("%d", &k);
    printf("n = ");
    scanf("%u", &n);

    m = n & ~(1ULL << k);
    printf("m = %llu, %llx\n", m, m);
}

void task4() {
    unsigned n;
    printf("n = ");
    scanf("%u", &n);

    unsigned first8 = (n >> 24) & 0xFF;
    unsigned last8  = n & 0xFF;
    unsigned middle = n & 0x00FFFF00;
    unsigned m = (last8 << 24) | middle | first8;

    printf("m = %u, %x\n", m, m);
}

void task5() {
    unsigned n;
    printf("n = ");
    scanf("%u", &n);

    int max_count = 0, current_count = 0;

    while (n > 0) {
        if (n & 1) {
            current_count++;
            if (current_count > max_count)
                max_count = current_count;
        } else {
            current_count = 0;
        }
        n >>= 1;
    }

    printf("max 1: %d\n", max_count);
}

void task6() {
    unsigned int x;

    printf("x   | ((x&(x-1))>0) | x&(-x) | bool\n");
    printf("------------------------------------------------------\n");

    for (x = 1; x <= 16; x++) {
        unsigned int expr1 = ((x & (x - 1)) > 0);
        unsigned int expr2 = x & (-x);

        printf("%2u  |       %u       |  %3u   | ", x, expr1, expr2);

        for (int i = 7; i >= 0; i--) {
            unsigned int bit = (x >> i) & 1;
            unsigned int mark_bit = (expr2 >> i) & 1;
            if (mark_bit)
                printf("[%u]", bit);
            else
                printf(" %u ", bit);
        }

        printf("\n");
    }

}

void task7() {
    unsigned int x = 0x11223344;
    unsigned char *p = (unsigned char *)&x;

    printf("Порядок байтів у пам’яті: ");
    for (int i = 0; i < sizeof(x); i++)
        printf("%02X ", p[i]);
    printf("\n");

    if (p[0] == 0x11 && p[1] == 0x22 && p[2] == 0x33 && p[3] == 0x44)
        printf("Архітектура: Big-endian\n");
    else if (p[0] == 0x44 && p[1] == 0x33 && p[2] == 0x22 && p[3] == 0x11)
        printf("Архітектура: Little-endian\n");
    else
        printf("Архітектура: Middle-endian\n");
}
