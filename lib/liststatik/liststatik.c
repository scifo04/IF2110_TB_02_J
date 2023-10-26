/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include "liststatik.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l) {
   int i;
   for (i = 0 ; i < CAPACITY ; i ++) {
      LISTSTATIK_ELMT(*l,i) = MARK_LISTSTATIK;
   }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength_ListStatik(ListStatik l) {
   int length,i;
   length = 0;
   for (i = 0 ; i < CAPACITY ; i ++) {
      if (LISTSTATIK_ELMT(l,i) != MARK_LISTSTATIK) {
         length += 1;
      }
   }
   return length;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx_ListStatik(ListStatik l) {
   return 0;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx_ListStatik(ListStatik l) {
   int i;
   for (i = CAPACITY-1 ; i >= 0 ; i --) {
      if (LISTSTATIK_ELMT(l,i) != MARK_LISTSTATIK) {
         return i;
         break ;
      }
   }
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListStatik(ListStatik l, IdxType i) {
   return (i>=0 && i<CAPACITY);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff_ListStatik(ListStatik l, IdxType i) {
   return (i>=0 && i<listLength_ListStatik(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty_ListStatik(ListStatik l) {
   int i;
   boolean a;
   a = true;
   for (i = 0 ; i < CAPACITY ; i ++) {
      if (LISTSTATIK_ELMT(l,i) != MARK_LISTSTATIK) {
         a = false;
         break;
      }
   }
   return a;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull_ListStatik(ListStatik l) {
   int i;
   boolean a;
   a = true;
   for (i = 0 ; i < CAPACITY ; i ++) {
      if (LISTSTATIK_ELMT(l,i) == MARK_LISTSTATIK) {
         a = false;
         break;
      }
   }
   return a;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList_ListStatik(ListStatik *l) {
   CreateListStatik(l);
   int n,i,element;
   do {
      scanf("%d",&n);
   } while (!(n >= 0 && n <= CAPACITY));
   if (n > 0) {
      for (i = 0 ; i < n ; i ++) {
         scanf("%d",&element);
         LISTSTATIK_ELMT(*l,i) = element;
      }
   }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList_ListStatik(ListStatik l) {
   int i,a;
   if (listLength_ListStatik(l) > 0) {
      printf("[");
      for (i = 0 ; i < listLength_ListStatik(l)-1 ; i ++) {
         printf("%d,",LISTSTATIK_ELMT(l,i));
      }
      printf("%d]",LISTSTATIK_ELMT(l,listLength_ListStatik(l)-1));
   } else {
      printf("[]");
   }
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList_ListStatik(ListStatik l1, ListStatik l2, boolean plus) {
   int i;
   ListStatik newl;
   CreateListStatik(&newl);
   if (plus) {
      for (i = 0 ; i < listLength_ListStatik(l1) ; i++) {
         LISTSTATIK_ELMT(newl,i) = LISTSTATIK_ELMT(l1,i) + LISTSTATIK_ELMT(l2,i);
      }
   } else {
      for (i = 0 ; i < listLength_ListStatik(l1) ; i++) {
         LISTSTATIK_ELMT(newl,i) = LISTSTATIK_ELMT(l1,i) - LISTSTATIK_ELMT(l2,i);
      }
   }
   return newl;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual_ListStatik(ListStatik l1, ListStatik l2) {
   boolean isequal;
   int i,truevalue;
   truevalue = 0;
   isequal = false;
   if (listLength_ListStatik(l1) == listLength_ListStatik(l2)) {
      for (i = 0 ; i < listLength_ListStatik(l1) ; i ++) {
         if (LISTSTATIK_ELMT(l1,i) == LISTSTATIK_ELMT(l2,i)) {
            truevalue += 1;
         }
      }
      if (truevalue == listLength_ListStatik(l1)) {
         isequal = true;
      }
   }
   return isequal;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf_ListStatik(ListStatik l, ElType val) {
   int i,indexof;
   indexof = -1;
   for (i = 0 ; i < listLength_ListStatik(l) ; i ++) {
      if (LISTSTATIK_ELMT(l,i) == val) {
         indexof = i;
         break;
      }
   }
   if (indexof == -1 || listLength_ListStatik(l) == 0) {
      return IDX_UNDEF;
   } else {
      return indexof;
   }
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues_ListStatik(ListStatik l, ElType *max, ElType *min) {
   int i,maxe,mine;
   maxe,mine = LISTSTATIK_ELMT(l,0);
   if (!isEmpty_ListStatik(l)) {
      for (i = 0 ; i < listLength_ListStatik(l) ; i++) {
         if (LISTSTATIK_ELMT(l,i) > maxe) {
            maxe = LISTSTATIK_ELMT(l,i);
         }
         if (LISTSTATIK_ELMT(l,i) < mine) {
            mine = LISTSTATIK_ELMT(l,i);
         }
      }
   }
   *max = maxe;
   *min = mine;
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst_ListStatik(ListStatik *l, ElType val) {
   int i;
   if (!isFull_ListStatik((*l))) {
      for (i = getLastIdx_ListStatik(*l) ; i >= 0 ; i--) {
         LISTSTATIK_ELMT(*l,i+1) = LISTSTATIK_ELMT(*l,i);
      }
      LISTSTATIK_ELMT(*l,0) = val;
   }
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt_ListStatik(ListStatik *l, ElType val, IdxType idx) {
   int i;
   if (!isFull_ListStatik(*l) && !isEmpty_ListStatik(*l)) {
      for (i = listLength_ListStatik(*l) - 1 ; i >= idx ; i--) {
         LISTSTATIK_ELMT(*l,i+1) = LISTSTATIK_ELMT(*l,i);
      }
      LISTSTATIK_ELMT(*l,idx) = val;
   }
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListStatik(ListStatik *l, ElType val) {
   if (!isFull_ListStatik(*l)) {
      LISTSTATIK_ELMT(*l,listLength_ListStatik(*l)) = val; 
   }
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst_ListStatik(ListStatik *l, ElType *val) {
   int i;
   if (!isFull_ListStatik(*l)) {
      *val = LISTSTATIK_ELMT(*l,0);
      if (listLength_ListStatik(*l) > 1) {
         for (i = 1 ; i <= listLength_ListStatik(*l) - 1 ; i++) {
            LISTSTATIK_ELMT(*l,i-1) = LISTSTATIK_ELMT(*l,i);
         }
      }
      LISTSTATIK_ELMT(*l,listLength_ListStatik(*l)-1) = MARK_LISTSTATIK;
   }
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt_ListStatik(ListStatik *l, ElType *val, IdxType idx) {
   int i;
   if (!isEmpty_ListStatik(*l) && isIdxValid_ListStatik(*l,idx)) {
      *val = LISTSTATIK_ELMT(*l,idx);
      if (listLength_ListStatik(*l) > 1) {
         for (i = idx ; i <= getLastIdx_ListStatik(*l)-1 ; i++) {
            LISTSTATIK_ELMT(*l,i) = LISTSTATIK_ELMT(*l,i+1);
         }
      }
      LISTSTATIK_ELMT(*l,getLastIdx_ListStatik(*l)) = MARK_LISTSTATIK;
   }
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast_ListStatik(ListStatik *l, ElType *val) {
   if (!isEmpty_ListStatik(*l)) {
      *val = LISTSTATIK_ELMT(*l,getLastIdx_ListStatik(*l));
      LISTSTATIK_ELMT(*l,getLastIdx_ListStatik(*l)) = MARK_LISTSTATIK;
   }
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList_ListStatik(ListStatik *l, boolean asc) {
   int i,j,temp;
   if (listLength_ListStatik(*l) > 1) {
      if (asc) {
         for (i = 0 ; i <= getLastIdx_ListStatik(*l)-1 ; i++) {
            for (j = 0 ; j <= getLastIdx_ListStatik(*l)-1-i ; j++) {
               if (LISTSTATIK_ELMT(*l,j) > LISTSTATIK_ELMT(*l,j+1)) {
                  temp = LISTSTATIK_ELMT(*l,j);
                  LISTSTATIK_ELMT(*l,j) = LISTSTATIK_ELMT(*l,j+1);
                  LISTSTATIK_ELMT(*l,j+1) = temp; 
               }
            }
         }
      } else {
         for (i = 0 ; i <= getLastIdx_ListStatik(*l)-1 ; i++) {
            for (j = 0 ; j <= getLastIdx_ListStatik(*l)-1-i ; j++) {
               if (LISTSTATIK_ELMT(*l,j) < LISTSTATIK_ELMT(*l,j+1)) {
                  temp = LISTSTATIK_ELMT(*l,j);
                  LISTSTATIK_ELMT(*l,j) = LISTSTATIK_ELMT(*l,j+1);
                  LISTSTATIK_ELMT(*l,j+1) = temp; 
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