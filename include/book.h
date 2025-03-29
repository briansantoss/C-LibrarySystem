#ifndef BOOK_H

#define BOOK_H

typedef struct BookData {
    char* title;
    char* author;
    double price;
    int quantity;
} BookData;

typedef struct TreeNode {
    BookData data;
    struct TreeNode* left;
    struct TreeNode* right;
} Book;

// Funções de CRUD
void insert_book(Book** book, char* title, char* author, double price, int quantity);
void search_book_name(Book* book, char* target_title);
void change_book_price(Book* book, char* target_title, double new_price);
void change_book_quant(Book* book, char* target_title, int new_quantity);
void remove_book(Book** book, char* target_title);

// Funções de percurso
void preorder_trav(Book* book);
void inorder_trav(Book* book);
void postorder_trav(Book* book);

// Funções auxiliares
Book* find_min(Book* book);
void free_library(Book* book);

// Versões iterativas (faem uso de loop e não de recursão)
void iter_insert_book(Book** root_book, char* title, char* author, double price, int quantity);
void iter_inorder_trav(Book* book);

#endif