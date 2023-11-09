/* ADT N-ARY TREE */

#ifndef TREE_H
#define TREE_H

#include "../boolean/boolean.h"
#include "../liststatik/liststatik.h"
#include "../wordmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"
#include "../matrix/matrix.h"
#include "../datetime/datetime.h"

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */

/* Definisi Type Data */
typedef struct tNode *addressTree;
typedef struct tNode {
    int Data;
    addressTree firstChild;
    addressTree nextSibling;
} Node;

typedef struct {
    addressTree root;
} Tree;

typedef Tree ListTreeStatik_ElType;
typedef int ListTreeStatik_IdxType;
typedef struct {
    ListTreeStatik_ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListTreeStatik;


// #define Id(P) (P)->id
// #define User(P) (P)->user
// #define DateTime(P) (P)->d
// #define Pesan(P) (P)->pesan
#define Data(P) (P)->Data
#define FirstChild(P) (P)->firstChild
#define NextSibling(P) (P)->nextSibling
#define Root(T) (T).root
// #define LISTELMT(l, i) (l).contents[(i)]

/* Definisi Pohon : */
/* Pohon kosong : P = Nil */
/* Setiap elemen dengan addressTree P dapat diacu Info(P), FirstChild(P), NextSibling(P) */
/* Elemen terakhir pohon : jika NextSibling(P) = Nil, maka P adalah elemen terakhir pohon */

void CreateTree(Tree *T);

addressTree Alokasi(int data);

void Dealokasi(addressTree P);

void AddChild(addressTree *P, addressTree C);

void AddSibling(addressTree *P, addressTree S);

void deleteTree(addressTree P);

void printSiblings(addressTree P);

void printChild(addressTree P);

void printTree (addressTree P, int h);

boolean isTreeElmt (addressTree P, int X);

addressTree getAddressBefore (addressTree P, addressTree R);

// int Treemachine(char string[], Matrix *m);

// void matrixToTree (Matrix m, int N, Tree *T);

// addressTree getParent(addressTree root,addressTree C);

// ListStatik getChild(addressTree parent);

// ListStatik getAllNodes(addressTree parent);

// void CreateListTreeStatik(ListTreeStatik *l);

// int listLength_ListTreeStatik(ListTreeStatik l);

// boolean isEmpty_ListTreeStatik(ListTreeStatik l);

// void insertLast_ListTreeStatik(ListTreeStatik *l, ListTreeStatik_ElType val);

// void printList_ListTreeStatik(ListTreeStatik l);

#endif