#include <stdio.h>
#include <float.h>

int main() {
    float a = 1.0f;
    while (1.0f + a != 1.0f) {
        a /= 2.0f;
    }
    printf("mach_float = %.10e\n", a * 2.0f);
    printf("FLT_EPSILON = %.10e\n", FLT_EPSILON);
}
