/* File : temanreq.c */
/* Definisi ADT Priority Queue Popularity dengan representasi Struktur Berkait */
/* Elemen queue terurut membesar berdasarkan popularitas */

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

boolean isEmpty(Queue q){
    return ADDR_HEAD(q)==NULL && ADDR_TAIL(q)==NULL;
}

int length_queue(Queue q){
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
void enqueue(Queue *q, ELFRType x){
    Address loc = ADDR_HEAD(*q);
    Address p = newRequest(x);
    if(p!=NULL){
        if (isEmpty(*q)){
            ADDR_HEAD(*q)= p;
        }
        else if(POPULARITYN(p)>POPULARITYN(loc)){ // cek indeks pertama
            NEXT(p)=loc;
            ADDR_HEAD(*q)= p;
        } else  { // cek indeks setelah pertama dan seterusnya
            while( POPULARITYN(p)<POPULARITYN(NEXT(loc)) && NEXT(loc)!=NULL){
                loc = NEXT(loc);  
            }
            NEXT(p)=NEXT(loc);
            NEXT(loc)=p;
        }
    }
}
void dequeue(Queue *q, ELFRType *x){
    Address p = ADDR_HEAD(*q);
    *x = INFO(p);
    ADDR_HEAD(*q)= NEXT(p);
    NEXT(p) = NULL;
    free(p);
}

int indexOf(Queue q, int idRequester) {
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
void displayFriendRequests (Queue q, ListAcc acc){
    int requests; Word name;
    if(isEmpty(q)){
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    } else{
        requests = length_queue(q);
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", requests);
        printf("\n");
        Address a = ADDR_HEAD(q);
        while(NEXT(a)!=NULL){
            name = getUsernamebyID(acc, ID_REQUESTERN(a));
            printf("| ");
            printWord(name);
            printf("\n");
            printf("| Jumlah teman: %d\n", POPULARITYN(a));
            printf("\n");
        }
    }   
}

void CreateFriendRequest(FriendRequest *FR, int idRequester, int idRequested, Affection friends){
    ID_REQUESTER(*FR) = idRequester;
    ID_REQUESTED(*FR) = idRequested;
    POPULARITY(*FR) = countFriends_Affection(friends, idRequester);
}

/* Tambah Teman*/
void addFriend(Queue qSelf, Queue *qRequested, ListAcc acc, Account currentuser, Affection friends){
    /* KAMUS LOKAL */
    Word nameReq;
    int idRequested, idRequester;
    FriendRequest FR;

    /* ALGORITMA */
    /* Check if friend request queue of currentacc is empty */
    if(!isEmpty(qSelf)){
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
            if(indexOf(*qRequested, idRequester)!=-1){
                CreateFriendRequest(&FR, idRequester, idRequested, friends);
                enqueue(qRequested, FR);

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
void processRequest(Queue *q, Affection friends, ListAcc acc){
    if(isEmpty(*q)){
        printf("Tidak terdapat permintaan pertemanan untuk Anda.\n");
    } else{
        /*Menampilkan Permintaan Pertemanan Teratas*/
        FriendRequest topRequest; int idRequested, idRequester;
        dequeue(q, &topRequest);
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
