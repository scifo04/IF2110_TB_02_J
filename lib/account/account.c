#include <stdio.h>
#include "account.h"

// DEFINED WORDS
Word copyWord_Pahing () {
    Word W;
    (W).TabWord[0] = 'P';
    (W).TabWord[1] = 'a';
    (W).TabWord[2] = 'h';
    (W).TabWord[3] = 'i';
    (W).TabWord[4] = 'n';
    (W).TabWord[5] = 'g';
    (W).Length = 6;
    return W;
}

Word copyWord_Legi () {
    Word W;
    (W).TabWord[0] = 'L';
    (W).TabWord[1] = 'e';
    (W).TabWord[2] = 'g';
    (W).TabWord[3] = 'i';
    (W).Length = 4;
    return W;
}

Word copyWord_Pon () {
    Word W;
    (W).TabWord[0] = 'P';
    (W).TabWord[1] = 'o';
    (W).TabWord[2] = 'n';
    (W).Length = 3;
    return W;
}

Word copyWord_Wage () {
    Word W;
    (W).TabWord[0] = 'W';
    (W).TabWord[1] = 'a';
    (W).TabWord[2] = 'g';
    (W).TabWord[3] = 'e';
    (W).Length = 4;
    return W;
}

Word copyWord_Kliwon () {
    Word W;
    (W).TabWord[0] = 'K';
    (W).TabWord[1] = 'l';
    (W).TabWord[2] = 'i';
    (W).TabWord[3] = 'w';
    (W).TabWord[4] = 'o';
    (W).TabWord[5] = 'n';
    (W).Length = 6;
    return W;
}

Word copyWord_YA () {
    Word W;
    (W).TabWord[0] = 'Y';
    (W).TabWord[1] = 'A';
    (W).Length = 2;
    return W;
}

Word copyWord_TIDAK () {
    Word W;
    (W).TabWord[0] = 'T';
    (W).TabWord[1] = 'I';
    (W).TabWord[2] = 'D';
    (W).TabWord[3] = 'A';
    (W).TabWord[4] = 'K';
    (W).Length = 5;
    return W;
}
// DEFINED WORDS

Pics CreateBlankPicture () {
    Pics P;
    int i,j;
    for (i = 0; i < 5; i++) {
        PICROW(P,i,0) = 'R';PICROW(P,i,1) = ' ';PICROW(P,i,2) = '*';PICROW(P,i,3) = ' ';
        PICROW(P,i,4) = 'R';PICROW(P,i,5) = ' ';PICROW(P,i,6) = '*';PICROW(P,i,7) = ' ';
        PICROW(P,i,8) = 'R';PICROW(P,i,9) = ' ';PICROW(P,i,10) = '*';PICROW(P,i,11) = ' ';
        PICROW(P,i,12) = 'R';PICROW(P,i,13) = ' ';PICROW(P,i,14) = '*';PICROW(P,i,15) = ' ';
        PICROW(P,i,16) = 'R';PICROW(P,i,17) = ' ';PICROW(P,i,18) = '*';PICROW(P,i,19) = '\n';
    }
    return P;
}
void CreateAccount (Account *A) {
    (*A).username.Length = 0;
    (*A).password.Length = 0;
    (*A).bio.Length = 0;
    (*A).phone_num.Length = 0;
    (*A).weton.Length = 0;
    (*A).photo = CreateBlankPicture();
    (*A).publicity = true;
    CreateQueueFR(&(*A).requests);
}

void readUsername(Account *A) {
    printf("Masukkan nama: ");
    printf("\n");
    STARTWORD();
    printf("\n");
    (*A).username = currentWord;
}

void readPassword(Account *A) {
    printf("Masukkan kata sandi: ");
    printf("\n");
    STARTWORD();
    printf("\n");
    (*A).password = currentWord;
}

void readBio (Account *A) {
    Word W;
    printf("Masukkan Bio Akun: ");
    printf("\n");
    STARTWORD();
    printf("\n");
    W = currentWord;
    if (W.Length > 135) {
        while (W.Length > 135) {
            printf("Panjang banget mas. Orang males baca. Masukkan Bio Akun: ");
            printf("\n");
            STARTWORD();
            printf("\n");
            W = currentWord;
        }
    }
    (*A).bio = W;
}

void readPhone_Num (Account *A) {
    Word W;
    printf("Masukkan No.HP: ");
    printf("\n");
    STARTWORD();
    printf("\n");
    W = currentWord;
    if (!(intCheck(W))) {
        while (!(intCheck(W))) {
            printf("Angka aja ya Nomor HP-nya. Masukkan No.HP: ");
            printf("\n");
            STARTWORD();
            printf("\n");
            W = currentWord;
        }
    }
    (*A).phone_num = W;
}
void readWeton (Account *A) {
    Word W;
    printf("Masukkan Weton: ");
    printf("\n");
    STARTWORD();
    printf("\n");
    W = currentWord;
    if ((wordSimilarCI(W,copyWord_Kliwon()) || wordSimilarCI(W,copyWord_Legi()) || wordSimilarCI(W,copyWord_Pon()) || wordSimilarCI(W,copyWord_Pahing()) || wordSimilarCI(W,copyWord_Wage()))) {
        /* NOTHING */
    } else {
        while (!((wordSimilarCI(W,copyWord_Kliwon()) || wordSimilarCI(W,copyWord_Legi()) || wordSimilarCI(W,copyWord_Pon()) || wordSimilarCI(W,copyWord_Pahing()) || wordSimilarCI(W,copyWord_Wage())))) {
            printf("Weton tidak valid. Masukkan kembali Weton: ");
            printf("\n");
            STARTWORD();
            printf("\n");
            W = currentWord;
        }
    }
    if (wordSimilarCI(W, copyWord_Kliwon())){PasteWord(copyWord_Kliwon(), &(A)->weton);}
    else if (wordSimilarCI(W, copyWord_Legi())){PasteWord(copyWord_Legi(), &(A)->weton);}
    else if (wordSimilarCI(W, copyWord_Pon())){PasteWord(copyWord_Pon(), &(A)->weton);}
    else if (wordSimilarCI(W, copyWord_Pahing())){PasteWord(copyWord_Pahing(), &(A)->weton);}
    else {PasteWord(copyWord_Wage(), &(A)->weton);}
}
void readPhoto (Account *A) {
    int i,j;
    Word W;
    Pics P;
    printf("Masukkan Foto Akun: ");
    printf("\n");
    STARTWORD();
    printf("\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 20; j++) {
            PICROW((*A).photo,i,j) = currentWord.TabWord[(20*i) + j];
        }
    }
}

void displayPhoto (Pics P) {
    int i,j;
    int color_offset;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 20; j++) {
            if (PICROW(P,i,j) == 'R') {
                color_offset = 1;
            } else if (PICROW(P,i,j) == 'B') {
                color_offset = 2;
            } else if (PICROW(P,i,j) == 'G') {
                color_offset = 3;
            } else if (PICROW(P,i,j) == '\n') {
                printf("\n");
            } else if (PICROW(P,i,j) == ' ') {
                // NOTHING
            } else {
                print_color(PICROW(P,i,j),color_offset);
            }
        }
    }
}
void change_publicity (Account *A) {
    if ((*A).publicity == true) {
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK) ");
        STARTWORD();
        if (wordSimilar(currentWord,copyWord_YA())) {
            (*A).publicity = false;
            printf("\n");
            printf("Akun anda sudah diubah menjadi akun Privat.");
            printf("\n");
        }
    } else {
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK) ");
        STARTWORD();
        if (wordSimilar(currentWord,copyWord_YA())) {
            (*A).publicity = true;
            printf("\n");
            printf("Akun anda sudah diubah menjadi akun Publik.");
            printf("\n");
        }
    }
}

void displayAccount(Account A) {
    printf("[");
    printWord(A.username);
    printf(",");
    printWord(A.password);
    printf(",");
    printWord(A.bio);
    printf(",");
    printWord(A.phone_num);
    printf(",");
    printWord(A.weton);
    printf("]");
}

void CreateListAccount (ListAcc *L) {
    (*L).NEff = 0;
}

boolean isEmpty_Account (ListAcc L) {
    return L.NEff == 0;
}

boolean isFull_Account (ListAcc L) {
    return L.NEff == 20;
}

int length_Account (ListAcc L) {
    return L.NEff;
}

Account getElmt_Account (ListAcc L, int idx) {
    return L.buffer[idx];
}

int getIdx_Account (ListAcc L, Account A) {
    int i;
    for (i = 0; i < length_Account(L); i++) {
        if (wordSimilar(L.buffer[i].username,A.username) && wordSimilar(L.buffer[i].password,A.password)) {
            return i;
        }
    }
    return IDX_ACCOUNT_UNDEF;
}

void setElmt_Account (ListAcc *L, int idx, Account A) {
    (((*L).buffer)[idx]).username = A.username;
    (((*L).buffer)[idx]).password = A.password;
    (((*L).buffer)[idx]).bio = A.bio;
    (((*L).buffer)[idx]).phone_num = A.phone_num;
    (((*L).buffer)[idx]).weton = A.weton;
    (((*L).buffer)[idx]).photo = A.photo;
    (((*L).buffer)[idx]).publicity = A.publicity;
    (((*L).buffer)[idx]).requests = A.requests;
}

void insertLast_Account (ListAcc *L, Account A) {
    if (!isFull_Account(*L)) {
        setElmt_Account(&(*L),length_Account(*L),A);
        (*L).NEff += 1;
    }
}

void displayList_Account (ListAcc L) {
    int i;
    printf("[");
    if (!isEmpty_Account(L)) {
        for (i = 0; i < length_Account(L)-1; i++) {
            displayAccount(L.buffer[i]);
            printf(",");
        }
        displayAccount(L.buffer[length_Account(L)-1]);
    }
    printf("]");
}

boolean nameAvailable (ListAcc L, Word U) {
    int i;
    boolean check = false;
    for (i = 0; i < length_Account(L); i++) {
        if (wordSimilar(U,L.buffer[i].username)) {
            check = true;
            return check;
        }
    }
    return check;
}

boolean passAvailable (ListAcc L, Word U) {
    int i;
    boolean check = false;
    for (i = 0; i < length_Account(L); i++) {
        if (wordSimilar(U,L.buffer[i].password)) {
            check = true;
            return check;
        }
    }
    return check;
}

int getIdx_Username(ListAcc L, Word U){
    int i;
    for (i = 0; i < length_Account(L); i++) {
        if (wordSimilar(U,L.buffer[i].username)) {
            return i;
        }
    }
    return IDX_ACCOUNT_UNDEF;
}

Word getUsernamebyID (ListAcc L, int id){
    return L.buffer[id].username;
}


boolean getPublicitybyUsername(ListAcc L, Word username){
    int i;
    for (i = 0; i < length_Account(L); i++) {
        if (wordSimilar(L.buffer[i].username, username)) {
            return L.buffer[i].publicity;
        }
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
            name = getElmt_Account(acc, idRequester).username;
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
void addFriend(Word name, int id, QueueFR *qRequested, ListAcc acc, Account currentuser, Affection friends){
    /* KAMUS LOKAL */
    FriendRequest FR;

    /* ALGORITMA */
    if(indexOfQueueFR(*qRequested, getIdx_Account(acc,currentuser))==-1){
        CreateFriendRequest(&FR, getIdx_Account(acc,currentuser), id, friends);
        enQueueFR(&(*qRequested), FR);

        printf("Permintaan pertemanan kepada ");
        printWord(name);
        printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.");
    } else {
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
        printWord(name);
        printf(". Silakan tunggu hingga permintaan Anda disetujui.");
    }
}

/* Setujui Pertemanan */
void processRequest(QueueFR *q, Affection *friends, ListAcc acc){
    if(isEmptyQueueFR(*q)){
        printf("Tidak terdapat permintaan pertemanan untuk Anda.\n");
    } else{
        /*Menampilkan Permintaan Pertemanan Teratas*/
        FriendRequest topRequest; int idRequested, idRequester;
        deQueueFR(q, &topRequest);
        idRequester = ID_REQUESTER(topRequest);
        idRequested = ID_REQUESTED(topRequest);
        Word name = getElmt_Account(acc, idRequester).username;
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
            convertAffection(&(*friends), idRequester, idRequested);

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