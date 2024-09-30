#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
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
newNode->prev = tail; tail = newNode;
        }
    }

    return head;
}
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
   printf("Name: Aadya \n");
printf("Roll no:2330002\n");  int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
Node* head = createList(n);
printf("Doubly Linked List: ");
    displayList(head);
    return 0;
}