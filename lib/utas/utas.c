#include <stdlib.h>
#include "utas.h"

extern int idUtas;

/* MODUL UTAS */
AddressUtas newUtas (DATETIME T, Word isiUtas){ // Alokasi elemen, newNode
    AddressUtas U;
    U = (AddressUtas) malloc (sizeof(TwitUtas));
    if (U != NULL){
        waktuUtas(U) = T;
        isiTwitUtas(U) = isiUtas;
        Sambungan(U) = NULL;
    }
    return U;
}

void CreateUtas (AddressUtas *U){
    *U = NULL;
}

/* Test Kosong */
boolean isEmpty_Utas (AddressUtas U){
    return (U == NULL);
}

int lengthUtas(AddressUtas U){
    if (isEmpty_Utas(U)){return 0;}
    return (1 + lengthUtas(Sambungan(U)));
}

// INDEX DIMULAI DARI 1, INDEX 0 UNTUK KICAUAN UTAMA

/* TAMBAH DAN HAPUS ELEMEN */
/* ASUMSI INDEX VALID */
void insertAtUtas(AddressUtas *U, DATETIME D, Word IsiUtas, int idx){
    AddressUtas NewUtas = newUtas(D, IsiUtas);
    if (NewUtas != NULL){
        if (idx == 1){
            Sambungan(NewUtas) = *U;
            *U = NewUtas;
        } else {
            AddressUtas P = *U;
            for (int i = idx; i > 2; i--){P = Sambungan(P);}
            Sambungan(NewUtas) = Sambungan(P);
            Sambungan(P) = NewUtas;
        }
    }
}

void insertLastUtas(AddressUtas *U, DATETIME D, Word IsiUtas){
    insertAtUtas(U, D, IsiUtas, (lengthUtas(*U) + 1));
}

void deleteAtUtas(AddressUtas *U, int idx){
    AddressUtas P = *U;
    if (idx == 1){
        *U = Sambungan(*U);
    } else {
        for (int i = idx; i > 2; i--){P = Sambungan(P);}
        AddressUtas PP = P;
        P = Sambungan(P);
        Sambungan(PP) = Sambungan(P);
    }
    free(P);
}

void cetakUtas(AddressUtas U, Word PembuatUtas){
    AddressUtas P = U;
    int idx = 1;
    while (P != NULL){
        printf("   | INDEX = %d\n   | ", idx);
        printWord(PembuatUtas);
        printf("\n   | ");
        TulisDATETIME(waktuUtas(P));
        printf("\n   | ");
        printWord(isiTwitUtas(P));
        printf("\n\n");
        P = Sambungan(P); idx++;
    }
}