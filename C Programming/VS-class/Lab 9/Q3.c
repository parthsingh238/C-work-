#include <stdio.h>

int main() {
    FILE *fp;
    char line[200];

    fp = fopen("newfile.txt", "r");  // open file to read
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    printf("File content (line by line):\n");

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);  // print each line
    }

    fclose(fp);

    return 0;
}