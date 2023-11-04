#include <stdio.h>
#include <stdlib.h>
#include "draft.h"
#include "../boolean/boolean.h"
#include "../kicauan/twit.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty_Draft(Draft *S){
    Top(*S) = Nil;
    Cap(*S) = 1;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
/* Mengirim true jika Draft kosong: lihat definisi di atas */
boolean IsEmpty_Draft(Draft S){
    return Top(S) == Nil;
}

/* Mengirim true jika tabel penampung nilai elemen stack penuh */
boolean IsFull_Draft(Draft S){
    return Top(S) == Cap(S)-1;
}

/* ************ Menambahkan sebuah elemen ke Draft ************ */
/* Menambahkan X sebagai elemen Draft S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void Push(Draft * S, infotype X){
    if (IsFull_Draft(*S)){
        Twit *temp = (Twit*)malloc(sizeof(infotype) * Cap(*S) * 2);
        if (temp == NULL){
            printf("Draft PENUH dan ekspansi draft GAGAL!");
            return;
        }

        int i;
        for (i = 0; i < Top(*S); i++){
            temp[i] = S->buffer[i];
        }

        free(S->buffer);
        S->buffer = temp;
        S->capacity *= 2;
    }

    Top(*S) += 1;
    InfoTop(*S) = X;
}


/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
void compressDraft(Draft *S) {
    int newCap = 0.5 * Cap(*S);
    Twit *temp = (Twit*)malloc(sizeof(infotype) * newCap);
    if (temp == NULL){
        printf("GAGAL mengalokasi memori");
        return;
    }

    int i;
    for (i = 0; i <= Top(*S); i++){
        temp[i] = S->buffer[i];
    }

    free(S->buffer);

    S->buffer = temp;
    Cap(*S) = newCap;
}


/* ************ Menghapus sebuah elemen Draft ************ */
/* Menghapus X dari Draft S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void Pop(Draft * S, infotype* X){
    if (!IsEmpty_Draft(*S)) {
        *X = InfoTop(*S);
        Top(*S) -= 1;
    }

    float eff = (Top(*S) + 1) / Cap(*S);
    if (eff <= 0.25){
        compressDraft(S);
    }
}