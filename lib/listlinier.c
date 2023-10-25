#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
    Address a;
    a = (Address) malloc(sizeof(Node));
    if (a != NULL) {
        INFO(a) = val;
        NEXT(a) = NULL;
    }
    return a;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
    Address a;
    a = FIRST(l);
    int i;
    for (i = 0; i < idx; i++) {
        a = NEXT(a);
    }
    return INFO(a);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val) {
    Address a;
    a = FIRST(*l);
    int i;
    for (i = 0; i < idx; i++) {
        a = NEXT(a);
    }
    INFO(a) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val) {
    Address a;
    int i = 0;
    a = FIRST(l);
    while (INFO(a) != val && NEXT(a) != NULL) {
        i += 1;
        a = NEXT(a);
    }
    if (INFO(a) == val) {
        return i;
    } else {
        return IDX_UNDEF;
    }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    Address a = newNode(val);
    if (FIRST(*l) != NULL) {
        NEXT(a) = FIRST(*l);
        FIRST(*l) = a;
    } else {
        FIRST(*l) = a;
    }
} 
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val) {
    Address a,b;
    a = newNode(val);
    b = FIRST(*l);
    if (FIRST(*l) != NULL) {
        if (NEXT(b) != NULL) {
            while (NEXT(b) != NULL) {
                b = NEXT(b);
                if (NEXT(b) == NULL) {
                    NEXT(b) = a;
                    break;
                }
            }
        } else {
            NEXT(b) = a;
        }
    } else {
        FIRST(*l) = a;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx) {
    Address a,b,c;
    int i;
    b = newNode(val);
    a = FIRST(*l);
    c = FIRST(*l);
    if (idx != 0) {
        for (i = 0; i < idx; i++) {
            a = NEXT(a);
        }
        if (idx != 0) {
            for (i = 0; i < idx-1; i++) {
                c = NEXT(c);
            }
        }
    }
    NEXT(b) = a;
    if (idx != 0) {
        NEXT(c) = b;
    } else {
        FIRST(*l) = b;
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    Address a;
    *val = INFO(FIRST(*l));
    a = FIRST(*l);
    a = NEXT(*l);
    FIRST(*l) = a;
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val) {
    Address a;
    if (NEXT(FIRST(*l)) != NULL) {
        a = FIRST(*l);
        while (NEXT(NEXT(a)) != NULL) {
            a = NEXT(a);
        }
        *val = INFO(NEXT(a));
        NEXT(a) = NULL;
    } else {
        *val = INFO(FIRST(*l));
        FIRST(*l) = NULL;
    }
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val) {
    Address a,b;
    a = FIRST(*l);
    b = FIRST(*l);
    int i;
    if (idx != 0) {
        for (i = 0; i < idx-1; i++) {
            a = NEXT(a);
        }
        for (i = 0; i < idx+1; i++) {
            b = NEXT(b);
        }
    }
    if (idx != 0) {
        *val = INFO(NEXT(a));
        NEXT(a) = b;
    } else {
        FIRST(*l) = NEXT(b);
        *val = INFO(a);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
    Address a;
    printf("[");
    a = FIRST(l);
    if (FIRST(l) != NULL) {
        while (NEXT(a) != NULL) {
            printf("%d,",INFO(a));
            a = NEXT(a);
        }
        printf("%d",INFO(a));
    }
    printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l) {
    Address a;
    int i = 1;
    a = FIRST(l);
    if (FIRST(a) == NULL) {
        return 0;
    } else {
        while (NEXT(a) != NULL) {
            i += 1;
            a = NEXT(a);
        }
    }
    return i;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    Address a,b;
    List l3;
    a = FIRST(l1);
    b = FIRST(l2);
    CreateList(&l3);
    if (FIRST(l1) != NULL) {
        insertLast(&l3,INFO(a));
        while (NEXT(a) != NULL) {
            a = NEXT(a);
            insertLast(&l3,INFO(a));
        }
    }
    if (FIRST(l2) != NULL) {
        insertLast(&l3,INFO(b));
        while (NEXT(b) != NULL) {
            b = NEXT(b);
            insertLast(&l3,INFO(b));
        }
    }
    FIRST(l1) = NULL;
    FIRST(l2) = NULL;
    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */