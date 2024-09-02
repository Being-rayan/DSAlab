//display contents of linked list in reverse order

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void print_reverse(struct Node* head) {
    if (head == NULL)
        return;

    
    print_reverse(head->next);

    printf("%d ", head->data);
}

int main() {
    struct Node* head = NULL;

 
    append(&head, 2);
    append(&head, 3);
    append(&head, 3);
    append(&head, 0);
    append(&head, 0);
    append(&head, 3);
    append(&head, 9);

    printf("Linked list in reverse order:\n");
    print_reverse(head);

    return 0;
}