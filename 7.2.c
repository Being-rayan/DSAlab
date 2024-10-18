#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    if (*rear == NULL) *front = *rear = new_node;
    else {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

int dequeue(struct Node** front) {
    if (*front == NULL) return -1;
    int value = (*front)->data;
    struct Node* temp = *front;
    *front = (*front)->next;
    free(temp);
    return value;
}

int peek(struct Node* front) {
    return (front != NULL) ? front->data : -1;
}

int isEmpty(struct Node* front) {
    return front == NULL;
}

void display(struct Node* front) {
    if (front == NULL) printf("Queue is empty\n");
    else {
        struct Node* temp = front;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Is Empty\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                printf("Dequeued value: %d\n", dequeue(&front));
                break;
            case 3:
                printf("Front value: %d\n", peek(front));
                break;
            case 4:
                printf(isEmpty(front) ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 5:
                display(front);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
