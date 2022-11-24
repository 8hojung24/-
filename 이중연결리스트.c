#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyListNodeType {
    int data;
    struct DoublyListNodeType * pLLink;
    struct DoublyListNodeType * pRLink;
}DoublyListNode;

typedef struct DoublyListType{
    int currentCount;
    DoublyListNode headerNode;
}DoublyList;

DoublyList * createDoublyList(){
    DoublyList *pReturn = (DoublyList *)malloc(sizeof(DoublyList));
    if (pReturn !=NULL){
        memset(pReturn, 0, sizeof(DoublyList));

        pReturn->headerNode.pLLink=&(pReturn->headerNode);
        pReturn->headerNode.pRLink=&(pReturn->headerNode);
    }
}