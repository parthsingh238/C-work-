#include <stdio.h>
#include <string.h>  

struct myStructure {
    int myNum;
    char myLetter;
    char myString[30];
};

int main() {
    struct myStructure s1 = {13, 'A', "hello"};

    s1.myNum = 45;
    s1.myLetter = 'C';
    strcpy(s1.myString, "Bye");

    printf("%d %c %s", s1.myNum, s1.myLetter, s1.myString);

    return 0;
}
