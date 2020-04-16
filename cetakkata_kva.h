#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print(struct Queue* q); 															// fungsi untuk mencetak semua isi queue
void buatGram(struct Queue* semua, struct Queue* q,int jumlahGram); 					// fungsi membuat gram yang menjadi patokan
void printNext(struct Queue* semua, struct Queue* q,int gram,int jumlah);	            // print next digunakan untuk mencari kata selanjutnya yang mungkin
void printRandom(struct Queue* mungkin,struct Queue* q);                                // print random untuk mencetak kata selanjutnya dan ambil ramdom