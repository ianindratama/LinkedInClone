#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_pekerja.h"

struct structAkunPekerja{
    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];
};

void gantiProfilePekerja(struct structAkunPekerja * akunPekerja){

    char buffer[50];
    printf("\n\n\n");
    printf("Ganti Profile (gunakan tanda \"-\" jika tidak ingin mengganti\n");
    printf("Biodata Diri : \n");
    //nama
    printf("Nama : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->nama, buffer)) != akunPekerja->nama){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    //tanggal lahir
    printf("Tanggal Lahir : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->tanggal_lahir, buffer)) != akunPekerja->tanggal_lahir){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    //kewarganegaraan
    printf("Kewarganegaraan : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->kewarganegaraan, buffer)) != akunPekerja->kewarganegaraan){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    //Nomer Telepon
    printf("Nomor Telepon : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->nomor_telepon, buffer)) != akunPekerja->nomor_telepon){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    //Preferensi Gaji
    printf("Preferensi Gaji : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->pref_gaji, buffer)) != akunPekerja->pref_gaji){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    printf("\nRiwayat Pendidikan : \n");
    //SD
    printf("SD : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->sd, buffer)) != akunPekerja->sd){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    //SMP
    printf("SMP : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->smp, buffer)) != akunPekerja->smp){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    //SMA
    printf("SMA : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->sma, buffer)) != akunPekerja->sma){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    //Sarjana
    printf("Sarjana : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->sarjana, buffer)) != akunPekerja->sarjana){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    printf("\nRiwayat Kerja : \n");
    //Pengalaman Kerja
    printf("Pengalaman Kerja : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPekerja->pengalaman_kerja, buffer)) != akunPekerja->pengalaman_kerja){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
        printf("\n\n%s", akunPekerja->pengalaman_kerja);
    }
    // stop right here
    printf("Berhasil mengupdate profile akun");

}

void profile_akun_pekerja(struct structAkunPekerja * akunPekerja){

    printf("Biodata Diri : \n");
    printf("Nama : %s\n", akunPekerja->nama);
    printf("Tanggal Lahir : %s\n", akunPekerja->tanggal_lahir);
    printf("Kewarganegaraan : %s\n", akunPekerja->kewarganegaraan);
    printf("Nomor Telepon : %s\n", akunPekerja->nomor_telepon);
    printf("Preferensi Gaji : %s\n", akunPekerja->pref_gaji);
    printf("\nRiwayat Pendidikan : \n");
    printf("SD : %s\n", akunPekerja->sd);
    printf("SMP : %s\n", akunPekerja->smp);
    printf("SMA : %s\n", akunPekerja->sma);
    printf("Sarjana : %s\n", akunPekerja->sarjana);
    printf("\nRiwayat Kerja : \n");
    printf("Pengalaman Kerja : %s\n", akunPekerja->pengalaman_kerja);

    int menu_profile_akun_pekerja;
    printf("\n\nIngin melakukan apa ?\n");
    printf("1.Ganti Profile\n");
    printf("2.Ubah Password\n");
    printf("3.Kembali ke menu pekerja\n");
    scanf("%d", &menu_profile_akun_pekerja);
    getchar();

    if(menu_profile_akun_pekerja == 1){

        FILE * bukaFilePekerja = fopen("akun_pencarikerja.txt", "r");
        (bukaFilePekerja == NULL) ? exit(0) : NULL;

        gantiProfilePekerja(akunPekerja);



    }else if(menu_profile_akun_pekerja == 2){

    }else if(menu_profile_akun_pekerja == 3){
        system("cls");
        main_menu_pekerja(akunPekerja);
    }
}
