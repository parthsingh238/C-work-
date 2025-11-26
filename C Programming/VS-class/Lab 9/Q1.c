#include <stdio.h>

int main() {
    FILE *fp;
    char text[200];

    fp = fopen("newfile.txt", "w");  // create file

    if (fp == NULL) {
        printf("Error! Cannot create file.\n");
        return 1;
    }

    printf("Enter text to write into the file:\n");
    fgets(text, sizeof(text), stdin);

    fputs(text, fp);
    fclose(fp);

    printf("File created and text written successfully.\n");

    return 0;
}