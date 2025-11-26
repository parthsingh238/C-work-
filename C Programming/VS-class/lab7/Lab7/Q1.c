#include <stdio.h>
#include <string.h>

// Function to reverse a string in place
void REVERSE(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    char temp;
    while (left < right) {
        // Swap characters
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    REVERSE(str);

    printf("Reversed string: %s\n", str);
    return 0;
}