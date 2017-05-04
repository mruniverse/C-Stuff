#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

struct registro{
     TIPOCHAVE chave;
};

struct elemento{
    struct registro reg;
    struct elemento* prox;
};

struct lista_circular{
    struct elemento* cabeca;
};

void inicializaLista(struct lista_circular*);

//==============================================================================
void inicializaLista(struct lista_circular *l){
    l->cabeca = (struct elemento*) malloc(sizeof(struct elemento));
    l->cabeca->prox = l->cabeca;
}
//==============================================================================
int quantidadeElementos(struct lista_circular *l){
   struct elemento* aux = l->cabeca->prox;
   int i = 0;
   while(aux != l->cabeca){
      i++;
      aux = aux->prox;
      printf("%d\n",l->reg);
   }
   return i;
}
//==============================================================================
