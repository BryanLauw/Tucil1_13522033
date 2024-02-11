# Tugas Kecil 1 IF2211 Strategi Algoritma
> by Bryan Cornelius Lauwrence

## Tabel Konten
* [Informasi Umum](#informasi-umum)
* [Deskripsi Singkat](#deskripsi-singkat)
* [Setup dan Penggunaan](#setup-dan-penggunaan)
* [Kreator](#kreator)

## Informasi Umum
Penyelesaian Cyberpunk 2077 Breach Protocol dengan Algoritma Brute Force.<br>
Contoh terdapat pada laman https://cyberpunk-hacker.com/.

## Deskripsi Singkat
Pemain menyediakan matriks berisi dua karakter alfanumerik dan beberapa sekuens beserta reward dari masing-masing sekuens.<br>
Program akan mencari solusi terbaik (reward maksimal) dari matriks dimulai dari salah satu kolom pada baris pertama,<br>lalu bergerak horizontal dan vertikal secara bergantian dengan algoritma brute force. <br>Program dibuat dalam bahasa C.

## Setup dan Penggunaan
1. Clone repository ini dengan perintah
```bash
git clone
```
2. Jika ingin meng-compile program jalankan perintah
```bash
gcc -o bin/main main.c data.c
```
3. Jalankan program dengan perintah
```bash
bin/main
```

## Struktur File
Direktori tugas ini memiliki struktur file sebagai berikut:
```bash
.
├── README.md
├── bin
│   └── main.exe
├── doc
│   └── Screenshot 2024-02-11 190004.png
├── src
│   ├── boolean.h
│   ├── data.c
│   ├── data.h
│   └── main.c
└── test
    ├── cli1.txt
    ├── percobaan-2.txt
    ├── percobaan2-answer.txt
    ├── try-answer.txt
    └── try.txt
```

## Kreator
| NIM | Nama |
|-----|------|
| 13522033 | Bryan Cornelius Lauwrence |