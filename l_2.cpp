#include <stdio.h>

int main() {
    int arr[4] = {5, 112, 4, 3};
    int n = 4;

    printf("Масив у зворотному порядку: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0) printf(", ");
    }

    printf("\n");
    return 0;
}
