#include <stdio.h>
#include <stdlib.h>
#include "../datetime/datetime.c"
#include "../datetime/time.c"
#include "tree.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"

int main () {
    Tree t;
    addressTree p, q, r, s, u;
    DATETIME d;
    int angka;
    Word input, user, pesan;
    ListAcc LAcc;
    Affection aff;

    printf("Masukkan input: ");
    STARTWORD();
    input = currentWord;

    printf("Masukkan username: ");
    STARTWORD();
    user = currentWord;
    
    angka = input.TabWord[0] - '0';

    switch (angka) {
        case 1: // Tree kosong
            CreateTree(&t);
            p = Root(t);
            if (p == NULL) {
                printf("Kosong");
            }
            break;

        case 2: // Alokasi berhasil
            printf("Masukkan pesan: ");
            STARTWORD();
            CreateDATETIME(&d);

            p = Alokasi(3, user, d, currentWord);
            printf("%d", Id(p));
            printf("\n");
            printWord(User(p));
            printf("\n");
            TulisDATETIME(Datetime(p));
            printWord(Pesan(p));
            break;

        case 3: // AddChild
            CreateTree(&t);
            p = Root(t);
            printf("Masukkan pesan: ");
            STARTWORD();
            CreateDATETIME(&d);

            q = Alokasi(3, user, d, currentWord);
            r = Alokasi(4, user, d, currentWord);
            AddChild(&p, q);
            AddChild(&p, r);
            printTree(p, 0);
            break;

        case 4: // AddSibling
            CreateTree(&t);
            p = Root(t);
            printf("Masukkan pesan: ");
            STARTWORD();
            CreateDATETIME(&d);

            q = Alokasi(3, user, d, currentWord);
            r = Alokasi(4, user, d, currentWord);
            s = Alokasi(5, user, d, currentWord);
            u = Alokasi(6, user, d, currentWord);
            AddChild(&p, q);
            AddChild(&q, r);
            AddSibling(&q, s);
            AddSibling(&r, u);
            printTree(p, 0);
            break;
        
        case 5: // IsIdTreeElmt
            CreateTree(&t);
            p = Root(t);
            printf("Masukkan pesan: ");
            STARTWORD();
            CreateDATETIME(&d);

            q = Alokasi(3, user, d, currentWord);
            r = Alokasi(4, user, d, currentWord);
            s = Alokasi(5, user, d, currentWord);
            u = Alokasi(6, user, d, currentWord);
            AddChild(&p, q);
            AddChild(&q, r);
            AddSibling(&q, s);
            AddSibling(&r, u);
            printf("%d\n", isIdTreeElmt(p, 3));
            printf("%d", isIdTreeElmt(p, 100));
            break;
        
        case 6: // getAddressBefore
            CreateTree(&t);
            p = Root(t);
            printf("Masukkan pesan: ");
            STARTWORD();
            CreateDATETIME(&d);

            q = Alokasi(3, user, d, currentWord);
            r = Alokasi(4, user, d, currentWord);
            s = Alokasi(5, user, d, currentWord);
            AddChild(&p, q);
            AddChild(&q, r);
            AddSibling(&r, s);
            u = getAddressBefore(p, s);
            printTree(p, 0);
            printf("%d\n", Id(u));

            u = getAddressBefore(p, r);
            printf("%d\n", Id(u));
            break;

        case 7: // getAddressWithId
            CreateTree(&t);
            p = Root(t);
            printf("Masukkan pesan: ");
            STARTWORD();
            CreateDATETIME(&d);

            q = Alokasi(3, user, d, currentWord);
            r = Alokasi(4, user, d, currentWord);
            s = Alokasi(5, user, d, currentWord);
            AddChild(&p, q);
            AddChild(&q, r);
            AddSibling(&r, s);

            u = getAddressWithId(p, 3);
            printf("%d\n", Id(u));

            u = getAddressWithId(p, 4);
            printf("%d\n", Id(u));

            u = getAddressWithId(p, 5);
            printf("%d\n", Id(u));
        
        case 8: // getParent
            CreateTree(&t);
            p = Root(t);
            printf("Masukkan pesan: ");
            STARTWORD();
            CreateDATETIME(&d);

            q = Alokasi(3, user, d, currentWord);
            r = Alokasi(4, user, d, currentWord);
            s = Alokasi(5, user, d, currentWord);
            AddChild(&p, q);
            AddChild(&q, r);
            AddChild(&r, s);

            printTree(p, 0);
            u = getParent(p, s);
            printf("%d", Id(u));

        case 9: // Menghapus tree dari root
            CreateTree(&t);
            p = Root(t);
            printf("Masukkan pesan: ");
            STARTWORD();
            CreateDATETIME(&d);

            q = Alokasi(3, user, d, currentWord);
            r = Alokasi(4, user, d, currentWord);
            s = Alokasi(5, user, d, currentWord);
            AddChild(&p, q);
            AddChild(&q, r);
            AddChild(&r, s);

            printTree(p, 0);
            deallocateAllTree(&p);
            printTree(p, 0);
            printf("\nApakah p NULL = ");
            printf("%d\n", (p == NULL));
    }
    return 0;
}