#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 10

// Structure to store book details
struct Book {
    char title[50];
    char author[50];
    int year;
};

// Global array to store books and a counter
struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter the book title: ");
    getchar(); // Clear the newline character from input buffer
    fgets(library[bookCount].title, sizeof(library[bookCount].title), stdin);
    strtok(library[bookCount].title, "\n"); // Remove trailing newline

    printf("Enter the author's name: ");
    fgets(library[bookCount].author, sizeof(library[bookCount].author), stdin);
    strtok(library[bookCount].author, "\n");

    printf("Enter the publication year: ");
    scanf("%d", &library[bookCount].year);

    bookCount++;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nLibrary Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library[i].title, library[i].author, library[i].year);
    }
}

// Function to search for a book by title
void searchBook() {
    char searchTitle[50];
    printf("Enter the title of the book to search: ");
    getchar(); // Clear the newline character
    fgets(searchTitle, sizeof(searchTitle), stdin);
    strtok(searchTitle, "\n"); // Remove trailing newline

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found: %s by %s (%d)\n", library[i].title, library[i].author, library[i].year);
            return;
        }
    }

    printf("Book not found.\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display Books\n");
        printf("3. Search for a Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
