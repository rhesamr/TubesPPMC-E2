#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue* createQueue(); 															// fungsi buat bikin queue/antrian baru
void enQueue(struct Queue* q, char* katabaru); 										    // fungsi buat nambah isinya queue
void deQueue(struct Queue* q);														    //fungsi buat mengurangi isinya queue
