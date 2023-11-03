#ifndef TWIT_H
#define TWIT_H

#include "../boolean/boolean.h"
#include "../datetime/datetime.h"
#include "../wordmachine/wordmachine.h"
#include "../account/account.h"
// include ADT Tree Balasan
// include ADT Linked List Utas

/* *** Definisi TYPE Twit *** */
typedef struct {
    int idKicau;
    int like; 
    int idUtas;
    Account author; 
    DATETIME datetime;
    Word isiTwit; /*Panjang maksimal 280 Karakter*/
    Word tagar;
    //Tree Balasan;
    //ListUtas Utas;
} Twit;

/* *** Notasi Akses: Selektor Twit *** */
#define ID(K) (K).id
#define IDUtas(K) (K).idUtas
#define Like(K) (K).like
#define Author(K) (K).author
#define DateTime(K) (K).datetime
#define IsiTwit(K) (K).isiTwit
#define Tagar(K) (K).tagar
// #define Balasan(K) (K).Balasan
// #define Utas(K) (K).Utas

/* **************************************************************** */
/* DEFINISI TWIT                                                */
/* **************************************************************** */

/* Konstruktor: Membentuk Twit dari komponen-komponennya*/
void CreateTwit(Twit *K, Word isiTwit, Word tagar);

/* Membaca Twit */
/* Twit yang dimasukkan terpotong secara otomatis dengan jumlah karakter maksimum 280.
Twit tidak boleh berisi spasi*/
void BacaTwit(Twit *K);

/* Detail Twit*/
void DetailTwit(Twit K);

/* Pesan Berhasil Membuat Twit*/
void SuccessTwit();
