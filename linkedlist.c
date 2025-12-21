#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data){
    Node *newNode = (Node*) malloc (sizeof(Node));
    if(newNode == NULL){
        perror("createNode()");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNodeTail(Node **head, int data){
    Node *new = createNode(data);
    new->next = *head;
    *head = new;
}

void insertNodeHead(Node **head, int data){
    Node *newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;   
    }
    temp->next = newNode;
}

void printMap(Node *head){
    while(head != NULL){
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node *head){
    while(head != NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
    }   
}

void deleteNode(Node **head, int data){
    if(*head == NULL) return;
    
    Node *temp = *head;
    Node *prev = NULL;

    if(temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != data){
        prev = temp;
        temp = temp -> next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main(){

    Node *map = NULL;

    insertNodeTail(&map, 4);
    insertNodeTail(&map, 5);

    insertNodeHead(&map, 10);
    insertNodeHead(&map, 2);

    printMap(map);

   
    freeList(map);
    return EXIT_SUCCESS;   
}
