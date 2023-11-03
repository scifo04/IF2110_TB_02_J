/* File : temanreq.c */
/* Definisi ADT Priority Queue Popularity dengan representasi Struktur Berkait */
/* Elemen queue terurut membesar berdasarkan popularitas */

#include <stdio.h>
#include <stdlib.h>
#include "temanreq.h"

/* ********* Prototype ********* */
/* Prototype manajemen memori */
Address newRequest(ElType x){
    Address a;
    a = (Address) malloc(sizeof(Node));
    if (a != NULL) {
        INFO(a) = val;
        NEXT(a) = NULL;
    } else {
        printf("Aw, Snap! Maaf, alokasi memori gagal.");
    }
    return a;
}

boolean isEmpty(Queue q){
    return ADDR_HEAD(q)==NULL && ADDR_TAIL(q)=NULL;
}

int length(Queue q){
    Address a;
    int i = 1;
    a = ADDR_HEAD(q);
    if (ADDR_HEAD(q) == NULL) {
        return 0;
    } else {
        while (NEXT(a) != NULL) {
            i += 1;
            a = NEXT(a);
        }
    }
    return i;
}

/*** Kreator ***/
void CreateQueue(Queue *q){
    ADDR_HEAD(*q)=NULL;
    ADDR_TAIL(*q)=NULL;
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x){
    Address p = newNode(x);
    if(p!=NULL){
        Address loc = ADDR_HEAD(*q);
        while( POPULARITY(p)<POPULARITY(loc) && NEXT(loc)!=NULL){
            loc = NEXT(loc);  
        }
        NEXT(p)=NEXT(loc);
        NEXT(loc)=p;
    }
}
void dequeue(Queue *q, ElType *x){
    Address p = ADDR_HEAD(*l);
    *x = INFO(p);
    ADDR_HEAD(*l)= NEXT(p);
    free(p);
}


/* Operasi Tambahan */
void displayFriendRequests (Queue q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
