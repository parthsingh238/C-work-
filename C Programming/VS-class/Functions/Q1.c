#include <stdio.h>

void sum();

int main()
{
    sum();
    return 0;
}

void sum()
{ 
    int a = 50, b = 80;
    int c = a + b; 
    printf("sum of %d and %d = %d", a, b, c);
}