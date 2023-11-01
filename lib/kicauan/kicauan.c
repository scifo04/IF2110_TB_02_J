/* MODUL KICAUAN DYNAMIC LIST */

#include "kicauan.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** FITUR ********** */
/*Pengguna dapat menyukai suatu Twit dengan indeks yang valid, milik pengguna sendiri,
milik teman, ataupun milik akun publik, (baca: semua selain privat)*/
void LikeKicauan(ListKicauan *l, int idKicauan){
    if(isIdxEff_ListKicauan(*l)){ 
        if(Author(ListKicauan_ELMT(*l, idKicauan-1)).publicity == true){ //Akun publik
            Like(ListKicauan_ELMT(*l, idKicauan-1))++;
        } else if(isFriend(Author(ListKicauan_ELMT(*l, idKicauan-1)), CurrentAccount)){ //Akun milik sendiri atau teman
            Like(ListKicauan_ELMT(*l, idKicauan-1))++;
        } else {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n")
        }
    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKicauan);
    }
}
/*Pengguna hanya dapat mengubah miliknya sendiri*/
void EditKicauan(ListKicauan *l, int idKicauan){
    if(isIdxEff_ListKicauan(*l)){ 
        if(Author(ListKicauan_ELMT(*l, idKicauan-1)) == CurrentAccount){
            Twit *K = ListKicauan_ELMT(*l, idKicauan-1);
            Word isiTwit; BacaTwit(&isiTwit); IsiTwit(*K) = isiTwit;
            Word tagar; BacaTagar(&tagar); Tagar(*K) = tagar;

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
        ListKicauan_BUFFER(*l) = malloc(ListKicauan_CAPACITY(*l)*sizeof(ElType));
        ListKicauan_NEFF(*l) = 0;
    }
}

void dealocateList(ListKicauan *l){
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
void readList_ListKicauan(ListKicauan *l);
/*Berisi serangkaian fungsi untuk membaca kicauan.config dan memasukannya ke List Dinamik Kicauan
Tapi kayanya nanti bikin file khusus deh readconfig.c*/

void DisplayListKicauan(ListKicauan l){
    if(isEmpty_ListKicauan(l)){
        printf("Tidak ada kicauan yang dapat ditampilkan");
    } else {
        int i; found=false;
        for(i=1;i<=ListKicauan_NEFF;i++){
            if(isFriend(Author(ListKicauan_ELMT(*l, i-1)), CurrentAccount)){
                found=true;
                DetailTwit(ListKicauan_ELMT(*l, i-1));
                printf("\n");
            }
        }
        if(!found){
            printf("Tidak ada kicauan yang dapat ditampilkan");
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
void insertLast_ListKicauan(ListKicauan *l, ElType val){
    if (isFull_ListKicauan(*l)) {
        expandList(l,50);
    }
    ListKicauan_ELMT(*l, ListKicauan_NEFF(*l)) = val;
    ListKicauan_NEFF(*l) += 1; 
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListKicauan *l, int num){
    ListKicauan temp;
    int i;
    copyList_ListKicauan(*l,&temp);
    dealocateList(l);
    CreateListKicauan(l, ListKicauan_CAPACITY(temp));
    ListKicauan_CAPACITY(temp) += num;
    ListKicauan_BUFFER(*l) = realloc(ListKicauan_BUFFER(*l),ListKicauan_CAPACITY(temp)*sizeof(ElType));
    for (i = 0; i < ListKicauan_NEFF(temp); i++) {
        ListKicauan_ELMT(*l,i) = ListKicauan_ELMT(temp,i);
    }
    ListKicauan_CAPACITY(*l) = ListKicauan_CAPACITY(temp);
    ListKicauan_NEFF(*l) = ListKicauan_NEFF(temp);
    dealocateList(&temp);
}
