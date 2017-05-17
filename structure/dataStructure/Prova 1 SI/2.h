#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
    struct aux* anterior;
}ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}LISTA;

void iniciarLista(LISTA *l);
int tamanhoAndExibeLista(LISTA *l);
PONT inserirElemListaOrd(LISTA *l, REGISTRO reg);
int excluirMaiorElemLista(LISTA *l, TIPOCHAVE ch);
void reinicializaLista(LISTA *l);

void iniciarLista(LISTA *l){
    l->inicio=NULL;
    l->fim=NULL;

}

int tamanhoAndExibeLista(LISTA *l){
    PONT end=l->inicio;
    int tam=0;

    printf("\nLista: \" ");
    while(end!=NULL){
        printf("%d ", end->reg.chave);
        end=end->prox;
        tam++;
    }

    printf(" \"\n");
    return tam;
}

PONT inserirElemListaOrd(LISTA *l, REGISTRO reg){
    TIPOCHAVE ch=reg.chave;
    PONT ant,i;
    i=buscaSequencialExc(l,ch,&ant);
    if(i!=NULL) return -1;
    i= (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    i->prox=NULL;
    i->anterior=NULL;
    if (ant == NULL){
        i->prox = l->inicio;
        i->anterior=NULL;
        l->inicio = i;
        if(l->fim == NULL){
            l->fim=i;

        }
    }else if(ant == l->fim){
        i->anterior=l->fim;
        l->fim->prox=i;
        l->fim=i;
    }else{
        i->prox = ant->prox;
        i->anterior=ant;
        ant->prox->anterior=i;
        ant->prox=i;
    }
    return 0;
}

int excluirMaiorElemLista(LISTA *l, TIPOCHAVE ch){
    PONT ant, i;
    i=buscaSequencialExc(l,ch,&ant);
    if(i == NULL) return -1;
    if(ant == NULL){
        l->inicio = i->prox;
        l->inicio->anterior=NULL;

    }else if(l->fim==i) {
        ant->prox=NULL;
        l->fim=ant;

    }else{
        ant->prox = i->prox;
        ant->prox->anterior=i->anterior;
    }
    free(i);
    return 0;
}

void reinicializaLista(LISTA *l){
    PONT end = l->inicio;
    while(end!= NULL ){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
    l->fim = NULL;
}
