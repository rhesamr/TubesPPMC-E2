/*/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  Modul               : Tugas Besar (9)
 *  Kelompok		: E-2
 *  Hari dan Tanggal    : Jumat, 17 April 2020
 *  Nama (NIM)          : Rhesa Muhammad Ramadhan (13217003);
 *                        Saif Sulthan Shaleh (18318032);
 *                        Faatihah Maurisna Ashfahani (18318036);
 *                        Jonathan Salomo (18318045)
 *  Asisten (NIM)       : Gabriella Hayley Tanudjaja (13216050)
 *  Nama File           : mainE2.c
 *  Deskripsi           : N-Grams Berdasarkan File Eksternal
 */

#include "queuestruct.h"
#include "queue.h"
#include "cetakkata_kva.h"
#include "mainmenu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <dirent.h>

void myStrcat(char *dst, const char *src);

COORD coord = {0, 0};
void gotoxy(int x, int y) // mengatur kursor agar dapat dipindahkan dengan nilai x & y tertentu
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Program Utama
int main(){
	Queue* q = createQueue(); 												  // Queue untuk menyimpan key n-grams secara dinamis
	Queue* semuaKata= createQueue();                                           // untuk menyimpan semua kata pada File Referensi
	FILE *fp;
	char fileName[106], kataFile[100];                                                // filename untuk menyimpan nama file, katafile sebagai string sementara untuk memindahkan teks ke Queue semuakata
	int gram;
	int jumlahKataFile;                                                               // jumlahakatafile menampilkan jumlah total seluruh kata pada file
	int jumlahKata;                                                                   // jumlah kata n-gram yang akan dicetak
	int i = 0;
	int opsi_menu;                                                                    // indeks menu pada main_menu
	char opsi_ulang;                                                                  // pilihan perulangan n-gram tanpa kembali ke menu utama
    char folderName[] = "texts/";

	system("cls");

    gotoxy(20,1);
    printf("Selamat datang di ");

    gotoxy(10,2);
    printf("N-Gram Application : Where Words Come from Nowhere\n\n");
	printf("-------------------------------------------------------------------------------\n");
    printf("----N-gram merupakan proses yang digunakan dalam pengolahan teks dan bahasa----\n");
	printf("--dalam pengembangan web seperti Google dan Microsoft berupa kumpulan paragraf-\n");
    printf("--------dengan menggerakan satu kata maju ke depan dari n-gram masukan.--------\n");
	printf("-------------------------------------------------------------------------------\n");
    printf("Program ini menjalankan prinsip N-Gram dalam Natural Language Programming(NLP)\n");
    printf("Berdasarkan file teks eksternal dan nilai N-gram preferensi user.\n");

    memset(fileName, '\0', 106);                                                                //flush isi array

	do{
	opsi_menu = main_menu(fileName);                                                            //memilih opsi pada main menu
        switch (opsi_menu){
        case 1:
			while(q->rear !=NULL){                                                              //Pengosongan Linked List jika belum kosong
                deQueue(q);
            }

            printf("Masukkan nama file yang ingin dibaca :");									//meminta nama file eksternal dari user
            scanf(" %s",&fileName);
            myStrcat(fileName, folderName);
            
            while((fp = fopen(fileName,"r")) == NULL){											//Jika file tidak valid, program mencetak peringatan
                printf("\nFile tidak ada!");
                printf("\nHanya letakkan file di folder \"/texts\"\n\n");

                memset(fileName, '\0', 106);                                                    //flush isi array

                printf("Masukkan nama file yang ingin dibaca pada folder:");
                scanf(" %s",&fileName);
                myStrcat(fileName, folderName);
                }

            while(fscanf(fp,"%s",kataFile) != EOF){                                             //Teks, kata per kata, dimasukkan ke Queue semuakata
                enQueue(semuaKata,kataFile);
                jumlahKataFile += 1;
            }
            semuaKata->rear->next = semuaKata->front;
            fclose(fp);
            printf("\nPembacaan file berhasil. \n");
            break;

        case 2:
            do{
            printf("Masukkan nilai gram yang diinginkan :");									// meminta nilai n-gram yang diinginkan
            scanf(" %d", &gram);
            printf("Masukkan jumlah kata yang ingin dicetak :");
            scanf(" %d", &jumlahKata);                                                          //meminta nilai jumlah kata ynag diinginkan

            buatGram(semuaKata,q,gram);
            printf("... ");
            print(q);						                                                    //pencetakan key pertama

            i = 0;
            while(i<jumlahKata-gram){
                printNext(semuaKata,q,gram,jumlahKataFile);                                     // pencetakan kata - kata selanjutnya
                i += 1;
            }
            printf("...");

            printf("\nApakah Anda ingin mencetak n-gram dengan file ini lagi [y/n]? ");         // pilihan perulangan operasi n-gram pada file yang sama
            scanf(" %c", &opsi_ulang);

            switch(opsi_ulang){
            case 'y':                                                                           // Perulangan dilakukan
                system("cls");
                break;
            case 'n':                                                                           //kembali ke menu utama
                break;
			//default :
         		//printf("Maaf, input Anda Salah.\n" );
                }
            }while(opsi_ulang != 'n');
            break;
        case 3:                                                                                  //IF 3: keluar dari program
            break;
        default:                                                                                 //jika opsi_menu tidak valid
            printf("\nInstruksi salah!\n ");
            break;
        }
	}while(opsi_menu != 3);

    system("cls");
	printf("-------------------------------------------------------------------------------\n");
    printf("---------------------Terimakasih sudah menggunakan program.--------------------\n");
	printf("-------------------------Semoga hari Anda bahagia :-)--------------------------\n");
	printf("-------------------------------------------------------------------------------\n");
	return(0);
}

void myStrcat(char *dst, const char *src)
{
    size_t dst_len = strlen(dst) + 1, src_len = strlen(src);
    memmove(dst + src_len, dst, dst_len);
    memcpy(dst, src, src_len);
}
