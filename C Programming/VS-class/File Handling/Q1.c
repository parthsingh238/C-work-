//Create a new file and write text into it.
#include <stdio.h>

int main() {
    FILE *fp;
    char text[200];

    fp = fopen("newfile.txt", "w"); // open file in write mode
     if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter text to write into the file:\n");
    fgets(text, sizeof(text), stdin);

    fprintf(fp, "%s", text); // write text to file
    fclose(fp);

    printf("File created and text written successfully!\n");
    return 0;
}