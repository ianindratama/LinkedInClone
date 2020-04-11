#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "profile_akun_perusahaan.h"

struct structAkunPerusahaan{
    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

void main_menu_perusahaan(struct structAkunPerusahaan * akunPerusahaan){

    int menu_perusahaan;

    printf("\nHai %s,", akunPerusahaan->namaPerusahaan);
    printf("\n\n");
    printf("1. Lihat Profile Perusahaan \t 2. Iklan Lowongan Kerja Perusahaan \t 3. Logout\n");
    printf("Mau ngapain ? : ");
    scanf("%d", &menu_perusahaan);

    if(menu_perusahaan == 1){
        profile_akun_perusahaan(akunPerusahaan);
    }else if(menu_perusahaan == 2){

    }else if(menu_perusahaan == 3){
        fflush(stdin);
        system("cls");
        printf("Berhasil Logout\n");
        main();
    }

}
