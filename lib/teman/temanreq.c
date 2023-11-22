/* File : temanreq.c */
/* Definisi ADT Priority QueueFR Popularity dengan representasi Struktur Berkait */
/* Elemen QueueFR terurut membesar berdasarkan popularitas */

#include <stdio.h>
#include <stdlib.h>
#include "temanreq.h"

/* ********* Prototype ********* */
/* Prototype manajemen memori */
Address newRequest(ELFRType x){
    Address a;
    a = (Address) malloc(sizeof(Node));
    if (a != NULL) {
        INFO(a) = x;
        NEXT(a) = NULL;
    } else {
        printf("Aw, Snap! Maaf, alokasi memori gagal.");
    }
    return a;
}

boolean isEmptyQueueFR(QueueFR q){
    return ADDR_HEAD(q)==NULL && ADDR_TAIL(q)==NULL;
}

int length_QueueFR(QueueFR q){
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
void CreateQueueFR(QueueFR *q){
    ADDR_HEAD(*q)=NULL;
    ADDR_TAIL(*q)=NULL;
}

/*** Primitif EnQueueFR/DeQueueFR ***/
void enQueueFR(QueueFR *q, ELFRType x){
    Address loc = ADDR_HEAD(*q);
    Address prec = NULL;
    Address p = newRequest(x);
    int i = 0;
    if(p!=NULL){
        if (isEmptyQueueFR(*q)){
            ADDR_HEAD(*q)= p;
        }
        else if(POPULARITYN(p)>POPULARITYN(loc)){ // cek indeks pertama
            NEXT(p)=loc;
            ADDR_HEAD(*q)= p;

        } else  { // cek indeks setelah pertama dan seterusnya
            if (NEXT(loc) != NULL) {
                while(POPULARITYN(p)<=POPULARITYN(loc) || NEXT(loc)!=NULL){
                    if (NEXT(loc) == NULL) {
                        break;
                    }
                    prec = loc;
                    loc = NEXT(loc);  
                }
            }
            if(NEXT(loc)==NULL && POPULARITYN(p) <= POPULARITYN(loc)) {
                NEXT(loc)=p;
            } else {
                NEXT(p)=loc;
                NEXT(prec)=p;
            }
        }
    }
}
void deQueueFR(QueueFR *q, ELFRType *x){
    Address p = ADDR_HEAD(*q);
    *x = INFO(p);
    ADDR_HEAD(*q)= NEXT(p);
    NEXT(p) = NULL;
    free(p);
}

int indexOfQueueFR(QueueFR q, int idRequester) {
    Address a;
    int i = 0;
    a = ADDR_HEAD(q);
    if (!isEmptyQueueFR(q)) {
        while (ID_REQUESTERN(a) != idRequester && NEXT(a) != NULL) {
            i += 1;
            a = NEXT(a);
        }
        if (ID_REQUESTERN(a) == idRequester) {
            return i;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

void displayQueueFR(QueueFR q) {
    Address a;
    a = ADDR_HEAD(q);
    printf("[");
    while (a != NULL) {
        printf("<%d,%d,%d>",ID_REQUESTED(INFO(a)),ID_REQUESTER(INFO(a)),POPULARITY(INFO(a)));
        if (NEXT(a) != NULL) {
            printf(",");
        }
        a = NEXT(a);
    }
    printf("]\n");
}