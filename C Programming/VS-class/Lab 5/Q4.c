//with else
#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num % 2 == 0)
        printf("NUMBER IS EVEN\n");
    else
        printf("NUMBER IS ODD\n");

    return 0;
}
//without else
#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num % 2 == 0)
        printf("NUMBER IS EVEN\n");

    if(num % 2 == 1)
        printf("NUMBER IS ODD\n");

    return 0;
}