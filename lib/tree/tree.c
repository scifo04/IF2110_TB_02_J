#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*KONSTRUKTOR*/
void CreateTree(Tree *T){
    Root(*T) = NULL;
}

/* *** Manajemen Memory *** */
addressTree Alokasi(int id, Word username, DATETIME d, Word message){
    addressTree P = (addressTree) malloc(sizeof(tNode));
    if(P != NULL){
        Id(P) = id;
        User(P).Length = username.Length;
        for (int i = 0; i < username.Length; i++) {
            User(P).TabWord[i] = username.TabWord[i];
        }
        Datetime(P) = d;
        Pesan(P).Length = message.Length;
        for (int i = 0; i < message.Length; i++) {
            Pesan(P).TabWord[i] = message.TabWord[i];
        }
        FirstChild(P) = NULL;
        NextSibling(P) = NULL;
    }
    return P;
}

void Dealokasi(addressTree P){
    free(P);
}


void AddChild(addressTree *P, addressTree C){
    if(*P == NULL){
        *P = C;
    }else{
        addressTree Q = *P;
        while(FirstChild(Q) != NULL){
            Q = FirstChild(Q);
        }
        FirstChild(Q) = C;
    }
}

void AddSibling(addressTree *P, addressTree S){
    if(*P == NULL){
        *P = S;
    }else{
        addressTree Q = *P;
        while(NextSibling(Q) != NULL){
            Q = NextSibling(Q);
        }
        NextSibling(Q) = S;
    }
}

void deleteTree(addressTree P) {
    if (P != NULL) {
        deleteTree(FirstChild(P));
        NextSibling(P) = NULL;
        FirstChild(P) = NULL;
        free(P);
    }
}

void printTree(addressTree P, int h){
    if(P != NULL){
        int i;
        printf("\n");
        for(i = 0; i < h; i++){
            printf("    ");
        }
        printf("| %d", Id(P));

        printf("\n");
        for(i = 0; i < h; i++){
            printf("    ");
        }
        printf("| ");
        printWord(User(P));

        printf("\n");
        for(i = 0; i < h; i++){
            printf("    ");
        }
        printf("| ");
        TulisDATETIME(Datetime(P));

        printf("\n");
        for(i = 0; i < h; i++){
            printf("    ");
        }
        printf("| ");
        printWord(Pesan(P));
        printf("\n");

        printTree(FirstChild(P), h+1);
        printTree(NextSibling(P), h);
    }
}

boolean isIdTreeElmt (addressTree P, int id){
    if(P != NULL){
        if(Id(P) == id){
            return true;
        }else{
            return isIdTreeElmt(FirstChild(P), id) || isIdTreeElmt(NextSibling(P), id);
        }
    }else{
        return false;
    }
}

// return address before Q with the root is P
addressTree getAddressBefore (addressTree P, addressTree Q){
    if(P != NULL){
        if(NextSibling(P) == Q){
            return P;
        }
        else if (FirstChild(P) == Q) {
            return P;
        }
        else{
            addressTree R = getAddressBefore(FirstChild(P), Q);
            if(R != NULL){
                return R;
            }
            else {
                addressTree R = getAddressBefore(NextSibling(P), Q);
            }
        }
    }
    else {
        return NULL;
    }
}
// Return addressTree with same input id
addressTree getAddressWithId(addressTree P, int id) {
    if (P != NULL) {
        if (Id(P) == id) {
            return P;
        }
        else {
            addressTree Q = getAddressWithId(FirstChild(P), id);
            if (Q != NULL) {
                return Q;
            }
            else {
                return getAddressWithId(NextSibling(P), id);
            }
        }
    }
    else {
        return NULL;
    }
}