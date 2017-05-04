#include <stdio.h>
#include <stdlib.h>

//==========================================================
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head;

struct Node *CreateNode(int x){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
};
//==========================================================
void insertHead(int x){
    struct Node *newNode = CreateNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
//==========================================================
void insertFoot(int x){
    struct Node *aux = head;
    struct Node *newNode = CreateNode(x);
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
//==========================================================
void Print(){
    struct Node *aux = head;

    if(head == NULL){
        printf("EMPTY\n");
        return;
    }

    printf("Forward: \n");
    while(aux != NULL){
        printf("%d\n",aux->data);
        aux = aux->next;
    }
}
//==========================================================
void ReversePrint(){
    struct Node *aux = head;
    if(aux == NULL){
        printf("EMPTY\n");
        return;
    }
    while(aux->next != NULL){
        aux = aux->next;
    }
    printf("Backwords:\n");
    while(aux != NULL){
        printf("%d\n",aux->data);
        aux = aux->prev;
    }
}
//==========================================================
void DeleteNode(int data){
    struct Node *auxNext, *auxPrev;
    struct Node *aux = head;

    if(aux == NULL){
        printf("EMPTY\n");
        return;
    }

    while(aux != NULL && aux->data != data){
        aux = aux->next;
    }

    if(aux == NULL){
        printf("There's no such thing...\n");
        return;
    }

    printf("Found it!\n");

    auxNext = aux->next;
    auxPrev = aux->prev;
    auxNext->prev = auxPrev;
    auxPrev->next = auxNext;

    printf("Done!\n");
}
//==========================================================
void insertOrderly(int x){
    struct Node *newNode = CreateNode(x);
    if(head == NULL){
        head == newNode;
        return;
    }

}
//==========================================================
