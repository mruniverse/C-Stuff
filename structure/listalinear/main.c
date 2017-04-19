#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void insertHead(int);
void insertFoot(int);
void Print();
void ReversePrint();
void DeleteNode(int);

int main(){
    Print();
    insertHead(4);
    insertHead(5);
    insertHead(6);
    insertHead(8);
    insertHead(10);
    insertHead(100);
    // DeleteNode(10);
    Print();
    DeleteNode(10);
    ReversePrint();


    return 0;
}
