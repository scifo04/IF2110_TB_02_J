#include <stdio.h>
#include <stdlib.h>
#include "draft.h"
#include "../boolean/boolean.h"
#include "../kicauan/kicauan.h"
#include "../utas/utas.h"
#include "../tree/tree.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty_Draft(Draft *S, Word currentusername){
    Top(*S) = Nil;
    Author(*S) = currentusername;
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
void Pushs(Draft *S, twitDraft X){
    if (IsFull_Draft(*S)){
        twitDraft *temp = (twitDraft*)malloc(sizeof(twitDraft) * Cap(*S) * 2);
        if (temp == NULL){
            printf("Memory allocation failed! The draft is Full");
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
    InfoTops(*S) = X;
}


/* Proses : Mengubah capacity menjadi setengah
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity 1/2 cap lama */
void compressDraft(Draft *S) {
    int newCap = 0.5 * Cap(*S);
    twitDraft *temp = (twitDraft*)malloc(sizeof(twitDraft) * newCap);
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
void Pops(Draft *S, twitDraft* X){
    if (!IsEmpty_Draft(*S)) {
        *X = InfoTops(*S);
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


Twit twitDraftToTwit(Word *W, ListKicauan kicauan, Word currentuser){
    Twit *K;

    ID(*K) = listLength_ListKicauan(kicauan)+1; /*Bingung. ListKicauan adalah suatu variabel global di main.*/
    IDUtas(*K) = -1; /*Secara default, Twit bukanlah Utas, kecuali ditandai sebagai Utas*/
    Like(*K) = 0;
    Author(*K) = currentuser; /*Bingung. Misal Account adalah variabel global yang selalu di-update di main. */
    DATETIME D; CreateDATETIME(&D); dateTwitDraft(*K) = D; 
    IsiTwit(*K) = *W;
    Word tagar; currentWord.TabWord[0] = '\0'; currentWord.Length = 0; Tagar(*K) = currentWord;
    Tree t; CreateTree(&t); Balasan(*K) = t;
    AddressUtas U; CreateUtas(&U); Utas(*K) = U;

    return *K;
}

void createDraft(Draft *S, ListKicauan kicauanList, Word currentuser){
    twitDraft kicau;
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
        isiTwitDraft(kicau) = isiDraft;
        DATETIME D; CreateDATETIME(&D); dateTwitDraft(kicau) = D;

        Pushs(S, kicau);
        printf("Draf telah berhasil disimpan");
    }
    else if (isWordSimilar(currentWord, "TERBIT")){
        Twit drafTwit = twitDraftToTwit(&isiDraft, kicauanList, currentuser);
        insertLast_ListKicauan(&kicauanList, drafTwit);
        SuccessTwit(drafTwit);
    }
    else{
        return;
    }
}


void displayDraft(Draft *S, ListKicauan kicauanList, Word currentuser){
    if (IsEmpty_Draft(*S)){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else{
        twitDraft delVal;

        twitDraft topDraft = InfoTops(*S);
        printf("Ini draf terakhir anda:\n");
        printf("| ");
        TulisDATETIME(dateTwitDraft(topDraft));
        printf("\n");
        printf("| ");
        printWord(isiTwitDraft(topDraft));
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
            Pops(S, &delVal);
            printf("Draf telah berhasil dihapus!\n");
        }
        else if (isWordSimilar(currentWord, "UBAH")){
            Pops(S, &delVal);
            twitDraft kicauBaru;
            Word isiDraft;

            printf("Masukkan draf yang baru: \n");
            BacaDraft(&isiDraft);

            isiTwitDraft(kicauBaru) = isiDraft;
            DATETIME D; CreateDATETIME(&D); dateTwitDraft(kicauBaru) = D; 

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
                Pushs(S, kicauBaru);
            }
            else{
                Twit drafTwit = twitDraftToTwit(&isiDraft, kicauanList, currentuser);
                insertLast_ListKicauan(&kicauanList, drafTwit);
                SuccessTwit(drafTwit);
            }
        }
        else{
            Word isiDraft = isiTwitDraft(InfoTops(*S));
            Twit drafTwit = twitDraftToTwit(&isiDraft, kicauanList, currentuser);
            insertLast_ListKicauan(&kicauanList, drafTwit);
            SuccessTwit(drafTwit);
        }
    }
}