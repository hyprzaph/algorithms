#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ko_co NULL

typedef struct Node {
  struct Node *left, *right;
  int data;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;  
}

Node *insertNode(Node *root, int data) {
  if (root == NULL) {
    return createNode(data);
  } else if (root->data > data) {
    root->left = insertNode(root->left, data);
  } else if (root->data < data) {
    root->right = insertNode(root->right, data);
  }
  return root;  
}

void printInorder(Node *root) {
  if (root == NULL)
    return;
  
  printInorder(root->left);
  printf("%d ", root->data);
  printInorder(root->right);  
}

void printPreOrder(Node *root) {
  if (root == ko_co) {
    return;
  }

  printf("%d ", root->data);
  printPreOrder(root->left);
  printPreOrder(root->right);
}

int main() {

  Node *root = NULL;

  root = insertNode(root, 5);  
  insertNode(root, 10);
  insertNode(root, -1);

  printInorder(root);
  printPreOrder(root);
  
  return EXIT_SUCCESS;  
}  
