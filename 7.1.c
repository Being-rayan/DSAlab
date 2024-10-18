#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue underflow\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) front = rear = -1;
        else front++;
        return value;
    }
}

int peek() {
    return (front != -1) ? queue[front] : -1;
}

int isEmpty() {
    return front == -1;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Check if Empty\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                printf("Dequeued value: %d\n", dequeue());
                break;
            case 3:
                printf("Front value: %d\n", peek());
                break;
            case 4:
                printf(isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
