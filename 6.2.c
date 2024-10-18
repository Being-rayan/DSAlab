#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void push(struct Node** top_ref, int new_data);
int pop(struct Node** top_ref);
int peek(struct Node* top);
int isEmpty(struct Node* top);
void display(struct Node* top);

int main() {
    struct Node* stack = NULL;
    int choice, value;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                if (!isEmpty(stack))
                    printf("Popped value: %d\n", pop(&stack));
                else
                    printf("Stack is empty.\n");
                break;
            case 3:
                if (!isEmpty(stack))
                    printf("Top value: %d\n", peek(stack));
                else
                    printf("Stack is empty.\n");
                break;
            case 4:
                if (isEmpty(stack))
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 5:
                display(stack);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct Node** top_ref) {
    int res;
    struct Node* top;
    if (*top_ref == NULL) {
        printf("Stack underflow\n");
        exit(0);
    }
    else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

int peek(struct Node* top) {
    if (top != NULL)
        return top->data;
    else
        exit(0);
}

int isEmpty(struct Node* top) {
    return (top == NULL);
}

void display(struct Node* top) {
    struct Node* temp = top;
    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
