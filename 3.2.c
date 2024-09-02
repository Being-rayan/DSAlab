#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
}; 
struct   Node* head=NULL;
void insertNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void FromLast(int m) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < length - m; i++) {
        temp = temp->next;
    }
    printf("The %dth node from the last is: %d\n", m, temp->data);
}

int main() {
printf("ANGAD SAHA, 2330010\n");
    struct Node* head = NULL;
    int numNodes;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(data);
    }
    int m;
    printf("Enter the value of m: ");
    scanf("%d", &m);
    FromLast(m);

    return 0;
}
