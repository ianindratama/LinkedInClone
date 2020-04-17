#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "login.h"
#include "profile_akun_perusahaan.h"
#include "main_list_kerja.h"

struct structAkunPerusahaan{
    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

void main_menu_perusahaan(struct structAkunPerusahaan * akunPerusahaan){

    int menu_perusahaan;

    konversi_underscore_ke_spasi_profile_perusahaan(akunPerusahaan->namaPerusahaan);

    printf("\nHai %s,", akunPerusahaan->namaPerusahaan);
    printf("\n\n");
    printf("1. Lihat Profile Perusahaan \t 2. Iklan Lowongan Kerja Perusahaan \t 3. Lihat Daftar Pelamar Kerja \t 4. Lihat Daftar Pelamar Kerja yang Diterima \t 5. Logout\n");
    printf("Mau ngapain ? : ");
    scanf("%d", &menu_perusahaan);

    if(menu_perusahaan == 1){
        profile_akun_perusahaan(akunPerusahaan);
    }else if(menu_perusahaan == 2){
        menu_list_kerja(akunPerusahaan);
    }else if(menu_perusahaan == 3){
        daftar_pelamar_kerja(akunPerusahaan);
    }else if(menu_perusahaan == 4){
        daftar_pelamar_kerja_yang_telah_diterima(akunPerusahaan);
    }
    else if(menu_perusahaan == 5){
        fflush(stdin);
        system("cls");
        printf("Berhasil Logout\n");
        main();
    }

}
