#include <stdio.h>
#include <stdlib.h>
#include "book.h"

#define MAX_STR_LEN 100
// Declarando opções do menu
typedef enum MenuOption {
    ADD_BOOK = 1,
    SEARCH_BYNAME,
    CHANGE_PRICE,
    CHANGE_QUANT,
    INORDER_SHOW,
    REMOVE_BOOK,
    QUIT
} MenuOption;

void print_menu(void) {
    puts("\n\n[1] - Add book\n[2] - Search by name\n[3] - Change price\n[4] - Change quantity\n[5] - Inorder library show\n[6] - Remove book\n[7] - Quit");
    printf("Insert the wished option number: ");
}

int main() {
    char book_title[MAX_STR_LEN], book_author[MAX_STR_LEN];
    double price;
    int quantity;

    Book *root;

    int option = 0;
    do {
        print_menu();
        scanf("%d", &option);
        switch (option) {
            case ADD_BOOK:
                printf("\nInsert book title: ");
                scanf("\n%99[^\n]", book_title);
                
                printf("\nInsert book author: ");
                scanf("\n%99[^\n]", book_author);
                
                printf("Insert book price: ");
                scanf("%lf", &price);
                
                printf("Insert book quantity: ");
                scanf("%d", &quantity);
                
                iter_insert_book(&root, book_title, book_author, price, quantity);
                break;

            case SEARCH_BYNAME:
                printf("\nInsert book title: ");
                scanf("\n%99[^\n]", book_title);
            
                search_book_name(root, book_title);
                break;

            case CHANGE_PRICE:
                printf("Insert book title: ");
                scanf("\n%99[^\n]", book_title);
                
                printf("\nInsert the new price: ");
                scanf("%lf", &price);

                change_book_price(root, book_title, price);
                break;
                
            case CHANGE_QUANT:
                printf("\nInsert book title: ");
                scanf("\n%99[^\n]", book_title);
                
                printf("\nInsert the new price: ");
                scanf("%d", &quantity);

                change_book_quant(root, book_title, quantity);
            break;

            case INORDER_SHOW:
                inorder_trav(root);
                break;
            
            case REMOVE_BOOK:
                printf("\nInsert book name: ");
                scanf("\n%99[^\n]", book_title);

                remove_book(&root, book_title);
        }
    } while (option != QUIT);
    free_library(root);
    puts("\nThanks for using our system. See you next time!");
    return 0;
}