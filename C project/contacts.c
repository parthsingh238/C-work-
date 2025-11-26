// contact_manager.c
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define ESC 27
#define MAX_NAME_SZ 10
#define MAX_NUM_SZ 20
#define READ_ARRAY_SZ 15
#define DATA_FILE "dataFile.dat"
#define TEMP_FILE "tempFile.dat"

struct data {
    char fName[MAX_NAME_SZ];
    char lName[MAX_NAME_SZ];
    char mPhone[MAX_NUM_SZ];
    char wPhone[MAX_NUM_SZ];
    char hPhone[MAX_NUM_SZ];
};

static void gotoxy(int x, int y) {
    COORD coord;
    coord.X = (SHORT)x;
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* function prototypes */
int view(struct data *arr, int max);
void add_record(struct data c);
void update_record(struct data c, const char *pNum);
void delete_record(const char *pNum);
int searchByNum(const char *pNum);
void getString(char *buf, int size);

struct data readData();
void mainMenu();
void viewItems();
void addItems();
void updateItems();
void deleteItems();

/* main */
int main(void) {
    mainMenu();
    return 0;
}

/* Display user menu (loop-based, non-recursive) */
void mainMenu() {
    char choice;
    while (1) {
        system("cls");
        gotoxy(35,6);    printf("----Welcome to Contact Management System----");
        gotoxy(35,8);    printf("Please select an option: V, A, U, D, E (or press ESC)");
        gotoxy(35,10);   printf("V) View All Contacts");
        gotoxy(35,12);   printf("A) Add Contact");
        gotoxy(35,14);   printf("U) Update Contact");
        gotoxy(35,16);   printf("D) Delete Contact");
        gotoxy(35,18);   printf("E) Exit application");

        choice = (char) tolower((unsigned char)getch());

        switch(choice) {
            case 'v': viewItems(); break;
            case 'a': addItems(); break;
            case 'u': updateItems(); break;
            case 'd': deleteItems(); break;
            case 'e': exit(0);
            case ESC: exit(0);
            default:
                gotoxy(35,30);
                printf("Please enter one of: V, A, U, D, E or ESC");
                getch();
        }
    }
}

/* View up to READ_ARRAY_SZ contacts */
void viewItems() {
    struct data c[READ_ARRAY_SZ];
    int data_sz = view(c, READ_ARRAY_SZ);

    system("cls");
    gotoxy(35,6); printf("----Welcome to Contact Management System----");
    gotoxy(35,8); printf("View Contacts (showing up to %d): %d found", READ_ARRAY_SZ, data_sz);

    gotoxy(15,10); printf("First Name");
    gotoxy(35,10); printf("Last Name");
    gotoxy(55,10); printf("Mobile Number");
    gotoxy(70,10); printf("Work Number");
    gotoxy(85,10); printf("Home Number");

    for (int i = 0; i < data_sz; i++) {
        gotoxy(15,11 + i); printf("%s", c[i].fName);
        gotoxy(35,11 + i); printf("%s", c[i].lName);
        gotoxy(55,11 + i); printf("%s", c[i].mPhone);
        gotoxy(70,11 + i); printf("%s", c[i].wPhone);
        gotoxy(85,11 + i); printf("%s", c[i].hPhone);
    }

    gotoxy(35,27); printf("Press any key to go back.");
    getch();
}

/* Add contacts */
void addItems() {
    struct data c;
    system("cls");
    gotoxy(35,6); printf("----Welcome to Contact Management System----");
    gotoxy(35,8); printf("Add Contact - please enter details:");

    c = readData();

    int s = searchByNum(c.mPhone);
    if (s == 2) {
        gotoxy(35,16); printf("Mobile number is empty. Record can't be saved.");
    } else if (s == 1) {
        gotoxy(35,16); printf("Mobile number %s already exists. Use Update instead.", c.mPhone);
    } else {
        add_record(c);
        gotoxy(35,17); printf("Record successfully saved.");
    }

    gotoxy(35,27); printf("Press any key to continue.");
    getch();
}

/* Update contact details */
void updateItems() {
    char pNum[MAX_NUM_SZ];
    struct data c;
    system("cls");
    gotoxy(35,6); printf("----Welcome to Contact Management System----");
    gotoxy(35,7); printf("Enter Mobile Phone to update:");
    gotoxy(35,9); getString(pNum, sizeof(pNum));

    int s = searchByNum(pNum);
    if (s == 1) {
        gotoxy(35,10); printf("Mobile number %s found. Enter new details:", pNum);
        c = readData();
        update_record(c, pNum);
        gotoxy(35,13); printf("Record updated.");
    } else if (s == 2) {
        gotoxy(35,11); printf("Empty input. Update aborted.");
    } else {
        gotoxy(35,11); printf("Mobile number %s does not exist.", pNum);
    }

    gotoxy(35,27); printf("Press any key to continue.");
    getch();
}

/* Delete contact */
void deleteItems() {
    char pNum[MAX_NUM_SZ];
    char choice;
    system("cls");
    gotoxy(35,6); printf("----Welcome to Contact Management System----");
    gotoxy(35,7); printf("Enter Mobile Phone to delete:");
    gotoxy(35,9); getString(pNum, sizeof(pNum));

    int s = searchByNum(pNum);
    if (s == 1) {
        gotoxy(35,12); printf("Mobile number %s exists. Delete it? (y/N)", pNum);
        choice = (char) tolower((unsigned char)getch());
        if (choice == 'y') {
            delete_record(pNum);
            gotoxy(35,16); printf("Phone number successfully deleted.");
        } else {
            gotoxy(35,16); printf("Delete cancelled.");
        }
    } else if (s == 2) {
        gotoxy(35,12); printf("Empty input. Delete aborted.");
    } else {
        gotoxy(35,12); printf("Mobile number %s does not exist.", pNum);
    }

    gotoxy(35,27); printf("Press any key to continue.");
    getch();
}

/* Read a contact from console */
struct data readData() {
    struct data c;
    memset(&c, 0, sizeof(c));

    gotoxy(35,11); printf("Enter first name: ");
    getString(c.fName, sizeof(c.fName));

    gotoxy(35,12); printf("Enter last name: ");
    getString(c.lName, sizeof(c.lName));

    /* Simple mobile validation: not empty and length reasonable */
    do {
        gotoxy(35,13); printf("Enter mobile phone: ");
        getString(c.mPhone, sizeof(c.mPhone));
        if (strlen(c.mPhone) == 0) {
            gotoxy(35,15); printf("Mobile cannot be empty. Try again.");
        } else if (strlen(c.mPhone) >= MAX_NUM_SZ) {
            gotoxy(35,15); printf("Mobile too long. Max %d chars.", MAX_NUM_SZ - 1);
        } else {
            break;
        }
    } while (1);

    gotoxy(35,14); printf("Enter work phone: ");
    getString(c.wPhone, sizeof(c.wPhone));

    gotoxy(35,15); printf("Enter home phone: ");
    getString(c.hPhone, sizeof(c.hPhone));

    return c;
}

/* File operations */

/* View: Read up to max records from file */
int view(struct data *arr, int max) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) return 0;
    int count = 0;
    while (count < max && fread(&arr[count], sizeof(struct data), 1, fp) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}

/* Add: Append a new record to file */
void add_record(struct data c) {
    FILE *fp = fopen(DATA_FILE, "ab");
    if (!fp) {
        gotoxy(35,19); printf("Error: Unable to open data file for writing.");
        return;
    }
    if (fwrite(&c, sizeof(struct data), 1, fp) != 1) {
        gotoxy(35,19); printf("Error: Failed to write record.");
    }
    fclose(fp);
}

/* Update: Replace matching pNum with new record */
void update_record(struct data c, const char *pNum) {
    FILE *fp = fopen(DATA_FILE, "rb");
    FILE *temp = fopen(TEMP_FILE, "wb");
    if (!fp || !temp) {
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        gotoxy(35,19); printf("Error opening files for update.");
        return;
    }
    struct data tempData;
    int replaced = 0;
    while (fread(&tempData, sizeof(struct data), 1, fp) == 1) {
        if (strcmp(tempData.mPhone, pNum) == 0) {
            fwrite(&c, sizeof(struct data), 1, temp);
            replaced = 1;
        } else {
            fwrite(&tempData, sizeof(struct data), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);

    if (remove(DATA_FILE) != 0) {
        gotoxy(35,19); printf("Warning: could not remove original file.");
    }
    if (rename(TEMP_FILE, DATA_FILE) != 0) {
        gotoxy(35,20); printf("Warning: could not rename temp file to data file.");
    }
    if (!replaced) {
        gotoxy(35,21); printf("Warning: record to update was not found.");
    }
}

/* Delete: Remove the record with matching pNum */
void delete_record(const char *pNum) {
    FILE *fp = fopen(DATA_FILE, "rb");
    FILE *temp = fopen(TEMP_FILE, "wb");
    if (!fp || !temp) {
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        gotoxy(35,19); printf("Error opening files for delete.");
        return;
    }
    struct data tempData;
    int deleted = 0;
    while (fread(&tempData, sizeof(struct data), 1, fp) == 1) {
        if (strcmp(tempData.mPhone, pNum) != 0) {
            fwrite(&tempData, sizeof(struct data), 1, temp);
        } else {
            deleted = 1;
        }
    }
    fclose(fp);
    fclose(temp);

    if (remove(DATA_FILE) != 0) {
        gotoxy(35,19); printf("Warning: could not remove original file.");
    }
    if (rename(TEMP_FILE, DATA_FILE) != 0) {
        gotoxy(35,20); printf("Warning: could not rename temp file to data file.");
    }
    if (!deleted) {
        gotoxy(35,21); printf("Warning: record to delete was not found.");
    }
}

/* Search: Check if pNum exists (0: not found, 1: found, 2: empty) */
int searchByNum(const char *pNum) {
    if (pNum == NULL || strlen(pNum) == 0) return 2;
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) return 0;
    struct data temp;
    while (fread(&temp, sizeof(struct data), 1, fp) == 1) {
        if (strcmp(temp.mPhone, pNum) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

/* Safe string input using fgets and strip CR/LF */
void getString(char *buf, int size) {
    if (!buf || size <= 0) return;

    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\r\n")] = '\0';

    /* If empty, allow user to input again (caller may handle emptiness) */
}
