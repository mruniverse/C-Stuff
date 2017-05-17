int junta_listas(LISTA *l1, LISTA *l2, LISTA3 *l3){
    int i1=0, i2=0, i3=0;
    while(i1<l1->numElem && i2<l2->numElem){
        if(l1->A[i1] == l2->A[i2]){
            l3->A[i3++]=l2->A[i2++];
            i1++;
        }
        else if(l1->A[i1] < l2->A[i2]){
            l3->A[i3++]=l1->A[i1++];
        }
        else {
            l3->A[i3++]=l2->A[i2++];
        }
    }
    if(i1>=l1->numElem) while(i2<l2->numElem){
        l3->A[i3++]=l2->A[i2++];
    }
    if(i2>=l2->numElem) while(i1<l1->numElem){
        l3->A[i3++]=l1->A[i1++];
    }
    l3->numElem=i3;
    return 0;
}
