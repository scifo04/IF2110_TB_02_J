#include <stdio.h>
#include "twit.h"
#include "kicauan.h"

/* **************************************************************** */
/* DEFINISI TWIT                                                */
/* **************************************************************** */

/* Konstruktor: Membentuk Twit dari komponen-komponennya*/
void CreateTwit(Twit *K){
    ID(*K) = listLength_ListKicauan(ListKicauan); /*Bingung. ListKicauan adalah suatu variabel global di main.*/
    IDUtas(*K) = -1; /*Secara default, Twit bukanlah Utas, kecuali ditandai sebagai Utas*/
    Like(*K) = 0;
    Author(*K) = currentuser; /*Bingung. Misal Account adalah variabel global yang selalu di-update di main. */
    DATETIME D; CreateDATETIME(&D); DateTime(*K) = D; 
    Word isiTwit; BacaTwit(&isiTwit); IsiTwit(*K) = isiTwit;
    Word tagar; BacaTagar(&tagar); Tagar(*K) = tagar;
    // Balasan(*K) = CreateTreeBalasan;
    // Utas(*K) = CreateLinkedListUtas;
}
/* Membaca Twit */
/* Twit yang dimasukkan terpotong secara otomatis dengan jumlah karakter maksimum 280.
Twit tidak boleh berisi spasi. Hal ini sudah di-handle di wordmachine. Panjang maksimal Word adalah 280.*/
void BacaTwit(Word *isiTwit){
    printf("Masukkan kicauan baru: \n");
    STARTWORD();
    printf("\n");
    *isiTwit = currentWord;
    if(isiTwit==""){ //W mungkin tidak berisi apa-apa
        while(isiTwit==""){
            printf("Kicauan tidak boleh hanya berisi spasi!\n")
            printf("Masukkan kicauan: \n");
            STARTWORD();
            printf("\n");
            *isiTwit = currentWord;
        }
    }
}

/*Membaca Tagar*/
void BacaTagar(Word *tagar){
    printf("Masukkan tagar: \n");
    STARTWORD();
    printf("\n");
    *tagar = currentWord;
    if(tagar==""){ //currentWord mungkin tidak berisi apa-apa
        while(tagar==""){
            printf("Tagar tidak boleh hanya berisi spasi!\n")
            printf("Masukkan tagar: \n");
            STARTWORD();
            printf("\n");
            *tagar = currentWord;
        }
    }
}

/* Detail Twit*/
void DetailTwit(Twit K){
    printf("| ID = %d\n", ID(K));
    printf("| ")
    printWord(Author(K));
    printf("\n");
    printf("| ")
    TulisDATETIME(DateTime(K));
    printf("\n");
    printf("| ")
    printWord(isiTwit(K));
    printf("\n");
    printf("| #")
    printWord(Tagar(K));
    printf("\n");
    printf("| Disukai = %d\n", Like(K));
}

/* Pesan Berhasil Membuat Twit*/
void SuccessTwit(Twit K){
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    DetailTwit(K);
}