#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*KONSTRUKTOR*/
void CreateTree(Tree *T){
    Root(*T) = NULL;
}

/* *** Manajemen Memory *** */
addressTree Alokasi(int id, Word username, DATETIME d, Word message){
    addressTree P = (addressTree) malloc(sizeof(Node));
    if(P != NULL){
        Id(P) = id;
        User(P).Length = username.Length;
        for (int i = 0; i < username.Length; i++) {
            User(P).TabWord[i] = username.TabWord[i];
        }
        DateTime(P) = d;
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
        P = NULL;
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
        TulisDATETIME(DateTime(P));

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

// int to addressTree
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

void Balas(Word input, ListAcc LAcc, Affection aff, ListKicauan LKicau, int id_untuk_balas) {
    int space_count, IDKicau, IDBalas, id_user_pembalas, id_user_dibalas;
    Word balasan, username_pembalas, username_dibalas;
    Tree tree;
    space_count = IDKicau = IDBalas = 0;
    for (int i = 0; input.TabWord[i] != EndWord; i++) {
        if (input.TabWord[i] == BLANK) {
            space_count++;
        }
        else if ((int)input.TabWord[i] >= 48 && (int)input.TabWord[i] <= 57) {
            if (space_count == 1) {
                IDKicau = IDKicau * 10 + (input.TabWord[i] - '0');
            }
            else if (space_count == 2) {
                IDBalas = IDBalas * 10 + (input.TabWord[i] - '0');
            }
        }
    }
    // username_pembalas = active_username;
    if (isIdxEff_ListKicauan(LKicau, IDKicau)) { // IdKicau EXIST (ADA)
        boolean cek_NULL = false;
        id_user_pembalas = getIdx_Username(LAcc, username_pembalas);
        for (int i = 0; i < listLength_ListKicauan(LKicau); i++) {
            if (ListKicauan_ELMT(LKicau, i).idKicau == IDKicau) {
                if (ListKicauan_ELMT(LKicau, i).Balasan == NULL) {
                    cek_NULL = true;
                }
                username_dibalas = ListKicauan_ELMT(LKicau, i).author.username;
                tree = ListKicauan_ELMT(LKicau, i).Balasan;
                p = Root(tree);
                break;
            }
        }
        if (IDBalas == -1) {
            if (cek_NULL) {
                id_user_dibalas = getIdx_Username(LAcc, username_dibalas);
                if (getPublicitybyUsername(LAcc, username_dibalas) || isFriends_Affection(Aff, id_user_pembalas, id_user_dibalas)) {
                    addressTree new, old;
                    DATETIME Date;
                    CreateDATETIME(&Date);
                    printf("\nMasukkan balasan:\n");
                    STARTWORD();
                    balasan = currentWord;
                    STARTWORD();
                    username_pembalas = currentWord;
                    printf("\nSelamat! balasan telah diterbitkan!\nDetil balasan:\n");
                    printf("| ID = \n"); // ID PENGGUNA
                    printf("| \n"); // USERNAME
                    printf("| "); // DATETIME
                    TulisDATETIME(Date);
                    printf("\n| ");
                    for (int i = 0; i < balasan.Length; i++) {
                        printf("%c", balasan.TabWord[i]);
                    }

                    new = Alokasi(id_untuk_balas, username_dibalas, Date, balasan);
                    old = getAddressWithId(p, IDKicau);
                    if (FirstChild(old) == NULL) {
                        AddChild(&old, new);
                    }
                    else {
                        AddSibling(&old, new);
                    }
                    id_untuk_balas++;
                }
                else {
                    printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
                }
            }
            else {

            }
        }
        else { // IDBALAS != (=1)
            if (isIdTreeElmt(p, IDBalas)) { // IdBalasan EXIST
                if (getPublicitybyUsername(LAcc, username_dibalas || isFriends_Affection(aff, id_user_pembalas, id_user_dibalas))) {  // Jika publik atau berteman
                    addressTree new, old;
                    DATETIME Date;
                    id_user_dibalas = getIdx_Username(LAcc, username_dibalas);
                    CreateDATETIME(&Date);
                    printf("\nMasukkan balasan:\n");
                    STARTWORD();
                    balasan = currentWord;
                    int id = 6969;
                    STARTWORD();
                    username_pembalas = currentWord;
                    printf("\nSelamat! balasan telah diterbitkan!\nDetil balasan:\n");
                    printf("| ID = \n"); // ID PENGGUNA
                    printf("| \n"); // USERNAME
                    printf("| "); // DATETIME
                    TulisDATETIME(Date);
                    printf("\n| ");
                    for (int i = 0; i < balasan.Length; i++) {
                        printf("%c", balasan.TabWord[i]);
                    }

                    new = Alokasi(id_untuk_balas, username_pembalas, Date, balasan);
                    old = getAddressWithId(p, IDBalas);
                    if (FirstChild(old) == NULL) {
                        AddChild(&old, new);
                    }
                    else {
                        AddSibling(&old, new);
                    }
                    id_untuk_balas++;
                }       
                else {
                    printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n");
                }
            }
            else { // IdBalas NOT EXIST
                printf("Wah, tidak terdapat balasan yang ingin anda balas!\n");
            }
        }
    }
    else { // IdKicau NOT EXIST
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
    }
}

void Balasan(Word input) {
    int space_count, IDKicau;
    space_count = IDKicau  = 0;

    for (int i = 0; input.TabWord[i] != EndWord; i++) {
        if (input.TabWord[i] == BLANK) {
            space_count++;
        }
        else if ((int)input.TabWord[i] >= 48 && (int)input.TabWord[i] <= 57) {
            if (space_count == 1) {
                IDKicau = IDKicau * 10 + (input.TabWord[i] - '0');
            }
        }
    }

    // user_pembalas = current_user;
    
    if (isIdxEff_ListKicauan(LKicau, IDKicau)) {
        for (int i = 0; i < listLength_ListKicauan(LKicau); i++) {
            if (ListKicauan_ELMT(LKicau, i).idKicau == IDKicau) {
                username_dibalas = ListKicauan_ELMT(LKicau, i).author.username;
                id_user_dibalas = getIdx_Account(LAcc, username_dibalas);
                break;
            }
        }
        tree = ListKicauan_ELMT(LKicau, IDKicau).balasan;
        p = Root(tree);
        if (p == NULL) {
            printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        }
        else {
            Account a = getElmt_Account(LAcc, id_user_dibalas);
            if (!isFriends_Affection(A, id_user_dibalas, id_user_pembalas)) {
                if (!a.publicity) {
                    printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
                }
                else {
                    printTree(p, 0);
                }
            }
        }
    }
    else {
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
    }

    
}

void hapusBalasan(Word input) {
    Tree t;
    addressTree p, q;
    int IDKicau, IDBalasan, space_count;
    IDKicau = IDBalasan = space_count = 0;
    for (int i = 0; input.TabWord[i] != EndWord; i++) {
        if (input.TabWord[i] == BLANK) {
            space_count++;
        }
        else if ((int)input.TabWord[i] >= 48 && (int)input.TabWord[i] <= 57) {
            if (space_count == 1) {
                IDKicau = IDKicau * 10 + (input.TabWord[i] - '0');
            }
            else if (space_count == 2) {
                IDBalasan = IDBalasan * 10 + (input.TabWord[i] - '0');
            }
        }
    }
    for (int i = 0; i < listLength_ListKicauan(LKicau); i++) {
            if (ListKicauan_ELMT(LKicau, i).idKicau == IDKicau) {
                username_dibalas = ListKicauan_ELMT(LKicau, i).author.username;
                t = ListKicauan_ELMT(LKicau, i).balasan;
                p = Root(t);
                break;
            }
    }
    if (isIdxEff_ListKicauan(LKicau, IDKicau)) { // IDKicau EXIST
        q = getAddressWithId(p, IDBalasan);
        if (q != NULL) { // PEMILIK BALASAN
            if (User(q) == active_user) {
                addressTree p1, p2, p3;
                p1 = getAddressWithId(p, IDBalasan);
                printf("%s", Pesan(p1));
                p2 = getAddressBefore(p, p1);
                printf("%s", Pesan(p2));
                if (NextSibling(p1) != NULL) {
                    if (FirstChild(p2) == p1) {
                        FirstChild(p2) = NextSibling(p1);
                    }
                    else {
                        NextSibling(p2) = NextSibling(p1);
                    }
                }
                deleteTree(p1);          
                printf("Balasan berhasil dihapus\n");
            }
            else {
                printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
            }
        }
        else { // NOT EXIST
            printf("Balasan tidak ditemukan\n");
        }
    }
    else {
        printf("Kicauan tidak ditemukan\n");
    }
}