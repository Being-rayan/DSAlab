#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;          
    struct node *left; 
    struct node *right; 
};

struct node *root = NULL;

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory Full\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void Pre_Order(struct node *nd) {
    if (nd == NULL) return;
    printf("%d ", nd->data);
    Pre_Order(nd->left);
    Pre_Order(nd->right);
}

void In_Order(struct node *nd) {
    if (nd == NULL) return;
    In_Order(nd->left);
    printf("%d ", nd->data);
    In_Order(nd->right);
}

void Post_Order(struct node *nd) {
    if (nd == NULL) return;
    Post_Order(nd->left);
    Post_Order(nd->right);
    printf("%d ", nd->data);
}


void insertValues() {
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 14);
    root = insert(root, 16);
    root = insert(root, 26);
    root = insert(root, 23);
    root = insert(root, 30);
    root = insert(root, 27);
}


int main() {
    insertValues();

   
    
    printf("\nThe In Order is: ");
    In_Order(root);
     printf("\nThe Pre Order is: ");
    Pre_Order(root);
    printf("\nThe Post Order is: ");
    Post_Order(root);
    
    return 0;
}
