#include<stdio.h>
void main()
{
    int i = 10, *j, **k;

    j = &i;
    k = &j;

    printf("%d\n", &i);   // address of i
    printf("%d\n", j);    // value in j (address of i)
    printf("%d\n", *k);   // value at k → j → address of i
    printf("%d\n", &j);   // address of j
    printf("%d\n", k);    // value in k (address of j)
    printf("%d\n", &k);   // address of k
    printf("%d\n", i);    // value of i
    printf("%d\n", *j);   // value at j → i → 10
    printf("%d\n", **k);  // value at k → j → i → 10
}