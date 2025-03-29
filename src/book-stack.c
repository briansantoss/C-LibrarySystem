#include <stdlib.h>
#include <stdio.h>
#include "book-stack.h"

BookStack* init_stack(void) {
    BookStack* stack = (BookStack*) malloc(sizeof (BookStack));
    if (!stack) {
        return NULL;
    }

    stack->head = stack->top = NULL;
    return stack;
}

int is_stack_empty(BookStack* stack) {
    return !stack || !stack->top;
}

int push(BookStack* stack, Book* book) {
    if (!stack) {
        return 1;
    }
    
    StackNode* new_node = (StackNode*) malloc(sizeof (StackNode));
    if (!new_node) {
        return 1;
    }

    new_node->book = book;
    new_node->next = NULL;

    if (is_stack_empty(stack)) {
        stack->head = stack->top = new_node;
        return 0;
    }

    stack->top->next = new_node;
    stack->top = new_node;
    return 0;
}

void free_stack(BookStack* stack) {
    if (!stack) { // Se a pilha for vazia retorna previamente
        return;
    }

    StackNode* curr = stack->head; // Recebe o primeiro nó da pilha
    while (curr) { // Percorre a pilha liberando memória
        // Armazena o próximo nó
        StackNode* next = curr->next;

        // Libera a memória reservada para o nó atual
        free(curr);
        curr = next;
    }

    // Atribui NULL a cabeça e a cauda
    stack->head = stack->top = NULL;
}