#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "profile_akun_pekerja.h"
#include "main.h"

struct structAkunPekerja{
    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50];
};

void main_menu_pekerja(struct structAkunPekerja * akunPekerja){

    int menu_pekerja;

    printf("\nHai %s,", akunPekerja->nama);
    printf("\n\n");
    printf("1. Lihat Profile Saya \t 2. Cari Pekerjaan \t 3. Logout\n");
    printf("Mau ngapain ? : ");
    scanf("%d", &menu_pekerja);

    if(menu_pekerja == 1){
        profile_akun_pekerja(akunPekerja);
    }else if(menu_pekerja == 2){

    }else if(menu_pekerja == 3){
        fflush(stdin);
        system("cls");
        printf("Berhasil Logout\n");
        main();
    }

}
