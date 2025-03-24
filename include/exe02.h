#ifndef EXE02_H

typedef struct BookData {
    char *name;
    char *author;
    double price;
    int quantity;
} BookData;

typedef struct TreeNode {
    BookData data;
    struct TreeNode *left;
    struct TreeNode *right;
} Book;

void insert_book(Book **root_book, char *name, char *author, double price, int quantity);
void search_book_name(Book **root_book, char *target_name);
void change_book_price(Book **root_book, char *target_name);
void change_book_quant(Book **root_book, char *target_name);
void inorder_trav(Book *book);
void free_library(Book *book);

#endif
