#include <stdio.h>
#include <stdlib.h>
#include "../datetime/datetime.c"
#include "../datetime/time.c"
#include "tree.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"

int main () {
    Tree t;
    addressTree p, p1, p2, p3, p4, p5, p6, p7;
    DATETIME d1, d2, d3, d4;
    int id1, id2, id3, id4;
    Word user1, user2, user3, user4, pesan1, pesan2, pesan3, pesan4;
    CreateTree(&t);
    p = Root(t);

    printf("Masukkan user 1 :\n");
    STARTWORD();
    user1 = currentWord;
    id1 = 1;
    CreateDATETIME(&d1);
    printf("Masukkan pesan 1 :\n");
    STARTWORD();
    pesan1 = currentWord;
    
    p1 = Alokasi(id1, user1, d1, pesan1);

    printf("Masukkan user 2 :\n");
    STARTWORD();
    user2 = currentWord;
    id2 = 123;
    CreateDATETIME(&d2);
    printf("Masukkan pesan 2 :\n");
    STARTWORD();
    pesan2 = currentWord;
    p2 = Alokasi(id2, user2, d2, pesan2);

    printf("Masukkan user 3 :\n");
    STARTWORD();
    user3 = currentWord;
    id3 = 12;
    CreateDATETIME(&d3);
    printf("Masukkan pesan 3 :\n");
    STARTWORD();
    pesan3 = currentWord;
    p3 = Alokasi(id3, user3, d3, pesan3);

    printf("Masukkan user 4 :\n");
    STARTWORD();
    user4 = currentWord;
    id4 = 456;
    CreateDATETIME(&d4);
    printf("Masukkan pesan 4 :\n");
    STARTWORD();
    pesan4 = currentWord;
    p4 = Alokasi(id4, user4, d4, pesan4);

    AddChild(&p, p1);
    AddChild(&p, p2);
    AddSibling(&p2, p3);
    AddSibling(&p2, p4);

    printTree(p,0);

    printf("\n%d\n", isIdTreeElmt(p, 456));
    printf("%d\n\n", isIdTreeElmt(p, 2));

    p5 = getAddressWithId(p, 12); // user3
    p6 = getAddressBefore(p, p5); // id = 123, user2

    if (NextSibling(p5) != NULL) { // Untuk mengatur NextSibling atau FirstChild dari address sebelum p5
        if(FirstChild(p6) == p5) {
            FirstChild(p6) = NextSibling(p5);
        }
        else {
            NextSibling(p6) = NextSibling(p5);
        }
    }
    deleteTree(p5);
    printTree(p, 0);

    return 0;
}