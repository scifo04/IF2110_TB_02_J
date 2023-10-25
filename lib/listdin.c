/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "boolean.h"
#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
    if (capacity > 0) {
        CAPACITY(*l) = capacity;
        BUFFER(*l) = malloc(CAPACITY(*l)*sizeof(int));
        NEFF(*l) = 0;
    }
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l) {
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l) {
    return (NEFF(l));
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l) {
    return 0;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l) {
    return (NEFF(l)-1);
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i) {
    return (i>=0 && i<CAPACITY(l));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i) {
    return (i>=0 && i<NEFF(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
    return (NEFF(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l) {
    return (NEFF(l) == CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
    int i,N;
    do {
        scanf("%d",&N);
    } while (!(N>=0 && N <= CAPACITY(*l)));
    NEFF(*l) = N;
    for (i = 0; i < N; i++) {
        scanf("%d",&ELMT(*l,i));
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
void printList(ListDin l) {
    int i;
    printf("[");
    if (NEFF(l) > 0) {
        for (i = 0; i<NEFF(l)-1; i++) {
            printf("%d,",ELMT(l,i));
        }
        printf("%d]",ELMT(l,NEFF(l)-1));
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
    copyList(l1,&newl);
    if (plus && (NEFF(l1) == NEFF(l2))) {
        for (i = 0; i < NEFF(l1); i++) {
            ELMT(newl,i) += ELMT(l2,i);
        }
    } else {
        for (i = 0; i < NEFF(l1); i++) {
            ELMT(newl,i) -= ELMT(l2,i);
        }
    }
    return newl;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
    int i;
    if (NEFF(l1) == NEFF(l2)) {
        for (i = 0; i < NEFF(l1); i++) {
            if (ELMT(l1,i) != ELMT(l2,i)) {
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
IdxType indexOf(ListDin l, ElType val) {
    int i;
    int value = IDX_UNDEF;
    if (NEFF(l) > 0) {
        for (i = 0; i < NEFF(l); i++) {
            if (ELMT(l,i) == val) {
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
    mine = ELMT(l,0);
    maxe = ELMT(l,0);
    if (!isEmpty(l)) {
        for (i = 0; i < NEFF(l); i++) {
            if (ELMT(l,i) > maxe) {
                maxe = ELMT(l,i);
            }
            if (ELMT(l,i) < mine) {
                mine = ELMT(l,i);
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
void copyList(ListDin lIn, ListDin *lOut) {
    int i;
    if (!isEmpty(lIn)) {
        CreateListDin(lOut,CAPACITY(lIn));
        NEFF(*lOut) = NEFF(lIn);
        CAPACITY(*lOut) = CAPACITY(lIn);
        for (i = 0; i < NEFF(lIn); i++) {
            ELMT(*lOut,i) = ELMT(lIn,i);
        }
    }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l) {
    int sume,i;
    sume = 0;
    if (isEmpty(l) == false) {
        for (i = 0; i<NEFF(l); i++) {
            sume += ELMT(l,i);
        }
    }
    return sume;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val) {
    int appear,i;
    appear = 0;
    if (!isEmpty(l)) {
        for (i = 0; i<NEFF(l); i++) {
            if (ELMT(l,i) == val) {
                appear += 1;
            }
        }
    }
    return appear;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
    int i,j,temp;
    if (NEFF(*l) > 1) {
        if (asc) {
            for (i = 0 ; i < NEFF(*l)-1 ; i++) {
                for (j = 0 ; j < NEFF(*l)-i-1 ; j++) {
                    if (ELMT(*l,j) > ELMT(*l,j+1)) {
                        temp = ELMT(*l,j);
                        ELMT(*l,j) = ELMT(*l,j+1);
                        ELMT(*l,j+1) = temp; 
                    }
                }
            }
        } else {
            for (i = 0 ; i < NEFF(*l)-1 ; i++) {
                for (j = 0 ; j < NEFF(*l)-i-1 ; j++) {
                    if (ELMT(*l,j) < ELMT(*l,j+1)) {
                        temp = ELMT(*l,j);
                        ELMT(*l,j) = ELMT(*l,j+1);
                        ELMT(*l,j+1) = temp; 
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
void insertLast(ListDin *l, ElType val) {
    if (!isFull(*l)) {
        ELMT(*l,NEFF(*l)) = val;
        NEFF(*l) += 1; 
    }
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
    if (!isEmpty(*l)) {
        *val = ELMT(*l,getLastIdx(*l));
        NEFF(*l) -= 1;
    }
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num) {
    ListDin temp;
    int i;
    copyList(*l,&temp);
    dealocateList(l);
    CreateListDin(l,CAPACITY(temp));
    CAPACITY(temp) += num;
    BUFFER(*l) = realloc(BUFFER(*l),CAPACITY(temp)*sizeof(int));
    for (i = 0; i < NEFF(temp); i++) {
        ELMT(*l,i) = ELMT(temp,i);
    }
    CAPACITY(*l) = CAPACITY(temp);
    NEFF(*l) = NEFF(temp);
    dealocateList(&temp);
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num) {
    ListDin temp;
    int i;
    if ((CAPACITY(*l) > num) && (NEFF(*l) < CAPACITY(*l) - num)) {
        copyList(*l,&temp);
        dealocateList(l);
        CreateListDin(l,CAPACITY(temp));
        BUFFER(*l) = realloc(BUFFER(*l),(CAPACITY(*l)-num)*sizeof(int));
        for (i = 0; i < NEFF(temp); i++) {
            ELMT(*l,i) = ELMT(temp,i);
        }
        CAPACITY(*l) -= num;
        NEFF(*l) = NEFF(temp);
        dealocateList(&temp);
    }
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l) {
    ListDin temp;
    int i;
    copyList(*l,&temp);
    dealocateList(l);
    CreateListDin(l,CAPACITY(temp));
    BUFFER(*l) = realloc(BUFFER(*l),(NEFF(temp))*sizeof(int));
    for (i = 0; i < NEFF(temp); i++) {
        ELMT(*l,i) = ELMT(temp,i);
    }
    CAPACITY(*l) = NEFF(temp);
    NEFF(*l) = NEFF(temp);
    dealocateList(&temp);
}
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */