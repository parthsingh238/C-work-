    #include <stdio.h>

    int main() {
    int day;

    printf("Enter a number (1-7) to represent a day of the week: ");
    scanf("%d", &day);


    switch (day) {
        case 1:
            printf("It's Monday.\n");
            break; 
        case 2:
            printf("It's Tuesday.\n");
            break;
        case 3:
            printf("It's Wednesday.\n");
            break;
        case 4:
            printf("It's Thursday.\n");
            break;
        case 5:
            printf("It's Friday.\n");
            break;
        case 6:
            printf("It's Saturday.\n");
            break;
        case 7:
            printf("It's Sunday.\n");
            break;
        default: 
            printf("Invalid input. Please enter a number between 1 and 7.\n");
            break;
    }

    return 0;
}

