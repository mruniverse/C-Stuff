#include <stdio.h>
#include <stdlib.h>

int main(){
  int *y = (int*) malloc(sizeof(int));

  if(y==NULL){
    printf("\n\n Não alocou memoria corretamente");
    return 1;
  }

  printf("%d\n",*y);
  *y = 20;
  printf("%d\n",*y);

  free(y);
  y = NULL;


  return 0;
}
