#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void insertHead(int);
void insertFoot(int);
void Print();
void ReversePrint();

int main(){
    Print();
    insertHead(4);
    insertHead(5);
    insertHead(6);
    insertHead(8);
    insertHead(10);
    insertHead(100);
    Print();
    ReversePrint();


    return 0;
}
