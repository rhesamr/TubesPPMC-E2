/*/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  Modul               : Tugas Besar (9)
 *  Kelompok		: E-2
 *  Hari dan Tanggal    : Jumat, 17 April 2020
 *  Nama (NIM)          : Rhesa Muhammad Ramadhan (13217003);
 *                        Saif Sulthan Shaleh (18318032);
 *                        Faatihah Maurisna Ashfahani (18318036);
 *                        Jonathan Salomo (18318045)
 *  Asisten (NIM)       : Gabriella Hayley Tanudjaja (13216050)
 *  Nama File           : queue.h
 *  Deskripsi           : File header untuk queue.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue* createQueue(); 															// fungsi buat bikin queue/antrian baru
void enQueue(struct Queue* q, char* katabaru); 										    // fungsi buat nambah isinya queue
void deQueue(struct Queue* q);														    //fungsi buat mengurangi isinya queue
