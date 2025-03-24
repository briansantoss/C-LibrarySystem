#include <stdio.h>
#include <stdlib.h>
#include "exe02.h"

// Declarando opções do menu
typedef enum MenuOption {
    ADD_BOOK = 1,
    SEARCH_BYNAME,
    CHANGE_PRICE,
    CHANGE_QUANT,
    INORDER_SHOW,
    QUIT
} MenuOption;

void print_menu(void) {
    puts("\n\n[1] - Add book\n[2] - Search by name\n[3] - Change price\n[4] - Change quantity\n[5] - Inorder library show\n[6] - Quit");
    printf("Insert the wished option number: ");
}

int main() {
    Book *root = NULL;

    int option = 0;
    do {
        print_menu();
        scanf("%d", &option);
        switch (option) {
            case ADD_BOOK:
                char book_name[100];
                printf("\nInsert book name: ");
                scanf("\n%99[^\n]", book_name);
                
                char book_author[100];
                printf("\nInsert book author: ");
                scanf("\n%99[^\n]", book_author);
                
                double book_price;
                printf("\nInsert book price: ");
                scanf("%lf", &book_price);
                
                int book_quantity;
                printf("Insert book quantity: ");
                scanf("%d", &book_quantity);
                
                insert_book(&root, book_name, book_author, book_price, book_quantity);
                break;

            case SEARCH_BYNAME:
                char target[100];
                printf("\nInsert book name: ");
                scanf("\n%99[^\n]", target);
            
                search_book_name(root, target);
                break;

            case CHANGE_PRICE:
                printf("\nInsert book name: ");
                scanf("\n%99[^\n]", book_name);
                
                double new_price;
                printf("\nInsert the new price: ");
                scanf("%lf", &new_price);

                change_book_price(root, book_name, new_price);
                break;
                
            case CHANGE_QUANT:
                printf("\nInsert book name: ");
                scanf("\n%99[^\n]", book_name);
                
                int quantity;
                printf("\nInsert the new price: ");
                scanf("%d", &quantity);

                change_book_quant(root, book_name, quantity);
            break;

            case INORDER_SHOW:
                inorder_trav(root);
                break;
        }
    } while (option != QUIT);
    free_library(root);
    puts("\nThanks for using our system. See you next time!");
    return 0;
}