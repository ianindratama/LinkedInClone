#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_pekerja.h"
#include "main_perusahaan.h"

int funcJumlahAkunPekerja(){
    FILE * bukaFilePekerja = fopen("akun_pencarikerja.txt", "r");
    (bukaFilePekerja == NULL) ? exit(0) : NULL;
    //menghitung jumlah akun di file pekerja
        char cek_jumlah_akun_pekerja;
        int jumlah_akun_pekerja = 0;
        while( (cek_jumlah_akun_pekerja = fgetc(bukaFilePekerja)) != EOF ){
            if(cek_jumlah_akun_pekerja == '\n'){
                jumlah_akun_pekerja++;
            }
        }
        fclose(bukaFilePekerja);
        bukaFilePekerja = NULL;
    return jumlah_akun_pekerja;
}
int funcJumlahAkunPerusahaan(){
    FILE * bukaFilePerusahaan = fopen("akun_perusahaan.txt", "r");
    (bukaFilePerusahaan == NULL) ? exit(0) : NULL;
    //menghitung jumlah akun di file perusahaan
        char cek_jumlah_akun_perusahaan;
        int jumlah_akun_perusahaan = 0;
        while( (cek_jumlah_akun_perusahaan = fgetc(bukaFilePerusahaan)) != EOF ){
            if(cek_jumlah_akun_perusahaan == '\n'){
                jumlah_akun_perusahaan++;
            }
        }
        fclose(bukaFilePerusahaan);
        bukaFilePerusahaan = NULL;
        return jumlah_akun_perusahaan;
}

//struct untuk menampung data
struct structAkunPekerja{
    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];
};

struct structAkunPerusahaan{
    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

void konversi_underscore_ke_spasi(char * kata){
    int i = 0;
    while( *(kata+i)!= '\0' ){
        if( *(kata+i) == '_' ){
            *(kata+i) = ' ';
        }
        i++;
    }

}

void retrieveDataPerusahaan(struct structAkunPerusahaan * akunPerusahaan, int * current_position_fiePerusahaan){

    FILE * bukaFilePerusahaan = fopen("akun_perusahaan.txt", "r");
    (bukaFilePerusahaan == NULL) ? exit(0) : NULL;

    fseek(bukaFilePerusahaan, *current_position_fiePerusahaan, SEEK_CUR);

    fscanf(bukaFilePerusahaan, "%s %s %s %s %s %s"
           , akunPerusahaan->username, akunPerusahaan->password
           , akunPerusahaan->namaPerusahaan, akunPerusahaan->kategoriPerusahaan
           , akunPerusahaan->alamatPerusahaan, akunPerusahaan->fasilitasPerusahaan);

    *current_position_fiePerusahaan = ftell(bukaFilePerusahaan);

    konversi_underscore_ke_spasi(akunPerusahaan->namaPerusahaan);
    konversi_underscore_ke_spasi(akunPerusahaan->kategoriPerusahaan);
    konversi_underscore_ke_spasi(akunPerusahaan->alamatPerusahaan);
    konversi_underscore_ke_spasi(akunPerusahaan->fasilitasPerusahaan);

    fclose(bukaFilePerusahaan);
    bukaFilePerusahaan = NULL;
}

void retrieveDataPekerja(struct structAkunPekerja * akunPekerja, int * current_position_filePekerja){

    FILE * bukaFilePekerja = fopen("akun_pencarikerja.txt", "r");
    (bukaFilePekerja == NULL) ? exit(0) : NULL;

    fseek(bukaFilePekerja, *current_position_filePekerja, SEEK_CUR);

    fscanf(bukaFilePekerja, "%s %s %s %s %s %s %s %s %s %s %s %s"
           , akunPekerja->username, akunPekerja->password, akunPekerja->nama, akunPekerja->tanggal_lahir, akunPekerja->kewarganegaraan
           , akunPekerja->nomor_telepon, akunPekerja->pref_gaji
           , akunPekerja->sd, akunPekerja->smp, akunPekerja->sma, akunPekerja->sarjana, akunPekerja->pengalaman_kerja);

    *current_position_filePekerja = ftell(bukaFilePekerja);

    konversi_underscore_ke_spasi(akunPekerja->nama);
    konversi_underscore_ke_spasi(akunPekerja->kewarganegaraan);
    konversi_underscore_ke_spasi(akunPekerja->sd);
    konversi_underscore_ke_spasi(akunPekerja->smp);
    konversi_underscore_ke_spasi(akunPekerja->sma);
    konversi_underscore_ke_spasi(akunPekerja->sarjana);
    konversi_underscore_ke_spasi(akunPekerja->pengalaman_kerja);

    fclose(bukaFilePekerja);
    bukaFilePekerja = NULL;
}

void prosesLogin(char * username, char * password){

    int current_position_filePekerja = 0;
    int current_position_fiePerusahaan = 0;
    int i;

    //buka file
    FILE * bukaFilePekerja = fopen("akun_pencarikerja.txt", "r");
    FILE * bukaFilePerusahaan = fopen("akun_perusahaan.txt", "r");

    if( (bukaFilePekerja == NULL) && (bukaFilePerusahaan == NULL) ){
        printf("Error file");
        exit(0);
    }else{
        int jumlah_akun = funcJumlahAkunPekerja() + funcJumlahAkunPerusahaan();
        struct structAkunPekerja akunPekerja;
        struct structAkunPerusahaan akunPerusahaan;

        for(i = 0; i<jumlah_akun; i++){
            if(i < funcJumlahAkunPekerja()){
                retrieveDataPekerja(&akunPekerja, &current_position_filePekerja);
                if( strcmp(username, akunPekerja.username) == 0 ){
                    if( strcmp(password, akunPekerja.password) == 0 ){
                        printf("\nBerhasil masuk");
                        system("cls");
                        main_menu_pekerja(&akunPekerja);
                        break;
                    }else{
                        printf("Password anda salah");
                        exit(0);
                        break;
                    }
                }
            }else if(i < funcJumlahAkunPekerja() + funcJumlahAkunPerusahaan()){
                retrieveDataPerusahaan(&akunPerusahaan, &current_position_fiePerusahaan);
                if( strcmp(username, akunPerusahaan.username) == 0 ){
                    if( strcmp(password, akunPerusahaan.password) == 0 ){
                        printf("\nBerhasil masuk");
                        system("cls");
                        main_menu_perusahaan(&akunPerusahaan);
                        break;
                    }else{
                        printf("Password anda salah");
                        exit(0);
                        break;
                    }
                }
            }
        }
        if(i == jumlah_akun){
            printf("\nAkun anda tidak terdaftar, silahkan mendaftar terlebih dahulu");
            exit(0);
        }

    }
}

void login_form(){

    char username[100];
    char password[100];

    getchar();
    printf("==Login==\n");
    printf("Username : ");
    gets(username);
    printf("Password : ");
    gets(password);
    prosesLogin(username, password);

}

