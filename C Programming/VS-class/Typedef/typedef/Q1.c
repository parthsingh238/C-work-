#include <stdio.h>

typedef struct student {
    char name[20];
    int age;
} stud;

int main() {
    stud s1;
    printf("Enter the details of student s1:\n");
    printf("Enter the name of the student: ");
    scanf("%s", &s1.name);

    printf("Enter the age of the student: ");
    scanf("%d", &s1.age);

    printf("\nName of the student is: %s", s1.name);
    printf("\nAge of the student is: %d", s1.age);
  return 0;
}