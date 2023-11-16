#include <stdio.h>
#include <stdlib.h>
#include "../lib/adt.h"

static boolean allowexit = false;
static ListAcc acc;
static boolean hasLogged = false;
static Account currentuser;
static Affection friends;
ListKicauan Kicauan;

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
Word copyWord_Ya () {
    Word W;
    (W).TabWord[0] = 'Y';(W).TabWord[1] = 'A';
    (W).Length = 2;
    return W;
}

Word copyWord_Tidak () {
    Word W;
    (W).TabWord[0] = 'T';(W).TabWord[1] = 'I';(W).TabWord[2] = 'D';(W).TabWord[3] = 'A';(W).TabWord[4] = 'K';
    (W).Length = 5;
    return W;
}

Word copyWord_Exit () {
    Word W;
    (W).TabWord[0] = 'E';(W).TabWord[1] = 'X';(W).TabWord[2] = 'I';(W).TabWord[3] = 'T';
    (W).Length = 4;
    return W;
}

Word copyWord_Daftar () {
    Word W;
    (W).TabWord[0] = 'D';(W).TabWord[1] = 'A';(W).TabWord[2] = 'F';(W).TabWord[3] = 'T';(W).TabWord[4] = 'A';
    (W).TabWord[5] = 'R';
    (W).Length = 6;
    return W;
}

Word copyWord_Masuk () {
    Word W;
    (W).TabWord[0] = 'M';(W).TabWord[1] = 'A';(W).TabWord[2] = 'S';(W).TabWord[3] = 'U';(W).TabWord[4] = 'K';
    (W).Length = 5;
    return W;
}

Word copyWord_Keluar () {
    Word W;
    (W).TabWord[0] = 'K';(W).TabWord[1] = 'E';(W).TabWord[2] = 'L';(W).TabWord[3] = 'U';(W).TabWord[4] = 'A';(W).TabWord[5] = 'R';
    (W).Length = 6;
    return W;
}

Word copyWord_Ganti_Profil () {
    Word W;
    (W).TabWord[0] = 'G';(W).TabWord[1] = 'A';(W).TabWord[2] = 'N';(W).TabWord[3] = 'T';(W).TabWord[4] = 'I';(W).TabWord[5] = '_';
    (W).TabWord[6] = 'P';(W).TabWord[7] = 'R';(W).TabWord[8] = 'O';(W).TabWord[9] = 'F';(W).TabWord[10] = 'I';(W).TabWord[11] = 'L';
    (W).Length = 12;
    return W;
}

Word copyWord_Lihat_Profil () {
    Word W;
    (W).TabWord[0] = 'L';(W).TabWord[1] = 'I';(W).TabWord[2] = 'H';(W).TabWord[3] = 'A';(W).TabWord[4] = 'T';(W).TabWord[5] = '_';
    (W).TabWord[6] = 'P';(W).TabWord[7] = 'R';(W).TabWord[8] = 'O';(W).TabWord[9] = 'F';(W).TabWord[10] = 'I';(W).TabWord[11] = 'L';
    (W).Length = 12;
    return W;
}

Word copyWord_Atur_Jenis_Akun () {
    Word W;
    (W).TabWord[0] = 'A';(W).TabWord[1] = 'T';(W).TabWord[2] = 'U';(W).TabWord[3] = 'R';(W).TabWord[4] = '_';(W).TabWord[5] = 'J';
    (W).TabWord[6] = 'E';(W).TabWord[7] = 'N';(W).TabWord[8] = 'I';(W).TabWord[9] = 'S';(W).TabWord[10] = '_';(W).TabWord[11] = 'A';
    (W).TabWord[12] = 'K';(W).TabWord[13] = 'U';(W).TabWord[14] = 'N';
    (W).Length = 15;
    return W;
}

Word copyWord_Ubah_Foto_Profil () {
    Word W;
    (W).TabWord[0] = 'U';(W).TabWord[1] = 'B';(W).TabWord[2] = 'A';(W).TabWord[3] = 'H';(W).TabWord[4] = '_';(W).TabWord[5] = 'F';
    (W).TabWord[6] = 'O';(W).TabWord[7] = 'T';(W).TabWord[8] = 'O';(W).TabWord[9] = '_';(W).TabWord[10] = 'P';(W).TabWord[11] = 'R';
    (W).TabWord[12] = 'O';(W).TabWord[13] = 'F';(W).TabWord[14] = 'I';(W).TabWord[15] = 'L';
    (W).Length = 16;
    return W;
}

Word copyWord_Daftar_Teman () {
    Word W;
    (W).TabWord[0] = 'D';(W).TabWord[1] = 'A';(W).TabWord[2] = 'F';(W).TabWord[3] = 'T';(W).TabWord[4] = 'A';(W).TabWord[5] = 'R';
    (W).TabWord[6] = '_';(W).TabWord[7] = 'T';(W).TabWord[8] = 'E';(W).TabWord[9] = 'M';(W).TabWord[10] = 'A';(W).TabWord[11] = 'N';
    (W).Length = 12;
    return W;
}

Word copyWord_Hapus_Teman () {
    Word W;
    (W).TabWord[0] = 'H';(W).TabWord[1] = 'A';(W).TabWord[2] = 'P';(W).TabWord[3] = 'U';(W).TabWord[4] = 'S';(W).TabWord[5] = '_';
    (W).TabWord[6] = 'T';(W).TabWord[7] = 'E';(W).TabWord[8] = 'M';(W).TabWord[9] = 'A';(W).TabWord[10] = 'N';
    (W).Length = 11;
    return W;
}
Word copyWord_Balas() {
    Word w;
    w.Length = 5;
    w.TabWord[0] = 'B'; w.TabWord[1] = 'A'; w.TabWord[2] = 'L'; w.TabWord[3] = 'A'; w.TabWord[4] = 'S';
    return w;
}

Word copyWord_Balasan() {
    Word w;
    w.Length = 7;
    w.TabWord[0] = 'B'; w.TabWord[1] = 'A'; w.TabWord[2] = 'L'; w.TabWord[3] = 'A'; w.TabWord[4] = 'S'; w.TabWord[5] = 'A';
    w.TabWord[6] = 'N';
    return w;
}

Word copyWord_hapusBalasan() {
    Word w;
    w.Length = 13;
    w.TabWord[0] = 'H'; w.TabWord[1] = 'A'; w.TabWord[2] = 'P'; w.TabWord[3] = 'U'; w.TabWord[4] = 'S'; w.TabWord[5] = '_';
    w.TabWord[6] = 'B'; w.TabWord[7] = 'A'; w.TabWord[8] = 'L'; w.TabWord[9] = 'A'; w.TabWord[10] = 'S'; w.TabWord[11] = 'A';
    w.TabWord[12] = 'N';
    return w;
}

Word copyWord_Kicau() {
    Word w;
    w.Length = 5;
    w.TabWord[0] = 'K'; w.TabWord[1] = 'I'; w.TabWord[2] = 'C'; w.TabWord[3] = 'A'; w.TabWord[4] = 'U';
    return w;
}

Word copyWord_Kicauan() {
    Word w;
    w.Length = 7;
    w.TabWord[0] = 'K'; w.TabWord[1] = 'I'; w.TabWord[2] = 'C'; w.TabWord[3] = 'A'; w.TabWord[4] = 'U'; w.TabWord[5] = 'A';
    w.TabWord[6] = 'N';
    return w;
}

Word copyWord_sukaKicauan() {
    Word w;
    w.Length = 12;
    w.TabWord[0] = 'S'; w.TabWord[1] = 'U'; w.TabWord[2] = 'K'; w.TabWord[3] = 'A'; w.TabWord[4] = '_'; w.TabWord[5] = 'K';
    w.TabWord[6] = 'I'; w.TabWord[7] = 'C'; w.TabWord[8] = 'A'; w.TabWord[9] = 'U'; w.TabWord[10] = 'A'; w.TabWord[11] = 'N';
    return w;
}

Word copyWord_ubahKicauan() {
    Word w;
    w.Length = 12;
    w.TabWord[0] = 'U'; w.TabWord[1] = 'B'; w.TabWord[2] = 'A'; w.TabWord[3] = 'H'; w.TabWord[4] = '_'; w.TabWord[5] = 'K';
    w.TabWord[6] = 'I'; w.TabWord[7] = 'C'; w.TabWord[8] = 'A'; w.TabWord[9] = 'U'; w.TabWord[10] = 'A'; w.TabWord[11] = 'N';
    return w;
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
            printf("Registrasi berhasil. Silakan nikmati fitur-fitur yang ada di BurBir!");
        } else {
            printf("BurBir sudah tidak bisa menghandle lebih banyak akun lagi! Coba lakukan pengusiran!");
        }
    } else {
        printf("Kamu sudah login sehingga tidak bisa daftar, sana nge-BurBir dulu!");
    }
    printf("\n");
}

// MASUK
void Masuk () {
    Account A;
    CreateAccount(&A);
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
        currentuser = getElmt_Account(acc,getIdx_Account(acc,A));
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
        setElmt_Account(&acc, getIdx_Account(acc,currentuser), currentuser);
        printf("\n");
        printf("Profil Anda sudah berhasil diperbarui!\n");
    } else {
        printf("Weh, login dulu dong!!!\n");
    }
}

void Lihat_Profil (Word Username) {
    if (hasLogged) {
        Account target_acc;
        target_acc = getElmt_Account(acc,getIdx_Username(acc,Username));
        if (getIdx_Username(acc,Username) != IDX_ACCOUNT_UNDEF) {
            if (target_acc.publicity || isFriends_Affection(friends,getIdx_Account(acc,currentuser),getIdx_Username(acc,Username))) {
                printf("| Nama: ");
                printWord(target_acc.username);
                printf("\n");
                printf("| Bio Akun: ");
                if (target_acc.bio.Length > 0) {
                    printWord(target_acc.bio);
                }
                printf("\n");
                printf("| No HP: ");
                if (target_acc.phone_num.Length > 0) {
                    printWord(target_acc.phone_num);
                }
                printf("\n");
                printf("| Weton: ");
                if (target_acc.weton.Length > 0) {
                    printWord(target_acc.weton);
                }
                printf("\n\n");
                printf("Foto profil akun ");
                printWord(target_acc.username);
                printf("\n\n");
                displayPhoto(target_acc.photo);
            } else {
                printf("Wah, akun ");
                printWord(target_acc.username);
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
                printWord(target_acc.username);
                printf("!\n");
            }
        } else {
            printf("Akun tidak ditemukan!\n");
        }
    } else {
        printf("Weh, login dulu dong!!!\n");
    }
}

void Atur_Jenis_Akun () {
    if (hasLogged) {
        Account copyToData;
        change_publicity(&currentuser);
        setElmt_Account(&acc, getIdx_Account(acc,currentuser), currentuser);
    } else {
        printf("Weh, login dulu dong!!!\n");
    }
}

void Ubah_Foto_Profil () {
    if (hasLogged) {
        Account copyToData;
        Pics P;
        printf("Foto profil Anda saat ini adalah\n");
        displayPhoto(currentuser.photo);
        printf("\n\n");
        readPhoto(&currentuser);
        displayPhoto(currentuser.photo);
        printf("\n\n");
        setElmt_Account(&acc, getIdx_Account(acc,currentuser), currentuser);
        printf("Widih, fotonya keren. Foto sudah diganti\n");
    } else {
        printf("Weh, login dulu dong!!!\n");
    }
}

void Daftar_Teman () {
    int i, idx_current;
    if (hasLogged) {
        printWord(currentuser.username);
        if (countFriends_Affection(friends, getIdx_Account(acc,currentuser)) > 0) {
            printf(" memiliki ");
            printf("%d ",countFriends_Affection(friends, getIdx_Account(acc,currentuser)));
            printf("teman\n");
            printf("Daftar teman ");
            printWord(currentuser.username);
            printf("\n");
            idx_current = getIdx_Account(acc,currentuser);
            for (i = 0; i < 20; i++) {
                if (isFriends_Affection(friends,i,idx_current) && i != idx_current) {
                    printf("| ");
                    printWord(getElmt_Account(acc,i).username);
                    printf("\n");
                }
            }
        } else {
            printf(" kesepian. Sed :(((((\n");
        }
    } else {
        printf("Weh, login dulu dong!!!\n");
    }
}

void Hapus_Teman () {
    if (hasLogged) {
        Word W;
        printf("Masukkan nama pengguna: \n");
        STARTWORD();
        W = currentWord;
        int idx_REMOVE = getIdx_Username(acc,W);
        if (idx_REMOVE != IDX_ACCOUNT_UNDEF) {
            if (isFriends_Affection(friends,idx_REMOVE,getIdx_Account(acc,currentuser))) {
                if (idx_REMOVE != getIdx_Account(acc,currentuser)) {
                    printf("Yakin ingin menghapus ");
                    printWord(getElmt_Account(acc,idx_REMOVE).username);
                    printf(" dari daftar teman anda? (YA/TIDAK)\n");
                    STARTWORD();
                    if (wordSimilar(currentWord,copyWord_Ya())) {
                        convertAffection(&friends,idx_REMOVE,getIdx_Account(acc,currentuser));
                        printWord(getElmt_Account(acc,idx_REMOVE).username);
                        printf(" berhasil dihapus dari daftar teman Anda.\n");
                    } else {
                        printf("Penghapusan teman dibatalkan!\n");
                    }
                } else {
                    printf("Brooo don't unfriend yourself. Itu tidak sehat!\n");
                }
            } else {
                printWord(getElmt_Account(acc,idx_REMOVE).username);
                printf(" bukan teman anda!\n");
            }
        } else {
            printf("Username tidak ditemukan. Don't remove something that doesnt exist...\n");
        }
    } else {
        printf("Weh, login dulu dong!!!\n");
    }
}

void Kicau(){
    Twit newTwit;
    CreateTwit(&newTwit, Kicauan, currentuser);
    insertLast_ListKicauan(&Kicauan, newTwit);
    SuccessTwit(newTwit);
}

void LihatKicauan(){
    DisplayListKicauan(Kicauan, currentuser, friends, acc);
}

void SukaKicauan(int idKicauan){
    LikeKicauan(&Kicauan, idKicauan, currentuser, friends, acc);
    printf("\n");
}

void UbahKicauan(int idKicau){
    EditKicauan(&Kicauan, idKicau, currentuser, acc);
    printf("\n");
}

void readCommand (Word W) {
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
    } else if (substring_beginning(W,copyWord_Lihat_Profil())) {
        Word user;
        user.Length = W.Length - copyWord_Lihat_Profil().Length - 1;
        for (int i = 0; i < user.Length; i++) {
            user.TabWord[i] = W.TabWord[i + W.Length - user.Length];
        }
        Lihat_Profil(user);
        printf("\n");
    } else if (wordSimilar(W,copyWord_Atur_Jenis_Akun())) {
        Atur_Jenis_Akun();
        printf("\n");
    } else if (wordSimilar(W,copyWord_Ubah_Foto_Profil())) {
        Ubah_Foto_Profil();
        printf("\n");
    } else if (wordSimilar(W,copyWord_Daftar_Teman())) {
        Daftar_Teman();
        printf("\n");
    } else if (wordSimilar(W,copyWord_Hapus_Teman())) {
        Hapus_Teman();
        printf("\n");
    } else if (wordSimilar(W,copyWord_Kicau())) {
        Kicau();
        printf("\n");
    } else if (wordSimilar(W,copyWord_Kicauan())) {
        LihatKicauan();
        printf("\n");
    } else if (wordSimilarWithoutLength(W,copyWord_sukaKicauan())) {
        int id = 0;
        boolean Ignore_ = false;
        for (int i = 12; i < W.Length; i++){
            if ((W.TabWord[i] == ' ') && Ignore_){break;}
            if (((int) W.TabWord[i]) >= 48 && ((int) W.TabWord[i]) <= 57){
                id = id*10;
                id += W.TabWord[i] - '0';
                Ignore_ = true;
            } else if (W.TabWord[i] != ' '){break;}
        }
        SukaKicauan(id);
        printf("\n");
    } else if (wordSimilarWithoutLength(W,copyWord_ubahKicauan())) {
        int id = 0;
        boolean Ignore_ = false;
        for (int i = 12; i < W.Length; i++){
            if ((W.TabWord[i] == ' ') && Ignore_){break;}
            if (((int) W.TabWord[i]) >= 48 && ((int) W.TabWord[i]) <= 57){
                id = id*10;
                id += W.TabWord[i] - '0';
                Ignore_ = true;
            } else if (W.TabWord[i] != ' '){break;}
        }
        UbahKicauan(id);
        printf("\n");
    }
}

int main() {
    printf("\e[1;1H\e[2J");
    boolean allowprint = false;
    CreateListAccount(&acc);
    CreateAffection(&friends);
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