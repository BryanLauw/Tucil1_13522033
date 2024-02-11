#include "data.h"
#include <unistd.h>

/* KAMUS */
int pilih;
char yesno;
char kalang;
Matrix m;
ListSequence l;
Buffer b;
Point p;
int bufferSize;
int totalSkor = 0;
/* ALGORITMA */
int main () {
    system("clear");
    printf("Selamat datang!\nPenyelesaian Cyberpunk 2077 Breach Protocol dengan Algoritma Brute Force\n");
    printf("====================================:====================================\n");
    do {
        printf("Silakan memilih cara input\n1. File txt\n2. CLI\nPilihan: ");
        scanf("%d",&pilih);
        while (pilih > 2 || pilih < 1) {
            printf("\nTidak ada pilihan tersebut\n");
            printf("Silakan memilih cara input kembali\n1. File txt\n2. CLI\nPilihan: ");
            scanf("%d",&pilih);
        }
        printf("\n");

        if (pilih == 1) {
            inputFileTXT(&bufferSize,&m,&l);
        } else {
            inputCLI(&bufferSize,&m,&l);
        }
        createEmptyBuffer(&b,bufferSize);

        clock_t begin = clock();
        findBestOption(m,l,&b,&totalSkor);
        clock_t end = clock();

        printf("\n\nSkor optimal: %d\n", totalSkor);
        if (totalSkor == 0) {
            printf("Tidak ada solusi\n\n");
        } else {
            printf("Buffer: ");printBufferMatrix(b,m);printf("\n");
            printf("Lokasi pada matriks:\n");printBuffer(b);printf("\n");
        }
        int time = (int)(((double)(end - begin) / CLOCKS_PER_SEC)*1000);
        printf("Perhitungan dilakukan selama %d ms\n\n", time);

        printf("Apakah ingin menyimpan solusi? (y/n)\n");
        scanf(" %c", &yesno);
        if (yesno == 'y' || yesno == 'Y') {
            saveToTXT(b,m, totalSkor,time);
            printf("\nPenyimpanan selesai.\n");
        } else {
            printf("Tidak melakukan penyimpanan\n");
        }

        printf("\nApakah ingin melakukan perhitungan lain? (y/n)\n");
        scanf(" %c", &kalang);
    } while (kalang == 'y' || kalang == 'Y');
    printf("\nProgram selesai dijalankan\nTerima kasih.\n");
    return 0;
}