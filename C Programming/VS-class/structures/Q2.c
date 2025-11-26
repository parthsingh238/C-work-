#include<stdio.h>
struct myStructure{
    int myNum;
    char myLetter;
};
int main(){
    struct myStructure s1;
    struct myStructure s2;

    s1.myNum = 10;
    s1.myLetter = 'C';
    s2.myNum = 20;
    s2.myLetter = 'D';

    printf("s1 number: %d\n", s1.myNum);
    printf("s1 Letter: %c\n", s1.myLetter);

    printf("s2 number: %d\n", s2.myNum);
    printf("s2 Letter: %c\n", s2.myLetter);
    return 0;
}