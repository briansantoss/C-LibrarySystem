#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "menus.h"

#define MAX_STR_LEN 100

int main() {
    char book_title[MAX_STR_LEN], book_author[MAX_STR_LEN];
    double price;
    int quantity;

    Book *root;

    int option = 0;
    do {
        print_main_menu();
        scanf("%d", &option);
        switch (option) {
            case ADD_BOOK:
                printf("\nInsert book title: ");
                scanf("\n%99[^\n]", book_title);
                
                printf("Insert book author: ");
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
                
                case SHOW_LIBRARY:
                    print_show_menu();
                
                    int option_show;
                    scanf("%d", &option_show);
                    
                    switch (option_show) {
                        case PREORDER_SHOW:
                        printf("\nPREORDER: ");
                        preorder_trav(root);
                        break;
                            
                        case INORDER_SHOW:
                        printf("\nINORDER: ");
                        inorder_trav(root);
                        break;
                        
                        case POSTORDER_SHOW:
                        printf("\nPOSTORDER: ");
                        postorder_trav(root);
                        break;
                        
                        case QUIT_SHOW:
                        printf("\nExiting show menu...");
                    }
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