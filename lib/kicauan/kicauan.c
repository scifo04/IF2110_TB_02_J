#include <stdio.h>
#include <stdlib.h>
#include "kicauan.h"

/* MODUL ADT SEDERHANA TWIT*/

/* Konstruktor: Membentuk Twit dari komponen-komponennya*/
void CreateTwit(Twit *K, ListKicauan kicauan, Word currentusername){
    ID(*K) = listLength_ListKicauan(kicauan)+1; /*Bingung. ListKicauan adalah suatu variabel global di main.*/
    IDUtas(*K) = -1; /*Secara default, Twit bukanlah Utas, kecuali ditandai sebagai Utas*/
    Like(*K) = 0;
    Author(*K) = currentusername;
    DATETIME D; CreateDATETIME(&D); DateTime(*K) = D; 
    Word isiTwit; BacaTwit(&isiTwit); IsiTwit(*K) = isiTwit;
    Tree t; CreateTree(&t); Balasan(*K) = t;
    AddressUtas U; CreateUtas(&U); Utas(*K) = U;
}
/* Membaca Twit */
/* Twit yang dimasukkan terpotong secara otomatis dengan jumlah karakter maksimum 280.
Twit tidak boleh berisi spasi. Hal ini sudah di-handle di wordmachine. Panjang maksimal Word adalah 280.*/
void BacaTwit(Word *isiTwit){
    printf("Masukkan kicauan baru: \n");
    currentWord.TabWord[0] = '\0'; //Mengosongkan currentWord
    currentWord.Length = 0;
    STARTWORD();
    if(isWordSimilar(currentWord, "")){ //W mungkin tidak berisi apa-apa
        while(isWordSimilar(currentWord, "")){
            printf("Kicauan tidak boleh hanya berisi spasi!\n");
            printf("Masukkan kicauan: \n");
            STARTWORD();
            printf("\n");
            *isiTwit = currentWord;
        }
    }else {
        *isiTwit = currentWord;
    }
}

/* Detail Twit*/
void DetailTwit(Twit K){
    printf("| ID = %d\n", ID(K));
    printf("| ");
    printWord(Author(K));
    printf("\n");
    printf("| ");
    TulisDATETIME(DateTime(K));
    printf("\n");
    printf("| ");
    printWord(IsiTwit(K));
    printf("\n");
    printf("| Disukai = %d\n", Like(K));
}

/* Pesan Berhasil Membuat Twit*/
void SuccessTwit(Twit K){
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    DetailTwit(K);
}

/* MODUL KICAUAN DYNAMIC LIST */

/* ********** FITUR ********** */
/*Pengguna dapat menyukai suatu Twit dengan indeks yang valid, milik pengguna sendiri,
milik teman, ataupun milik akun publik, (baca: semua selain privat)*/
void LikeKicauan(ListKicauan *l, int idKicauan, Account currentuser, Affection friends, ListAcc accounts){
    if(isIdxEff_ListKicauan(*l, idKicauan-1)){ 
        if(getPublicitybyUsername(accounts, Author(ListKicauan_ELMT(*l, idKicauan-1)))){ //Akun publik
            Like(ListKicauan_ELMT(*l, idKicauan-1))++;
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detail Kicauan:\n");
            DetailTwit(ListKicauan_ELMT(*l, idKicauan-1));
            printf("\n");
        } else if(isFriends_Affection(friends, getIdx_Username(accounts, Author(ListKicauan_ELMT(*l, idKicauan-1))), getIdx_Account(accounts, currentuser))){ //Akun milik sendiri atau teman
            Like(ListKicauan_ELMT(*l, idKicauan-1))++;
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detail Kicauan:\n");
            DetailTwit(ListKicauan_ELMT(*l, idKicauan-1));
            printf("\n");
        } else {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        }
    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKicauan);
    }
}
/*Pengguna hanya dapat mengubah miliknya sendiri*/
void EditKicauan(ListKicauan *l, int idKicauan, Account currentuser, ListAcc accounts){
    if(isIdxEff_ListKicauan(*l, idKicauan-1)){ 
        if(getIdx_Username(accounts, Author(ListKicauan_ELMT(*l, idKicauan-1))) == getIdx_Account(accounts, currentuser)){
            Twit *K = &ListKicauan_ELMT(*l, idKicauan-1);
            Word isiTwit; BacaTwit(&isiTwit); IsiTwit(*K) = isiTwit;
            DATETIME newDatetime; CreateDATETIME(&newDatetime); DateTime(*K) = newDatetime; 

            printf("Selamat! kicauan telah diterbitkan!\n");
            printf("Detail Kicauan:\n");
            DetailTwit(*K);
            printf("\n");
        } else {
            printf("Kicauan dengan ID = %d bukan milikmu!\n", idKicauan);
        }
    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKicauan);
    }
    
}

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListKicauan(ListKicauan *l, int capacity){
    if (capacity > 0) {
        ListKicauan_CAPACITY(*l) = capacity;
        ListKicauan_BUFFER(*l) = (ElKicauanType*)malloc(ListKicauan_CAPACITY(*l)*sizeof(ElKicauanType));
        ListKicauan_NEFF(*l) = 0;
    }
}

void dealocateListKicauan(ListKicauan *l){
    ListKicauan_CAPACITY(*l) = 0;
    ListKicauan_NEFF(*l) = 0;
    free(ListKicauan_BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength_ListKicauan(ListKicauan l){
    return (ListKicauan_NEFF(l));
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListKicauan(ListKicauan l, IdxType i){
    return (i>=0 && i<ListKicauan_CAPACITY(l));
}

boolean isIdxEff_ListKicauan(ListKicauan l, IdxType i){
    return (i>=0 && i<ListKicauan_NEFF(l));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty_ListKicauan(ListKicauan l){
    return (ListKicauan_NEFF(l) == 0);
}
/* *** Test list penuh *** */
boolean isFull_ListKicauan(ListKicauan l){
    return (ListKicauan_NEFF(l) == ListKicauan_CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
// void readList_ListKicauan(ListKicauan *l);
/*Berisi serangkaian fungsi untuk membaca kicauan.config dan memasukannya ke List Dinamik Kicauan
Tapi kayanya nanti bikin file khusus deh readconfig.c*/

void DisplayListKicauan(ListKicauan l, Account currentuser, Affection friends, ListAcc accounts){
    if(isEmpty_ListKicauan(l)){
        printf("Tidak ada kicauan yang dapat ditampilkan\n");
    } else {
        int i; boolean found=false;
        for(i = ListKicauan_NEFF(l); i > 0;i--){
            if(isFriends_Affection(friends, getIdx_Username(accounts, Author(ListKicauan_ELMT(l, i-1))), getIdx_Account(accounts, currentuser))){
                found=true;
                DetailTwit(ListKicauan_ELMT(l, i-1));
                printf("\n");
            }
        }
        if(!found){
            printf("Tidak ada kicauan yang dapat ditampilkan\n");
        }
    }
}



/* ********** OPERASI LAIN ********** */
void copyList_ListKicauan(ListKicauan lIn, ListKicauan *lOut){
    int i;
    if (!isEmpty_ListKicauan(lIn)) {
        CreateListKicauan(lOut, ListKicauan_CAPACITY(lIn));
        ListKicauan_NEFF(*lOut) = ListKicauan_NEFF(lIn);
        ListKicauan_CAPACITY(*lOut) = ListKicauan_CAPACITY(lIn);
        for (i = 0; i < ListKicauan_NEFF(lIn); i++) {
            ListKicauan_ELMT(*lOut,i) = ListKicauan_ELMT(lIn,i);
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListKicauan(ListKicauan *l, ElKicauanType val){
    if (isFull_ListKicauan(*l)) {
        expandListKicauan(l,50);
    }
    ListKicauan_ELMT(*l, ListKicauan_NEFF(*l)) = val;
    ListKicauan_NEFF(*l) += 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListKicauan(ListKicauan *l, int num){
    ListKicauan temp;
    int i;
    copyList_ListKicauan(*l,&temp);
    dealocateListKicauan(l);
    ListKicauan_CAPACITY(temp) += num;
    CreateListKicauan(l, ListKicauan_CAPACITY(temp));
    for (i = 0; i < ListKicauan_NEFF(temp); i++) {
        ListKicauan_ELMT(*l,i) = ListKicauan_ELMT(temp,i);
    }
    ListKicauan_CAPACITY(*l) = ListKicauan_CAPACITY(temp);
    ListKicauan_NEFF(*l) = ListKicauan_NEFF(temp);
    dealocateListKicauan(&temp);
}
