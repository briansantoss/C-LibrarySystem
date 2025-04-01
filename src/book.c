#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

Book* create_book(char* title, char* author, double price, int quantity) {
    Book* new_book = (Book*) malloc(sizeof (Book));
    if (!new_book) {
        return NULL;
    }
    
    // Reserva espaço para o título e o nome do autor
    new_book->data.title = (char*) malloc(strlen(title) + 1);
    new_book->data.author = (char*) malloc(strlen(author) + 1);
    
    // Caso alguma falhe, libera o espaço
    if (!new_book->data.title || !new_book->data.author) {
        free(new_book->data.title);
        free(new_book->data.author);
        free(new_book);
        return NULL;
    }
    
    // Preenche título e autor 
    strcpy(new_book->data.title, title);
    strcpy(new_book->data.author, author);

    // Inicializa os demais campos
    new_book->data.price = price;
    new_book->data.quantity = quantity;

    // Inicializa o novo livro sem filhos
    new_book->left = new_book->right = NULL;

    return new_book;
}

void free_book(Book* book) {
    if (!book) { // Retorna previamente caso o nó seja vazio
        return;
    }

    // Libera o espaço destinado ao título e autor
    free(book->data.title);
    free(book->data.author);

    // Por fim, libera o espaço do livro em si
    free(book);
}

size_t library_height(Book* book) {
    if (!book) { // Se o nó atual for vazio é adicionado 0 para não interferir
        return 0;
    }

    size_t left_subtree_height = library_height(book->left); // Calcula a altura da subárvore esquerda
    size_t right_subtree_height = library_height(book->right); // Calcula a altura da subárvore direita

    // Pega a maior altura das subárvores e contabiliza a raiz (nó atual) somando 1
    return 1 + (left_subtree_height > right_subtree_height ? left_subtree_height : right_subtree_height);
}

int book_balance_factor(Book* book) {
    if (!book) { // Se o nó atual for vazio a diferença entre as alturas de suas subárvores é nula
        return 0;
    }

    return library_height(book->left) - library_height(book->right);
}

void insert_book(Book** book, char* title, char* author, double price, int quantity) {
    if (!*book) {
        Book *new_book = create_book(title, author, price, quantity);
        if (!new_book) {
            fprintf(stderr, "\nError: Cannot allocate memory.\n");
            return;
        }

        // Anexando o nó à árvore
        *book = new_book;
        return; // Retorno prévio para evitar chamadas recursivas desncessárias
    }

    // Armazena o resultado da comperação do nome do alvo com o nome do nó atual
    int target_cmp = strcmp(title, (*book)->data.title);
    if (target_cmp > 0) {
        insert_book((&(*book)->right), title, author, price, quantity);
    } else if (target_cmp < 0) {
        insert_book((&(*book)->left), title, author, price, quantity);
    } else {
        fprintf(stderr, "\nError: Duplicate spotted.\n");
        return;
    }
}

void iter_insert_book(Book** book, char* title, char* author, double price, int quantity) {
    Book** curr = book;
    while (*curr) {
        int target_cmp = strcmp(title, (*curr)->data.title);
        if (target_cmp > 0) {
            curr = &(*curr)->right;
        } else if (target_cmp < 0) {
            curr = &(*curr)->left;
        } else {
            fprintf(stderr, "\nError: Duplicate spotted.\n");
            return;
        }
    }

    Book* new_book =  create_book(title, author, price, quantity);
    if (!new_book) {
        fprintf(stderr, "\nError: Cannot allocate memory.\n");
        return;
    }

    *curr = new_book;
}

void search_book_name(Book* book, char* target_title) {
    if (!book) {
        fprintf(stderr, "\nError: No book with name %s was found.", target_title);
        return; // Retorno prévio
    }
    
    int target_cmp = strcmp(target_title, book->data.title);
    if (target_cmp == 0) {
        printf("\nName: %s\nAuthor: %s\nPrice: %.2lf\nQuantity: %d\n", book->data.title, book->data.author, book->data.price, book->data.quantity);
    } else if (target_cmp > 0) {
        search_book_name(book->right, target_title);
    } else {
        search_book_name(book->left, target_title);
    }
}

void change_book_price(Book* book, char* target_title, double new_price) {
    if (!book) {
        fprintf(stderr, "\nError: No book with name %s was found.", target_title);
        return; // Retorno prévio
    }
    
    int target_cmp = strcmp(target_title, book->data.title);
    if (target_cmp == 0) {
        if (book->data.price == new_price) {
            fprintf(stderr, "\nError: The price already is %.2lf.", new_price);
            return; 
        }
        // Caso o novopreço seja de fato maior, realiza a alteração
        book->data.price = new_price;
        printf("\nPrice changed to %.2lf succesfully.", new_price);
        return;
    } else if (target_cmp > 0) {
        change_book_price(book->right, target_title, new_price);
    } else {
        change_book_price(book->left, target_title, new_price);
    }
}

void change_book_quant(Book* book, char* target_title, int new_quantity) {
    if (!book) {
        fprintf(stderr, "\nError: No book with name %s was found.", target_title);
        return; // Retorno prévio
    }
   
    int target_cmp = strcmp(target_title, book->data.title);
    if (target_cmp == 0) {
        if (book->data.quantity == new_quantity) {
            fprintf(stderr, "\nError: The quantity in stock already is %d.", new_quantity);
            return; 
        }
        book->data.quantity = new_quantity;
    } else if (target_cmp > 0) {
        change_book_quant(book->right, target_title, new_quantity);
    } else {
        change_book_quant(book->left, target_title, new_quantity);
    }
}

void preorder_trav(Book* book) {
    if (book) {
        printf("\n%s", book->data.title);
        preorder_trav(book->left);
        preorder_trav(book->right);
    }
}

void inorder_trav(Book* book) {
    if (book) {
        inorder_trav(book->left);
        printf("\n%s", book->data.title);
        inorder_trav(book->right);
    }
}

void postorder_trav(Book* book) {
    if (book) {
        postorder_trav(book->left);
        postorder_trav(book->right);
        printf("\n%s", book->data.title);
    }
}

Book* find_min(Book* book) {
    Book* curr = book;
    // Percorre a subárvore esquerda
    while (curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

void remove_book(Book** book, char* target_title) {
    if (!*book) {
        fprintf(stderr, "\nError: No book with name %s was found.", target_title);
        return;
    }

    int target_cmp = strcmp(target_title, (*book)->data.title);
    if (target_cmp > 0) {
        remove_book(&(*book)->right, target_title);
    } else if (target_cmp < 0) {
        remove_book(&(*book)->left, target_title);
    } else {
        // Verifica quais filhos o nó tem (esquerda e direita)
        Book* right = (*book)->right;
        Book* left = (*book)->left;
        if (right && left) { // Caso onde o nó atual tem os dois filhos
            // Encontra o menor nó da subárvore direita
            Book* right_min_book = find_min((*book)->right);

            (*book)->data = right_min_book->data;

            // Remove o menor nó da subárvore direita
            remove_book(&(*book)->right, right_min_book->data.title);
        } else if (right || left) { // Caso onde só há um filho
            // Obtém o nó não vazio
            Book* existent_child = right ? right : left;

            free(*book);

            // Troca o nó atual pelo seu único filho
            *book = existent_child;
        } else { // Caso o nó seja uma folha
            // Libera o espaço reservado para o nó atual
            free(*book);
            *book = NULL;
        }
    }
}

void free_library(Book *book) {
    if (book) { 
        // Percorre as subárvores, desalocando-as primeiro
        free_library(book->left);
        free_library(book->right);

        free_book(book);
    }
}