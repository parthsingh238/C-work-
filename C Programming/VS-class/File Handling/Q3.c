//Open a file, read its content line by line, and display each line on the console
#include <stdio.h>

int main() {
    FILE *fp;
    char line[200];

    fp = fopen("newfile.txt", "r"); // open file in read mode
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    printf("File content (line by line):\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line); // print each line
    }

    fclose(fp);
    return 0;
}