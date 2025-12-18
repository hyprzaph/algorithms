#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ko_co NULL //i dont have single finger to type "NULL" lol

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

void searchNode(Node *root, int data) {
  if (root == ko_co) {
     printf("ko tim thay\n"); return;
  } else if (root->data == data) {
     printf("tim thay\n"); return;
  } else if (root->data < data) {
    searchNode(root->right, data);
  }
  searchNode(root->left, data);
}

Node *findMin(Node *root) {
  if (root == ko_co) {
    return NULL;
  } else if (root->left != ko_co) {
    return findMin(root->left);
  }
  return root;
}

Node *deleteNode(Node *root, int data) {
  if (root == ko_co) {
    return ko_co;
  }

  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    // case 1: no child
    if (root->left == ko_co && root->right == ko_co) {
      free(root);
      return ko_co;
    }
    // case 2: one child
    else if (root->left == ko_co) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == ko_co) {
      Node *temp = root->left;
      free(root);
      return temp;
    }
    // case 3: two children
    else {
      Node *temp = findMin(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  return root;
}

int main() {

  Node *root = NULL;

  root = insertNode(root, 5);  
  insertNode(root, 10);
  insertNode(root, -1);

  printInorder(root);  printf("\n");
  printPreOrder(root); printf("\n");
  
  searchNode(root, -1); printf("\n");
  searchNode(root, 100);

  root = deleteNode(root, 10);
  printInorder(root);  
  
  return EXIT_SUCCESS;  
}  
