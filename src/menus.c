#include <stdio.h>
#include "menus.h"

void print_main_menu(void) {
    printf("\n\n[%d] - Add book\n[%d] - Search by name\n[%d] - Change price\n[%d] - Change quantity\n[%d] - Show library\n[%d] - Remove book\n[%d] - Quit", ADD_BOOK, SEARCH_BYNAME, CHANGE_PRICE, CHANGE_QUANT, SHOW_LIBRARY, REMOVE_BOOK, QUIT);
    printf("\nInsert the wished option number: ");
}

void print_show_menu(void) {
    printf("\nWhat kind of traversal do you want?");
    printf("\n[%d] Preorder\n[%d] Inorder\n[%d] Postorder\n[%d] Quit", PREORDER_SHOW, INORDER_SHOW, POSTORDER_SHOW, QUIT_SHOW);
    printf("\nInsert the wished option number: ");
}