/*/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  Modul               : Tugas Besar (9)
 *  Kelompok		: E-2
 *  Hari dan Tanggal    : Jumat, 17 April 2020
 *  Nama (NIM)          : Rhesa Muhammad Ramadhan (13217003);
 *                        Saif Sulthan Shaleh (18318032);
 *                        Faatihah Maurisna Ashfahani (18318036);
 *                        Jonathan Salomo (18318045)
 *  Asisten (NIM)       : Gabriella Hayley Tanudjaja (13216050)
 *  Nama File           : queue.c
 *  Deskripsi           : File berisi fungsi-fungsi operasi pada queue.
 */
#include "queuestruct.h"
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enQueue(Queue* q, char katabaru[100])
{
    QNode* temp = ( QNode*)malloc(sizeof(QNode));                                   // Membuat linked list baru
	strcpy(temp->kata,katabaru);
	temp->next = NULL;

    if (q->rear == NULL) {                                                          // Keadaan queue kosong, node baru berisi front dan rear
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;                                                           // Menambahkan node baru di akhir queue dan mengganti rear
    q->rear = temp;
}

void deQueue(Queue* q)
{
    if (q->front == NULL)                                                           // Queue kosong mengembalikan NULL
        return;

    QNode* temp = q->front;                                                         // Menyimpan front sebelumnya dan memindahkan front node di depan

    q->front = q->front->next;

    if (q->front == NULL)                                                           // Jika front berupa NULL, rear juga akan NULL
        q->rear = NULL;

    free(temp);
}

Queue* createQueue()
{
    Queue* q = ( Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
