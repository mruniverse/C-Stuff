//======================================================================================
//======================================================================================
//                       Disciplina de Estrutura de Dados
//                       Profa. Tamara Ang�lica Baldo
//======================================================================================
//======================================================================================


#include <stdio.h>
#include <stdlib.h>

//======================================================================================
//                       Disciplina de Estrutura de Dados
//                       Profa. Tamara Ang�lica Baldo
//======================================================================================
//Lista linear: estrutura de dados na qual cada elemento � precedido por um elemento e
//sucedido por outro (exceto o primeiro, que n�o tem predecessor, e o �ltimo, que n�o tem
//sucessor). E, ainda, os elementos est�o em uma dada ordem (por exemplo: a mesma ordem em
//que foram inclu�dos, ou ordenados de acordo com a chave).
//--------------------------------------------------------------------------------------
// Lista linear sequencial: � uma lista linear na qual a ordem l�gica dos elementos (a
//ordem �vista�pelo usu�rio) � a mesma ordem f�sica (em mem�ria principal) dos elementos.
//Elementos vizinhos na lista estar�o em posi��es vizinhas de mem�ria. Utiliza-se bastante
//ao se trabalhar com arranjo/array
//======================================================================================
//======================================================================================
//Lista linear sequencial � Modelagem:
//- Modelaremos utilizando arranjo de registros;
//- Registros conter�o as informa��es de interesse do usu�rio;
//- Nosso arranjo ter� um tamanho fixo controlaremos o n�mero de elementos como uma vari�vel adicional.
//======================================================================================
//Fun��es de gerenciamento a ser implementadas:
//-Inicializar a estrutura
//-Retornar a quantidade de elementos v�lidos
//-Exibir os elementos da estrutura
//-Buscar um elemento na estrutura
//-Inserir elemento na estrutura
//-Excluir elementos da estrutura
//-Reinicializar a estrutura
//======================================================================================

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
     TIPOCHAVE chave;
     //outros dados podem ser inseridos aqui
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int nroElem;
}LISTA;


//Prot�tipo das fun��es e procedimentos
void inicializaLista(LISTA*);
int tamanho(LISTA*);
void exibirLista(LISTA*);
int buscaSequencial(LISTA*, TIPOCHAVE);
int inserirElemLista(LISTA*, REGISTRO, int);
int excluirElemLista(TIPOCHAVE, LISTA*);
void reinicializacao(LISTA*);



//======================================================================================
//Lista linear: estrutura de dados na qual cada elemento � precedido por um elemento e
//sucedido por outro (exceto o primeiro, que n�o tem predecessor, e o �ltimo, que n�o tem
//sucessor). E, ainda, os elementos est�o em uma dada ordem (por exemplo: a mesma ordem em
//que foram inclu�dos, ou ordenados de acordo com a chave).
//--------------------------------------------------------------------------------------
// Lista linear sequencial: � uma lista linear na qual a ordem l�gica dos elementos (a
//ordem �vista�pelo usu�rio) � a mesma ordem f�sica (em mem�ria principal) dos elementos.
//Elementos vizinhos na lista estar�o em posi��es vizinhas de mem�ria. Utiliza-se bastante
//ao se trabalhar com arranjo/array
//======================================================================================
//======================================================================================
//Lista linear sequencial � Modelagem:
//- Modelaremos utilizando arranjo de registros;
//- Registros conter�o as informa��es de interesse do usu�rio;
//- Nosso arranjo ter� um tamanho fixo controlaremos o n�mero de elementos como uma vari�vel adicional.
//======================================================================================
//Fun��es de gerenciamento a ser implementadas:
//-Inicializar a estrutura
//-Retornar a quantidade de elementos v�lidos
//-Exibir os elementos da estrutura
//-Buscar um elemento na estrutura
//-Inserir elemento na estrutura
//-Excluir elementos da estrutura
//-Reinicializar a estrutura
//======================================================================================



//**************************************************************************************
// Inicializar a estrutura: Para inicializar uma estrutura qualquer, precisa pensar nos
// valores adequados para cada um dos campos da estrutura
//                            void inicializaLista(LISTA *l)
//**************************************************************************************
void inicializaLista(LISTA *l){
    l->nroElem = 0;
}



//**************************************************************************************
// Retornar a quantidade de elementos v�lidos: pra esta estrutura deve-se retornar nroElem
//                                  int tamanho(LISTA *l)
//**************************************************************************************
int tamanho(LISTA *l){
    return l->nroElem;
}


//**************************************************************************************
//Exibir os elementos da estrutura: para exibir os elementos da estrutura precisamos
//iterar pelos elementos v�lidos e, por exemplo, imprimir suas chaves
//                               void exibirLista(LISTA *l)
//**************************************************************************************
void exibirLista(LISTA *l){
     int i;
     printf("Lista: \" ");
     for(i=0; i<l->nroElem; i++)
         printf("%i ", l->A[i].chave);
     printf("\"\n");
}



//**************************************************************************************
//Busca por elemento: a fun��o deve conter:
//-receber uma chave do usu�rio
//-retornar a posi��o em que este elemento se encontra na lista (caso seja encontrado)
//-retornar -1 caso n�o haja um registro com essa chave na lista
//                int buscaSequencial(LISTA *l, TIPOCHAVE ch)
//**************************************************************************************
int buscaSequencial(LISTA *l, TIPOCHAVE ch){
    int i=0;
    while(i < l->nroElem){
        if( ch == l->A[i].chave) return i;
        else i++;
    }
    return -1;
}



//**************************************************************************************
//Inserir elemento na estrutura: O usu�rio passa como par�metro um registro a ser inserido
//na lista. H� diversas possibilidades de inser��o:
//-no in�cio
//-no final
//-ordenada pela chave
//-numa posi��o indicada pelo usu�rio
//Como inserir? Se a lista n�o estiver cheia e o �ndice passado pelo usu�rio for v�lido,
//desloca-se todos os elementos posteriores para a direita e insere o elemento na posi��o
//desejada, soma-se uma unidade no campo nroElem e retorna true. Caso contr�rio false.
//OBS: Padr�o ANSI C n�o aceita bool
//             bool inserirElemLista(LISTA *l, REGISTRO reg, int i)
//**************************************************************************************
int inserirElemLista(LISTA *l, REGISTRO reg, int i){
   int j;
   if( (i<0) || (i>l->nroElem) || (l->nroElem ==MAX))
       return -1;
   for( j = l->nroElem; j > i; j--)  l->A[j] = l->A[j-1];
   l->A[i] = reg;
   l->nroElem++;
   return 0;
}


//**************************************************************************************
//Exclus�o de um elemento: o usu�rio passa a chave do elemento que ele quer excluir.
//Se houver um elemento com esta chave na lista se exclui este elemento, desloca todos
//os elementos posteriores uma posi��o � esquerda, diminui o nroElem e retorna true.
//Caso contr�rio, retorna false.
//                 bool excluirElemLista(TIPOCHAVE ch, LISTA *l)
//**************************************************************************************
int excluirElemLista(TIPOCHAVE ch, LISTA *l){
   int pos, j;
   pos = buscaSequencial( l, ch);
   if(pos == -1)  return -1;
   for( j = pos; j< l->nroElem-1; j++)  l->A[j] = l->A[j+1];
   l->nroElem--;
   return 0;
}



//**************************************************************************************
//Reinicializa��o da lista: pra esta estrutura, reinicializar a lista basta zerar o nroElem
//                       void reinicializa��o(LISTA *l)
//**************************************************************************************
void reinicializacao(LISTA *l){
    l->nroElem=0;
}
