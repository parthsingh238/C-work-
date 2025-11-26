#include <stdio.h>
#include <string.h>

struct Book {
    int book_id;
    char title[100];
    char author[100];
    float price;
};

static void trim_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

void displayBook(const struct Book *b) {
    printf("\n--- Book Details ---\n");
    printf("Book ID   : %d\n", b->book_id);
    printf("Title     : %s\n", b->title);
    printf("Author    : %s\n", b->author);
    printf("Price     : %.2f\n", b->price);
}

int main() {
    struct Book book1;

    printf("Enter Book ID: ");
    if (scanf("%d", &book1.book_id) != 1) {
        fprintf(stderr, "Invalid Book ID\n");
        return 1;
    }
    /* consume leftover newline from scanf */
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    printf("Enter Book Title: ");
    if (!fgets(book1.title, sizeof(book1.title), stdin)) {
        fprintf(stderr, "Error reading title\n");
        return 1;
    }
    trim_newline(book1.title);

    printf("Enter Author Name: ");
    if (!fgets(book1.author, sizeof(book1.author), stdin)) {
        fprintf(stderr, "Error reading author\n");
        return 1;
    }
    trim_newline(book1.author);

    printf("Enter Price: ");
    if (scanf("%f", &book1.price) != 1) {
        fprintf(stderr, "Invalid price\n");
        return 1;
    }

    displayBook(&book1);

    return 0;
}
