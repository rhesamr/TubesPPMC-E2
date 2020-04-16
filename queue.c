/*/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  Modul               : Tugas Besar (9)
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
    // Create a new LL node
    QNode* temp = ( QNode*)malloc(sizeof(QNode));
	strcpy(temp->kata,katabaru);
	temp->next = NULL;

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    QNode* temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

Queue* createQueue()
{
    Queue* q = ( Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}