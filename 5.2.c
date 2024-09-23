//modify the program to add a node, traverse the list, and delete the node in doubly linked list.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node* createDoublyLinkedList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    int data, i;

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode;
    }
    return head;
}

void displayDoublyLinkedList(Node* head) {
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with data %d deleted.\n", key);
}

int main() {
    int n, data, key;
    Node* head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createDoublyLinkedList(n);
    displayDoublyLinkedList(head);

    printf("Enter data to add a new node: ");
    scanf("%d", &data);
    addNode(&head, data);
    displayDoublyLinkedList(head);

    printf("Enter data of the node to delete: ");
    scanf("%d", &key);
    deleteNode(&head, key);
    displayDoublyLinkedList(head);

    return 0;
}