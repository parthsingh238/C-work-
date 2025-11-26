#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("newfile.txt", "r");  // open existing file
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    printf("File content (character by character):\n");

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}