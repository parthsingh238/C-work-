#include <stdio.h>

int main() 
{
    int n1, n2, s;
    n1 = 5;
    n2 = 6;
    s = n1 + n2;
    printf("sum is = %d\n", s);

    int n3, n4, s2;
    printf("Enter n3: ");
    scanf("%d", &n3);
    printf("Enter n4: ");
    scanf("%d", &n4);

    s2 = n3 + n4;
    printf("sum is = %d\n", s2);

    return 0;
}
