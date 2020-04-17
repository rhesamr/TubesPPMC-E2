/*/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  Modul               : Tugas Besar (9)
 *  Kelompok		: E-2
 *  Hari dan Tanggal    : Jumat, 17 April 2020
 *  Nama (NIM)          : Rhesa Muhammad Ramadhan (13217003);
 *                        Saif Sulthan Shaleh (18318032);
 *                        Faatihah Maurisna Ashfahani (18318036);
 *                        Jonathan Salomo (18318045)
 *  Asisten (NIM)       : Gabriella Hayley Tanudjaja (13216050)
 *  Nama File           : cetakkata_kva.c
 *  Deskripsi           : File berisi fungsi untuk main menu dan penentuan key-value array
 */

#include "queuestruct.h"
#include "queue.h"
#include "cetakkata_kva.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printRandom(Queue* mungkin,Queue* q){                                        // Untuk mencetak kata jika key terhubung dengan lebih dari satu value
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	int low = 1;
	int up = 0;
	int i = 1;
	int num;
	temp = mungkin->front;
	if(temp->next == NULL){
		up = 1;
	}
	else{
	while(temp != NULL){                                                                        // struct node temp jika tidak kosong
		up += 1;
		temp = temp->next;
	}
	}
	temp = mungkin->front;
	if(up>1){
	num = (rand() % up)+1;
	while(temp!=NULL && i<num){
		temp = temp->next;
		i += 1;
	}
	}
	printf("%s ",temp->kata);
	enQueue(q,temp->kata);
	deQueue(q);
	return;
}

void printNext(Queue* semua, Queue* q,int gram,int jumlah){                   //Untuk mencetak kata berdasarkan queue q, bisa memanggil printrandom jika kondisi sesuai
	QNode* temp1 = (QNode*)malloc(sizeof(QNode));
	QNode* temp2 = (QNode*)malloc(sizeof(QNode));
	QNode* checkPoint = (QNode*)malloc(sizeof(QNode));
	int hitung = 0;
	int i = 0;
	Queue* kataMungkin = createQueue();

	temp1 = q->front;
	temp2 = semua->front;

	while(i<(jumlah+gram)){
		if(hitung==gram){
			enQueue(kataMungkin,temp2->kata);
			hitung = 0;
			temp1 = q->front;
		}
		if((temp1->kata != NULL) && strcmp(temp2->kata,temp1->kata)==0){
			if(hitung==0){
				checkPoint = temp2->next;
			}
			hitung += 1;
			temp1 = temp1->next;
			temp2 = temp2->next;
			i += 1;
		} else{
			if(hitung>0){
				i -= hitung;
				hitung = 0;
				temp1 = q->front;
				temp2 = checkPoint;
			}else{
				temp1 = q->front;
				temp2 = temp2->next;
				i += 1;
			}
		}
	}
	printRandom(kataMungkin,q);
	return;
}
void buatGram(Queue* semua, Queue* q,int jumlahGram){                     //Pengisian & pengosongan Queue q secara dinamis, key pertama dipilih menggunakan random number generator dari seed
	int i = -1;
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	time_t t;
	srand((unsigned) time(&t));
	temp = semua->front;
	while(q->front != NULL){
          deQueue(q);
          }
	while(i<((rand()%50)+1)){
		temp = temp->next;
		i+= 1;
	}
	i = 1;
	while(i<=jumlahGram){
		temp = temp->next;
		enQueue(q,temp->kata);
		i += 1;
	}
	return;
}
void print(Queue* q){                                                        // Fungsi untuk mencetak key pertama
	QNode* temp = ( QNode*)malloc(sizeof(QNode));
	temp = q->front;
	while(temp != NULL){
		printf("%s ", temp->kata);
		temp = temp->next;
	}
}
