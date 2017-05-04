#include <stdio.h>
#include <stdlib.h>

#define MAX 50;

typedef int TIPOCHAVE;

struct registro{
    TIPOCHAVE chave;
};

struct elemento{
    struct registro reg;
    int prox;
};

struct lista{
    struct elemento A[MAX];
    int inicio;
    int dispo;
};

//==============================================================================
void inicializaLista(struct lista* l){
    for(int i = 0; i < MAX-1; i++){
        l->A[i].prox = i+1;
    }
    l->A[i].prox = -1;
    l->dispo = 0;
    l->inicio = -1;
}
//==============================================================================
int quantidadeElementos(struct lista* l){
    int l = l->inicio;
    int i = 0;
    while(i != -1){
        i++;
        i = l->A[i].prox;
    }
    return i;
}
//==============================================================================
void retornarNum(struct lista* l, int i){
    l->A[i].prox = l->dispo;
    l->dispo = i;
}
//==============================================================================
int excluirElemento(struct lista* l, TIPOCHAVE c){
    int aux = -1;
    int i = l->inicio;

    if(l->dispo == -1){
        return -1;
    }

    while(l != -1 && l-> A[i].reg.chave < c){
        aux = i;
        i=l->A[i].prox;
    }
    if(i == -1 || l->A[i].reg.chave != c){
        return -1;
    }
    if(aux == -1){
        l->inicio = l->A[i].prox;
    }
    else{
        l->A[aux].prox = l->A[i].prox;
        retornarNum(l, i);
        return 0;
    }
}
