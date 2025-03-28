#include <stdio.h>
#include "menu.h"

void print_menu(void) {
    printf("\n\n[%d] - Add book\n[%d] - Search by name\n[%d] - Change price\n[%d] - Change quantity\n[%d] - Show library\n[%d] - Remove book\n[%d] - Quit", ADD_BOOK, SEARCH_BYNAME, CHANGE_PRICE, CHANGE_QUANT, SHOW_LIBRARY, REMOVE_BOOK, QUIT);
    printf("\nInsert the wished option number: ");
}
