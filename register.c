#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "profile_akun_pekerja.h"
#include "profile_akun_perusahaan.h"

struct structAkunPekerja{
    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];
};

struct structAkunPerusahaan{
    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

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

void cek_spasi(int * ada_spasi, char * kata){

    int i = 0;
    while( *(kata+i)!= '\0' ){
        if( *(kata+i) == ' ' ){
            *ada_spasi = 1;
            break;
        }else{
            *ada_spasi = 0;
        }
        i++;
    }

}

void register_pencari_kerja(){

    int jumlah_akun_pekerja = funcJumlahAkunPekerjaProfile();

    struct structAkunPekerja semuaAkunPekerja[funcJumlahAkunPekerjaProfile()];

    retrieveSemuaDataPekerjaDiFile(&semuaAkunPekerja);

    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];

    fflush(stdin);
    printf("Anda mendaftar sebagai Pencari Kerja\n");
    printf("Silahkan mengisi data dibawah ini!\n");

    int ada_spasi_username_pekerja = 0;

    menu_username_sesuai_kriteria_pekerja:
    printf("Username : ");
    gets(username);

    cek_spasi(&ada_spasi_username_pekerja, username);

    while( ada_spasi_username_pekerja == 1 ){
        printf("Username yang didaftarkan tidak boleh terdiri dari karakter spasi, silahkan gunakan username yang sesuai dengan kriteria tersebut\n");
        goto menu_username_sesuai_kriteria_pekerja;
    }

    while( (strlen(username) < 6) || (strlen(username) > 20) ){
        printf("Username yang didaftarkan harus terdiri dari 6 - 20 karakter, silahkan gunakan username yang sesuai dengan kriteria tersebut\n");
        goto menu_username_sesuai_kriteria_pekerja;
    }

    for(int i = 0; i<jumlah_akun_pekerja; i++){
        while( (strcmp(username, (semuaAkunPekerja+i)->username)) == 0 ){
            printf("Username yang anda masukkan sudah terdaftar, silahkan gunakan yang lain\n");
            goto menu_username_sesuai_kriteria_pekerja;
        }
    }

    int ada_spasi_password_pekerja = 0;

    menu_password_sesuai_kriteria_pekerja:
    printf("Password : ");
    gets(password);

    cek_spasi(&ada_spasi_password_pekerja, password);

    while( ada_spasi_password_pekerja == 1 ){
        printf("Password yang didaftarkan tidak boleh terdiri dari karakter spasi, silahkan gunakan password yang sesuai dengan kriteria tersebut\n");
        goto menu_password_sesuai_kriteria_pekerja;
    }

    while( (strlen(password) < 6) || (strlen(password) > 30) ){
        printf("Password yang didaftarkan harus terdiri dari 6 - 30 karakter, silahkan gunakan Password yang sesuai dengan kriteria tersebut\n");
        goto menu_password_sesuai_kriteria_pekerja;
    }


    printf("Nama : ");
    gets(nama);
    konversi_spasi_ke_underscore(nama);

    for(int i = 0; i<jumlah_akun_pekerja; i++){
        while( (strcmp(nama, (semuaAkunPekerja+i)->nama)) == 0 ){
            printf("Nama yang anda masukkan sudah terdaftar, silahkan gunakan yang lain\n");
            printf("Nama : ");
            gets(nama);
            konversi_spasi_ke_underscore(nama);
        }
    }

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
        if((fprintf(bukaFilePekerja, "%s %s %s %s %s %s %s %s %s %s %s %s",
        username, password, nama, tanggal_lahir, kewarganegaraan, nomor_telepon, pref_gaji, sd, smp, sma, sarjana, pengalaman_kerja)) < 0){
            printf("Ada kesalahan menulis data");
            exit(0);
        }else{
            fputc('\n', bukaFilePekerja);
            fclose(bukaFilePekerja);
            bukaFilePekerja = NULL;
            system("cls");
            printf("Berhasil Register sebagai pencari kerja, Silahkan Login terlebih dahulu\n\n");
            main();
        }
    }
}

void register_perusahaan(){

    int jumlah_akun_perusahaan = funcJumlahAkunPerusahaanProfile();

    struct structAkunPerusahaan semuaAkunPerusahaan[funcJumlahAkunPerusahaanProfile()];

    retrieveSemuaDataPerusahaanDiFile(&semuaAkunPerusahaan);

    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];

    fflush(stdin);
    printf("Anda mendaftar sebagai Perusahaan\n");
    printf("Silahkan mengisi data dibawah ini!\n");

    int ada_spasi_username_perusahaan = 0;

    menu_username_sesuai_kriteria_perusahaan:
    printf("Username : ");
    gets(username);

    cek_spasi(&ada_spasi_username_perusahaan, username);

    while( ada_spasi_username_perusahaan == 1 ){
        printf("Username yang didaftarkan tidak boleh terdiri dari karakter spasi, silahkan gunakan username yang sesuai dengan kriteria tersebut\n");
        goto menu_username_sesuai_kriteria_perusahaan;
    }

    while( (strlen(username) < 6) || (strlen(username) > 20) ){
        printf("Username yang didaftarkan harus terdiri dari 6 - 20 karakter, silahkan gunakan username yang sesuai dengan kriteria tersebut\n");
        goto menu_username_sesuai_kriteria_perusahaan;
    }

    for(int i = 0; i<jumlah_akun_perusahaan; i++){
        while( (strcmp(username, (semuaAkunPerusahaan+i)->username)) == 0 ){
            printf("Username yang anda masukkan sudah terdaftar, silahkan gunakan yang lain\n");
            goto menu_username_sesuai_kriteria_perusahaan;
        }
    }

    int ada_spasi_password_perusahaan = 0;

    menu_password_sesuai_kriteria_perusahaan:
    printf("Password : ");
    gets(password);

    cek_spasi(&ada_spasi_password_perusahaan, password);

    while( ada_spasi_password_perusahaan == 1 ){
        printf("Password yang didaftarkan tidak boleh terdiri dari karakter spasi, silahkan gunakan password yang sesuai dengan kriteria tersebut\n");
        goto menu_password_sesuai_kriteria_perusahaan;
    }

    while( (strlen(password) < 6) || (strlen(password) > 30) ){
        printf("Password yang didaftarkan harus terdiri dari 6 - 30 karakter, silahkan gunakan Password yang sesuai dengan kriteria tersebut\n");
        goto menu_password_sesuai_kriteria_perusahaan;
    }

    printf("Nama Perusahaan : ");
    gets(namaPerusahaan);
    konversi_spasi_ke_underscore(namaPerusahaan);

    for(int i = 0; i<jumlah_akun_perusahaan; i++){
        while( (strcmp(namaPerusahaan, (semuaAkunPerusahaan+i)->namaPerusahaan)) == 0 ){
            printf("Nama Perusahaan yang anda masukkan sudah terdaftar, silahkan gunakan yang lain\n");
            printf("Nama Perusahaan : ");
            gets(namaPerusahaan);
            konversi_spasi_ke_underscore(namaPerusahaan);
        }
    }

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
            printf("Berhasil Register sebagai Perusahaan , Silahkan Login menggunakan Akun Anda\n\n");
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
