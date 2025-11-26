
#include <stdio.h>

int sum();   // function declaration

int main()
{
    int s = sum();       // function call
    printf("sum = %d\n", s); 
    return 0;
}

int sum()    // function definition
{
    int a, b, c;
    printf("Enter values of a and b:\n");
    scanf("%d %d", &a, &b);
    c = a + b;
    return c;
}