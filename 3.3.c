//display contents in reverse order in a linked lists

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
void print_mth_from_last(struct Node* head, int m) {
    struct Node *first = head, *second = head;
 for (int i = 0; i < m; i++) {
        if (first == NULL) {
            printf("The list has less than %d nodes.\n", m);
            return;
        }
        first = first->next;
    }
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    if (second != NULL)
        printf("The %dth node from the last is: %d\n", m, second->data);
}
int main() {
    struct Node* head = NULL;
append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    int m = 2; 
    print_mth_from_last(head, m);

    return 0;
}
