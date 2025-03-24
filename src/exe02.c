#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exe02.h"

void insert_book(Book **root_book, char *name, char *author, double price, int quantity) {
    if (!*root_book) {
        Book *new_book = malloc(sizeof (Book));
        if (!new_book) {
            fprintf(stderr, "\nError: Cannot allocate memory.\n");
            return;
        }
        
        // Reservando espaço para o nome do livro e realizando a atribuição
        new_book->data.name = malloc(sizeof (name) + 1);
        if (!new_book->data.name) {
            fprintf(stderr, "\nError: Cannot allocate memory.\n");
            return;
        }
        strcpy(new_book->data.name, name);
        
        // Reservando espaço para o autor do livro e realizando a atribuição
        new_book->data.author = malloc(sizeof (author) + 1);
        if (!new_book->data.author) {
            fprintf(stderr, "\nError: Cannot allocate memory.\n");
            return;
        }
        strcpy(new_book->data.author, author);

        // Inicializando os campos de preço e quantidade com os valores passos via argumento
        new_book->data.price = price;
        new_book->data.quantity = quantity;

        // Inicializando ambos os filhos do novo livro com NULL (folha)
        new_book->left = new_book->right = NULL;

        *root_book = new_book;
        return;
    }

    if (strcmp(name, (*root_book)->data.name) > 0) {
        insert_book((&(*root_book)->right), name, author, price, quantity);
    } else if (strcmp(name, (*root_book)->data.name) < 0) {
        insert_book((&(*root_book)->left), name, author, price, quantity);
    } else {
        fprintf(stderr, "\nError: Duplicate spotted.\n");
    }
}

void inorder_trav(Book *book) {
    if (book) {
        inorder_trav(book->left);
        puts(book->data.name);
        inorder_trav(book->right);
    }
}