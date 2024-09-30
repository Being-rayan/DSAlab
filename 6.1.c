#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
void push(struct Node **top, int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Stack overflow\n");
    } else {
        ptr->data = value;
        ptr->next = *top;
        *top = ptr;  
        printf("Pushed %d into the stack\n", value);
    }
}
int pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    } else {
        struct Node *ptr = *top;
        int value = ptr->data;
        *top = ptr->next;  
        free(ptr);       
        printf("Popped %d from the stack\n", value);
        return value;
    }
}
void printStack(struct Node *top) {
    struct Node *current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void freeStack(struct Node *top) {
    struct Node *current = top;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
}
}
int main() {
    struct Node *head = NULL;

    push(&head, 2);
    push(&head, 3);
    push(&head, 3);
    push(&head, 0);
 push(&head, 0);
push(&head, 3);
push(&head, 2);
printf("Current stack: ");
    printStack(head);
 pop(&head);
    pop(&head);
 printf("Current stack after pops: ");
    printStack(head);
    freeStack(head); 
    return 0;
}