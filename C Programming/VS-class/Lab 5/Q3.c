#include <stdio.h>

int main() {
    int x, y, z, largest;

    printf("Enter three values: ");
    scanf("%d %d %d", &x, &y, &z);

    largest = x*((x>y)&&(x>z)) + y*((y>x)&&(y>z)) + z*((z>x)&&(z>y));

    printf("Largest = %d\n", largest);

    return 0;
}