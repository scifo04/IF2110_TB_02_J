/* File : temanreq.h */
/* Definisi ADT Priority Queue Popularity dengan representasi Struktur Berkait */
/* Elemen queue terurut mengecil berdasarkan popularitas */

#ifndef TEMANREQ_H
#define TEMANREQ_H

#include "../boolean/boolean.h"
#include "../account/account.h"

/* Definisi elemen dan address */
typedef struct {
	Account account;
	int popularity;
} FriendRequest;

typedef FriendRequest ElType;
typedef struct node *Address;
typedef struct node { 
	ElType info;
	Address next;
} Node;

/* Type queue dengan ciri HEAD dan TAIL: */
typedef struct {
Address addrHead; /* alamat penghapusan */
Address addrTail; /* alamat penambahan */
} Queue;

/* Definisi list : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* ********* AKSES (Selektor) ********* */
/* Jika p adalah node dan q adalah Queue serta r adalah FriendRequest, maka akses elemen : */
#define NAME(p) (p)->info.account.username
#define ACCOUNT(p) (p)->info.account
#define POPULARITY(p) (p)->info.popularity
#define NEXT(p) (p)->next
#define INFO(p) (p)->info
#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail
#define HEAD(q) (q).addrHead->info

/* ********* Prototype ********* */
/* Prototype manajemen memori */
Address newNode(ElType x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
atau NIL jika alokasi gagal */

boolean isEmpty(Queue q);
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */

int length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x);
/* Proses: Mengalokasi x dan menambahkan x terurut mengecil pada q
jika alokasi berhasil; jika alokasi gagal q tetap */
void dequeue(Queue *q, ElType *x);
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */


/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/

#endif