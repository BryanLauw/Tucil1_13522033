/* File data.c */
/* Realisasi tipe data yang akan digunakan */

#include "data.h"

/* Konstruktor */
void createPoint (int a, int b, Point *p)
/* Membuat sebuah point sebagai koordinat matriks */
/* I.S. titik p sembarang, a merupakan baris dan b merupakan kolom yang terdefinisi pada suatu matriks */
/* F.S. p terdefinisi sebagai titik (a,b) */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ABSIS(*p) = a;
    ORDINAT(*p) = b;
}

void createToken (char f, char b, Token *T) {
/* Membentuk token baru */
/* I.S. f dan b adalah karakter yang valid, T sembarang */
/* F.S. Token T terdefinisi sebagai "fb" */
    FRONT(*T) = f;
    BACK(*T) = b;
}

void createMatrix (int nRows, int nCols, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

void createEmptySequence (Sequence *s)
/* Membentuk sebuah sekuens "kosong" yang siap diisi */
/* I.S. Sekuens s sembarang */
/* F.S. Sekeuns s terdefinisi dan kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    LENGTH_SEQUENCE(*s) = 0;
    SKOR(*s) = 0;
}

void inputToken (Token *T)
/* Membuat point dari input user */
/* I.S. P sembarang */
/* F.S. P terdefinisi sesuai input user */
{
    /* KAMUS LOKAL */
    char depan, belakang;
    /* ALGORITMA */
    scanf(" %c%c", &depan, &belakang);
    createToken(depan,belakang,T);
}

void fillSequence (Sequence *s, Token t)
/* Mengisi sekuens s dengan suatu token t di ujung sekuens */
/* I.S. Sequence s terdefinisi kosong atau sudah berisi dan tidak penuh */
/* F.S. Token t tergabung dalam Sequence s */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ELMT_SEQUENCE(*s, LENGTH_SEQUENCE(*s)) = t;
    LENGTH_SEQUENCE(*s) += 1; 
}

void fillScoreSequence (Sequence *s, int skor)
/* Mengisi nilai sekuens dengan skor */
/* I.S. Sequence s terdefinisi dengan skor 0 */
/* F.S. Skor sequence didefinisikan sebagai skor */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    SKOR(*s) = skor;
}

void createListOfSequence (ListSequence *l)
/* Membuat list untuk menampung sekuens */
/* I.S. List sequence sembarang */
/* F.S. List sequence terdefinisi kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    LENGTH_LS(*l) = 0;
}

void pushListOfSequence (ListSequence *l, Sequence s)
/* Mengisi list of sequence dengan sequence s */
/* I.S. List l kosong atau berisi tetapi tidak penuh, s terdefinisi */
/* F.S. s ditambahkan pada list l */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ELMT_LS(*l,LENGTH_LS(*l)) = s;
    LENGTH_LS(*l) += 1;
}

void createEmptyBuffer (Buffer *b, int max_capacity)
/* Membuat buffer kosong */
/* I.S. Buffer b sembarang */
/* F.S. Buffer b terdefinisi dan kosong */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    LENGTH_BUFFER(*b) = 0;
    MAX_CAP(*b) = max_capacity;
}

void pushBuffer (Buffer *b, Point p)
/* Buffer diisi dengan point sebagai elemen terakhirnya */
/* I.S. Buffer b kosong atau isi tetapi tidak penuh, point p terdefinisi pada suatu matriks */
/* F.S. Point p ditambahkan menjadi elemen terakhir dari Buffer b*/
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ELMT_BUFFER(*b, LENGTH_BUFFER(*b)) = p;
    LENGTH_BUFFER(*b) += 1;
}

void popBuffer (Buffer *b)
/* Point di posisi palin atas Buffer dikeluarkan */
/* I.S. Buffer tidak kosong */
/* F.S. Elemen buffer berkurang 1, yaitu elemen paling atas */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    LENGTH_BUFFER(*b) -= 1;
}

boolean checkBuffer (Buffer b, Matrix m, Sequence s)
/* Menghasilkan true jika point pada buffer b, yang menunjuk poisisi matriks m, terdapat sekuens s */
{
    /* KAMUS LOKAL */
    int i, j;
    /* ALGORITMA */
    if (LENGTH_BUFFER(b) >= LENGTH_SEQUENCE(s)) {
        i = 0;
        while (i <= (LENGTH_BUFFER(b) - LENGTH_SEQUENCE(s))) {
            if (samePointToken(ELMT_SEQUENCE(s,0),m,ELMT_BUFFER(b,i))) {
                j = 1;
                while (j < LENGTH_SEQUENCE(s) && samePointToken(ELMT_SEQUENCE(s,j),m,ELMT_BUFFER(b,i+j))) {
                    j++;
                }
                if (j == LENGTH_SEQUENCE(s)) {
                    return true;
                }
            }
            i++;
        }
    }
    return false;
}

int checkBufferListSequence (Buffer b, Matrix m, ListSequence l)
/* Mengembalikan skor total dari buffer b */
{
    /* KAMUS LOKAL */
    int i;
    int n = 0;
    /* ALGORITMA */
    for (i = 0; i < LENGTH_LS(l); i++) {
        if (checkBuffer(b,m,ELMT_LS(l,i))) {
            n += SKOR(ELMT_LS(l,i));
        }
    }
    return n;
}

boolean sameSequence (Sequence S1, Sequence S2)
/* Mengembalikan true jika S1 dan S2 adalah sekuens yang sama */
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (LENGTH_SEQUENCE(S1) != LENGTH_SEQUENCE(S2)) {
        return false;
    } else {
        for (i = 0; i < LENGTH_SEQUENCE(S1); i++) {
            if ((FRONT(ELMT_SEQUENCE(S1,i)) != FRONT(ELMT_SEQUENCE(S2,i))) && (BACK(ELMT_SEQUENCE(S1,i)) != BACK(ELMT_SEQUENCE(S2,i)))) {
                return false;
            }
        }
        return true;
    }
}

boolean sequenceExist (Sequence S, ListSequence L)
/* Mengembalikan true jika terdapat sequence S pada list L */
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (LENGTH_LS(L) == 0) {
        return false;
    } else {
        for (i = 0; i < LENGTH_LS(L); i++) {
            if (sameSequence(S,ELMT_LS(L,i))) {
                return true;
            }
        }
        return false;
    }
}

boolean samePointToken (Token t, Matrix m, Point p)
/* Mengembalikan true jika point p pada matriks sama dengan token */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (FRONT(t) == FRONT(ELMT_MATRIX(m,ABSIS(p),ORDINAT(p))) && BACK(t) == BACK(ELMT_MATRIX(m,ABSIS(p),ORDINAT(p))));
}

boolean pointNotExist (Buffer b, int x, int y)
/* Menghasilkan true jika titik (x,y) belum ada pada buffer b */
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < b.length; i++) {
        if (ABSIS(ELMT_BUFFER(b,i)) == x && ORDINAT(ELMT_BUFFER(b,i)) == y) {
            return false;
        }
    }
    return true;
}

void printPoint (Point p)
/* Menampilkan point */
{
    printf("%d, %d", ORDINAT(p)+1, ABSIS(p)+1);
}

void printToken (Token t)
/* Menampilkan token */
{
    printf("%c%c",FRONT(t), BACK(t));
}

void printSequence (Sequence s)
/* Menampilkan sekuens*/
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < LENGTH_SEQUENCE(s); i++) {
        printToken(ELMT_SEQUENCE(s,i));
        printf(" ");
    }
}

void printListOfSequence (ListSequence l)
/* Menampilkan list of sequence */
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < LENGTH_LS(l); i++) {
        printf("%d. ", i+1);
        printSequence(ELMT_LS(l,i));
        printf("(Reward: %d)\n", SKOR(ELMT_LS(l,i)));
    }
}

void printBuffer (Buffer b)
/* Menampilkan buffer */
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < LENGTH_BUFFER(b); i++) {
        printPoint(ELMT_BUFFER(b, i));
        printf("\n");
    }
}

void printBufferMatrix (Buffer b, Matrix m)
/* Menampilkan elemen buffer b pada matriksnya */
{
    /* KAMUS LOKAL */
    int i;
    Point current;
    /* ALGORITMA */
    for (i = 0; i < LENGTH_BUFFER(b); i++) {
        current = ELMT_BUFFER(b,i);
        printToken(ELMT_MATRIX(m,ABSIS(current),ORDINAT(current)));
        printf(" ");
    }
}

void printMatriks (Matrix m)
/* Menampilkan matriks */
{
    /* KAMUS LOKAL */
    int i, j;
    /* ALGORITMA */
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            printToken(ELMT_MATRIX(m,i,j));
            printf(" ");
        }
        printf("\n");
    }
}

int convertStringToInteger (char str[]) 
/* Menerima string angka-angka lalu mengembalikannya menjadi integer */
{
    /* KAMUS LOKAL */
    int i = 0;
    int n = 0;
    /* ALGORITMA */
    if (str[0] == '-') {
        return 0;
    }
    while (str[i] != ' ' && str[i] != '\n' && str[i] != '\r' && str[i] != '\0') {
        n *= 10;
        n += str[i] - '0';
        i++;
    }
    return n;
}

void inputFileTXT (int *buffer_size, Matrix *m, ListSequence *l)
{
    /* KAMUS LOKAL */
    FILE *f;
    char path[] = "./test/";
    char file[50];
    char myString[256];
    char *temp;
    int i, j;
    int col, row;
    int nSeq;
    Token t;
    Sequence s;
    /* ALGORITMA */
    printf("Input dilakukan melalui file txt\n");
    printf("Masukkan nama file txt pada folder test (tanpa ekstensi): ");
    scanf("%s",file);
    strcat(path,file);
    strcat(path,".txt");

    f = fopen(path,"r");
    while (f == NULL)
    {
        path[8] = '\0';
        printf("File tidak ditemukan pada folder test.\n");
        printf("Masukkan kembali nama file txt pada folder test (tanpa ekstensi): ");
        scanf("%s",file);
        strcat(path,file);
        strcat(path,".txt");
        f = fopen(path,"r");
    }

    printf("\nMembaca file...\n");
    /* 1. Membaca ukuran buffer */
    fgets(myString,256,f);
    *buffer_size = convertStringToInteger(myString);

    /* 2. Membaca matriks */
    fgets(myString,256,f);
    temp = strtok(myString, " ");
    col = convertStringToInteger(temp);
    temp = strtok(NULL, " ");
    row = convertStringToInteger(temp);
    createMatrix(row,col,m);

    for (i = 0; i < row; i++) {
        fgets(myString,256,f);
        for (j = 0; j < col; j++) {
            createToken(myString[j*3],myString[(j*3)+1],&t);
            ELMT_MATRIX(*m,i,j) = t;
        }
    }

    /* 3. Membaca sekuens */
    createListOfSequence(l);
    fgets(myString,256,f);
    nSeq = convertStringToInteger(myString);

    for (i = 0; i < nSeq; i++) {
        createEmptySequence(&s);
        fgets(myString,256,f);
        temp = strtok(myString, " ");
        while (temp != NULL) {
            createToken(temp[0],temp[1],&t);
            fillSequence(&s,t);
            temp = strtok(NULL, " ");
        }
        fgets(myString,256,f);
        fillScoreSequence(&s,convertStringToInteger(myString));
        pushListOfSequence(l,s);
    }
    fclose(f);
    printf("File selesai dibaca\n");
}

int findMinimumSequenceSize (int nToken, int nSequence)
/* Mengmebalikan panjang sekuens minimum untuk menghasilkan sekuens yang unik dengan jumlah token tertentu */
{
    /* KAMUS LOKAL */
    int i = 1;
    double sum = 0;
    /* ALGORITMA */
    while (sum < nSequence) {
        i++;
        sum += pow((double)nToken,(double)i);
    }
    return i;
}

void inputCLI (int *buffer_size, Matrix *m, ListSequence *l)
/* Membaca masukkan melalui command line interface */
/* I.S. buffer_size, Matrix m, dan ListSequence l sembarang */
/* F.S. buffer_size, Matrix m, dan ListSequence l terdefinisi sesuai bacaan command line */
{
    /* KAMUS LOKAL */
    int i, j;
    int nToken, maksSequence, nSequence;
    int row, col;
    int random, sLong, minSequenceSize;
    Token t;
    Sequence s;
    /* ALGORITMA */
    srand(time(0));
    printf("Input dilakukan melalui command line\n");
    printf("Masukkan jumlah token unik: ");
    scanf("%d",&nToken);
    while (nToken < 2) {
        printf("Jumlah token unik harus lebih dari 1\n");
        printf("Masukkan jumlah token unik kembali: ");
        scanf("%d",&nToken);
    }

    Token listOfToken[nToken];
    printf("Masukkan seluruh token (pisahkan dengan spasi atau enter): ");
    for (i = 0; i < nToken; i++) {
        inputToken(&t);
        listOfToken[i] = t;
    }

    printf("Masukkan ukuran buffer: ");
    scanf("%d",buffer_size);
    while (*buffer_size < 2) {
        printf("Ukuran buffer harus lebih dari 1\n");
        printf("Masukkan ukuran buffer kembali: ");
        scanf("%d",buffer_size);
    }

    printf("Masukkan ukuran matriks (kolom baris): ");
    scanf("%d %d",&col,&row);
    while (col <= 1 || row <= 1) {
        printf("Ukuran matriks minimal 2x2\n");
        printf("Masukkan ukuran matriks kembali (kolom baris): ");
        scanf("%d %d",&col,&row);
    }
    createMatrix(row,col,m);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            random = rand() % nToken;
            ELMT_MATRIX(*m,i,j) = listOfToken[random];
        }
    }

    printf("Masukkan jumlah sekuens: ");
    scanf("%d",&nSequence);
    while (nSequence < 1) {
        printf("Jumlah sekuens minimal 1\nMasukkan jumlah sekuens kembali: ");
        scanf("%d",&nSequence);
    }
    minSequenceSize = findMinimumSequenceSize(nToken,nSequence);
    do {
        printf("Masukkan ukuran maksimal sekuens (harap lebih dari sama dengan %d): ",minSequenceSize);scanf("%d",&maksSequence);
    } while (maksSequence < minSequenceSize);
    createListOfSequence(l);
    for (i = 0; i < nSequence; i++) {
        createEmptySequence(&s);
        sLong = (rand() % (maksSequence - 1)) + 2; // Menghasilkan ukuran sekuens
        fillScoreSequence(&s, ((rand() % 5) + 1) * 5);
        for (j = 0; j < sLong; j++) {
            random = rand() % nToken;
            fillSequence(&s, listOfToken[random]);
        }

        if (sequenceExist(s,*l)) {
            i--;
        } else {
            pushListOfSequence(l,s);
        }
    }

    printf("\nMatriks yang terbentuk:\n");printMatriks(*m);printf("\n");
    printf("Sekuens-sekuens yang terbentuk:\n");printListOfSequence(*l);
}

void saveToTXT (Buffer b, Matrix m, int skor, int time)
/* Menyimpan solusi ke dalam file txt */
{
    /* KAMUS LOKAL */
    FILE *f;
    char path[256] = "./test/";
    char saveName[50];
    int i;
    Token t;
    /* ALGORITMA */
    printf("\nMasukkan nama file untuk penyimpanan (tanpa ekstensi): ");
    scanf("%s",saveName);
    strcat(path,saveName);
    strcat(path,".txt");

    printf("\nMelakukan penyimpanan pada file %s.txt\n",saveName);
    f = fopen(path,"w");
    fprintf(f,"%d\n",skor);
    if (skor == 0) {
        fprintf(f, "Tidak ada solusi\n");
    } else {
        for (i = 0; i < LENGTH_BUFFER(b); i++) {
            t = ELMT_MATRIX(m,ABSIS(ELMT_BUFFER(b,i)),ORDINAT(ELMT_BUFFER(b,i)));
            fprintf(f,"%c%c ",FRONT(t),BACK(t));
        }
        fprintf(f,"\n");
        for (i = 0; i < LENGTH_BUFFER(b); i++) {
            fprintf(f,"%d, %d\n",ORDINAT(ELMT_BUFFER(b,i))+1,ABSIS(ELMT_BUFFER(b,i))+1);
        }
    }
    fprintf(f,"\n\n%d ms",time);
    fclose(f);
}

void findBestOption (Matrix m, ListSequence l, Buffer *b, int *skorAkhir)
/* Mencari solusi optimal */
/* I.S. buffer_size, Matrix m, dan ListSequence l terdefinisi. Buffer b sembarang */
/* F.S. Buffer b sebagai solusi paling optimal dari matriks m */
{
    /* KAMUS LOKAL */
    int i;
    int idx = 0;
    int ctr[MAX_CAP(*b)];
    Point p;
    Buffer tempBuffer;
    int skorMaks = 0;
    int skorTemp;
    /* ALGORITMA */
    if (MAX_CAP(*b) > 1) {
        for (i = 0; i < MAX_CAP(*b); i++) {
            ctr[i] = 0;
        }

        for (i = 0; i < LENGTH_LS(l); i++) {
            skorMaks += SKOR(ELMT_LS(l,i));
        }

        createEmptyBuffer(&tempBuffer,MAX_CAP(*b));

        while (ctr[0] < COL_EFF(m) && *skorAkhir != skorMaks) {
            if (idx == 0) {
                createPoint(0,ctr[idx],&p);
                pushBuffer(&tempBuffer,p);
                idx++;
            } else if (idx < MAX_CAP(*b)-1) {
                if (idx % 2 != 0) {
                    if (ctr[idx] != ROW_EFF(m)) {
                        if (pointNotExist(tempBuffer,ctr[idx],ctr[idx-1])) {
                            createPoint(ctr[idx],ctr[idx-1],&p);
                            pushBuffer(&tempBuffer,p);
                            skorTemp = checkBufferListSequence(tempBuffer,m,l);
                            if (skorTemp > *skorAkhir) {
                                *skorAkhir = skorTemp;
                                *b = tempBuffer;
                            }
                            idx++;
                        } else {
                            ctr[idx]++;
                        }
                    } else {
                        popBuffer(&tempBuffer);
                        ctr[idx] = 0;
                        idx--;
                        ctr[idx]++;
                    }
                } else {
                    if (ctr[idx] != COL_EFF(m)) {
                        if (pointNotExist(tempBuffer,ctr[idx-1],ctr[idx])) {
                            createPoint(ctr[idx-1],ctr[idx],&p);
                            pushBuffer(&tempBuffer,p);
                            skorTemp = checkBufferListSequence(tempBuffer,m,l);
                            if (skorTemp > *skorAkhir) {
                                *skorAkhir = skorTemp;
                                *b = tempBuffer;
                            }
                            idx++;
                        } else {
                            ctr[idx]++;
                        }
                    } else {
                        popBuffer(&tempBuffer);
                        ctr[idx] = 0;
                        idx--;
                        ctr[idx]++;
                    }
                }
            } else {
                if (idx % 2 != 0) {
                    while (ctr[idx] < ROW_EFF(m) && *skorAkhir != skorMaks) {
                        if (pointNotExist(tempBuffer,ctr[idx],ctr[idx-1])) {
                            createPoint(ctr[idx],ctr[idx-1],&p);
                            pushBuffer(&tempBuffer,p);
                            
                            skorTemp = checkBufferListSequence(tempBuffer,m,l);
                            if (skorTemp > *skorAkhir) {
                                *skorAkhir = skorTemp;
                                *b = tempBuffer;
                            }
                            ctr[idx]++;
                            popBuffer(&tempBuffer);
                        } else {
                            ctr[idx]++;
                        }
                    }
                } else {
                    while (ctr[idx] < COL_EFF(m) && *skorAkhir != skorMaks) {
                        if (pointNotExist(tempBuffer,ctr[idx-1],ctr[idx])) {
                            createPoint(ctr[idx-1],ctr[idx],&p);
                            pushBuffer(&tempBuffer,p);
                            skorTemp = checkBufferListSequence(tempBuffer,m,l);
                            if (skorTemp > *skorAkhir) {
                                *skorAkhir = skorTemp;
                                *b = tempBuffer;
                            }
                            ctr[idx]++;
                            popBuffer(&tempBuffer);
                        } else {
                            ctr[idx]++;
                        }
                    }
                }
                ctr[idx] = 0;
                idx--;
                ctr[idx]++;
                popBuffer(&tempBuffer);
            }
        }
    } else {
        *skorAkhir = 0;
    }
}