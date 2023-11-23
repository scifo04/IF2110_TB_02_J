#include <stdio.h>
#include <stdlib.h>
#include "../lib/adt.h"

static boolean allowexit = false;
static ListAcc acc;
static boolean hasLogged = false;
static Account currentuser;
static Affection friends;
static ListKicauan Kicauan;
static QueueFR requests;
static Word file_balasan;
static Word file_draf;
static Word file_kicauan;
static Word file_pengguna;
static Word file_utas;
int id_untuk_balas;
int idUtas = 1; // ID Utas selanjutnya kalau ada yang buat, auto increment dari 1

void inisialisasi() {
    Word word_inpute;
    printf(".______    __    __  .______      .______    __  .______      \n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\     \n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n\n");
    printf("Selamat datang di BurBir.\n\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    STARTWORD();
    word_inpute = concatWordStart("./", currentWord);
    file_balasan = concatWordEnd(word_inpute, "/balasan.config");
    file_draf = concatWordEnd(word_inpute, "/draf.config");
    file_kicauan = concatWordEnd(word_inpute, "/kicauan.config");
    file_pengguna = concatWordEnd(word_inpute, "/pengguna.config");
    file_utas = concatWordEnd(word_inpute, "/utas.config");
}

void load (Word W);

// COMMAND READERS
Word copyWord_Lihat_Profil () {
    Word W;
    (W).TabWord[0] = 'L';(W).TabWord[1] = 'I';(W).TabWord[2] = 'H';(W).TabWord[3] = 'A';(W).TabWord[4] = 'T';(W).TabWord[5] = '_';
    (W).TabWord[6] = 'P';(W).TabWord[7] = 'R';(W).TabWord[8] = 'O';(W).TabWord[9] = 'F';(W).TabWord[10] = 'I';(W).TabWord[11] = 'L';
    (W).Length = 12;
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

Word copyWord_Utas() {
    Word w;
    w.Length = 4;
    w.TabWord[0] = 'U'; w.TabWord[1] = 'T'; w.TabWord[2] = 'A'; w.TabWord[3] = 'S';
    return w;
}

Word copyWord_SambungUtas() {
    Word w;
    w.Length = 12;
    w.TabWord[0] = 'S'; w.TabWord[1] = 'A'; w.TabWord[2] = 'M'; w.TabWord[3] = 'B'; w.TabWord[4] = 'U'; w.TabWord[5] = 'N';
    w.TabWord[6] = 'G'; w.TabWord[7] = '_'; w.TabWord[8] = 'U'; w.TabWord[9] = 'T'; w.TabWord[10] = 'A'; w.TabWord[11] = 'S';
    return w;
}

Word copyWord_HapusUtas() {
    Word w;
    w.Length = 10;
    w.TabWord[0] = 'H'; w.TabWord[1] = 'A'; w.TabWord[2] = 'P'; w.TabWord[3] = 'U'; w.TabWord[4] = 'S'; w.TabWord[5] = '_';
    w.TabWord[6] = 'U'; w.TabWord[7] = 'T'; w.TabWord[8] = 'A'; w.TabWord[9] = 'S';
    return w;
}

Word copyWord_CetakUtas() {
    Word w;
    w.Length = 10;
    w.TabWord[0] = 'C'; w.TabWord[1] = 'E'; w.TabWord[2] = 'T'; w.TabWord[3] = 'A'; w.TabWord[4] = 'K'; w.TabWord[5] = '_';
    w.TabWord[6] = 'U'; w.TabWord[7] = 'T'; w.TabWord[8] = 'A'; w.TabWord[9] = 'S';
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
                    if (isWordSimilar(currentWord, "YA")) {
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

void Tambah_Teman() {
    if (hasLogged) {
        if (isEmptyQueueFR(currentuser.requests)) {
            Word nameReq;
            printf("Masukkan nama pengguna: \n");
            STARTWORD();
            printf("\n");
            nameReq = currentWord;
            int idReq = getIdx_Username(acc, nameReq);
            if (nameAvailable(acc,nameReq) && !isFriends_Affection(friends,getIdx_Account(acc,currentuser),idReq)) {
                addFriend(nameReq,idReq,&(acc.buffer[idReq]).requests,acc,currentuser,friends);
            } else if (isFriends_Affection(friends,getIdx_Account(acc,currentuser),idReq)) {
                printf("Pengguna bernama ");
                printWord(nameReq);
                printf(" sudah menjadi teman anda. You can't be more than just friends.....\n");
            } else {
                printf("Pengguna bernama ");
                printWord(nameReq);
                printf(" tidak ditemukan.\n");
            }
        } else {
            printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
        }
    } else {
        printf("Weh, login dulu dong!\n");
    }
}
void Daftar_Permintaan_Pertemanan() {
    if (hasLogged) {
        displayQueueFR(currentuser.requests);
        displayFriendRequests(currentuser.requests,acc);
    }
}
void Setujui_Pertemanan() {
    if (hasLogged) {
        if (!isEmptyQueueFR(currentuser.requests)) {
            processRequest(&currentuser.requests,&friends,acc);
            setElmt_Account(&acc, getIdx_Account(acc,currentuser), currentuser);
        } else {
            printf("Tidak terdapat permintaan pertemanan untuk anda\n");
        }
    }
}
void FrList() {
    if (hasLogged) {
        displayAffection(friends);
    }
}
void Kicau(){
    if (hasLogged){
        Twit newTwit;
        CreateTwit(&newTwit, Kicauan, currentuser.username);
        insertLast_ListKicauan(&Kicauan, newTwit);
        SuccessTwit(newTwit);
    } else {printf("Weh, login dulu dong!!!\n");}
}

void LihatKicauan(){
    if (hasLogged){
        DisplayListKicauan(Kicauan, currentuser, friends, acc);
    } else {printf("Weh, login dulu dong!!!\n\n");}
}

void SukaKicauan(int idKicauan){
    if (hasLogged){
        LikeKicauan(&Kicauan, idKicauan, currentuser, friends, acc);
    } else {printf("Weh, login dulu dong!!!\n");}
}

void UbahKicauan(int idKicau){
    if (hasLogged){
        EditKicauan(&Kicauan, idKicau, currentuser, acc);
    } else {printf("Weh, login dulu dong!!!\n");}
}

void BuatUtas(int idKicau){
    if (!hasLogged){
        printf("\nWeh, login dulu dong!!!\n");
    } else if (!isIdxEff_ListKicauan(Kicauan, (idKicau - 1))){
        printf("\nKicauan tidak ditemukan\n");
    } else if (!wordSimilar(Author(ListKicauan_ELMT(Kicauan, (idKicau - 1))), currentuser.username)){
        printf("\nKicauan ini bukan milik anda!\n");
    } else if (Utas(ListKicauan_ELMT(Kicauan, (idKicau - 1))) != NULL){
        printf("\nTidak boleh ada dua utas yang memiliki kicauan utama yang sama!!!\n");
    } else {
        IDUtas(ListKicauan_ELMT(Kicauan, (idKicau - 1))) = idUtas; idUtas++;
        printf("\nUtas berhasil dibuat!\n\nMasukkan kicauan:\n");
        STARTWORD(); DATETIME WaktuUtas; CreateDATETIME(&WaktuUtas); insertLastUtas(&Utas(ListKicauan_ELMT(Kicauan, (idKicau - 1))), WaktuUtas, currentWord);
        printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK) "); STARTWORD();
        while (isWordSimilar(currentWord, "YA")){
            printf("\nMasukkan kicauan:\n");
            STARTWORD(); CreateDATETIME(&WaktuUtas); insertLastUtas(&Utas(ListKicauan_ELMT(Kicauan, (idKicau - 1))), WaktuUtas, currentWord);
            printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK) "); STARTWORD();
        }
        printf("\nUtas selesai!\n");
    }
}

void SambungUtas(int IdUtas, int index){
    if (!hasLogged){
        printf("\nWeh, login dulu dong!!!\n");
    } else {
        boolean found = false;
        DATETIME WaktuUtas;
        int i = ListKicauan_NEFF(Kicauan);
        while (!found && (i > 0)){
            i--; if (IDUtas(ListKicauan_ELMT(Kicauan, i)) == IdUtas){found = true;}
        }
        if (!found){
            printf("\nUtas tidak ditemukan!\n");
        } else if (!wordSimilar(Author(ListKicauan_ELMT(Kicauan, i)), currentuser.username)){
            printf("\nAnda tidak bisa menyambung utas ini!\n");
        } else if (index <= 0){
            printf("\nTidak bisa disisipkan pada kicauan utama!\n");
        } else if (index > (lengthUtas(Utas(ListKicauan_ELMT(Kicauan, i))) + 1)){
            printf("\nIndex terlalu tinggi!\n");
        } else {
            printf("\nMasukkan kicauan:\n");
            STARTWORD(); CreateDATETIME(&WaktuUtas); insertAtUtas(&Utas(ListKicauan_ELMT(Kicauan, i)), WaktuUtas, currentWord, index);
        }
    }
}

void HapusUtas(int IdUtas, int index){
    if (!hasLogged){
        printf("\nWeh, login dulu dong!!!\n");
    } else {
        boolean found = false;
        int i = ListKicauan_NEFF(Kicauan);
        while (!found && (i > 0)){
            i--; if (IDUtas(ListKicauan_ELMT(Kicauan, i)) == IdUtas){found = true;}
        }
        if (!found){
            printf("\nUtas tidak ditemukan!\n");
        } else if (!wordSimilar(Author(ListKicauan_ELMT(Kicauan, i)), currentuser.username)){
            printf("\nAnda tidak bisa menghapus kicauan dalam utas ini!\n");
        } else if (index <= 0){
            printf("\nAnda tidak bisa menghapus kicauan utama!\n");
        } else if (index > lengthUtas(Utas(ListKicauan_ELMT(Kicauan, i)))){
            printf("\nKicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
        } else {
            deleteAtUtas(&Utas(ListKicauan_ELMT(Kicauan, i)), index);
            printf("\nKicauan sambungan berhasil dihapus!\n");
        }
    }
}

void CetakUtas(int IdUtas){
    if (!hasLogged){
        printf("\nWeh, login dulu dong!!!\n\n");
    } else {
        boolean found = false;
        int i = ListKicauan_NEFF(Kicauan);
        while (!found && (i > 0)){
            i--; if (IDUtas(ListKicauan_ELMT(Kicauan, i)) == IdUtas){found = true;}
        }
        if (!found){
            printf("\nUtas tidak ditemukan!\n\n");
        } else if (!((getPublicitybyUsername(acc, Author(ListKicauan_ELMT(Kicauan, i)))) || (isFriends_Affection(friends, getIdx_Username(acc, Author(ListKicauan_ELMT(Kicauan, i))), getIdx_Account(acc, currentuser))))){ // bukan publik atau teman
            printf("\nAkun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n\n");
        } else {
            printf("\n | ID = %d\n | ", (i + 1)); printWord(Author(ListKicauan_ELMT(Kicauan, i)));
            printf("\n | "); TulisDATETIME(DateTime(ListKicauan_ELMT(Kicauan, i)));
            printf("\n | "); printWord(IsiTwit(ListKicauan_ELMT(Kicauan, i))); printf("\n\n");
            cetakUtas(Utas(ListKicauan_ELMT(Kicauan, i)), Author(ListKicauan_ELMT(Kicauan, i)));
        }
    }
}

void balas (Word input, ListAcc acc, Affection friends, ListKicauan Kicauan) {
    int space_count, IDKicau, IDBalas, id_user_pembalas, id_user_dibalas;
    Word balasan, username_pembalas, username_dibalas;
    boolean neg = false;
    Tree tree;
    addressTree p;
    space_count = IDKicau = IDBalas = 0;
    for (int i = 0; i < input.Length; i++) {
        if (input.TabWord[i] == BLANK) {
            space_count++;
        }
        else if ((int)input.TabWord[i] == 45 && space_count == 2) {
            neg = true;
        }
        else if ((int)input.TabWord[i] >= 48 && (int)input.TabWord[i] <= 57) {
            if (space_count == 1) {
                IDKicau = IDKicau * 10 + (input.TabWord[i] - '0');
            }
            else if (space_count == 2) {
                IDBalas = IDBalas * 10 + (input.TabWord[i] - '0');
            }
        }
    }
    if (neg) {
        IDBalas *= -1;
    }
    // username_pembalas = active_username;
    if (isIdxEff_ListKicauan(Kicauan, IDKicau - 1)) { // IdKicau EXIST (ADA)
        int i;
        username_pembalas = currentuser.username;
        id_user_pembalas = getIdx_Username(acc, username_pembalas);
        for (i = 0; i < listLength_ListKicauan(Kicauan); i++) {
            if (ListKicauan_ELMT(Kicauan, i).idKicau == IDKicau) {
                username_dibalas = ListKicauan_ELMT(Kicauan, i).author;
                tree = ListKicauan_ELMT(Kicauan, i).Balasan;
                p = Root(tree);
                break;
            }
        }
        if (IDBalas == -1) {
            id_user_dibalas = getIdx_Username(acc, username_dibalas);
            if (getPublicitybyUsername(acc, username_dibalas) || isFriends_Affection(friends, id_user_pembalas, id_user_dibalas)) {
                addressTree new, old;
                DATETIME Date;
                printf("\nMasukkan balasan:\n");
                STARTWORD();
                balasan = currentWord;
                CreateDATETIME(&Date);
                printf("\nSelamat! balasan telah diterbitkan!\nDetil balasan:\n");
                printf("| ID = %d\n", id_untuk_balas);
                printf("| "); printWord(currentuser.username); printf("\n");
                printf("| "); TulisDATETIME(Date); printf("\n");
                printf("| "); printWord(balasan); printf("\n");
                new = Alokasi(id_untuk_balas, currentuser.username, Date, balasan);
                id_untuk_balas++;
                if (p != NULL) {
                    AddSibling(&p, new);
                }
                else {
                    AddChild(&p, new);
                    Root(ListKicauan_ELMT(Kicauan, i).Balasan) = p;
                }
            }
            else {
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
            }
        }
        else { // IDBALAS != (=1)
            if (isIdTreeElmt(p, IDBalas)) { // IdBalasan EXIST
                if (getPublicitybyUsername(acc, username_dibalas) || isFriends_Affection(friends, id_user_pembalas, id_user_dibalas)) {  // Jika publik atau berteman
                    addressTree new, old;
                    DATETIME Date;
                    id_user_dibalas = getIdx_Username(acc, username_dibalas);
                    printf("\nMasukkan balasan:\n");
                    STARTWORD();
                    balasan = currentWord;
                    CreateDATETIME(&Date);
                    printf("\nSelamat! balasan telah diterbitkan!\nDetil balasan:\n");
                    printf("| ID = %d\n", id_untuk_balas);
                    printf("| "); printWord(currentuser.username); printf("\n");
                    printf("| "); TulisDATETIME(Date); printf("\n");
                    printf("| "); printWord(balasan); printf("\n");

                    new = Alokasi(id_untuk_balas, username_pembalas, Date, balasan);
                    old = getAddressWithId(p, IDBalas);
                    if (FirstChild(old) == NULL) {
                        AddChild(&old, new);
                    }
                    else {
                        AddSibling(&old, new);
                    }
                    id_untuk_balas++;
                }       
                else {
                    printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n");
                }
            }
            else { // IdBalas NOT EXIST
                printf("Wah, tidak terdapat balasan yang ingin anda balas!\n");
            }
        }
    }
    else { // IdKicau NOT EXIST
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
    }
}

void print_balasan(Word input, ListAcc acc, Affection friends, ListKicauan Kicauan) {
    int space_count, IDKicau, id_user_dibalas, current_user_id, i;
    Word username_dibalas;
    Tree tree;
    addressTree p;
    space_count = IDKicau  = 0;

    for (int i = 0; i < input.Length; i++) {
        if (input.TabWord[i] == BLANK) {
            space_count++;
        }
        else if ((int)input.TabWord[i] >= 48 && (int)input.TabWord[i] <= 57) {
            if (space_count == 1) {
                IDKicau = IDKicau * 10 + (input.TabWord[i] - '0');
            }
        }
    }
    // user_pembalas = current_user;
    
    if (isIdxEff_ListKicauan(Kicauan, IDKicau - 1)) {
        for (i = 0; i < listLength_ListKicauan(Kicauan); i++) {
            if (ListKicauan_ELMT(Kicauan, i).idKicau == IDKicau) {
                username_dibalas = ListKicauan_ELMT(Kicauan, i).author;
                id_user_dibalas = getIdx_Username(acc, username_dibalas);
                tree = ListKicauan_ELMT(Kicauan, i).Balasan;
                p = Root(tree);
                break;
            }
        }
        if (p == NULL) {
            printf("\nBelum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        }
        else {
            Account a = getElmt_Account(acc, id_user_dibalas);
            current_user_id = getIdx_Username(acc, currentuser.username);
            if (!a.publicity) {
                printf("\nWah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
            }
            else {
                if (isFriends_Affection(friends, id_user_dibalas, current_user_id)) {
                    printTreeBalasan(p, 0, acc, friends, current_user_id);
                }
            }
        }
    }
    else {
        printf("\nTidak terdapat kicauan dengan id tersebut!\n");
    }
}

void hapusBalasan(Word input, ListAcc acc, Affection friends, ListKicauan Kicauan) {
    Tree t;
    addressTree p, q;
    int IDKicau, IDBalasan, space_count, i;
    IDKicau = IDBalasan = space_count = 0;
    for (i = 0; input.TabWord[i] != EndWord; i++) {
        if (input.TabWord[i] == BLANK) {
            space_count++;
        }
        else if ((int)input.TabWord[i] >= 48 && (int)input.TabWord[i] <= 57) {
            if (space_count == 1) {
                IDKicau = IDKicau * 10 + (input.TabWord[i] - '0');
            }
            else if (space_count == 2) {
                IDBalasan = IDBalasan * 10 + (input.TabWord[i] - '0');
            }
        }
    }
    for (i = 0; i < listLength_ListKicauan(Kicauan); i++) {
            if (ListKicauan_ELMT(Kicauan, i).idKicau == IDKicau) {
                t = ListKicauan_ELMT(Kicauan, i).Balasan;
                p = Root(t);
                break;
            }
    }
    if (isIdxEff_ListKicauan(Kicauan, IDKicau - 1)) { // IDKicau EXIST
        q = getAddressWithId(p, IDBalasan);
        if (q != NULL) {
            if (wordSimilar(User(q), currentuser.username)) { // PEMILIK BALASAN
                if (q == Root(t)) {
                    if (NextSibling(q) == NULL) {
                        deleteTree(q);
                        Root(ListKicauan_ELMT(Kicauan, i).Balasan) = NULL;
                        printf("\nBalasan berhasil dihapus\n");
                    }
                    else {
                        Root(ListKicauan_ELMT(Kicauan, i).Balasan) = NextSibling(q);
                        deleteTree(q);
                        printf("\nBalasan berhasil dihapus\n");
                    }
                }
                else {
                    addressTree p1;
                    p1 = getAddressBefore(p, q);
                    if (NextSibling(q) != NULL) {
                        if (FirstChild(p1) == q) {
                            FirstChild(p1) = NextSibling(q);
                        }
                        else {
                            NextSibling(p1) = NextSibling(q);
                        }
                    }
                    else {
                        if (NextSibling(p1) == q) {
                            NextSibling(p1) = NULL;
                        }
                        else {
                            FirstChild(p1) = NULL;
                        }
                    }
                    deleteTree(q);          
                    printf("\nBalasan berhasil dihapus\n");
                }
            }
            else {
                printf("\nHei, ini balasan punya siapa? Jangan dihapus ya!\n");
            }
        }
        else { // NOT EXIST
            printf("\nBalasan tidak ditemukan\n");
        }
    }
    else {
        printf("\nKicauan tidak ditemukan\n");
    }
}

void readCommand (Word W) {
    if (isWordSimilar(W, "EXIT")) {
        allowexit = true;
    } else if (isWordSimilar(W, "DAFTAR")) {
        Daftar();
        printf("\n");
    } else if (isWordSimilar(W, "MASUK")) {
        Masuk();
        printf("\n");
    } else if (isWordSimilar(W, "KELUAR")) {
        Keluar();
        printf("\n");
    } else if (isWordSimilar(W, "GANTI_PROFIL")) {
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
    } else if (isWordSimilar(W, "ATUR_JENIS_AKUN")) {
        Atur_Jenis_Akun();
        printf("\n");
    } else if (isWordSimilar(W, "UBAH_FOTO_PROFIL")) {
        Ubah_Foto_Profil();
        printf("\n");
    } else if (isWordSimilar(W, "DAFTAR_TEMAN")) {
        Daftar_Teman();
        printf("\n");
    } else if (isWordSimilar(W, "HAPUS_TEMAN")) {
        Hapus_Teman();
        printf("\n");
    } else if (isWordSimilar(W, "TAMBAH_TEMAN")) {
        Tambah_Teman();
        printf("\n");
    } else if (isWordSimilar(W, "DAFTAR_PERMINTAAN_PERTEMANAN")) {
        Daftar_Permintaan_Pertemanan();
        printf("\n");
    } else if (isWordSimilar(W, "SETUJUI_PERTEMANAN")) {
        Setujui_Pertemanan();
        printf("\n");
    } else if (isWordSimilar(W, "FRLIST")) {
        FrList();
        printf("\n");
    } else if (isWordSimilar(W, "KICAU")) {
        Kicau();
        printf("\n");
    } else if (isWordSimilar(W, "KICAUAN")) {
        LihatKicauan();
    } else if (wordSimilarWithoutLength(W,copyWord_sukaKicauan())) {
        int id = Akuisisi_First_Integer(W);
        SukaKicauan(id);
        printf("\n");
    } else if (wordSimilarWithoutLength(W,copyWord_ubahKicauan())) {
        int id = Akuisisi_First_Integer(W);
        UbahKicauan(id);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, copyWord_Balasan())) {
        print_balasan(W, acc, friends, Kicauan);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, copyWord_Balas())) {
        balas(W, acc, friends, Kicauan);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, copyWord_hapusBalasan())) {
        hapusBalasan(W, acc, friends, Kicauan);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, copyWord_Utas())) {
        int id = Akuisisi_First_Integer(W);
        BuatUtas(id);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, copyWord_SambungUtas())) {
        int idU = Akuisisi_First_Integer(W);
        int idx = Akuisisi_Second_Integer(W);
        SambungUtas(idU, idx);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, copyWord_HapusUtas())) {
        int idU = Akuisisi_First_Integer(W);
        int idx = Akuisisi_Second_Integer(W);
        HapusUtas(idU, idx);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, copyWord_CetakUtas())) {
        int id = Akuisisi_First_Integer(W);
        CetakUtas(id);
    }
}

int main() {
    printf("\e[1;1H\e[2J");
    id_untuk_balas = 1;
    boolean allowprint = false;
    CreateListAccount(&acc);
    CreateAffection(&friends);
    CreateQueueFR(&requests);
    CreateListKicauan(&Kicauan, 50);
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