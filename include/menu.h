#ifndef MENU_H

// Declarando opções do menu
typedef enum MenuOption {
    ADD_BOOK = 1,
    SEARCH_BYNAME,
    CHANGE_PRICE,
    CHANGE_QUANT,
    SHOW_LIBRARY,
    REMOVE_BOOK,
    QUIT
} MenuOption;

void print_menu(void);

#endif