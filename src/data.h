/* File data.h */
/* Berisi definisi tipe-tipe data yang akan digunakan */

#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "boolean.h"
/* Ukuran maksimum baris dan kolom untuk matriks dan ukuran maksimum sekuens */
#define CAP 100

/* Definis tipe data */
/* Tipe data point */
typedef struct {
    int X;
    int Y;
} Point;
/* Tipe data token */
typedef struct {
    char F; /* Huruf/Angka pertama token */
    char B; /* Huruf/Angka kedua token */
} Token;
/* Tipe data matriks */
typedef struct {
   Token mem[CAP][CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* Tipe data sekuens */
typedef struct {
    Token contents[CAP]; 
    int skor; /* Hadiah untuk suatu sekuens */
    int nEff; /* Panjang sekuens */
} Sequence;

typedef struct {
    Sequence fill[CAP];
    int n;
} ListSequence;
/* Tipe data buffer */
typedef struct {
    Point container[CAP]; /* Stack untuk menyimpan point */
    int length;
    int max;
} Buffer;

/* Selektor Point */
#define ABSIS(P) (P).X
#define ORDINAT(P) (P).Y
/* Selektor Token */
#define FRONT(T) (T).F
#define BACK(T) (T).B
/* Selektor Matriks */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT_MATRIX(M, i, j) (M).mem[(i)][(j)]
/* Selektor Sekuens */
#define ELMT_SEQUENCE(S, i) (S).contents[(i)]
#define SKOR(S) (S).skor
#define LENGTH_SEQUENCE(S) (S).nEff

#define ELMT_LS(L, i) (L).fill[(i)]
#define LENGTH_LS(L) (L).n
/* Selektor Buffer */
#define ELMT_BUFFER(B, i) (B).container[(i)]
#define LENGTH_BUFFER(B) (B).length
#define MAX_CAP(B) (B).max

/* Konstruktor */
void createPoint (int a, int b, Point *p);
/* Membuat sebuah point sebagai koordinat matriks */
/* I.S. titik p sembarang, a merupakan baris dan b merupakan kolom yang terdefinisi pada suatu matriks */
/* F.S. p terdefinisi sebagai titik (a,b) */

void createToken (char f, char b, Token *T);
/* Membentuk token baru */
/* I.S. f dan b adalah karakter yang valid, T sembarang */
/* F.S. Token T terdefinisi sebagai "fb" */
    
void createMatrix (int nRows, int nCols, Matrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

void createEmptySequence (Sequence *s);
/* Membentuk sebuah sekuens "kosong" yang siap diisi */
/* I.S. Sekuens s sembarang */
/* F.S. Sekeuns s terdefinisi dan kosong */

void fillSequence (Sequence *s, Token t);
/* Mengisi sekuens s dengan suatu token t di ujung sekuens */
/* I.S. Sequence s terdefinisi kosong atau sudah berisi dan tidak penuh */
/* F.S. Token t tergabung dalam Sequence s */

void fillScoreSequence (Sequence *s, int skor);
/* Mengisi nilai sekuens dengan skor */
/* I.S. Sequence s terdefinisi dengan skor 0 */
/* F.S. Skor sequence didefinisikan sebagai skor */

void createListOfSequence (ListSequence *l);
/* Membuat list untuk menampung sekuens */
/* I.S. List sequence sembarang */
/* F.S. List sequence terdefinisi kosong */

void pushListOfSequence (ListSequence *l, Sequence s);
/* Mengisi list of sequence dengan sequence s */
/* I.S. List l kosong atau berisi tetapi tidak penuh, s terdefinisi */
/* F.S. s ditambahkan pada list l */

void createEmptyBuffer (Buffer *b, int max_capaxity);
/* Membuat buffer kosong */
/* I.S. Buffer b sembarang */
/* F.S. Buffer b terdefinisi dan kosong */

void pushBuffer (Buffer *b, Point p);
/* Point ditempatkan pada buffer pada posisi paling atas */
/* I.S. Buffer b kosong atau berisi tetapi tidak penuh, point p terdefinisi pada suatu matriks */
/* F.S. Point p ditambahkan menjadi elemen paling atas dari Buffer b*/

void popBuffer (Buffer *b);
/* Point di posisi palin atas Buffer dikeluarkan */
/* I.S. Buffer tidak kosong */
/* F.S. Elemen buffer berkurang 1, yaitu elemen paling atas */

boolean checkBuffer (Buffer b, Matrix m, Sequence s);
/* Menghasilkan true jika point pada buffer b, yang menunjuk poisisi matriks m, terdapat sekuens s */

int checkBufferListSequence (Buffer b, Matrix m, ListSequence l);
/* Mengembalikan skor total dari buffer b */

boolean samePointToken (Token t, Matrix m, Point p);
/* Mengembalikan true jika point p pada matriks sama dengan token */

boolean pointNotExist (Buffer b, int x, int y);
/* Menghasilkan true jika titik (x,y) belum ada pada buffer b */

void printPoint (Point p);
/* Menampilkan point */

void printToken (Token t);
/* Menampilkan token */

void printSequence (Sequence s);
/* Menampilkan sekuens*/

void printListOfSequence (ListSequence l);
/* Menampilkan list of sequence */

void printBuffer (Buffer b);
/* Menampilkan buffer */

void printBufferMatrix (Buffer b, Matrix m);
/* Menampilkan elemen buffer b pada matriksnya */

void printMatriks (Matrix m);
/* Menampilkan matriks */

void inputFileTXT (int *buffer_size, Matrix *m, ListSequence *l);
/* Membaca masukkan melalui file berkestensi .txt */
/* I.S. buffer_size, Matrix m, dan ListSequence l sembarang */
/* F.S. buffer_size, Matrix m, dan ListSequence l terdefinisi sesuai bacaan file */

void inputCLI (int *buffer_size, Matrix *m, ListSequence *l);
/* Membaca masukkan melalui command line interface */
/* I.S. buffer_size, Matrix m, dan ListSequence l sembarang */
/* F.S. buffer_size, Matrix m, dan ListSequence l terdefinisi sesuai bacaan command line */

void saveToTXT (Buffer b, Matrix m, int skor, int time);
/* Menyimpan solusi ke dalam file txt */

void findBestOption (Matrix m, ListSequence l, Buffer *b, int *skorAkhir);
/* Mencari solusi optimal */
/* I.S. buffer_size, Matrix m, dan ListSequence l terdefinisi. Buffer b sembarang */
/* F.S. Buffer b sebagai solusi paling optimal dari matriks m */

#endif