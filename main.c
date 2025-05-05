#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {

    char title[100];
    char author[50];
    uint16_t book_id;
    uint8_t is_available;

}Book_Details_t;

Book_Details_t book_details[50];

uint32_t book_cnt;

uint8_t available = 1;
uint8_t unavailable = 0;


void displayMessages();
void addNewBook(Book_Details_t *book_details, uint32_t *book_count);
void displayAllBooks(Book_Details_t *book_details, uint32_t *book_count);
void markBookBorrow_Return(Book_Details_t *book_details, uint32_t *book_count);
void deleteBook(Book_Details_t *book_details, uint32_t *book_count);

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

void displayMessages() {


    printf("Add a new book press                    (1)\n");
    printf("Display all books press                 (2)\n");
    printf("Mark a book as borrowed/returned press  (3)\n");
    printf("Delete Book press                       (4)\n");

}

void addNewBook(Book_Details_t *book_details, uint32_t *book_count) {

    uint32_t book_id = 0;
    printf("Enter book ID: ");
    scanf("%d",&book_id);
    for (uint32_t i = 0; i < *book_count; i++) {

        if(book_details[i].book_id != book_id) {

            book_details[i].book_id = book_id;
            printf("Enter book Title: ");
            scanf("%50[^\n]",book_details[i].title);
            printf("Enter Book Author: ");
            scanf("%50[^\n]",book_details[i].author);
            book_details[i].is_available = available;
            return;


        }

        printf("This book is Already Exited!");
    }




}


void displayAllBooks(Book_Details_t *book_details, uint32_t *book_count) {




}

void markBookBorrow_Return(Book_Details_t *book_details, uint32_t *book_count) {




}

void deleteBook(Book_Details_t *book_details, uint32_t *book_count) {




}