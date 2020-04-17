/*/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  Modul               : Tugas Besar (9)
 *  Kelompok		: E-2
 *  Hari dan Tanggal    : Jumat, 17 April 2020
 *  Nama (NIM)          : Rhesa Muhammad Ramadhan (13217003);
 *                        Saif Sulthan Shaleh (18318032);
 *                        Faatihah Maurisna Ashfahani (18318036);
 *                        Jonathan Salomo (18318045)
 *  Asisten (NIM)       : Gabriella Hayley Tanudjaja (13216050)
 *  Nama File           : cetakkata_kva.h
 *  Deskripsi           : File header untuk cetakkata_kva.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print(struct Queue* q); 															// fungsi untuk mencetak semua isi queue
void buatGram(struct Queue* semua, struct Queue* q,int jumlahGram); 					// fungsi membuat gram yang menjadi patokan
void printNext(struct Queue* semua, struct Queue* q,int gram,int jumlah);	            // print next digunakan untuk mencari kata selanjutnya yang mungkin
void printRandom(struct Queue* mungkin,struct Queue* q);                                // print random untuk mencetak kata selanjutnya dan ambil ramdom
