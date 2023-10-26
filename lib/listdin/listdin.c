/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
    if (capacity > 0) {
        LISTDIN_CAPACITY(*l) = capacity;
        LISTDIN_BUFFER(*l) = malloc(LISTDIN_CAPACITY(*l)*sizeof(int));
        LISTDIN_NEFF(*l) = 0;
    }
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l) {
    LISTDIN_CAPACITY(*l) = 0;
    LISTDIN_NEFF(*l) = 0;
    free(LISTDIN_BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength_ListDin(ListDin l) {
    return (LISTDIN_NEFF(l));
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx_ListDin(ListDin l) {
    return 0;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx_ListDin(ListDin l) {
    return (LISTDIN_NEFF(l)-1);
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListDin(ListDin l, IdxType i) {
    return (i>=0 && i<LISTDIN_CAPACITY(l));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff_ListDin(ListDin l, IdxType i) {
    return (i>=0 && i<LISTDIN_NEFF(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty_ListDin(ListDin l) {
    return (LISTDIN_NEFF(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull_ListDin(ListDin l) {
    return (LISTDIN_NEFF(l) == LISTDIN_CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList_ListDin(ListDin *l) {
    int i,N;
    do {
        scanf("%d",&N);
    } while (!(N>=0 && N <= LISTDIN_CAPACITY(*l)));
    LISTDIN_NEFF(*l) = N;
    for (i = 0; i < N; i++) {
        scanf("%d",&LISTDIN_ELMT(*l,i));
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList_ListDin(ListDin l) {
    int i;
    printf("[");
    if (LISTDIN_NEFF(l) > 0) {
        for (i = 0; i<LISTDIN_NEFF(l)-1; i++) {
            printf("%d,",LISTDIN_ELMT(l,i));
        }
        printf("%d]",LISTDIN_ELMT(l,LISTDIN_NEFF(l)-1));
    } else {
        printf("]");
    }
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    int i;
    ListDin newl;
    copyList_ListDin(l1,&newl);
    if (plus && (LISTDIN_NEFF(l1) == LISTDIN_NEFF(l2))) {
        for (i = 0; i < LISTDIN_NEFF(l1); i++) {
            LISTDIN_ELMT(newl,i) += LISTDIN_ELMT(l2,i);
        }
    } else {
        for (i = 0; i < LISTDIN_NEFF(l1); i++) {
            LISTDIN_ELMT(newl,i) -= LISTDIN_ELMT(l2,i);
        }
    }
    return newl;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual_ListDin(ListDin l1, ListDin l2) {
    int i;
    if (LISTDIN_NEFF(l1) == LISTDIN_NEFF(l2)) {
        for (i = 0; i < LISTDIN_NEFF(l1); i++) {
            if (LISTDIN_ELMT(l1,i) != LISTDIN_ELMT(l2,i)) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf_ListDin(ListDin l, ElType val) {
    int i;
    int value = IDX_UNDEF;
    if (LISTDIN_NEFF(l) > 0) {
        for (i = 0; i < LISTDIN_NEFF(l); i++) {
            if (LISTDIN_ELMT(l,i) == val) {
                return i;
            }
        }
    } else {
        return IDX_UNDEF;
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min) {
    int i,j, maxe, mine;
    mine = LISTDIN_ELMT(l,0);
    maxe = LISTDIN_ELMT(l,0);
    if (!isEmpty_ListDin(l)) {
        for (i = 0; i < LISTDIN_NEFF(l); i++) {
            if (LISTDIN_ELMT(l,i) > maxe) {
                maxe = LISTDIN_ELMT(l,i);
            }
            if (LISTDIN_ELMT(l,i) < mine) {
                mine = LISTDIN_ELMT(l,i);
            }
        }
    }
    *max = maxe;
    *min = mine;
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList_ListDin(ListDin lIn, ListDin *lOut) {
    int i;
    if (!isEmpty_ListDin(lIn)) {
        CreateListDin(lOut, LISTDIN_CAPACITY(lIn));
        LISTDIN_NEFF(*lOut) = LISTDIN_NEFF(lIn);
        LISTDIN_CAPACITY(*lOut) = LISTDIN_CAPACITY(lIn);
        for (i = 0; i < LISTDIN_NEFF(lIn); i++) {
            LISTDIN_ELMT(*lOut,i) = LISTDIN_ELMT(lIn,i);
        }
    }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l) {
    int sume,i;
    sume = 0;
    if (isEmpty_ListDin(l) == false) {
        for (i = 0; i<LISTDIN_NEFF(l); i++) {
            sume += LISTDIN_ELMT(l,i);
        }
    }
    return sume;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val) {
    int appear,i;
    appear = 0;
    if (!isEmpty_ListDin(l)) {
        for (i = 0; i<LISTDIN_NEFF(l); i++) {
            if (LISTDIN_ELMT(l,i) == val) {
                appear += 1;
            }
        }
    }
    return appear;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort_ListDin(ListDin *l, boolean asc) {
    int i,j,temp;
    if (LISTDIN_NEFF(*l) > 1) {
        if (asc) {
            for (i = 0 ; i < LISTDIN_NEFF(*l)-1 ; i++) {
                for (j = 0 ; j < LISTDIN_NEFF(*l)-i-1 ; j++) {
                    if (LISTDIN_ELMT(*l,j) > LISTDIN_ELMT(*l,j+1)) {
                        temp = LISTDIN_ELMT(*l,j);
                        LISTDIN_ELMT(*l,j) = LISTDIN_ELMT(*l,j+1);
                        LISTDIN_ELMT(*l,j+1) = temp; 
                    }
                }
            }
        } else {
            for (i = 0 ; i < LISTDIN_NEFF(*l)-1 ; i++) {
                for (j = 0 ; j < LISTDIN_NEFF(*l)-i-1 ; j++) {
                    if (LISTDIN_ELMT(*l,j) < LISTDIN_ELMT(*l,j+1)) {
                        temp = LISTDIN_ELMT(*l,j);
                        LISTDIN_ELMT(*l,j) = LISTDIN_ELMT(*l,j+1);
                        LISTDIN_ELMT(*l,j+1) = temp; 
                    }
                }
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListDin(ListDin *l, ElType val) {
    if (!isFull_ListDin(*l)) {
        LISTDIN_ELMT(*l, LISTDIN_NEFF(*l)) = val;
        LISTDIN_NEFF(*l) += 1; 
    }
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast_ListDin(ListDin *l, ElType *val) {
    if (!isEmpty_ListDin(*l)) {
        *val = LISTDIN_ELMT(*l,getLastIdx_ListDin(*l));
        LISTDIN_NEFF(*l) -= 1;
    }
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList_ListDin(ListDin *l, int num) {
    ListDin temp;
    int i;
    copyList_ListDin(*l,&temp);
    dealocateList(l);
    CreateListDin(l, LISTDIN_CAPACITY(temp));
    LISTDIN_CAPACITY(temp) += num;
    LISTDIN_BUFFER(*l) = realloc(LISTDIN_BUFFER(*l),LISTDIN_CAPACITY(temp)*sizeof(int));
    for (i = 0; i < LISTDIN_NEFF(temp); i++) {
        LISTDIN_ELMT(*l,i) = LISTDIN_ELMT(temp,i);
    }
    LISTDIN_CAPACITY(*l) = LISTDIN_CAPACITY(temp);
    LISTDIN_NEFF(*l) = LISTDIN_NEFF(temp);
    dealocateList(&temp);
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num) {
    ListDin temp;
    int i;
    if ((LISTDIN_CAPACITY(*l) > num) && (LISTDIN_NEFF(*l) < LISTDIN_CAPACITY(*l) - num)) {
        copyList_ListDin(*l,&temp);
        dealocateList(l);
        CreateListDin(l,LISTDIN_CAPACITY(temp));
        LISTDIN_BUFFER(*l) = realloc(LISTDIN_BUFFER(*l),(LISTDIN_CAPACITY(*l)-num)*sizeof(int));
        for (i = 0; i < LISTDIN_NEFF(temp); i++) {
            LISTDIN_ELMT(*l,i) = LISTDIN_ELMT(temp,i);
        }
        LISTDIN_CAPACITY(*l) -= num;
        LISTDIN_NEFF(*l) = LISTDIN_NEFF(temp);
        dealocateList(&temp);
    }
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l) {
    ListDin temp;
    int i;
    copyList_ListDin(*l,&temp);
    dealocateList(l);
    CreateListDin(l,LISTDIN_CAPACITY(temp));
    LISTDIN_BUFFER(*l) = realloc(LISTDIN_BUFFER(*l),(LISTDIN_NEFF(temp))*sizeof(int));
    for (i = 0; i < LISTDIN_NEFF(temp); i++) {
        LISTDIN_ELMT(*l,i) = LISTDIN_ELMT(temp,i);
    }
    LISTDIN_CAPACITY(*l) = LISTDIN_NEFF(temp);
    LISTDIN_NEFF(*l) = LISTDIN_NEFF(temp);
    dealocateList(&temp);
}
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */