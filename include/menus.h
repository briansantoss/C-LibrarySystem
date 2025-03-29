#ifndef MENUS_H

#define MENUS_H

// Declarando opções do menu
typedef enum MainMenuOption {
    ADD_BOOK = 1,
    SEARCH_BYNAME,
    CHANGE_PRICE,
    CHANGE_QUANT,
    SHOW_LIBRARY,
    REMOVE_BOOK,
    QUIT
} MainMenuOption;


typedef enum ShowMenuOption {
    PREORDER_SHOW = 1,
    INORDER_SHOW,
    POSTORDER_SHOW,
    QUIT_SHOW,
} ShowMenuOption;

void print_main_menu(void);
void print_show_menu(void);

#endif