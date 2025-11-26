#include<stdio.h>
void main()
{
    int i = 5, *j;
    j = &i;

    printf("%d\n", &i);     // address of i
    printf("%d\n", j);      // value stored in j (address of i)
    printf("%d\n", &j);     // address of pointer j
    printf("%d\n", j);      // again address stored in j
    printf("%d\n", i);      // value of i
    printf("%d\n", *(&i));  // value of i (5)
    printf("Value of i=%d\n", *j);  // value using pointer
}