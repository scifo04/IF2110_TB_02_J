#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../lib/adt.h"

static boolean allowexit = false;
static ListAcc acc;
static boolean hasLogged = false;
static Account currentuser;
static Affection friends;
static ListKicauan Kicauan;
static Draft myDraft;
static QueueFR requests;
static Word file_balasan;
static Word file_draf;
static Word file_kicauan;
static Word file_pengguna;
static Word file_utas;
int id_untuk_balas = 1;
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

void deleteAllData(){
    // SEBELUM MUAT
    // Untuk variable variable seperti id_untuk_balas, idUtas, dll mungkin di loadnya tapi gak tau
    for (int i = 0; i < ListKicauan_NEFF(Kicauan); i++){
        if (Utas(ListKicauan_ELMT(Kicauan, i)) != NULL){deallocateAllUtas(&Utas(ListKicauan_ELMT(Kicauan, i)));}
        if (Root(Balasan(ListKicauan_ELMT(Kicauan, i))) != NULL){deallocateAllTree(&Root(Balasan(ListKicauan_ELMT(Kicauan, i))));}
    }
    dealocateListKicauan(&Kicauan);
    // dealokasi stack draft
    // dealokasi queue fr
}

void save_pengguna(char *path) {
    char *filename = "/pengguna.config";
    int e = strilen(path);
    for (int i = strilen(path); i < strilen(path)+strilen(filename); i++) {
        path[i] = filename[i-e]; 
    }
    for (int i = 0; i < strilen(path); i++) {
        printf("%c",path[i]);
    }
    printf("\n");
    FILE *file = fopen(path,"w");
    fprintf(file,"%d",acc.NEff);
    fprintf(file,"\n");
    for (int i = 0; i < acc.NEff; i++) {
        for (int j = 0; j < acc.buffer[i].username.Length; j++) {
            fprintf(file,"%c",acc.buffer[i].username.TabWord[j]);
        }
        fprintf(file,"\n");
        for (int j = 0; j < acc.buffer[i].password.Length; j++) {
            fprintf(file,"%c",acc.buffer[i].password.TabWord[j]);
        }
        fprintf(file,"\n");
        for (int j = 0; j < acc.buffer[i].bio.Length; j++) {
            fprintf(file,"%c",acc.buffer[i].bio.TabWord[j]);
        }
        fprintf(file,"\n");
        for (int j = 0; j < acc.buffer[i].phone_num.Length; j++) {
            fprintf(file,"%c",acc.buffer[i].phone_num.TabWord[j]);
        }
        fprintf(file,"\n");
        for (int j = 0; j < acc.buffer[i].weton.Length; j++) {
            fprintf(file,"%c",acc.buffer[i].weton.TabWord[j]);
        }
        fprintf(file,"\n");
        if (acc.buffer[i].publicity) {
            fprintf(file,"Public\n");
        } else {
            fprintf(file,"Private\n");
        }
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 20; k++) {
                fprintf(file,"%c",acc.buffer[i].photo.content[j][k]);
            }
        }
    }
    for (int i = 0; i < acc.NEff; i++) {
        for (int j = 0; j < acc.NEff; j++) {
            fprintf(file,"%d",friends.status[i][j]);
            if (j != (acc.NEff - 1)) {
                fprintf(file," ");
            } else {
                fprintf(file,"\n");
            }
        }
    }
    int len_total = 0;
    for (int i = 0; i < acc.NEff; i++) {
        len_total += length_QueueFR(acc.buffer[i].requests);
    }
    fprintf(file,"%d\n",len_total);
    for (int i = 0; i < acc.NEff; i++) {
        Address a = ADDR_HEAD(acc.buffer[i].requests);
        if (length_QueueFR(acc.buffer[i].requests) != 0) {
            for (int j = 0; j < length_QueueFR(acc.buffer[i].requests); j++) {
                fprintf(file,"%d ",ID_REQUESTERN(a));
                fprintf(file,"%d ",ID_REQUESTEDN(a));
                fprintf(file,"%d\n",POPULARITYN(a));
                a = NEXT(a);
            }
        }
    }
    fclose(file);
}

void save_kicauan(){
    FILE *tweeter = fopen(file_kicauan.TabWord, "w");
    if (tweeter != NULL){
        fprintf(tweeter, "%d\n", ListKicauan_NEFF(Kicauan));
        for (int i = 0; i < ListKicauan_NEFF(Kicauan); i++){
            fprintf(tweeter, "%d\n", ID(ListKicauan_ELMT(Kicauan, i)));
            fprintWord(IsiTwit(ListKicauan_ELMT(Kicauan, i)), tweeter);
            fprintf(tweeter, "%d\n", Like(ListKicauan_ELMT(Kicauan, i)));
            fprintWord(Author(ListKicauan_ELMT(Kicauan, i)), tweeter);
            TulisDATETIMEFILE(DateTime(ListKicauan_ELMT(Kicauan, i)), tweeter);
        }
    }
    fclose(tweeter);
}

void displayBalasan(FILE *file, addressTree p, addressTree root, ListKicauan LKicau, int i) {
    addressTree q;
    if (p != NULL) {
        if (p == Root(ListKicauan_ELMT(LKicau, i).Balasan)) {
            fprintf(file, "-1 %d\n", Id(p));
        }
        else {
            q = getParent(root, p);
            fprintf(file, "%d %d\n", Id(q), Id(p));
        }
        fprintWord(Pesan(p), file);
        fprintWord(User(p), file);
        TulisDATETIMEFILE(Datetime(p), file);
        displayBalasan(file, FirstChild(p), root, LKicau, i);
        displayBalasan(file, NextSibling(p), root, LKicau, i);
    }
}

void save_balasan(ListKicauan LKicau, Word FILEBALAS) {
    FILE *file;
    int i, count = 0;
    addressTree p, q, r;
    file = fopen(FILEBALAS.TabWord, "w");

    for (int j = 0; j < listLength_ListKicauan(LKicau); j++) {
        if (Root(ListKicauan_ELMT(LKicau, j).Balasan) != NULL) {
            count++;
        }
    }
    fprintf(file, "%d\n", count);

    for (i = 0; i < listLength_ListKicauan(LKicau); i++) {
        p = r = Root(ListKicauan_ELMT(LKicau, i).Balasan); // r always root
        if (p != NULL) {
            fprintf(file, "%d\n", i+1);
            count = countElmtTree(p);
            fprintf(file, "%d\n", count);
            displayBalasan(file, p, r, LKicau, i);
        }
    }
    fclose(file);
}

void save_draf(){
    int number;
    twitDraft delVal;

    FILE *drafts = fopen(file_draf.TabWord, "w");
    if (drafts != NULL){
        if (fscanf(drafts, "%d", &number) == 1) {
            printf("Number from the file: %d\n", number);
        } else {
            Draft temp;
            copyDraft(myDraft, &temp);

            fprintf(drafts, "%d\n", 1);
            if (!IsEmpty_Draft(temp)){
                fprintWord(DAuthor(temp), drafts);
                while(!IsEmpty_Draft(temp)){
                    fprintWord(isiTwitDraft(InfoTops(temp)), drafts);
                    TulisDATETIMEFILE(dateTwitDraft(InfoTops(temp)), drafts);
                    Pops(&temp, &delVal);
                }
            }
        }
    }
    fclose(drafts);
}

void save_utas(){
    FILE *notthreads = fopen(file_utas.TabWord, "w");
    if (notthreads != NULL){
        fprintf(notthreads, "%d\n", (idUtas - 1));
        for (int i = 1; i < idUtas; i++){
            int j;
            for(j = 0; j < ListKicauan_NEFF(Kicauan); j++){ // cari twit dengan id utas i
                if (IDUtas(ListKicauan_ELMT(Kicauan, j)) == i){break;}
            }
            if (j < ListKicauan_NEFF(Kicauan)){
                fprintf(notthreads, "%d\n", ID(ListKicauan_ELMT(Kicauan, j)));
                AddressUtas Utas_Traversal = Utas(ListKicauan_ELMT(Kicauan, j));
                int LU = lengthUtas(Utas_Traversal); fprintf(notthreads, "%d\n", LU);
                for (int k = 0; k < LU; k++){
                    fprintWord(isiTwitUtas(Utas_Traversal), notthreads);
                    fprintWord(Author(ListKicauan_ELMT(Kicauan, j)), notthreads);
                    TulisDATETIMEFILE(waktuUtas(Utas_Traversal), notthreads);
                    Utas_Traversal = Sambungan(Utas_Traversal);
                }
            }
        }
    }
    fclose(notthreads);
}

void load_kicauan(){
    // HARUS SEBELUM LOAD BALASAN DAN UTAS
    FILE *tweeter = fopen(file_kicauan.TabWord, "r");
    if (tweeter != NULL){
        CopyWordFILE(tweeter);
        int neff = Akuisisi_First_Integer(currentWord);
        CreateListKicauan(&Kicauan, (neff + 50));
        ListKicauan_NEFF(Kicauan) = neff;
        for (int i = 0; i < neff; i++){
            IDUtas(ListKicauan_ELMT(Kicauan, i)) = -1;
            Root(Balasan(ListKicauan_ELMT(Kicauan, i))) = NULL;
            Utas(ListKicauan_ELMT(Kicauan, i)) = NULL;
            CopyWordFILE(tweeter); ID(ListKicauan_ELMT(Kicauan, i)) = Akuisisi_First_Integer(currentWord);
            CopyWordFILE(tweeter); IsiTwit(ListKicauan_ELMT(Kicauan, i)) = currentWord;
            CopyWordFILE(tweeter); Like(ListKicauan_ELMT(Kicauan, i)) = Akuisisi_First_Integer(currentWord);
            CopyWordFILE(tweeter); Author(ListKicauan_ELMT(Kicauan, i)) = currentWord;
            CopyWordFILE(tweeter); DateTime(ListKicauan_ELMT(Kicauan, i)) = BacaDateTimeWord(currentWord);
        }
    }
    fclose(tweeter);
}

void load_utas(){
    // HARUS SETELAH LOAD KICAUAN
    FILE *notthreads = fopen(file_utas.TabWord, "r");
    if (notthreads != NULL){
        CopyWordFILE(notthreads);
        idUtas = (Akuisisi_First_Integer(currentWord)) + 1;
        int idxK, loop;
        for (int i = 1; i < idUtas; i++){
            CopyWordFILE(notthreads); idxK = Akuisisi_First_Integer(currentWord);
            CopyWordFILE(notthreads); loop = Akuisisi_First_Integer(currentWord);
            for (int j = 0; j < loop; j++){
                CopyWordFILE(notthreads); Word isiU = currentWord;
                CopyWordFILE(notthreads); CopyWordFILE(notthreads); DATETIME waktuU = BacaDateTimeWord(currentWord);
                insertLastUtas(&Utas(ListKicauan_ELMT(Kicauan, (idxK - 1))), waktuU, isiU);
            }
            IDUtas(ListKicauan_ELMT(Kicauan, (idxK - 1))) = i;
        }
    }
    fclose(notthreads);
}

// KICAUAN HARUS DILOAD TERLEBIH DAHULU
void load_balasan(ListKicauan LKicau) {
    addressTree root, p, q, r;
    Word user, pesan;
    DATETIME d;
    int id_terbesar = 1;
    FILE *file = fopen(file_balasan.TabWord, "r");
    if (file != NULL) {
        CopyWordFILE(file);
        int jumlah_kicau = Akuisisi_First_Integer(currentWord);
        for (int i = 0; i < jumlah_kicau; i++) {
            CopyWordFILE(file); int idx_kicau = Akuisisi_First_Integer(currentWord); printf("Idx kicau = %d\n", idx_kicau);
            CopyWordFILE(file); int jumlah_balasan = Akuisisi_First_Integer(currentWord);
            root = Root(Balasan(ListKicauan_ELMT(LKicau, idx_kicau - 1)));
            for (int j = 0; j < jumlah_balasan; j++) {
                int id_parent, id_balasan;
                CopyWordFILE(file); id_parent = Akuisisi_First_Integer(currentWord); printf("Id parent = %d\n", id_parent); id_balasan = Akuisisi_Second_Integer(currentWord); printf("Id balas = %d\n", id_balasan);
                CopyWordFILE(file); pesan = currentWord;
                CopyWordFILE(file); user = currentWord;
                CopyWordFILE(file); d = BacaDateTimeWord(currentWord);
                if (id_terbesar < id_balasan) {
                    id_terbesar = id_balasan;
                }
                p = Alokasi(id_balasan, user, d, pesan);
                if (id_parent == -1) {
                    if (root == NULL) {
                        AddChild(&root, p);
                        Root(Balasan(ListKicauan_ELMT(Kicauan, idx_kicau - 1))) = root;   
                    }
                    else {
                        AddSibling(&root, p);
                    }
                }
                else {
                    q = getAddressWithId(root, id_parent);
                    if (FirstChild(q) == NULL) {
                        AddChild(&q, p);
                    }
                    else {
                        AddSibling(&FirstChild(q), p);
                    }
                }
            }
        }   
    }
    id_untuk_balas = id_terbesar + 1;
    fclose(file);
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

void BuatDraft(){
    if (hasLogged){
        if (!wordSimilar(myDraft.author, currentuser.username)){
            CreateEmpty_Draft(&myDraft, currentuser.username, 50);
            createDraft(&myDraft, &Kicauan, currentuser.username);
        }
        else{
            createDraft(&myDraft, &Kicauan, currentuser.username);
        }
    }
    else {printf("Weh, login dulu dong!!!\n\n");}
}

void LihatDraft(){
    if (hasLogged){
        if (!wordSimilar(myDraft.author, currentuser.username)){
            printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
        }
        else{
            displayDraft(&myDraft, &Kicauan, currentuser.username);
        }
    }
    else {printf("Weh, login dulu dong!!!\n\n");}
}

void BuatUtas(int idKicau){
    if (!hasLogged){
        printf("\nWeh, login dulu dong!!!\n");
    } else if (!isIdxEff_ListKicauan(Kicauan, (idKicau - 1))){
        printf("\nKicauan tidak ditemukan\n");
    } else if (!wordSimilar(Author(ListKicauan_ELMT(Kicauan, (idKicau - 1))), currentuser.username)){
        printf("\nKicauan ini bukan milik anda!\n");
    } else if (IDUtas(ListKicauan_ELMT(Kicauan, (idKicau - 1))) != -1){
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
    if (hasLogged) {
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
                            AddSibling(&FirstChild(old), new);
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
    else {
        printf("Weh, login dulu dong!!!\n");
    }
}

void printTreeBalasan (addressTree p, int h, ListAcc acc, Affection aff, int current_user_id) {
    if(p != NULL){
        if (getPublicitybyUsername(acc, User(p)) || isFriends_Affection(aff, current_user_id, Id(p))) {
            int i;
            printf("\n");
            for (i = 0; i < h; i++){
                printf("    ");
            }
            printf("| %d", Id(p)); printf("\n");

            for(i = 0; i < h; i++){
                printf("    ");
            }
            printf("| "); printWord(User(p));

            printf("\n");
            for(i = 0; i < h; i++){
                printf("    ");
            }
            printf("| "); TulisDATETIME(Datetime(p)); printf("\n");

            for (i = 0; i < h; i++){
                printf("    ");
            }
            printf("| "); printWord(Pesan(p)); printf("\n");

            printTreeBalasan(FirstChild(p), h + 1, acc, aff, current_user_id);
            printTreeBalasan(NextSibling(p), h, acc, aff, current_user_id);
        }
        else {
            int i;
            printf("\n");
            for(i = 0; i < h; i++){
                printf("    ");
            }
            printf("| %d", Id(p)); printf("\n");

            for (i = 0; i < h; i++){
                printf("    ");
            }
            printf("| PRIVAT\n");

            for(i = 0; i < h; i++){
                printf("    ");
            }
            printf("| PRIVAT\n");

            for(i = 0; i < h; i++){
                printf("    ");
            }
            printf("| PRIVAT\n");
            printTreeBalasan(FirstChild(p), h + 1, acc, aff, current_user_id);
            printTreeBalasan(NextSibling(p), h, acc, aff, current_user_id);
        }
    }
}

void print_balasan(Word input, ListAcc acc, Affection friends, ListKicauan Kicauan) {
    if (hasLogged) {
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
                if (!a.publicity && !isFriends_Affection(friends, id_user_dibalas, current_user_id)) {
                    printf("\nWah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
                }
                else {
                    printTreeBalasan(p, 0, acc, friends, current_user_id);
                }
            }
        }
        else {
            printf("\nTidak terdapat kicauan dengan id tersebut!\n");
        }
    }
    else {
        printf("Weh, login dulu dong!!!\n");
    }
}

void hapusBalasan(Word input, ListAcc acc, Affection friends, ListKicauan Kicauan) {
    if (hasLogged) {
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
    else {
        printf("Weh, login dulu dong!!!\n");
    }
}

void Save() {
    printf("Masukkan tujuan untuk menyimpan data anda: ");
    currentWord.Length = 0;
    STARTWORD();
    Word directory = currentWord;
    char *folderPath = directory.TabWord;
    folderPath[currentWord.Length] = '\0';
    printWord(currentWord);
    printf("\n");
    struct stat folderStats;
    if (stat(folderPath, &folderStats) == 0 && S_ISDIR(folderStats.st_mode)) {
        printf("Folder exists.\n");
    } else {
        printf("Folder does not exist. Making a new folder...\n");
        if (mkdir(folderPath,0777) == 0) {
            printf("Folder created successfully\n");
        } else {
            printf("FAIL\n");
        }
    }
    file_balasan = concatWordEnd(CopyWord_Any(folderPath), "/balasan.config");
    file_draf = concatWordEnd(CopyWord_Any(folderPath), "/draf.config");
    file_kicauan = concatWordEnd(CopyWord_Any(folderPath), "/kicauan.config");
    file_pengguna = concatWordEnd(CopyWord_Any(folderPath), "/pengguna.config");
    file_utas = concatWordEnd(CopyWord_Any(folderPath), "/utas.config");

    save_pengguna(folderPath);
    save_kicauan();
    save_balasan(Kicauan, file_balasan);
    //save_draf();
    save_utas();
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
    } else if (substring_beginning(W, CopyWord_Any("LIHAT_PROFIL"))) {
        Word user;
        user.Length = W.Length - (CopyWord_Any("LIHAT_PROFIL")).Length - 1;
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
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("SUKA_KICAUAN"))) {
        int id = Akuisisi_First_Integer(W);
        SukaKicauan(id);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("UBAH_KICAUAN"))) {
        int id = Akuisisi_First_Integer(W);
        UbahKicauan(id);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("BALASAN"))) {
        print_balasan(W, acc, friends, Kicauan);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("BALAS"))) {
        balas(W, acc, friends, Kicauan);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("HAPUS_BALASAN"))) {
        hapusBalasan(W, acc, friends, Kicauan);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("BUAT_DRAF"))) {
        BuatDraft();
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("LIHAT_DRAF"))){
        LihatDraft();
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("UTAS"))) {
        int id = Akuisisi_First_Integer(W);
        BuatUtas(id);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("SAMBUNG_UTAS"))) {
        int idU = Akuisisi_First_Integer(W);
        int idx = Akuisisi_Second_Integer(W);
        SambungUtas(idU, idx);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("HAPUS_UTAS"))) {
        int idU = Akuisisi_First_Integer(W);
        int idx = Akuisisi_Second_Integer(W);
        HapusUtas(idU, idx);
        printf("\n");
    } else if (wordSimilarWithoutLength(W, CopyWord_Any("CETAK_UTAS"))) {
        int id = Akuisisi_First_Integer(W);
        CetakUtas(id);
    } else if (isWordSimilar(W,"SIMPAN")) {
        Save();
    } else if (isWordSimilar(W, "LOAD_KICAUAN")) {
        load_kicauan();
    } else if (isWordSimilar(W, "LOAD_BALASAN")) {
        load_balasan(Kicauan);
    }
}

int main() {
    printf("\e[1;1H\e[2J");
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