#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create a doubly linked list of n nodes
Node* createList(int n) {
    if (n <= 0) return NULL;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to add a node at the end of the doubly linked list
void addNodeEnd(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to delete a node with a given value from the doubly linked list
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    // Traverse to find the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If node not found
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // If node to be deleted is the head
    if (temp == *head_ref) {
        *head_ref = temp->next;
    }

    // Change next of previous node if not deleting the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Change prev of next node if not deleting the head
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Main function
int main() {
    Node* head = NULL;
    int n, data, key;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Doubly Linked List: ");
    displayList(head);

    // Adding a node at the end
    printf("Enter data to add at the end: ");
    scanf("%d", &data);
    addNodeEnd(&head, data);
    
    printf("List after adding node at the end: ");
    displayList(head);

    // Deleting a node
    printf("Enter data to delete: ");
    scanf("%d", &key);
    deleteNode(&head, key);
    
    printf("List after deleting node with data %d: ", key);
    displayList(head);

    // Free allocated memory
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}