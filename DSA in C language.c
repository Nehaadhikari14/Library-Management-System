#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_BOOKS 100
#define MAX_MEMBERS 100
 
// Book structure
typedef struct {
    char title[100];
    char author[100];
    char isbn[13];
    int availability;
} Book;
// Member structure
typedef struct {
    char name[100];
    int memberId;
} Member;
 
// Global variables
Book libraryBooks[MAX_BOOKS];
Member libraryMembers[MAX_MEMBERS];
int bookCount = 0;
int memberCount = 0;
 
// Function prototypes
void addBook();
void displayBooks();
void addMember();
void displayMembers();
 
int main() {
    int choice;
 
    do {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Add Member\n");
        printf("4. Display Members\n");
        printf("0. Exit\n");
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
                addMember();
                break;
            case 4:
                displayMembers();
                break;
            case 0:
                printf("Exiting Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
 
    return 0;
}
 
void addBook() {
    if (bookCount == MAX_BOOKS) {
        printf("Maximum book capacity reached. Unable to add more books.\n");
        return;
    }
 
    Book newBook;
 
    printf("Enter Book Title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", newBook.author);
    printf("Enter ISBN: ");
    scanf("%s", newBook.isbn);
    newBook.availability = 1;  // Set availability to 1 (available)
 
    libraryBooks[bookCount++] = newBook;
 
    printf("Book added successfully!\n");
}
 
void displayBooks() {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }
 
    printf("\n===== Book List =====\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s\n", libraryBooks[i].title);
        printf("Author: %s\n", libraryBooks[i].author);
        printf("ISBN: %s\n", libraryBooks[i].isbn);
        printf("Availability: %s\n", libraryBooks[i].availability ? "Available" : "Not Available");
        printf("-------------------------\n");
    }
}
 
void addMember() {
    if (memberCount == MAX_MEMBERS) {
        printf("Maximum member capacity reached. Unable to add more members.\n");
        return;
    }
 
    Member newMember;
 
    printf("Enter Member Name: ");
    scanf(" %[^\n]", newMember.name);
    newMember.memberId = memberCount + 1;
 
    libraryMembers[memberCount++] = newMember;
 
    printf("Member added successfully!\n");
}
 
void displayMembers() {
    if (memberCount == 0) {
        printf("No members registered in the library.\n");
        return;
    }
 
    printf("\n===== Member List =====\n");
    for (int i = 0; i < memberCount; i++) {
        printf("Name: %s\n", libraryMembers[i].name);
        printf("Member ID: %d\n", libraryMembers[i].memberId);
        printf("-------------------------\n");
    }
}