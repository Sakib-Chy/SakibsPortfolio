#include<stdio.h>
#include<string.h>

#define MAX 100 //defining maximum number of books in the library

struct Book{    //structure for book details
    int id;
    char title[50];
    char author[50];
    int quantity;
};

struct Book library[MAX];   //array of structure to store book details
int count = 0; //variable to keep track of number of books in the library

void addbook();
void displaybook();
void searchbook();
void updatebook();
void deletebook();

int main() {
    int choice = 0;

    while (choice!=6) //user can perform operations until they choose to exit
    {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice==1)
        {
            addbook(); //Calling addbook function
        }else if (choice==2)
        {
            displaybook();
        }else if (choice==3)
        {
            searchbook(); //Calling searchbook function
        }else if (choice==4)
        {
            updatebook(); //Calling updatebook function
        }else if (choice==5)
        {
            deletebook(); //Calling deletebook function
        }else if (choice==6)
        {
            printf("Byee, See you next time...\n");
        }else
        {
            printf("Invalid Input!\n");
        }
    }
    return 0;
}
// Adding book to the library
void addbook(){
    if (count >= MAX)
    {
        printf("Storage is full!");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", library[count].title);

    printf("Enter Book Author: ");
    scanf(" %[^\n]", library[count].author);

    printf("Enter Stock quantity: ");
    scanf("%d", &library[count].quantity);

    count++;
    printf("Book inserted successfully.\n");
}
// Displaying all books in the library
void displaybook(){
    if (count == 0)
    {
        printf("No books available.\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("\nBook ID: %d", library[i].id);
        printf("\nTitle: %s", library[i].title);
        printf("\nAuthor: %s", library[i].author);
        printf("\nQuantity: %d", library[i].quantity);
        printf("\n");
    }
    
}
// Searching for a book in the library
void searchbook(){
    int id, found = 0;

    printf("Enter Your Book ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (library[i].id == id)
        {
            printf("Book found.\n");
            printf("Title: %s\n", library[i].title);
            printf("author: %s\n", library[i].author);
            printf("quantity: %d\n", library[i].quantity);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Book isn't available.\n");
    }
    
    
}
// Updating a book in the library
void updatebook(){
    int id;

    printf("Enter Your Book ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (library[i].id == id)
        {
            printf("New Enter Book ID: ");
            scanf("%d", &library[i].id);

            printf("New Enter Book Name: ");
            scanf(" %[^\n]", library[i].title);

            printf("New Enter Book Author: ");
            scanf(" %[^\n]", library[i].author);

            printf("New Enter Stock quantity: ");
            scanf("%d", &library[i].quantity);

            printf("Book updated.\n");
            return;
        }
    }
    printf("Book not found.\n");
    
}
// Deleting a book from the library
void deletebook(){
    int id;

    printf("Enter Your book id: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (library[i].id == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                library[j] = library[j + 1];
            }
            
            count--;
            printf("Book deleted.\n");
            return;
        }
    }
    printf("Book not found.\n");
}
