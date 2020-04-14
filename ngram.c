#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

struct QNode { 
    char kata[100]; 
    struct QNode* next; 																// struct dengan isi node yang isinya string
};

struct Queue { 
    struct QNode *front, *rear; 														// struct dengan isi data front mana belakang (rear) mana
};

struct Queue* createQueue(); 															// fungsi buat bikin queue/antrian baru
//struct Qnode* newNode(char katabaru[100]);					<- ini nggak guna
void enQueue(struct Queue* q, char katabaru[100]); 										// fungsi buat nambah isinya queue
void deQueue(struct Queue* q); 															//fungsi buat mengurangi isinya queue
void print(struct Queue* q); 															// fungsi buat ngeprint semua isi queue
void buatgram(struct Queue* semua, struct Queue* q,int jumlahgram); 								//fungsi buat ngebuat gram yang jadi patokan
void printnext(struct Queue* semua, struct Queue* q,int gram,int jumlah);	// print next ini buat nyari kata selanjutnya yang mungkin
void printrandom(struct Queue* mungkin,struct Queue* q);								//ini buat ngeprint kata selanjutanya dan ambil random
																						//fungsi printrandom aku satuin sama printnext
																						//fungsi printrandom sekalian langsung masukin kata kunci baru
																						//buat nyari kata selanjutnya yang lain														
int main(){
	struct Queue* q = createQueue(); 													// bikin queue baru
	struct Queue* semuakata= createQueue();
	FILE *fp;
	char filename[100], katafile[100];
	int gram;
	int jumlahkata, jumlahkatafile;
	int i = 0;
	printf("Masukkan nama file yang ingin dibaca :");									//Dari line 29 sampai line 37
	scanf(" %s",&filename);																//ini dia ngambil input
	while((fp = fopen(filename,"r")) == NULL){											//file apa yang mau dibuka
		printf("\nFile tidak ada\n\n");													//dan gramnya berapa
		printf("Masukkan nama file yang ingin dibaca :");								//
		scanf(" %s",&filename);															//
	}																					//
	printf("Masukkan nilai gram yang diinginkan :");									//
	scanf(" %d", &gram);																//
	printf("Masukkan jumlah kata yang ingin dicetak :");
	scanf(" %d", &jumlahkata);
	while(fscanf(fp,"%s",katafile) != EOF){
		enQueue(semuakata,katafile);
		jumlahkatafile += 1;
	}
	semuakata->rear->next = semuakata->front;
	fclose(fp);
	buatgram(semuakata,q,gram);																//ini buat ngebuat gramnya yang jadi patokan
	
	
	print(q);																		//ini cuma ngeprint sih biar tau kalau gramnya kebuat										
	
	while(i<jumlahkata){
		printnext(semuakata,q,gram,jumlahkatafile);
		i += 1;
	}
	return(0);
}

/*struct Qnode* newNode(char katabaru[100]){
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	strcpy(temp->kata,katabaru);
	temp->next = NULL;
	return temp;
}*/

void printrandom(struct Queue* mungkin,struct Queue* q){
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	int low = 1;
	int up = 0;
	int i = 1;
	int num;
	time_t t;
	srand((unsigned) time(&t));
	temp = mungkin->front;
	if(temp->next == NULL){
		up = 1;
	}else{
	while(temp != NULL){
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

void printnext(struct Queue* semua, struct Queue* q,int gram,int jumlah){
	struct QNode* temp1 = (struct QNode*)malloc(sizeof(struct QNode));
	struct QNode* temp2 = (struct QNode*)malloc(sizeof(struct QNode));
	int hitung = 0;
	int i = 0;
	struct Queue* katamungkin = createQueue();
	temp1 = q->front;
	temp2 = semua->front;
	while(i<=(jumlah+gram)){																	
		if(hitung==gram){
			enQueue(katamungkin,temp2->kata);
			hitung = 0;
			temp1 = q->front;
		}
		if((temp1->kata != NULL) && strcmp(temp2->kata,temp1->kata)==0){
			hitung += 1;
			temp1 = temp1->next;
		} else{
			hitung = 0;
			temp1 = q->front;
		}
		temp2 = temp2->next;
		i += 1;
	}
	printrandom(katamungkin,q);
	return;
}
void buatgram(struct Queue* semua, struct Queue* q,int jumlahgram){
	int i = -1;
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	time_t t;
	srand((unsigned) time(&t));
	temp = semua->front;
	while(i<((rand()%50)+1)){
		temp = temp->next;
		i+= 1;
	}
	i = 1;
	while(i<=jumlahgram){
		temp = temp->next;
		enQueue(q,temp->kata);
		i += 1;
	}
	return;
}
void print(struct Queue* q){
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp = q->front;
	while(temp != NULL){
		printf("%s ", temp->kata);
		temp = temp->next;
	}
}
void enQueue(struct Queue* q, char katabaru[100]) 
{ 
    // Create a new LL node 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
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

void deQueue(struct Queue* q) 
{ 
    // If queue is empty, return NULL. 
    if (q->front == NULL) 
        return; 
  
    // Store previous front and move front one node ahead 
    struct QNode* temp = q->front; 
  
    q->front = q->front->next; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL) 
        q->rear = NULL; 
  
    free(temp); 
}

struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 