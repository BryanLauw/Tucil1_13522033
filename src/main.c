#include "data.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/* KAMUS */
int pilih;
char yesno;
char kalang;
Matrix m;
ListSequence l;
Buffer b;
Point p;
int bufferSize;
int totalSkor;
/* ALGORITMA */
int main () {
    system(CLEAR);
    

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@                                                                              @\n");
    printf("@   ____      _                                 _      ____   ___ _____ _____  @\n");
    printf("@  / ___|   _| |__   ___ _ __ _ __  _   _ _ __ | | __ |___ \\ / _ \\___  |___  | @\n");
    printf("@ | |  | | | | '_ \\ / _ \\ '__| '_ \\| | | | '_ \\| |/ /   __) | | | | / /   / /  @\n");
    printf("@ | |__| |_| | |_) |  __/ |  | |_) | |_| | | | |   <   / __/| |_| |/ /   / /   @\n");
    printf("@  \\____\\__, |_.__/ \\___|_|  | .__/ \\__,_|_| |_|_|\\_\\ |_____|\\___//_/   /_/    @\n");
    printf("@       |___/                |_|                                               @\n");
    printf("@  ____                      _       ____            _                  _      @\n");
    printf("@ | __ ) _ __ ___  __ _  ___| |__   |  _ \\ _ __ ___ | |_ ___   ___ ___ | |     @\n");
    printf("@ |  _ \\| '__/ _ \\/ _` |/ __| '_ \\  | |_) | '__/ _ \\| __/ _ \\ / __/ _ \\| |     @\n");
    printf("@ | |_) | | |  __/ (_| | (__| | | | |  __/| | | (_) | || (_) | (_| (_) | |     @\n");
    printf("@ |____/|_|  \\___|\\__,_|\\___|_| |_| |_|   |_|  \\___/ \\__\\___/ \\___\\___/|_|     @\n");
    printf("@                                                                              @\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");


    printf("\n========================================:========================================\n");
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

        printf("\nMelakukan perhitungan...\n");
        totalSkor = 0;
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