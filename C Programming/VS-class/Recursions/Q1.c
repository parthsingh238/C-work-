#include <stdio.h>

// Function declaration
unsigned long long factorial(unsigned int n);

int main() {
    unsigned int n;

    // Prompt user for input
    printf("Enter any number: ");
    scanf("%u", &n);

    // Display result
    printf("Factorial of %u is %llu\n", n, factorial(n));

    return 0;
}

// Function definition
unsigned long long factorial(unsigned int n) {
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}