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
    if(p!=NULL){
        if (isEmptyQueueFR(*q)){
            ADDR_HEAD(*q)= p;
        }
        else if(POPULARITYN(p)>POPULARITYN(loc)){ // cek indeks pertama
            NEXT(p)=loc;
            ADDR_HEAD(*q)= p;

        } else  { // cek indeks setelah pertama dan seterusnya
            while(POPULARITYN(p)<=POPULARITYN(loc) && NEXT(loc)!=NULL){
                prec = loc;
                loc = NEXT(loc);  
            }
            if(NEXT(loc)==NULL){NEXT(loc)=p;}
            else {
                NEXT(prec)=p;
                NEXT(p)=loc;
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
    while (ID_REQUESTERN(a) != idRequester && NEXT(a) != NULL) {
        i += 1;
        a = NEXT(a);
    }
    if (ID_REQUESTERN(a) == idRequester) {
        return i;
    } else {
        return -1;
    }
}


/* Daftar Permintaan Pertemanan*/
void displayFriendRequests (QueueFR q, ListAcc acc){
    int requests, idRequester; Word name;
    if(isEmptyQueueFR(q)){
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    } else{
        requests = length_QueueFR(q);
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", requests);
        printf("\n");
        Address a = ADDR_HEAD(q);
        while(a != NULL){
            idRequester = ID_REQUESTERN(a);
            printf("idreq = %d\n",  idRequester);
            name = getUsernamebyID(acc, idRequester);
            printf("| ");
            printWord(name);
            printf("\n");
            printf("| Jumlah teman: %d\n", POPULARITYN(a));
            printf("\n");

            a = NEXT(a);
        }
    }   
}

void CreateFriendRequest(FriendRequest *FR, int idRequester, int idRequested, Affection friends){
    ID_REQUESTER(*FR) = idRequester;
    ID_REQUESTED(*FR) = idRequested;
    POPULARITY(*FR) = countFriends_Affection(friends, idRequester);
}

/* Tambah Teman*/
void addFriend(QueueFR qSelf, QueueFR *qRequested, ListAcc acc, Account currentuser, Affection friends){
    /* KAMUS LOKAL */
    Word nameReq;
    int idRequested, idRequester;
    FriendRequest FR;

    /* ALGORITMA */
    /* Check if friend request QueueFR of currentacc is empty */
    if(!isEmptyQueueFR(qSelf)){
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    } else {
        /* Insert username of friend to be requested*/
        printf("Masukkan nama pengguna:\n");
        STARTWORD();
        printf("\n");
        nameReq = currentWord;

        /* Check if username exist*/
        if(nameAvailable(acc, nameReq)){
            /* Check if request has actually been sent*/
            idRequested = getIdx_Username(acc, nameReq);
            idRequester = getIdx_Account(acc, currentuser);
            if(indexOfQueueFR(*qRequested, idRequester)!=-1){
                CreateFriendRequest(&FR, idRequester, idRequested, friends);
                enQueueFR(qRequested, FR);

                printf("Permintaan pertemanan kepada ");
                printWord(nameReq);
                printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.");
            } else {
                printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
                printWord(nameReq);
                printf(". Silakan tunggu hingga permintaan Anda disetujui.");
            }  
        } else {
            printf("Pengguna bernama ");
            printWord(nameReq);
            printf(" tidak ditemukan.\n");
        }
    }
}

/* Setujui Pertemanan */
void processRequest(QueueFR *q, Affection friends, ListAcc acc){
    if(isEmptyQueueFR(*q)){
        printf("Tidak terdapat permintaan pertemanan untuk Anda.\n");
    } else{
        /*Menampilkan Permintaan Pertemanan Teratas*/
        FriendRequest topRequest; int idRequested, idRequester;
        deQueueFR(q, &topRequest);
        idRequester = ID_REQUESTER(topRequest);
        idRequested = ID_REQUESTED(topRequest);
        Word name = getUsernamebyID(acc, idRequester);
        printf("Permintaan pertemanan teratas dari ");
        printWord(name);
        printf("\n");
        printf("\n");

        printf("| ");
        printWord(name);
        printf("\n");
        printf("| Jumlah teman: %d\n", POPULARITY(topRequest));
        printf("\n");

        /* Pilihan Persetujuan */
        Word choice;
        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) \n");
        STARTWORD();
        choice = currentWord;

        /* Proses Persetujuan */
        if(isWordSimilar(choice, "YA")){
            convertAffection(&friends, idRequester, idRequested);

            printf("Permintaan pertemanan dari ");
            printWord(name);
            printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
            printWord(name);
            printf(".\n");
        } else if(isWordSimilar(choice, "TIDAK")){
            printf("Permintaan pertemanan dari ");
            printWord(name);
            printf(" telah ditolak.");
        } else {
            printf("Masukkan salah.\n");
        }
    }
}
