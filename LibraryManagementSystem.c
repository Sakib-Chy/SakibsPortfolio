#include<stdio.h>
#include<string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};

struct Book library[MAX];
int count = 0;

// Adding book to the library
void addBook() {
    if(count >= MAX) {
        printf("Storage full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Title: ");
    scanf(" %[^\n]", library[count].title);

    printf("Enter Author: ");
    scanf(" %[^\n]", library[count].author);

    printf("Enter Quantity: ");
    scanf("%d", &library[count].quantity);

    count++;
    printf("Book added successfully.\n");
}

// Displaying Books from the library
void displayBooks() {
    if(count == 0) {
        printf("No books available.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("\nBook ID: %d", library[i].id);
        printf("\nTitle: %s", library[i].title);
        printf("\nAuthor: %s", library[i].author);
        printf("\nQuantity: %d\n", library[i].quantity);
    }
}

// Searching for a book in the library
void searchBook() {
    int id, found = 0;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(library[i].id == id) {
            printf("Book found.\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Quantity: %d\n", library[i].quantity);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Book not found.\n");
    }
}

// Updating a book in the library
void updateBook() {
    int id;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(library[i].id == id) {

            printf("Enter New Title: ");
            scanf(" %[^\n]", library[i].title);

            printf("Enter New Author: ");
            scanf(" %[^\n]", library[i].author);

            printf("Enter New Quantity: ");
            scanf("%d", &library[i].quantity);

            printf("Book updated.\n");
            return;
        }
    }

    printf("Book not found.\n");
}

// Deleting a book from the library
void deleteBook() {
    int id;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(library[i].id == id) {

            for(int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }

            count--;
            printf("Book deleted.\n");
            return;
        }
    }

    printf("Book not found.\n");
}

// Main function
int main() {
    int choice = 0;

    while(choice != 6) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) addBook();
        else if(choice == 2) displayBooks();
        else if(choice == 3) searchBook();
        else if(choice == 4) updateBook();
        else if(choice == 5) deleteBook();
        else if(choice == 6) printf("Program ended.\n");
        else printf("Invalid choice.\n");
    }

    return 0;
}