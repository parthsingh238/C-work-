//Open an existing file and read its content character by character, and then close the file.
#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("newfile.txt", "r"); // open file in read mode
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    printf("File content (character by character):\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch); // print each character
    }

    fclose(fp);
    return 0;
}