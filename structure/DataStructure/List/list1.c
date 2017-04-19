#include <stdio.h>
#include <stdlib.h>

#define max 50

struct write{
    int key;
};

struct list{
    struct write list[max];
    int i; //conta o numero de elementos
};


void startList(struct list*);
int size(struct list);
void showList(struct list);
int sequencialSearch(struct list*, int);
int insertElements(struct list*, struct write, int);
void restart(struct list*);

int main(){
    struct list l;
    struct write r;
    r.key = 10;
    startList(&l);
    insertElements(&l, r,0);
    r.key = 20;
    insertElements(&l, r,1);
    showList(l);

    return 0;
}



// A função abaixo recebe um inteiro x e um vetor
// crescente v[0..n-1]. Ela devolve um índice m
// tal que v[m] == x ou devolve -1 se tal m não
// existe.
binarySearch (int x, int n, int v[]) {
   int e, m, d;
   e = 0; d = n-1;
   while (e <= d){
      m = (e + d)/2;
      if (v[m] == x){
          return m;
      }
      if (v[m] < x){
          e = m + 1;
      }
      else{
          d = m - 1;
      }
   }
   return -1;
}

//==========================================================
void startList(struct list *l){
    l -> i = 0;
}
//==========================================================
int size(struct list l){
    return(l.i);
}
//==========================================================
void showList(struct list l){
    printf("List: \n");
    for(int c = 0; c < l.i; c++){
        printf("%d \n", l.list[c].key);
    }
}
//==========================================================
int sequencialSearch(struct list *l, int k){
      int c=0;
      while(c < l -> i){
        if(k == l->list[c].key){
          return c;
        }
        else{
          c++;
        }
      }
      return -1;
}
//==========================================================
int insertElements(struct list *l, struct write r, int c){
      int j;
      if( (c < 0) || (c > l->i) || (l->i == max) ){
        return -1;
      }
      for(j = l->i; j > c; j--){
        l->list[j] = l->list[j-1];
      }
      l->list[c] = r;
      l->i++;

      return 0;
}
//==========================================================
int deleteElements(int k, struct list *l){
      int pos;
      int j;

      pos = sequencialSearch(l, k);
      if(pos == -1){
        return -1;
      }
      for(j = pos; j < l->i-1; j++){
        l->list[j] = l->list[j+1];
      }
      l->i--;
      return 0;
}
//==========================================================
void restart(struct list *l){
    l->i=0;
}
//==========================================================
