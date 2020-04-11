#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void input_register_pencarikerja_file(char username[50], char password[50], char nama[50], char tanggal_lahir[50], char kewarganegaraan[50],
                                      char nomor_telepon[25], char pref_gaji[50],
                                      char sd[50],char smp[50],char sma[50],char sarjana[50], char pengalaman_kerja[50]);

void input_register_perusahaan_file(char *username, char *password,
                               char *namaPerusahaan, char *kategoriPerusahaan, char *alamatPerusahaan, char *fasilitasPerusahaan);

void konversi_spasi_ke_underscore(char * kata){
    int i = 0;
    while( *(kata+i)!= '\0' ){
        if( *(kata+i) == ' ' ){
            *(kata+i) = '_';
        }
        i++;
    }

}

void register_pencari_kerja(){
    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];

    fflush(stdin);
    printf("Anda mendaftar sebagai Pencari Kerja\n");
    printf("Silahkan mengisi data dibawah ini!\n");
    printf("Username : ");
    gets(username);
    printf("Password : ");
    gets(password);
    printf("Nama : ");
    gets(nama);
    konversi_spasi_ke_underscore(nama);
    printf("Tanggal Lahir(dd/mm/yy) : ");
    gets(tanggal_lahir);
    printf("Kewarganegaraan : ");
    gets(kewarganegaraan);
    konversi_spasi_ke_underscore(kewarganegaraan);
    printf("Nomer Telepon : ");
    gets(nomor_telepon);
    printf("Preferensi Gaji (ex: 3.000.000) : ");
    gets(pref_gaji);
    printf("Riwayat Pendidikan\n");
    printf("SD : ");
    gets(sd);
    konversi_spasi_ke_underscore(sd);
    printf("SMP : ");
    gets(smp);
    konversi_spasi_ke_underscore(smp);
    printf("SMA : ");
    gets(sma);
    konversi_spasi_ke_underscore(sma);
    printf("Sarjana : ");
    gets(sarjana);
    konversi_spasi_ke_underscore(sarjana);
    printf("Riwayat Kerja\n");
    printf("Pengalaman Kerja (jika tidak ada ketik \" - \") : ");
    gets(pengalaman_kerja);
    konversi_spasi_ke_underscore(pengalaman_kerja);

    input_register_pencarikerja_file(username, password, nama, tanggal_lahir, kewarganegaraan, nomor_telepon, pref_gaji, sd, smp, sma, sarjana, pengalaman_kerja);
}

void input_register_pencarikerja_file(char *username, char *password, char *nama, char *tanggal_lahir, char *kewarganegaraan, char *nomor_telepon, char *pref_gaji,
char *sd, char *smp, char *sma, char *sarjana, char *pengalaman_kerja){
    FILE * bukaFilePekerja = fopen("akun_pencarikerja.txt", "a+");
    if(bukaFilePekerja == NULL){
        printf("terjadi kesalahan");
        exit(0);
    }else{
        printf("\n\n%s", nama);
        if((fprintf(bukaFilePekerja, "%s %s %s %s %s %s %s %s %s %s %s %s",
        username, password, nama, tanggal_lahir, kewarganegaraan, nomor_telepon, pref_gaji, sd, smp, sma, sarjana, pengalaman_kerja)) < 0){
            printf("Ada kesalahan menulis data");
            exit(0);
        }else{
            fputc('\n', bukaFilePekerja);
            fclose(bukaFilePekerja);
            bukaFilePekerja = NULL;
            system("cls");
            printf("Berhasil Register sebagai pencari kerja\n\n");
            main();
        }
    }
}

void register_perusahaan(){

    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];

    fflush(stdin);
    printf("Anda mendaftar sebagai Perusahaan\n");
    printf("Silahkan mengisi data dibawah ini!\n");
    printf("Username : ");
    gets(username);
    printf("Password : ");
    gets(password);
    printf("Nama Perusahaan : ");
    gets(namaPerusahaan);
    konversi_spasi_ke_underscore(namaPerusahaan);
    printf("Kategori Perusahaan (ex : Teknologi ) : ");
    gets(kategoriPerusahaan);
    konversi_spasi_ke_underscore(kategoriPerusahaan);
    printf("Alamat Perusahaan : ");
    gets(alamatPerusahaan);
    konversi_spasi_ke_underscore(alamatPerusahaan);
    printf("Fasilitas Perusahaan : ");
    gets(fasilitasPerusahaan);
    konversi_spasi_ke_underscore(fasilitasPerusahaan);

    input_register_perusahaan_file(username, password, namaPerusahaan, kategoriPerusahaan, alamatPerusahaan, fasilitasPerusahaan);
}

void input_register_perusahaan_file(char *username, char *password, char *namaPerusahaan, char *kategoriPerusahaan, char *alamatPerusahaan, char *fasilitasPerusahaan){
    FILE * bukaFilePerusahaan = fopen("akun_perusahaan.txt", "a+");
    if(bukaFilePerusahaan == NULL){
        printf("terjadi kesalahan");
        exit(0);
    }else{
        if((fprintf(bukaFilePerusahaan, "%s %s %s %s %s %s",
        username, password, namaPerusahaan, kategoriPerusahaan, alamatPerusahaan, fasilitasPerusahaan)) < 0){
            printf("Ada kesalahan menulis data");
            exit(0);
        }else{
            fputc('\n', bukaFilePerusahaan);
            fclose(bukaFilePerusahaan);
            bukaFilePerusahaan = NULL;
            system("cls");
            printf("Berhasil Register sebagai pencari kerja, Silahkan Login menggunakan Akun Anda\n\n");
            main();
        }
    }
}

void register_form(){
    int register_sebagai;
    printf("==Register==\n");
    menu_register:
    printf("Register sebagai : 1.Pencari Kerja\t2.Perusahaan\n");
    scanf("%d", &register_sebagai);
    if(register_sebagai == 1){
        register_pencari_kerja();
    }else if(register_sebagai == 2){
        register_perusahaan();
    }else{
        printf("Menu yang dipilih salah");
        goto menu_register;
    }

}
