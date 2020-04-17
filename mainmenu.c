/*/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  Modul               : Tugas Besar (9)
 *  Kelompok		: E-2
 *  Hari dan Tanggal    : Jumat, 17 April 2020
 *  Nama (NIM)          : Rhesa Muhammad Ramadhan (13217003);
 *                        Saif Sulthan Shaleh (18318032);
 *                        Faatihah Maurisna Ashfahani (18318036);
 *                        Jonathan Salomo (18318045)
 *  Asisten (NIM)       : Gabriella Hayley Tanudjaja (13216050)
 *  Nama File           : mainmenu.c
 *  Deskripsi           : File berisi fungsi untuk menampilkan Main Menu
 */

#include "mainmenu.h"

#include <stdio.h>

int main_menu(char readFileName[106]){

    int pilihMenu;

    if (readFileName[0]!='\0'){
        printf("File Terbaca: %s\n", readFileName);
    }
    printf("\nMenu yang tersedia: \n");
    printf("1. Memilih File Eksternal Baru dari Folder \"/texts\"\n");
    printf("2. Mencetak n-grams \n");
    printf("3. Keluar dari program\n");
    printf("Silakan pilih menu yang diinginkan: ");
    scanf("%d", &pilihMenu);

    return pilihMenu;
}
