#include <stdio.h>
#include <math.h>
#include "main.h"

int FindN(double x, double e) {
    double left = sin(x), right = 0, a = x, b = 1;
    int n = 0;
    while (fabs(left - right) >= e) {
        if (n % 2 == 0) {
            right += a / b;
        } else {
            right -= a / b;
        }
        n++;
        a *= x * x;
        b *= 2 * n * (2 * n + 1);
    }
    return n;
}

int main() {
    double x, e;
    printf("Enter your angel x (x > 0):\n");
    while (scanf("%lf", &x) != 1 || x <= 0) {
        printf("Error, enter again\n");
        while (getchar() != '\n') {}
    }
    printf("Enter your e (e > 0):\n");
    while (scanf("%lf", &e) != 1 || e <= 0) {
        printf("Error, enter again\n");
        while (getchar() != '\n') {}
    }
    printf("N = %d\n", FindN(x, e));
    system("pause");
    return 0;
}