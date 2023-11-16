#ifndef KICAUAN_H
#define KICAUAN_H
#include "../boolean/boolean.h"
#include "../datetime/datetime.h" 
#include "../wordmachine/wordmachine.h" 
#include "../account/account.h"
#include "../affection/affection.h"
#include "../tree/tree.h"

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

/* MODUL ADT SEDERHANA TWIT*/
/* *** Definisi TYPE Twit *** */
typedef struct {
    int idKicau;
    int like;
    int idUtas;
    Account author;
    DATETIME datetime;
    Word isiTwit; /*Panjang maksimal 280 Karakter*/
    Word tagar;
    Tree Balasan;
    AddressUtas Utas;
} Twit;

/* *** Notasi Akses: Selektor Twit *** */
#define ID(K) (K).idKicau
#define IDUtas(K) (K).idUtas
#define Like(K) (K).like
#define Author(K) (K).author
#define DateTime(K) (K).datetime
#define IsiTwit(K) (K).isiTwit
#define Tagar(K) (K).tagar
#define Balasan(K) (K).Balasan
#define Utas(K) (K).Utas

/* MODUL KICAUAN DYNAMIC LIST */

/*  Kamus Umum */
#define KICAU_IDX_MIN 0
/* Indeks minimum list */
#define KICAU_IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Twit ElKicauanType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElKicauanType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListKicauan;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListKicauan, cara deklarasi dan akses: */
/* Deklarasi : l : ListKicauan */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define ListKicauan_NEFF(l) (l).nEff
#define ListKicauan_BUFFER(l) (l).buffer
#define ListKicauan_ELMT(l, i) (l).buffer[i]
#define ListKicauan_CAPACITY(l) (l).capacity

/* **************************************************************** */
/* DEFINISI UTAS                                                    */
/* **************************************************************** */

void CreateUtas (AddressUtas *U);

/* **************************************************************** */
/* DEFINISI TWIT                                                    */
/* **************************************************************** */

/* Konstruktor: Membentuk Twit dari komponen-komponennya*/
void CreateTwit(Twit *K, ListKicauan kicauan, Account currentuser);

/* Membaca Twit */
/* Twit yang dimasukkan terpotong secara otomatis dengan jumlah karakter maksimum 280.
Twit tidak boleh berisi spasi*/
void BacaTwit(Word *isiTwit);

/*Menambahkan tagar pada Twit*/
void BacaTagar(Word *tagar);

/* Detail Twit*/
void DetailTwit(Twit K);

/* Pesan Berhasil Membuat Twit*/
void SuccessTwit(Twit K);


/* ********************************************************************************************************************************** */
/* ********************************************************************************************************************************** */

/* ********** FITUR ********** */
/*Pengguna dapat menyukai suatu Twit dengan indeks yang vali, milik pengguna sendiri,
milik teman, ataupun milik akun publik*/
void LikeKicauan(ListKicauan *l, int idKicauan, Account currentuser, Affection friends, ListAcc accounts);

void EditKicauan(ListKicauan *l, int idKicauan, Account currentuser, ListAcc accounts);


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListKicauan(ListKicauan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListKicauan(ListKicauan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength_ListKicauan(ListKicauan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListKicauan(ListKicauan l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff_ListKicauan(ListKicauan l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty_ListKicauan(ListKicauan l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull_ListKicauan(ListKicauan l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
// void readList_ListKicauan(ListKicauan *l);
/*Berisi serangkaian fungsi untuk membaca kicauan.config dan memasukannya ke List Dinamik Kicauan
Tapi kayanya nanti bikin file khusus deh readconfig.c*/

void DisplayListKicauan(ListKicauan l, Account currentuser, Affection friends, ListAcc accounts);
/* Menuliskan Kicauan milik sendiri dan teman.
Proses: Melakukan traversal terhadap kicauan dengan mengecek Author setiap elemen Twit K.
Jika Author(K) adalah diri sendiri, atau teman, maka tampilkan.*/

/* ********** OPERASI LAIN ********** */
void copyList_ListKicauan(ListKicauan lIn, ListKicauan *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListKicauan(ListKicauan *l, ElKicauanType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListKicauan(ListKicauan *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

#endif