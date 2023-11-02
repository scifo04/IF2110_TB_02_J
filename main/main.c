#include <stdio.h>
#include <stdlib.h>
#include "../lib/adt.h"

static boolean allowexit = false;
static ListAcc acc;
static boolean hasLogged = false;
static Account currentuser;

void enter() {
    printf("\n");
}

void inisialisasi() {
    Word word_inpute;
    printf(".______    __    __  .______      .______    __  .______      \n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\     \n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");
    enter();
    printf("Selamat datang di BurBir.\n");
    enter();
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    enter();
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    STARTWORD();
    word_inpute = currentWord;
}

void load (Word W);

// COMMAND READERS
Word copyWord_Exit () {
    Word W;
    (W).TabWord[0] = 'E';
    (W).TabWord[1] = 'X';
    (W).TabWord[2] = 'I';
    (W).TabWord[3] = 'T';
    (W).Length = 4;
    return W;
}

Word copyWord_Daftar () {
    Word W;
    (W).TabWord[0] = 'D';
    (W).TabWord[1] = 'A';
    (W).TabWord[2] = 'F';
    (W).TabWord[3] = 'T';
    (W).TabWord[4] = 'A';
    (W).TabWord[5] = 'R';
    (W).Length = 6;
    return W;
}

Word copyWord_Masuk () {
    Word W;
    (W).TabWord[0] = 'M';
    (W).TabWord[1] = 'A';
    (W).TabWord[2] = 'S';
    (W).TabWord[3] = 'U';
    (W).TabWord[4] = 'K';
    (W).Length = 5;
    return W;
}

Word copyWord_Keluar () {
    Word W;
    (W).TabWord[0] = 'K';
    (W).TabWord[1] = 'E';
    (W).TabWord[2] = 'L';
    (W).TabWord[3] = 'U';
    (W).TabWord[4] = 'A';
    (W).TabWord[5] = 'R';
    (W).Length = 6;
    return W;
}

Word copyWord_Ganti_Profil () {
    Word W;
    (W).TabWord[0] = 'G';
    (W).TabWord[1] = 'A';
    (W).TabWord[2] = 'N';
    (W).TabWord[3] = 'T';
    (W).TabWord[4] = 'I';
    (W).TabWord[5] = '_';
    (W).TabWord[6] = 'P';
    (W).TabWord[7] = 'R';
    (W).TabWord[8] = 'O';
    (W).TabWord[9] = 'F';
    (W).TabWord[10] = 'I';
    (W).TabWord[11] = 'L';
    (W).Length = 12;
    return W;
}

// DAFTAR
void Daftar () {
    Account A;
    CreateAccount(&A);
    printf("\n");
    if (!hasLogged) {
        if (!isFull_Account(acc)) {
            while (true) {
                readUsername(&A);
                if (!nameAvailable(acc,A.username)) {
                    break;
                } else {
                    printf("Anda seharusnya lebih orisinil! Carilah nama pengguna yang baru!\n");
                }
            }
            readPassword(&A);
            insertLast_Account((&acc),A);
            printf("Registrasi berhasil. Silakan nikmati fitur-fitur yang ada di BurBir!\n");
        } else {
            printf("BurBir sudah tidak bisa menghandle lebih banyak akun lagi! Coba lakukan pengusiran!\n");
        }
    } else {
        printf("Kamu sudah login sehingga tidak bisa daftar, sana nge-BurBir dulu!\n");
    }
    printf("\n");
}

// MASUK
void Masuk () {
    Account A;
    if (!hasLogged) {
        while (true) {
            readUsername(&A);
            if (nameAvailable(acc,A.username)) {
                break;
            } else {
                printf("Username tidak ditemukan! Coba diinget-inget lagi!\n");
            }
        }
        while (true) {
            readPassword(&A);
            if (passAvailable(acc,A.password)) {
                break;
            } else {
                printf("Waduh! Password kamu belum tepat! Coba masukkin password yang benar!\n");
            }
        }
        printf("Wawww!! Kamu sudah masuk ke BurBir dengan username ");
        printWord(A.username);
        printf(". Silakan menelusuri dunia BurBir bersama Ande-Ande Lumut!!!");
        currentuser = A;
        hasLogged = true;
    } else {
        printf("Kamu sudah login sehingga tidak perlu login lagi, sana nge-BurBir dulu!");
    }
    printf("\n");
}

// KELUAR
void Keluar () {
    if (hasLogged) {
        printf("Kamu sudah berhasil logout (Cepet banget :') ). Sampai jumpa di pertemuan berikutnya!\n");
        hasLogged = false;
    } else {
        printf("Belum masuk kok dah keluar? Silakan login dulu!\n");
    }
    printf("\n");
}

// GANTI_PROFIL
void Ganti_Profil () {
    if (hasLogged) {
        printf("| Nama: ");
        printWord(currentuser.username);
        printf("\n");
        printf("| Bio Akun: ");
        if (currentuser.bio.Length > 0) {
            printWord(currentuser.bio);
        }
        printf("\n");
        printf("| No HP: ");
        if (currentuser.phone_num.Length > 0) {
            printWord(currentuser.phone_num);
        }
        printf("\n");
        printf("| Weton: ");
        if (currentuser.weton.Length > 0) {
            printWord(currentuser.weton);
        }
        printf("\n");
        printf("\n");
        readBio(&currentuser);
        readPhone_Num(&currentuser);
        readWeton(&currentuser);
        // displayAccount(currentuser);
    }
}

void readCommand (Word W) {
    Word Reader;
    if (wordSimilar(W,copyWord_Exit())) {
        allowexit = true;
    } else if (wordSimilar(W,copyWord_Daftar())) {
        Daftar();
        printf("\n");
    } else if (wordSimilar(W,copyWord_Masuk())) {
        Masuk();
        printf("\n");
    } else if (wordSimilar(W,copyWord_Keluar())) {
        Keluar();
        printf("\n");
    } else if (wordSimilar(W,copyWord_Ganti_Profil())) {
        Ganti_Profil();
        printf("\n");
    }
}

int main() {
    printf("\e[1;1H\e[2J");
    boolean allowprint = false;
    CreateListAccount(&acc);
    while (true) {
        inisialisasi();
        while (true) {
            printf(">> ");
            STARTWORD();
            readCommand(currentWord);
            if (allowexit) {
                break;
            }
        }
        if (allowexit) {
            break;
        }
    }
    return 0;
}