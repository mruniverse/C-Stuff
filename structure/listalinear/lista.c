#include <stdio.h>
#include <stdlib.h>

//==========================================================

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
//==========================================================

struct Node *head;
//==========================================================

struct Node *CreateNode(int x){
    struce Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->prev = NULL;
    return newNode;
};
//==========================================================

void insertHead(int x){
    struct Node *newNode = *CreateNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertFoot(int x){
    struct Node *aux = head;
    struct Node *newNode = *CreateNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = newNode;
    newNode->prev = aux;
}

void Print(){
    struct Node *aux = head;
    printf("Forward: ");
    while(temp != NULL){
        printf("%d\n",aux->data);
        aux = aux->next;
    }
}
