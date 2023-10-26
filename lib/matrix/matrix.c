/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#include "matrix.h"
#include <stdio.h>

// /* *** Selektor *** */
// #define ROW_EFF(M) (M).rowEff
// #define COL_EFF(M) (M).colEff
// #define ELMT(M, i, j) (M).mem[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF_MATRIX(*m) = nRows;
    COL_EFF_MATRIX(*m) = nCols;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
    return ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow_Matrix(Matrix m) {
    return ROW_EFF_MATRIX(m)-1;
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol_Matrix(Matrix m) {
    return COL_EFF_MATRIX(m)-1;
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff_Matrix(Matrix m, IdxType i, IdxType j) {
    return ((i >= 0 && i < ROW_EFF_MATRIX(m)) && (j >= 0 && j < COL_EFF_MATRIX(m)));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal_Matrix(Matrix m, IdxType i) {
    return (MATRIX_ELMT(m,i,i));
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
    int i,j;
    createMatrix(ROW_EFF_MATRIX(mIn),COL_EFF_MATRIX(mIn),mOut);
    for (i = 0; i < ROW_EFF_MATRIX(mIn); i++) {
        for (j = 0; j < COL_EFF_MATRIX(mIn); j++) {
            MATRIX_ELMT(*mOut,i,j) = MATRIX_ELMT(mIn,i,j);
        }
    }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
    int i,j;
    if (isMatrixIdxValid(nRow,nCol)) {
        createMatrix(nRow,nCol,m);
        for (i = 0; i < nRow; i++) {
            for (j = 0; j < nCol; j++) {
                scanf("%d",&MATRIX_ELMT(*m,i,j));
            }        
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m) {
    int i,j;
    for (i = 0; i < ROW_EFF_MATRIX(m); i++) {
        for (j = 0; j < COL_EFF_MATRIX(m); j++) {
            if (j == COL_EFF_MATRIX(m)-1) {
                printf("%d",MATRIX_ELMT(m,i,j));
            } else {
                printf("%d ",MATRIX_ELMT(m,i,j));
            }
        }
        printf("\n");
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
    Matrix m3;
    copyMatrix(m1,&m3);
    int i,j;
    for (i = 0; i < ROW_EFF_MATRIX(m1); i++) {
        for (j = 0; j < COL_EFF_MATRIX(m1); j++) {
            MATRIX_ELMT(m3,i,j) = MATRIX_ELMT(m1,i,j) + MATRIX_ELMT(m2,i,j);
        }        
    }
    return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2) {
    Matrix m3;
    copyMatrix(m1,&m3);
    int i,j;
    for (i = 0; i < ROW_EFF_MATRIX(m1); i++) {
        for (j = 0; j < COL_EFF_MATRIX(m1); j++) {
            MATRIX_ELMT(m3,i,j) = MATRIX_ELMT(m1,i,j) - MATRIX_ELMT(m2,i,j);
        }        
    }
    return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    Matrix m3;
    int i,j,k;
    createMatrix(ROW_EFF_MATRIX(m1), COL_EFF_MATRIX(m2),&m3);
    for (i = 0; i < ROW_EFF_MATRIX(m1); i++) {
        for (j = 0; j < COL_EFF_MATRIX(m2); j++) {
            MATRIX_ELMT(m3,i,j) = 0;
            for (k = 0; k < COL_EFF_MATRIX(m1); k++) {
                MATRIX_ELMT(m3,i,j) += MATRIX_ELMT(m1,i,k)*MATRIX_ELMT(m2,k,j);
            }
        }        
    }
    return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod) {
    Matrix m3;
    copyMatrix (m1,&m3);
    int i,j;
    m3 = multiplyMatrix(m1,m2);
    for (i = 0; i < ROW_EFF_MATRIX(m3); i++) {
        for (j = 0; j < COL_EFF_MATRIX(m3); j++) {
            MATRIX_ELMT(m3,i,j) = MATRIX_ELMT(m3,i,j)%mod;
        }        
    }
    return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
Matrix multiplyByConst(Matrix m, ElType x) {
    int i,j;
    for (i = 0; i < ROW_EFF_MATRIX(m); i++) {
        for (j = 0; j < COL_EFF_MATRIX(m); j++) {
            MATRIX_ELMT(m,i,j) *= x;
        }        
    }
    return m;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k) {
    int i,j;
    for (i = 0; i < ROW_EFF_MATRIX(*m); i++) {
        for (j = 0; j < COL_EFF_MATRIX(*m); j++) {
            MATRIX_ELMT(*m,i,j) *= k;
        }        
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
    int i,j;
    boolean eq = true;
    if ((ROW_EFF_MATRIX(m1) == ROW_EFF_MATRIX(m2)) && (COL_EFF_MATRIX(m1) == COL_EFF_MATRIX(m2))) {
        for (i = 0; i < ROW_EFF_MATRIX(m2); i++) {
            for (j = 0; j < COL_EFF_MATRIX(m2); j++) {
                if (MATRIX_ELMT(m1,i,j) != MATRIX_ELMT(m2,i,j)) {
                    eq = false;
                    return eq;
                }
            }        
        }
    } else {
        return false;
    }
    return eq;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    return !(isMatrixEqual(m1,m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return ((ROW_EFF_MATRIX(m1) == ROW_EFF_MATRIX(m2)) && (COL_EFF_MATRIX(m1) == COL_EFF_MATRIX(m2)));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt_Matrix(Matrix m) {
    return (COL_EFF_MATRIX(m)*ROW_EFF_MATRIX(m));
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare_Matrix(Matrix m) {
    return (COL_EFF_MATRIX(m) == ROW_EFF_MATRIX(m));
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric_Matrix(Matrix m) {
    int i,j;
    if (isSquare_Matrix(m)) {
        for (i = 0; i < ROW_EFF_MATRIX(m); i++) {
            for (j = 0; j < i; j++) {
                if (MATRIX_ELMT(m,i,j) != MATRIX_ELMT(m,j,i)) {
                    return false;
                }
            }        
        }
    } else {
        return false;
    }
    return true;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity_Matrix(Matrix m) {
    int i,j;
    if (isSquare_Matrix(m)) {
        for (i = 0; i < ROW_EFF_MATRIX(m); i++) {
            for (j = 0; j < COL_EFF_MATRIX(m); j++) {
                if (i == j) {
                    if (MATRIX_ELMT(m,i,j) != 1) {
                        return false;
                    }
                } else {
                    if (MATRIX_ELMT(m,i,j) != 0) {
                        return false;
                    }
                }
            }        
        }
    } else {
        return false;
    }
    return true;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse_Matrix(Matrix m) {
    int i,j;
    float not0 = 0;
    for (i = 0; i < ROW_EFF_MATRIX(m); i++) {
        for (j = 0; j < COL_EFF_MATRIX(m); j++) {
            if (MATRIX_ELMT(m,i,j) != 0) {
                not0++;
            }
        }
    }
    return (not0 <= countElmt_Matrix(m)*0.05);
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation_Matrix(Matrix m) {
    return multiplyByConst(m,-1);
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation_Matrix(Matrix *m) {
    pMultiplyByConst(m,-1);
}

/*Fungsi bantuan*/
Matrix minor_Matrix(Matrix m, int a, int b) {
    int i,j,k,l;
    Matrix mnew;
    k = 0;
    l = 0;
    createMatrix(ROW_EFF_MATRIX(m)-1,COL_EFF_MATRIX(m)-1,&mnew);
    for (i = 0; i < ROW_EFF_MATRIX(m); i++) {
        for (j = 0; j < COL_EFF_MATRIX(m); j++) {
            if ((i != a) && (j != b)) {
                MATRIX_ELMT(mnew,k,l) = MATRIX_ELMT(m,i,j);
                l += 1;
            }
        }
        if (l != 0) {
            k += 1;
            l = 0;
        }
    }
    return mnew;
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant_Matrix(Matrix m) {
    float det = 0;
    int multiplier = 1;
    int i;
    if (ROW_EFF_MATRIX(m) == 1 && COL_EFF_MATRIX(m) == 1) {
        return MATRIX_ELMT(m,0,0);
    } else {
        for (i = 0; i < COL_EFF_MATRIX(m); i++) {
            det += multiplier*MATRIX_ELMT(m,0,i)*determinant_Matrix(minor_Matrix(m,0,i));
            multiplier *= -1;
        }
        return det;
    }
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose_Matrix(Matrix m) {
    int i,j;
    Matrix mcopy;
    copyMatrix(m,&mcopy);
    if (isSquare_Matrix(m)) {
        for (i = 0; i < ROW_EFF_MATRIX(m); i++) {
            for (j = 0; j < COL_EFF_MATRIX(m); j++) {
                MATRIX_ELMT(m,i,j) = MATRIX_ELMT(mcopy,j,i);
            }        
        }
    }
    return m;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose_Matrix(Matrix *m) {
    int i,j;
    Matrix mcopy;
    copyMatrix(*m,&mcopy);
    if (isSquare_Matrix(*m)) {
        for (i = 0; i < ROW_EFF_MATRIX(*m); i++) {
            for (j = 0; j < COL_EFF_MATRIX(*m); j++) {
                MATRIX_ELMT(*m,i,j) = MATRIX_ELMT(mcopy,j,i);
            }        
        }
    }
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */