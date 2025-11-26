#include<stdio.h>
struct myStructure{
    int myNum;
    char myLetter;
};

int main() {
    struct myStructure si;
    si.myNum = 13;
    si.myLetter = 'B';
    printf("Number: %d\n", si.myNum);
    printf("Letter: %c\n", si.myLetter);

    return 0;

}