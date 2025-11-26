#include <stdio.h>

// Function declaration
unsigned long long fibonacci(int n);

int main() {
    int i, n;

    // Prompt user for input
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Print Fibonacci series
    printf("Fibonacci series up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%llu\t", fibonacci(i));
    }

    printf("\n");
    return 0;
}

// Function definition (Iterative and fast)
unsigned long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}