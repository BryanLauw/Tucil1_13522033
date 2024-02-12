# Tugas Kecil 1 IF2211 Strategi Algoritma
> by Bryan Cornelius Lauwrence

## Daftar Konten
* [Informasi Umum](#informasi-umum)
* [Deskripsi Singkat](#deskripsi-singkat)
* [Setup dan Penggunaan](#setup-dan-penggunaan)
* [Kreator](#kreator)

## Informasi Umum
Penyelesaian Cyberpunk 2077 Breach Protocol dengan Algoritma Brute Force.

## Deskripsi Singkat
Pemain menyediakan matriks berisi dua karakter alfanumerik dan beberapa sekuens beserta reward dari masing-masing sekuens. Program akan mencari solusi terbaik (reward maksimal) dari matriks dimulai dari salah satu kolom pada baris pertama, lalu bergerak horizontal dan vertikal secara bergantian dengan algoritma brute force.<br>Program dibuat dalam bahasa pemrograman C.<br>Contoh terdapat pada laman https://cyberpunk-hacker.com/.

## Setup dan Penggunaan
1. Clone repository ini dengan perintah
```bash
git clone https://github.com/BryanLauw/Tucil1_13522033.git
```
2. Jika ingin meng-compile program jalankan perintah sesuai OS
Pada Windows:
```shell
gcc -o bin/main src/main.c src/data.c
```
Pada Linux:
```bash
gcc -o bin/main src/main.c src/data.c -lm
```
3. Pada Windows, jalankan program dengan perintah:
```shell
.\bin\main.exe
```
Sedangkan pada Linux, jalankan program dengan perintah:
```bash
bin/main
```
4. Jika ingin menginput dari file, gunakan format berikut pada file txt dan tempatkan pada folder test.
```
buffer_size
matrix_width matrix_height
matrix
number_of_sequences
sequences_1
sequences_1_reward
sequences_2
sequences_2_reward
…
sequences_n
sequences_n_reward
```
Contoh terdapat pada file percobaan1.txt
5. Ikuti arahan program dan berikan input.

## Struktur File
Direktori tugas ini memiliki struktur file sebagai berikut:
```
.
.
├── README.md
├── bin
│   ├── main
│   └── main.exe
├── doc
│   └── Tucil1_K01_13522033_Bryan Cornelius Lauwrence.pdf
├── src
│   ├── boolean.h
│   ├── data.c
│   ├── data.h
│   ├── main.c
│   └── try.py
└── test
    ├── percobaan1-answer.txt
    ├── percobaan1.txt
    ├── percobaan2-answer.txt
    ├── percobaan2.txt
    ├── percobaan3-answer.txt
    ├── percobaan3.txt
    ├── percobaan4-answer.txt
    ├── percobaan5-answer.txt
    ├── percobaan5.txt
    ├── percobaan6-answer.txt
    ├── percobaan7-answer.txt
    └── percobaan7.txt
```

## Kreator
| NIM | Nama |
|-----|------|
| 13522033 | Bryan Cornelius Lauwrence |