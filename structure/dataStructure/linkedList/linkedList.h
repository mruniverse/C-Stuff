#include <stdio.h>
#include <stdlib.h>

struct  Node{
    struct Node *next;
    int data;
}

struct Node *head;

struct Node *CreateNode(int x){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
};

void deleteEvenNodes(){
    struct Node *auxNext;
    struct Node *aux = head;

    while(aux != NULL){
        if(aux == NULL){
            printf("EMPTY\n");
            return;
        }

        if(aux->data%2 == 0){
            aux->next = aux;
        }

        while(aux != NULL && aux->data%2 != 0){
            if(aux->next != NULL && aux->next->data%2 == 0){
                break;
            }
            aux = aux->next;
        }

        auxNext = aux->next;
        aux->next = auxNext->next;
    }
}
