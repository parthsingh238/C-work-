#include <stdio.h>

int main() {
    FILE *fptr;

    // Open a file in read mode
    fptr = fopen("filename.txt", "r");

    // Buffer to store file content
    char myString[100];

    // Check if file exists
    if (fptr != NULL) {

        // Read and print file line by line
        while (fgets(myString, sizeof(myString), fptr)) {
            printf("%s", myString);
        }

    } else {
        // If file does not exist
        printf("Not able to open the file.\n");
    }

    // Close the file
    fclose(fptr);

    return 0;
}