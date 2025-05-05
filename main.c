#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {

    char title[100];
    char author[50];
    uint32_t book_id;
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

    while (1) {
        uint8_t user_choise = 0;
        displayMessages();
        scanf("%d",&user_choise);

        switch (user_choise) {

            case 1:
                addNewBook(book_details,&book_cnt);
                break;
            case 2:
                displayAllBooks(book_details,&book_cnt);
                break;
            case 3:
                markBookBorrow_Return(book_details,&book_cnt);
                break;
            case 4:
                deleteBook(book_details,&book_cnt);
                break;
            default:
                printf("Invalid User Choise!");
        }
    }


}

void displayMessages() {


    printf("Add a new book press                    (1)\n");
    printf("Display all books press                 (2)\n");
    printf("Mark a book as borrowed/returned press  (3)\n");
    printf("Delete Book press                       (4)\n");

}

void addNewBook(Book_Details_t *book_details, uint32_t *book_count) {


    printf("Enter book ID: ");
    uint32_t book_id = 0;
    scanf("%d",&book_id);

    for (uint32_t i = 0; i < *book_count; i++) {
        if(book_details[i].book_id == book_id) {

            printf("This book is Already Exited!");
            return;
        }
    }
            book_details[*book_count].book_id = book_id;
            getchar();
            printf("Enter book Title: ");
            scanf("%100[^\n]",book_details[*book_count].title);
            getchar();
            printf("Enter Book Author: ");
            scanf("%50[^\n]",book_details[*book_count].author);
            book_details[*book_count].is_available = available;
            (*book_count)++;

        }






void displayAllBooks(Book_Details_t *book_details, uint32_t *book_count) {

    if(*(book_count) !=0) {
        for (uint32_t i = 0; i<*book_count; i++)
        {
            printf("Book Title : %s\n",book_details[i].title);
            printf("Book Author : %s\n",book_details[i].author);
            printf("Book ID : %d\n",book_details[i].book_id);
            printf("Book Availability : ");
            (book_details[i].is_available == available)? (printf("Available\n")): (printf("Unavailable\n"));
            printf("\n");
        }
    }
    else
        printf("Books are Empty!!\n");
        printf("\n");


}

void markBookBorrow_Return(Book_Details_t *book_details, uint32_t *book_count) {

    uint32_t book_id = 0;
    char user_input;
    printf("Please Enter Book ID: ");
    scanf("%d",&book_id);

    for (uint32_t i=0; i<*book_count;i++) {
        if(book_details[i].book_id==book_id) {

            if(book_details[i].is_available == available) {
                getchar();
                printf("Borrow this book? press (y/n): ");
                scanf("%c",&user_input);
                if (user_input == 'y') {
                    book_details[i].is_available =unavailable;
                    return;
                }



            }
            else {
                getchar();
                printf("Do you want to make this book available ? press (y/n): ");
                scanf("%c",&user_input);
                if (user_input == 'y') {
                    book_details[i].is_available =available;
                    return;
                }
            }
        }
        else
            printf("Invalid Book ID\n");
    }

}

void deleteBook(Book_Details_t *book_details, uint32_t *book_count) {

    uint32_t book_id = 0;
    printf("Please Enter Book ID: ");
    scanf("%d",&book_id);

    for (uint32_t i = 0; i< (*book_count); i++) {

        if(book_details[i].book_id == book_id) {

            for (uint32_t j = i; j<(*book_count)-1; j++) {

                book_details[j] =book_details[j+1];


            }
            (*book_count)--;
            return;

        }

        printf("Invalid Book ID!\n");
    }


}