#include <stdio.h>

int main() {
    char name[100][50];    
    float basic[100];      
    float da[100];         
    float gross[100];    

    int i;

    printf("Enter details for 100 employees:\n");

    for(i = 0; i < 100; i++) {
        printf("\nEnter name of employee %d: ", i + 1);
        scanf("%s", name[i]);

        printf("Enter basic pay of %s: ", name[i]);
        scanf("%f", &basic[i]);

        da[i] = 0.52 * basic[i];             
        gross[i] = basic[i] + da[i];         
    }

    printf("\n-----------------------------------------------------\n");
    printf("Employee Name\t\tGross Salary\n");
    printf("-----------------------------------------------------\n");

    for(i = 0; i < 100; i++) {
        printf("%-15s\t%.2f\n", name[i], gross[i]);
    }

    return 0;
}
