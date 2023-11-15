#include <stdio.h>
#include <stdlib.h>
#include "draft.h"
#include "../boolean/boolean.h"
#include "../kicauan/kicauan.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty_Draft(Draft *S, Account author){
    Top(*S) = Nil;
    Cap(*S) = 1;
    Author(*S) = author.username;
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
void Push(Draft *S, infotype X){
    if (IsFull_Draft(*S)){
        kicauDraft *temp = (kicauDraft*)malloc(sizeof(infotype) * Cap(*S) * 2);
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
    kicauDraft *temp = (kicauDraft*)malloc(sizeof(infotype) * newCap);
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
void Pop(Draft *S, infotype* X){
    if (!IsEmpty_Draft(*S)) {
        *X = InfoTop(*S);
        Top(*S) -= 1;
    }

    float eff = (Top(*S) + 1) / Cap(*S);
    if (eff <= 0.25){
        compressDraft(S);
    }
}


void BacaDraft(Word *isiTwit){
    printf("Masukkan draf: \n");
    currentWord.TabWord[0] = '\0'; //Mengosongkan currentWord
    currentWord.Length = 0;
    STARTWORD();
    printWord(currentWord);
    if(isWordSimilar(currentWord, "")){ //W mungkin tidak berisi apa-apa
        while(isWordSimilar(currentWord, "")){
            printf("Draf tidak boleh hanya berisi spasi!\n");
            printf("Masukkan draf: \n");
            STARTWORD();
            printf("\n");
            *isiTwit = currentWord;
        }
    }else {
        *isiTwit = currentWord;
    }
}


Twit kicauDraftToTwit(Word *W, ListKicauan kicauan, Account currentuser){
    Twit *K;
    ID(*K) = listLength_ListKicauan(kicauan)+1; /*Bingung. ListKicauan adalah suatu variabel global di main.*/
    IDUtas(*K) = -1; /*Secara default, Twit bukanlah Utas, kecuali ditandai sebagai Utas*/
    Like(*K) = 0;
    Author(*K) = currentuser; /*Bingung. Misal Account adalah variabel global yang selalu di-update di main. */
    DATETIME D; CreateDATETIME(&D); DateTime(*K) = D; 
    IsiTwit(*K) = *W;
    Word tagar; currentWord.TabWord[0] = '\0'; currentWord.Length = 0; Tagar(*K) = currentWord;

    return *K;
}

void createDraft(Draft *S, ListKicauan kicauanList, Account currentuser){
    kicauDraft kicau;
    Word isiDraft;
    
    BacaDraft(&isiDraft);
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    currentWord.TabWord[0] = '\0'; //Mengosongkan currentWord
    currentWord.Length = 0;
    STARTWORD();
    printWord(currentWord);
    if(isWordSimilar(currentWord, "HAPUS")){
        printf("Draf telah berhasil dihapus");
    }
    else if (isWordSimilar(currentWord, "SIMPAN")){
        KicauDraf(kicau) = isiDraft;
        DATETIME D; CreateDATETIME(&D); DateTime(kicau) = D;

        Push(S, kicau);
        printf("Draf telah berhasil disimpan");
    }
    else if (isWordSimilar(currentWord, "TERBIT")){
        Twit drafTwit = kicauDraftToTwit(&isiDraft, kicauanList, currentuser);
        insertLast_ListKicauan(&kicauanList, drafTwit);
        SuccessTwit(drafTwit);
    }
    else{
        exit(0);
    }
}


void displayDraft(Draft *S, ListKicauan kicauanList, Account currentuser){
    if (IsEmpty_Draft(*S)){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else{
        kicauDraft delVal;

        kicauDraft topDraft = InfoTop(*S);
        printf("Ini draf terakhir anda:\n");
        printf("| ");
        TulisDATETIME(DateTime(topDraft));
        printf("\n");
        printf("| ");
        printWord(KicauDraf(topDraft));
        printf("\n");

        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");

        currentWord.TabWord[0] = '\0'; //Mengosongkan currentWord
        currentWord.Length = 0;
        STARTWORD();
        printWord(currentWord);
        if(isWordSimilar(currentWord, "KEMBALI")){
            exit(0);
        }
        else if (isWordSimilar(currentWord, "HAPUS")){
            Pop(S, &delVal);
            printf("Draf telah berhasil dihapus!\n");
        }
        else if (isWordSimilar(currentWord, "UBAH")){
            Pop(S, &delVal);
            kicauDraft kicauBaru;
            Word isiDraft;

            printf("Masukkan draf yang baru: \n");
            BacaDraft(&isiDraft);

            KicauDraf(kicauBaru) = isiDraft;
            DATETIME D; CreateDATETIME(&D); DateTime(kicauBaru) = D; 

            // ubah word nya dan waktu
            printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

            currentWord.TabWord[0] = '\0'; //Mengosongkan currentWord
            currentWord.Length = 0;
            STARTWORD();
            printWord(currentWord);
            if(isWordSimilar(currentWord, "HAPUS")){
                exit(0);
            }
            else if(isWordSimilar(currentWord, "SIMPAN")){
                Push(S, kicauBaru);
            }
            else{
                Twit drafTwit = kicauDraftToTwit(&isiDraft, kicauanList, currentuser);
                insertLast_ListKicauan(&kicauanList, drafTwit);
                SuccessTwit(drafTwit);
            }
        }
        else{
            Word isiDraft = KicauDraf(InfoTop(*S));
            Twit drafTwit = kicauDraftToTwit(&isiDraft, kicauanList, currentuser);
            insertLast_ListKicauan(&kicauanList, drafTwit);
            SuccessTwit(drafTwit);
        }
    }
}