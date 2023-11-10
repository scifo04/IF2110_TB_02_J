#include "tree/tree.c"
#include "wordmachine/wordmachine.c"
#include "wordmachine/charmachine.c"
#include "datetime/datetime.c"
#include "datetime/time.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "affection/affection.c"
#include "account/account.c"
#include "affection/affection.h"
#include "kicauan/kicauan.h"
#include "kicauan/twit.h"

int IDKicau, IDBalasan, id_user_dibalas, id_user_pembalas;
ListKicauan LKicau;
ListAcc LAcc;
Affection A;
addressTree q;
Twit t;
Word username_pembalas, username_dibalas;

void Balas(Word input, addressTree p) {
    int space_count, IDKicau, IDBalas;
    Word balasan;
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
        if (IDBalas == -1) {
            for (int i = 0; i < listLength_ListKicauan(LKicau); i++) {
                if (ListKicauan_ELMT(LKicau, i).idKicau == IDKicau) {
                    if (ListKicauan_ELMT(LKicau, i).balasan == NULL) {
                        cek_NULL = true;
                    }
                    break;
                    user_dibalas = ListKicauan_ELMT(LKicau, i).author.username;
                }
            }
            if (cek_NULL) {
                id_user_dibalas = getIdx_Username(LAcc, user_dibalas);
                if (getPublicitybyUsername(LAcc, user_dibalas) || isFriends_Affection(A, id_user_pembalas, id_user_dibalas)) {
                    addressTree new, old;
                    DATETIME Date;
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

                    new = Alokasi(id, username, Date, balasan);
                    old = getAddressWithId(p, IDKicau);
                    if (FirstChild(old) == NULL) {
                        AddChild(&old, new);
                    }
                    else {
                        AddSibling(&old, new);
                    }
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

                if (getPublicitybyUsername(LAcc, User(q)) || isFriends_Affection(A, id_user_pembalas, id_user_dibalas)) {  // Jika publik atau berteman
                    addressTree new, old;
                    DATETIME Date;

                    id_user_dibalas = getIdx_Username(LAcc, User(q));
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

                    new = Alokasi(id, username, Date, balasan);
                    old = getAddressWithId(p, IDBalas);
                    if (FirstChild(old) == NULL) {
                        AddChild(&old, new);
                    }
                    else {
                        AddSibling(&old, new);
                    }
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

void Balasan(Word input, addressTree P) {
    int space_count, IDKicau;
    Tree t;
    addressTree p;
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
        t = ListKicauan_ELMT(LKicau, IDKicau).balasan;
        p = Root(t);
        if (p == NULL) {
            printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        }
        else {
            if (!isFriends_Affection(A, username_pembalas, username_dibalas)) {
                Account a = getElmt_Account(LAcc, id_user_dibalas);
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

void hapusBalasan(Word input, addressTree p) {
    addressTree q;
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
    if (isIdxEff_ListKicauan(LKicau, IDKicau)) { // IDKicau EXIST
        q = getAddressWithId(IDBalasan);
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