/* File : draft.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran dinamis*/
/* TOP adalah alamat elemen puncak */
#ifndef DRAFT_H
#define DRAFT_H

#include "../boolean/boolean.h"
#include "../kicauan/twit.h"

/* Nil adalah stack dengan elemen kosong . */
#define Nil -1

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).buffer[(S).TOP]
#define Cap(S) (S).capacity

typedef Twit infotype;
typedef int address;   /* indeks tabel */

typedef struct { 
  infotype* buffer; /* tabel penyimpan elemen */
  int capacity;
  address TOP;  /* alamat TOP: elemen puncak */
} Draft;


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty_Draft(Draft *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas 0 */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
/* Mengirim true jika Draft kosong: lihat definisi di atas */
boolean IsEmpty_Draft(Draft S);

/* Mengirim true jika tabel penampung nilai elemen stack penuh */
boolean IsFull_Draft(Draft S);

/* ************ Menambahkan sebuah elemen ke Draft ************ */
/* Menambahkan X sebagai elemen Draft S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void Push(Draft * S, infotype X);

/* ************ Menghapus sebuah elemen Draft ************ */
/* Menghapus X dari Draft S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void Pop(Draft * S, infotype* X);

/* ************ Mengompress kapasitas Draft ************ */
/* Mengompress kapasitas draft jika (sepi) efisensi kapasitas <= 0.25. */
/* I.S. S adalah Draft yang sepi */
/* F.S. kapasitas Draft menjadi 50% dari kapasitas sebelumnya */
void compressDraft(Draft *S);

/* ************ Membuat Draft Kicau ************ */
/* Membaca draft dan melakukan operasi HAPUS atau SIMPAN atau TERBIT  */
/* I.S. S terdefinisi */
/* F.S. Jika SIMPAN maka kicau ditambahkan ke draft
        Jika TERBIT maka kicau langsung diterbitkan
        JIKA HAPUS maka operasi sebelumnya diabaikan
*/
void createDraft(Draft *S);

/* ************ Menampilkan Draft Kicau ************ */
/* Menampilkan draft terbaru (time-based) dan melakukan operasi KEMBALI atau HAPUS atau UBAH atau TERBIT  */
/* I.S. S mungkin kosong */
/* F.S. Jika KEMBALI maka nothing
        JIKA HAPUS maka draft kicau tersebut dihapus
        Jika UBAH maka pengguna menulis ulang isi draft lalu melakukan operasi HAPUS atau SIMPAN atau TERBIT
        Jika TERBIT maka kicau langsung diterbitkan
*/
void displayDraft(Draft *S);

#endif