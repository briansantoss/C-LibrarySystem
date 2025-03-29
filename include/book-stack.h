#ifndef BOOK_STACK_H

#define BOOK_STACK_H

#include "book.h"

typedef struct Node {
    Book* book;
    struct Node* next;
} StackNode;

typedef struct Stack {
    StackNode* head;
    StackNode* top;
} BookStack;

BookStack* init_stack(void);
int push(BookStack* stack, Book* book);
Book* pop(BookStack* stack);
int is_stack_empty(BookStack* stack);
void free_stack(BookStack* stack);

#endif