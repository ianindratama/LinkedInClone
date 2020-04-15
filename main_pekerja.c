#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "profile_akun_pekerja.h"
#include "main.h"
#include "cari_kerja_pekerja.h"

struct structAkunPekerja{
    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];
};

void main_menu_pekerja(struct structAkunPekerja * akunPekerja){

    konversi_underscore_ke_spasi_profile(akunPekerja->nama);

    int menu_pekerja;

    printf("\nHai %s,", akunPekerja->nama);
    printf("\n\n");
    printf("1. Lihat Profile Saya \t 2. Cari Pekerjaan \t 3. Cek Daftar Pekerjaan yang saya Applied \t 4. Logout\n");
    printf("Mau ngapain ? : ");
    scanf("%d", &menu_pekerja);

    if(menu_pekerja == 1){
        profile_akun_pekerja(akunPekerja);
    }else if(menu_pekerja == 2){
        tampilkan_semua_pekerjaan(akunPekerja);
    }else if(menu_pekerja == 3){
        cek_daftar_pekerjaan(akunPekerja);
    }else if(menu_pekerja == 4){
        fflush(stdin);
        system("cls");
        printf("Berhasil Logout\n");
        main();
    }

}
