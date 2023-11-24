#ifndef UTAS_H
#define UTAS_H
#include "../boolean/boolean.h"
#include "../datetime/datetime.h"
#include "../wordmachine/wordmachine.h"

/* MODUL UTAS */
/* *** Definisi Type Utas *** */
typedef struct Node* AddressUtas;
typedef struct Node {
  DATETIME waktuUtas;
  Word isiTwitUtas;
  AddressUtas Sambungan;
} TwitUtas;

#define waktuUtas(U) (U)->waktuUtas
#define isiTwitUtas(U) (U)->isiTwitUtas
#define Sambungan(U) (U)->Sambungan

/* **************************************************************** */
/* DEFINISI UTAS                                                    */
/* **************************************************************** */

// INDEX DIMULAI DARI 1, INDEX 0 UNTUK KICAUAN UTAMA

AddressUtas newUtas (DATETIME T, Word isiTwitUtas); // Alokasi elemen, newNode
void CreateUtas (AddressUtas *U);

/* Test Kosong */
boolean isEmpty_Utas (AddressUtas U);

int lengthUtas(AddressUtas U);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/* TAMBAH DAN HAPUS ELEMEN */
/* ASUMSI INDEX VALID */
void insertAtUtas(AddressUtas *U, DATETIME D, Word IsiUtas, int idx);
void insertLastUtas(AddressUtas *U, DATETIME D, Word IsiUtas);
void deleteAtUtas(AddressUtas *U, int idx);

void cetakUtas(AddressUtas U, Word PembuatUtas);

void deallocateAllUtas(AddressUtas *U);
#endif