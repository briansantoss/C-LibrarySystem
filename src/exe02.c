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

void search_book_name(Book *book, char *target_name) {
    if (book) {
        if (strcmp(book->data.name, target_name) == 0) {
            printf("\nName: %s\nAuthor: %s\nPrice: %.2lf\nQuantity: %d\n", book->data.name, book->data.author, book->data.price, book->data.quantity);
        } else if (strcmp(target_name, book->data.name) > 0) {
            search_book_name(book->right, target_name);
        } else {
            search_book_name(book->left, target_name);
        }
    }
}

void inorder_trav(Book *book) {
    if (book) {
        inorder_trav(book->left);
        printf("\n%s", book->data.name);
        inorder_trav(book->right);
    }
}

void free_library(Book *book) {
    if (book) { 
        // Percorre as subárvores, desalocando-as primeiro
        free_library(book->left);
        free_library(book->right);

        // Libera o espaço alocado para o nome do livro e o autor
        free(book->data.name);
        free(book->data.author); 

        // Libera a raiz
        free(book);
    }
}