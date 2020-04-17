/*/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  Modul               : Tugas Besar (9)
 *  Kelompok		: E-2
 *  Hari dan Tanggal    : Jumat, 17 April 2020
 *  Nama (NIM)          : Rhesa Muhammad Ramadhan (13217003);
 *                        Saif Sulthan Shaleh (18318032);
 *                        Faatihah Maurisna Ashfahani (18318036);
 *                        Jonathan Salomo (18318045)
 *  Asisten (NIM)       : Gabriella Hayley Tanudjaja (13216050)
 *  Nama File           : queuestruct.h
 *  Deskripsi           : File header untuk tipe data linked list dan queue
 */

#ifndef queuestruct
#define queuestruct

typedef struct QNode {
    char kata[300];
    struct QNode* next; 																// struct dengan isi node yang isinya string
} QNode;

typedef struct Queue {
    struct QNode *front, *rear; 														// struct dengan isi data front mana belakang (rear) mana
} Queue;

#endif
