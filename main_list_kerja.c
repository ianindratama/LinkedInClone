#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_perusahaan.h"

struct structAkunPerusahaan{
    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

struct structLowonganKerja{
    char username[50]; char nama_pekerjaan[50]; char deskripsi_pekerjaan[50]; char gaji_pekerjaan[50]; char jenis_pekerjaan[50];
};

void menu_list_kerja(struct structAkunPerusahaan * akunPerusahaan);

void konversi_spasi_ke_underscore_ListKerja(char * kata){
    int i = 0;
    while( *(kata+i)!= '\0' ){
        if( *(kata+i) == ' ' ){
            *(kata+i) = '_';
        }
        i++;
    }

}

void konversi_underscore_ke_spasi_ListKerja(char * kata){
    int i = 0;
    while( *(kata+i)!= '\0' ){
        if( *(kata+i) == '_' ){
            *(kata+i) = ' ';
        }
        i++;
    }

}

int funcJumlahListKerja(){
    FILE * bukaFileListKerja = fopen("list_kerja.txt", "a+");
    (bukaFileListKerja == NULL) ? exit(0) : NULL;
    //menghitung jumlah lowongan kerja di file
        char cek_jumlah_list_kerja;
        int jumlah_list_kerja = 0;
        while( (cek_jumlah_list_kerja = fgetc(bukaFileListKerja)) != EOF ){
            if(cek_jumlah_list_kerja == '\n'){
                jumlah_list_kerja++;
            }
        }
        fclose(bukaFileListKerja);
        bukaFileListKerja = NULL;
    return jumlah_list_kerja;
}

void retrieveSemuaListKerjaDiFile(struct structLowonganKerja * semuaListKerja){

    FILE * bukaFileListKerja = fopen("list_kerja.txt", "r");
    (bukaFileListKerja == NULL) ? exit(0) : NULL;

    for(int i = 0; i<funcJumlahListKerja(); i++){
        fscanf(bukaFileListKerja, "%s %s %s %s %s"
           , (semuaListKerja+i)->username, (semuaListKerja+i)->nama_pekerjaan
           , (semuaListKerja+i)->deskripsi_pekerjaan, (semuaListKerja+i)->gaji_pekerjaan, (semuaListKerja+i)->jenis_pekerjaan);
    }

    fclose(bukaFileListKerja);
    bukaFileListKerja = NULL;
}

void input_tambah_lowongan_pekerjaan(struct structAkunPerusahaan * akunPerusahaan, struct structLowonganKerja * lowonganKerjaBaru){

    FILE * bukaFileListKerja = fopen("list_kerja.txt", "a+");
    (bukaFileListKerja == NULL) ? exit(0) : NULL;

    if((fprintf(bukaFileListKerja, "%s %s %s %s %s",
        lowonganKerjaBaru->username, lowonganKerjaBaru->nama_pekerjaan,
        lowonganKerjaBaru->deskripsi_pekerjaan, lowonganKerjaBaru->gaji_pekerjaan, lowonganKerjaBaru->jenis_pekerjaan)) < 0){
        printf("Ada kesalahan menulis data");
        exit(0);
    }else{
        fputc('\n', bukaFileListKerja);
        fclose(bukaFileListKerja);
        bukaFileListKerja = NULL;
        system("cls");
        printf("Berhasil menambahkan lowongan kerja\n\n");
        menu_list_kerja(akunPerusahaan);
    }

}

void tambah_lowongan_pekerjaan(struct structAkunPerusahaan * akunPerusahaan){

    struct structLowonganKerja lowonganKerjaBaru;

    printf("\n==Tambah Lowongan Pekerjaan==\n");

    //username perusahaan
    strcpy(lowonganKerjaBaru.username, akunPerusahaan->username);

    printf("Nama Pekerjaan : ");
    gets(lowonganKerjaBaru.nama_pekerjaan);
    konversi_spasi_ke_underscore_ListKerja(lowonganKerjaBaru.nama_pekerjaan);

    printf("Deskripsi Pekerjaan : ");
    gets(lowonganKerjaBaru.deskripsi_pekerjaan);
    konversi_spasi_ke_underscore_ListKerja(lowonganKerjaBaru.deskripsi_pekerjaan);

    printf("Gaji Pekerjaan : ");
    gets(lowonganKerjaBaru.gaji_pekerjaan);
    konversi_spasi_ke_underscore_ListKerja(lowonganKerjaBaru.gaji_pekerjaan);

    printf("Jenis Pekerjaan (penuh / paruh waktu) : ");
    gets(lowonganKerjaBaru.jenis_pekerjaan);
    konversi_spasi_ke_underscore_ListKerja(lowonganKerjaBaru.jenis_pekerjaan);

    input_tambah_lowongan_pekerjaan(akunPerusahaan, &lowonganKerjaBaru);

}

void menu_list_kerja(struct structAkunPerusahaan * akunPerusahaan){

    struct structLowonganKerja semuaListKerja[funcJumlahListKerja()];

    retrieveSemuaListKerjaDiFile(&semuaListKerja);

    int jumlah_list_kerja_perusahaan = funcJumlahListKerja();

    if(jumlah_list_kerja_perusahaan == 0){
        printf("\n\nPerusahaan Anda belum Pernah mengiklankan Lowongan Pekerjaan\n\n");
    }else{

        int counter = 0;

        printf("\n\nList Lowongan Pekerjaan Perusahaan\n\n");
        printf("Nama Pekerjaan\t\tDeskripsi Pekerjaan\t\tGaji Pekerjaan\t\tJenis Pekerjaan\n");

        for(int i = 0; i<jumlah_list_kerja_perusahaan; i++){
            if( strcmp(akunPerusahaan->username, semuaListKerja[i].username ) == 0 ){

                counter += 1;

                konversi_underscore_ke_spasi_ListKerja(semuaListKerja[i].nama_pekerjaan);
                konversi_underscore_ke_spasi_ListKerja(semuaListKerja[i].deskripsi_pekerjaan);
                konversi_underscore_ke_spasi_ListKerja(semuaListKerja[i].gaji_pekerjaan);
                konversi_underscore_ke_spasi_ListKerja(semuaListKerja[i].jenis_pekerjaan);

                printf("%d.%s\t\t", counter, semuaListKerja[i].nama_pekerjaan);
                printf("%s\t\t", semuaListKerja[i].deskripsi_pekerjaan);
                printf("%s\t\t", semuaListKerja[i].gaji_pekerjaan);
                printf("%s\t", semuaListKerja[i].jenis_pekerjaan);
                printf("\n");
            }
        }
    }

    int pilihan_tambah_lowongan_pekerjaan;
    printf("\n\n1. Tambah Lowongan Pekerjaan \t 2. Kembali ke Menu Perusahaan \t 3. Logout\n");
    scanf("%d", &pilihan_tambah_lowongan_pekerjaan);
    fflush(stdin);

    if(pilihan_tambah_lowongan_pekerjaan == 1){
        tambah_lowongan_pekerjaan(akunPerusahaan);
    }else if(pilihan_tambah_lowongan_pekerjaan == 2){
        system("cls");
        main_menu_perusahaan(akunPerusahaan);
    }else if(pilihan_tambah_lowongan_pekerjaan == 3){
        system("cls");
        printf("Anda Berhasil Logout\n");
        main();
    }


}
