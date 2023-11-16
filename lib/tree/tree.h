#ifndef TREE_H
#define TREE_H

#include "../boolean/boolean.h"
#include "../wordmachine/wordmachine.h"
#include "../datetime/datetime.h"

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */

/* Definisi Type Data */
typedef struct tnode *addressTree;
typedef struct tnode {
    int id;
    Word user;
    DATETIME d;
    Word pesan;
    addressTree firstChild;
    addressTree nextSibling;
} tNode;

typedef struct {
    addressTree root;
} Tree;

#define Id(P) (P)->id
#define User(P) (P)->user
#define Datetime(P) (P)->d
#define Pesan(P) (P)->pesan
#define FirstChild(P) (P)->firstChild
#define NextSibling(P) (P)->nextSibling
#define Root(T) (T).root
// #define LISTELMT(l, i) (l).contents[(i)]

/* Definisi Pohon : */
/* Pohon kosong : P = Nil */
/* Setiap elemen dengan addressTree P dapat diacu Info(P), FirstChild(P), NextSibling(P) */
/* Elemen terakhir pohon : jika NextSibling(P) = Nil, maka P adalah elemen terakhir pohon */

void CreateTree(Tree *T);

addressTree Alokasi(int id, Word user, DATETIME d, Word pesan);

void Dealokasi(addressTree P);

void AddChild(addressTree *P, addressTree C);

void AddSibling(addressTree *P, addressTree S);

void deleteTree(addressTree P);

void printSiblings(addressTree P);

void printChild(addressTree P);

void printTree (addressTree P, int h);

boolean isIdTreeElmt(addressTree P, int id);

addressTree getAddressBefore (addressTree P, addressTree R);

addressTree getAddressWithId (addressTree P, int id);

#endif