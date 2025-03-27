#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

void insert_book(Book **root_book, char* name, char* author, double price, int quantity) {
    if (!*root_book) {
        Book *new_book = (Book*) malloc(sizeof (Book));
        if (!new_book) {
            fprintf(stderr, "\nError: Cannot allocate memory.\n");
            return;
        }

        // Reservando espaço para o nome do livro e do autor
        char* book_name = (char*) malloc(strlen(name) + 1);
        char* book_author = (char*) malloc(strlen(author) + 1);

        // Liibera a memória das alocações não bem sucedidas caso alguma falhe
        if (!book_name || !book_author) {
            free(new_book);
            free(book_name);
            free(book_author);
            fprintf(stderr, "\nError: Cannot allocate memory.\n");
            return;
        }

        // Preenche a memória alocada com o respectivo conteúdo
        strcpy(book_name, name);
        strcpy(book_author, author);

        // Inicializando os campos do livro
        new_book->data.name = book_name;
        new_book->data.author = book_author;
        new_book->data.price = price;
        new_book->data.quantity = quantity;

        // Inicializando ambos os filhos do novo livro com NULL (folha)
        new_book->left = new_book->right = NULL;

        // Anexando o nó à árvore
        *root_book = new_book;
        return; // Retorno prévio para evitar chamadas recursivas desncessárias
    }

    // Armazena o resultado da comperação do nome do alvo com o nome do nó atual
    int target_cmp = strcmp(name, (*root_book)->data.name);
    if (target_cmp > 0) {
        insert_book((&(*root_book)->right), name, author, price, quantity);
    } else if (target_cmp < 0) {
        insert_book((&(*root_book)->left), name, author, price, quantity);
    } else {
        fprintf(stderr, "\nError: Duplicate spotted.\n");
        return;
    }
}

void iter_insert_book(Book** root_book, char* name, char* author, double price, int quantity) {
    Book** curr = root_book;
    while (*curr) {
        int target_cmp = strcmp(name, (*curr)->data.name);
        if (target_cmp > 0) {
            curr = &(*curr)->right;
        } else if (target_cmp < 0) {
            curr = &(*curr)->left;
        } else {
            fprintf(stderr, "\nError: Duplicate spotted.\n");
            return;
        }
    }

    Book* new_book = (Book*) malloc(sizeof (Book));
    if (!new_book) {
        fprintf(stderr, "\nError: Cannot allocate memory.\n");
        return;
    }

    char* book_name = (char*) malloc(strlen(name) + 1);
    char* book_author = (char*) malloc(strlen(author) + 1);

    if (!book_name || !book_author) {
        free(new_book);
        free(book_name);
        free(book_author);
        fprintf(stderr, "\nError: Cannot allocate memory.\n");
        return;
    }

    strcpy(book_name, name);
    strcpy(book_author, author);

    new_book->data.name = book_name;
    new_book->data.author = book_author;
    new_book->data.price = price;
    new_book->data.quantity = quantity;

    new_book->left = new_book->right = NULL;

    *curr = new_book;
}

void search_book_name(Book *book, char *target_name) {
    if (!book) {
        fprintf(stderr, "\nError: No book with name %s was found.", target_name);
        return; // Retorno prévio
    }
    
    if (strcmp(target_name, book->data.name) == 0) {
        printf("\nName: %s\nAuthor: %s\nPrice: %.2lf\nQuantity: %d\n", book->data.name, book->data.author, book->data.price, book->data.quantity);
    } else if (strcmp(target_name, book->data.name) > 0) {
        search_book_name(book->right, target_name);
    } else {
        search_book_name(book->left, target_name);
    }
}

void change_book_price(Book *book, char *target_name, double new_price) {
    if (!book) {
        fprintf(stderr, "\nError: No book with name %s was found.", target_name);
        return; // Retorno prévio
    }
    
    if (strcmp(target_name, book->data.name) == 0) {
        if (book->data.price == new_price) {
            fprintf(stderr, "\nError: The price already is %.2lf.", new_price);
            return; 
        }
        // Caso o novopreço seja de fato maior, realiza a alteração
        book->data.price = new_price;
        printf("\nPrice changed to %.2lf succesfully.", new_price);
        return;
    } else if (strcmp(target_name, book->data.name) > 0) {
        change_book_price(book->right, target_name, new_price);
    } else {
        change_book_price(book->left, target_name, new_price);
    }
}

void change_book_quant(Book *book, char *target_name, int new_quantity) {
    if (!book) {
        fprintf(stderr, "\nError: No book with name %s was found.", target_name);
        return; // Retorno prévio
    }
   
    if (strcmp(target_name, book->data.name) == 0) {
        if (book->data.quantity == new_quantity) {
            fprintf(stderr, "\nError: The quantity in stock already is %d.", new_quantity);
            return; 
        }
        book->data.quantity = new_quantity;
    } else if (strcmp(target_name, book->data.name) > 0) {
        change_book_quant(book->right, target_name, new_quantity);
    } else {
        change_book_quant(book->left, target_name, new_quantity);
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