#include <stdio.h>

  struct structure1{
    int weight;
    int height;
  };


int main(){
  struct structure1 person;
  person.weight = 8500;
  person.height = 180;

  printf("Struct bytes: %lu\n",sizeof(person));

  printf(
    "Weigth: %d\n"
    "Height: %d\n",person.weight, person.height);


  return 0;
}
