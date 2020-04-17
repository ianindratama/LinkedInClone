#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_perusahaan.h"
#include "main.h"

struct structPekerjaPerusahaan{

    char username_pekerja[50]; char username_perusahaan[50];

    char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];

    char namaPerusahaan[50]; char nama_pekerjaan[50];

    char status[50]; char pesan[50];
};

struct structAkunPerusahaan{
    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

struct structLowonganKerja{
    char username[50]; char nama_pekerjaan[50]; char deskripsi_pekerjaan[50]; char gaji_pekerjaan[50]; char jenis_pekerjaan[50];
};

void menu_list_kerja(struct structAkunPerusahaan * akunPerusahaan);
void daftar_pelamar_kerja(struct structAkunPerusahaan * akunPerusahaan);

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

int funcJumlahPelamarKerja(){
    FILE * bukaFile = fopen("list_kerja_apply.txt", "a+");
    (bukaFile == NULL) ? exit(0) : NULL;
    //menghitung jumlah lowongan kerja yang di applied user
        char cek_jumlah_pelamar_kerja_applied;
        int jumlah_pelamar_kerja_applied = 0;
        while( (cek_jumlah_pelamar_kerja_applied = fgetc(bukaFile)) != EOF ){
            if(cek_jumlah_pelamar_kerja_applied == '\n'){
                jumlah_pelamar_kerja_applied++;
            }
        }
        fclose(bukaFile);
        bukaFile = NULL;
    return jumlah_pelamar_kerja_applied;
}

void retrieveDataPekerjaanAppliedKePerusahaan(struct structPekerjaPerusahaan * semuaPekerjaanAppliedKePerusahaan){

    FILE * bukaFile = fopen("list_kerja_apply.txt", "a+");
    (bukaFile == NULL) ? exit(0) : NULL;

    for(int i = 0; i<funcJumlahPelamarKerja(); i++){
        if( fscanf(bukaFile, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                   (semuaPekerjaanAppliedKePerusahaan+i)->username_pekerja,
                   (semuaPekerjaanAppliedKePerusahaan+i)->username_perusahaan,
                   (semuaPekerjaanAppliedKePerusahaan+i)->nama,
                   (semuaPekerjaanAppliedKePerusahaan+i)->tanggal_lahir,
                   (semuaPekerjaanAppliedKePerusahaan+i)->kewarganegaraan,
                   (semuaPekerjaanAppliedKePerusahaan+i)->nomor_telepon,
                   (semuaPekerjaanAppliedKePerusahaan+i)->pref_gaji,
                   (semuaPekerjaanAppliedKePerusahaan+i)->sd,
                   (semuaPekerjaanAppliedKePerusahaan+i)->smp,
                   (semuaPekerjaanAppliedKePerusahaan+i)->sma,
                   (semuaPekerjaanAppliedKePerusahaan+i)->sarjana,
                   (semuaPekerjaanAppliedKePerusahaan+i)->pengalaman_kerja,
                   (semuaPekerjaanAppliedKePerusahaan+i)->namaPerusahaan,
                   (semuaPekerjaanAppliedKePerusahaan+i)->nama_pekerjaan,
                   (semuaPekerjaanAppliedKePerusahaan+i)->status,
                   (semuaPekerjaanAppliedKePerusahaan+i)->pesan
                   ) < 0 ){
            printf("\nError terjadi");
            exit(0);
        }
    }

    fclose(bukaFile);
    bukaFile = NULL;

}

void daftar_pelamar_kerja_yang_telah_diterima(struct structAkunPerusahaan * akunPerusahaan){

    int jumlah_pekerjaan_yang_diterima_perusahaan = 0;
    int cek = 0; int x = -1;
    int jumlah_list_kerja_applied = funcJumlahPelamarKerja();

    //retrive data
    struct structPekerjaPerusahaan semuaPekerjaanAppliedKePerusahaan[jumlah_list_kerja_applied];
    retrieveDataPekerjaanAppliedKePerusahaan(&semuaPekerjaanAppliedKePerusahaan);

    //sortir data
    struct structPekerjaPerusahaan pekerjaanDiterima[jumlah_list_kerja_applied];

    for(int i = 0; i<jumlah_list_kerja_applied; i++){
        if( (strcmp(akunPerusahaan->username, semuaPekerjaanAppliedKePerusahaan[i].username_perusahaan)) == 0 ){
            if( (strcmp(semuaPekerjaanAppliedKePerusahaan[i].status, "diterima")) == 0 ){
                cek = 1;
                jumlah_pekerjaan_yang_diterima_perusahaan += 1; x+=1;

                strcpy(pekerjaanDiterima[x].username_pekerja, semuaPekerjaanAppliedKePerusahaan[i].username_pekerja);
                strcpy(pekerjaanDiterima[x].username_perusahaan, semuaPekerjaanAppliedKePerusahaan[i].username_perusahaan);
                strcpy(pekerjaanDiterima[x].nama, semuaPekerjaanAppliedKePerusahaan[i].nama);
                strcpy(pekerjaanDiterima[x].tanggal_lahir, semuaPekerjaanAppliedKePerusahaan[i].tanggal_lahir);
                strcpy(pekerjaanDiterima[x].kewarganegaraan, semuaPekerjaanAppliedKePerusahaan[i].kewarganegaraan);
                strcpy(pekerjaanDiterima[x].nomor_telepon, semuaPekerjaanAppliedKePerusahaan[i].nomor_telepon);
                strcpy(pekerjaanDiterima[x].pref_gaji, semuaPekerjaanAppliedKePerusahaan[i].pref_gaji);
                strcpy(pekerjaanDiterima[x].sd , semuaPekerjaanAppliedKePerusahaan[i].sd);
                strcpy(pekerjaanDiterima[x].smp , semuaPekerjaanAppliedKePerusahaan[i].smp);
                strcpy(pekerjaanDiterima[x].sma , semuaPekerjaanAppliedKePerusahaan[i].sma);
                strcpy(pekerjaanDiterima[x].sarjana , semuaPekerjaanAppliedKePerusahaan[i].sarjana);
                strcpy(pekerjaanDiterima[x].pengalaman_kerja , semuaPekerjaanAppliedKePerusahaan[i].pengalaman_kerja);
                strcpy(pekerjaanDiterima[x].namaPerusahaan , semuaPekerjaanAppliedKePerusahaan[i].namaPerusahaan);
                strcpy(pekerjaanDiterima[x].nama_pekerjaan , semuaPekerjaanAppliedKePerusahaan[i].nama_pekerjaan);
                strcpy(pekerjaanDiterima[x].status , semuaPekerjaanAppliedKePerusahaan[i].status);
                strcpy(pekerjaanDiterima[x].pesan , semuaPekerjaanAppliedKePerusahaan[i].pesan);
            }
        }
    }

    if(cek == 1){
        printf("\n\t\t\t==Daftar Pelamar Kerja yang Diterima==\n\n");
        printf(" No Nama Pelamar\t\t\t\tNama Pekerjaan\t\tStatus\t\tPesan\n");
        for(int i = 0; i<jumlah_pekerjaan_yang_diterima_perusahaan; i++){

            konversi_underscore_ke_spasi_ListKerja(pekerjaanDiterima[i].nama);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanDiterima[i].nama_pekerjaan);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanDiterima[i].status);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanDiterima[i].pesan);

            printf("%2d  %-40s\t%-20s\t%-8s\t%s\n", i+1, pekerjaanDiterima[i].nama, pekerjaanDiterima[i].nama_pekerjaan,
                                            pekerjaanDiterima[i].status, pekerjaanDiterima[i].pesan);
        }
    }else{
        printf("\nMaaf Anda belum pernah ACC Pekerjaan\n");
    }

    int menu_setelah_lihat_daftar;
    printf("\n1. Kembali ke menu utama \t 2. Logout\n");
    scanf("%d", &menu_setelah_lihat_daftar);
    getchar();
    system("cls");
    if(menu_setelah_lihat_daftar == 1){
        main_menu_perusahaan(akunPerusahaan);
    }else{
        main();
    }

}

void accPelamarKerja(int * pelamar_kerja_id, struct structPekerjaPerusahaan * semuaPekerjaanAppliedKePerusahaan, struct structAkunPerusahaan * akunPerusahaan ){

    int jumlah_pelamar_kerja = funcJumlahPelamarKerja();

    FILE * bukaFile = fopen("list_kerja_apply.txt", "w+");
    (bukaFile == NULL) ? exit(0) : NULL;

    char pesan[50];
    int cek = 0;

    konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->nama);
    strcpy( (semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->status, "diterima");
    printf("Masukkan Pesan yang ingin disampaikan ke %s : ", (semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->nama);
    konversi_spasi_ke_underscore_ListKerja((semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->nama);
    gets(pesan);
    konversi_spasi_ke_underscore_ListKerja(pesan);
    strcpy( (semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->pesan, pesan );

    for(int i = 0; i<jumlah_pelamar_kerja; i++){
        if( fprintf(bukaFile, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                    (semuaPekerjaanAppliedKePerusahaan+i)->username_pekerja,
                    (semuaPekerjaanAppliedKePerusahaan+i)->username_perusahaan,
                    (semuaPekerjaanAppliedKePerusahaan+i)->nama,
                    (semuaPekerjaanAppliedKePerusahaan+i)->tanggal_lahir,
                    (semuaPekerjaanAppliedKePerusahaan+i)->kewarganegaraan,
                    (semuaPekerjaanAppliedKePerusahaan+i)->nomor_telepon,
                    (semuaPekerjaanAppliedKePerusahaan+i)->pref_gaji,
                    (semuaPekerjaanAppliedKePerusahaan+i)->sd,
                    (semuaPekerjaanAppliedKePerusahaan+i)->smp,
                    (semuaPekerjaanAppliedKePerusahaan+i)->sma,
                    (semuaPekerjaanAppliedKePerusahaan+i)->sarjana,
                    (semuaPekerjaanAppliedKePerusahaan+i)->pengalaman_kerja,
                    (semuaPekerjaanAppliedKePerusahaan+i)->namaPerusahaan,
                    (semuaPekerjaanAppliedKePerusahaan+i)->nama_pekerjaan,
                    (semuaPekerjaanAppliedKePerusahaan+i)->status,
                    (semuaPekerjaanAppliedKePerusahaan+i)->pesan
                     ) < 0 ){
            printf("\nError terjadi");
            exit(0);
        }else{
            cek = 1;
            fputc('\n', bukaFile);
        }
    }
    fclose(bukaFile);
    bukaFile = NULL;

    if(cek == 1){

        konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->nama);
        konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->nama_pekerjaan);
        konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->namaPerusahaan);

        int pilih_pelamar_lagi;

        printf("\nAnda berhasil menerima %s sebagai %s di %s\n\n", (semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->nama, (semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->nama_pekerjaan, (semuaPekerjaanAppliedKePerusahaan + (*pelamar_kerja_id-1))->namaPerusahaan);
        printf("1. ACC Pelamar Kerja Lagi \t 2. Kembali ke Menu Utama\n");
        scanf("%d", &pilih_pelamar_lagi);
        fflush(stdin);
        if(pilih_pelamar_lagi == 1){
            system("cls");
            daftar_pelamar_kerja(akunPerusahaan);
        }else if(pilih_pelamar_lagi == 2){
            system("cls");
            main_menu_perusahaan(akunPerusahaan);
        }
    }

}

void daftar_pelamar_kerja_berdasarkanNamaPekerjaan( struct structAkunPerusahaan * akunPerusahaan, struct structPekerjaPerusahaan * semuaPekerjaanAppliedKePerusahaan ){

    struct structPekerjaPerusahaan pekerjaanAppliedKePerusahaan[funcJumlahPelamarKerja()];

    char pekerjaan_yang_dicari[50];
    int id_counter[funcJumlahPelamarKerja()];
    int i;int counter = 0; int cek = 0;
    printf("\nMasukkan Nama Pekerjaan yang ingin dicari : ");
    gets(pekerjaan_yang_dicari);
    printf("\n");
    konversi_spasi_ke_underscore_ListKerja(pekerjaan_yang_dicari);

    for(i = 0; i<funcJumlahPelamarKerja(); i++){
        if( strcmp(akunPerusahaan->username, (semuaPekerjaanAppliedKePerusahaan+i)->username_perusahaan) == 0 ){
            if( strcmp( (semuaPekerjaanAppliedKePerusahaan+i)->nama_pekerjaan, pekerjaan_yang_dicari) == 0 ){
                if( strcmp((semuaPekerjaanAppliedKePerusahaan+i)->status, "applied") == 0){
                    counter += 1; cek = 1;
                    id_counter[(counter-1)] = i+1;
                    konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->nama);
                    konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->kewarganegaraan);
                    konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->sd);
                    konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->smp);
                    konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->sma);
                    konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->sarjana);
                    konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->pengalaman_kerja);
                    konversi_underscore_ke_spasi_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->nama_pekerjaan);

                    printf("%3d Nama Pelamar Kerja : %s\n", counter, (semuaPekerjaanAppliedKePerusahaan+i)->nama);
                    printf("    Tanggal Lahir : %s\n", (semuaPekerjaanAppliedKePerusahaan+i)->tanggal_lahir);
                    printf("    Kewarganegaraan : %s\n", (semuaPekerjaanAppliedKePerusahaan+i)->kewarganegaraan);
                    printf("    Nomor Telepon : %s\n", (semuaPekerjaanAppliedKePerusahaan+i)->nomor_telepon);
                    printf("    Preferensi Gaji : %s\n", (semuaPekerjaanAppliedKePerusahaan+i)->pref_gaji);
                    printf("    SD : %s\n", (semuaPekerjaanAppliedKePerusahaan+i)->sd);
                    printf("    SMP : %s\n", (semuaPekerjaanAppliedKePerusahaan+i)->smp);
                    printf("    SMA : %s\n", (semuaPekerjaanAppliedKePerusahaan+i)->sma);
                    printf("    Sarjana : %s\n", (semuaPekerjaanAppliedKePerusahaan+i)->sarjana);
                    printf("    Pengalaman Kerja : %s\n", (semuaPekerjaanAppliedKePerusahaan+i)->pengalaman_kerja);
                    printf("    Pekerjaan yang dilamar : %s\n\n", (semuaPekerjaanAppliedKePerusahaan+i)->nama_pekerjaan);

                    konversi_spasi_ke_underscore_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->nama);
                    konversi_spasi_ke_underscore_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->kewarganegaraan);
                    konversi_spasi_ke_underscore_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->sd);
                    konversi_spasi_ke_underscore_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->smp);
                    konversi_spasi_ke_underscore_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->sma);
                    konversi_spasi_ke_underscore_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->sarjana);
                    konversi_spasi_ke_underscore_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->pengalaman_kerja);
                    konversi_spasi_ke_underscore_ListKerja((semuaPekerjaanAppliedKePerusahaan+i)->nama_pekerjaan);
                }
            }
        }
    }

    if(cek == 0){
        konversi_underscore_ke_spasi_ListKerja(pekerjaan_yang_dicari);
        printf("Maaf tidak ada Pelamar Kerja yang melamar pekerjaan %s\n", pekerjaan_yang_dicari);
        printf("1. Kembali ke menu utama \t 2.Logout\n");
        int menu_setelah;
        scanf("%d", &menu_setelah);
        getchar();
        if(menu_setelah == 1){
            system("cls");
            main_menu_perusahaan(akunPerusahaan);
        }else if(menu_setelah == 2){
            system("cls");
            printf("Berhasil Logout\n");
            main();
        }
    }else if(cek == 1){
        printf("\n1. Jika ingin ACC Pelamar \t 2.Jika ingin Kembali ke menu Utama\n");
        int menu_setelah;
        scanf("%d", &menu_setelah);
        if(menu_setelah == 1){
            int indeks_pelamar_kerja;
            printf("Pilih Pelamar Kerja yang akan di ACC (ex:1) : ");
            scanf("%d", &indeks_pelamar_kerja);
            printf("\n");
            fflush(stdin);
            accPelamarKerja(&id_counter[(indeks_pelamar_kerja-1)], semuaPekerjaanAppliedKePerusahaan, akunPerusahaan);
        }else if(menu_setelah == 2){
            system("cls");
            main_menu_perusahaan(akunPerusahaan);
        }

    }


}

void daftar_pelamar_kerja(struct structAkunPerusahaan * akunPerusahaan){

    int jumlah_pelamar_applied_to_perusahaan = 0;
    int cek = 0; int x = -1;
    int jumlah_pelamar_kerja = funcJumlahPelamarKerja();
    int pelamar_kerja_id[jumlah_pelamar_kerja];

    //retrive data
    struct structPekerjaPerusahaan semuaPekerjaanAppliedKePerusahaan[jumlah_pelamar_kerja];
    retrieveDataPekerjaanAppliedKePerusahaan(&semuaPekerjaanAppliedKePerusahaan);

    //sortir data
    struct structPekerjaPerusahaan pekerjaanAppliedKePerusahaan[jumlah_pelamar_kerja];

    for(int i = 0; i<jumlah_pelamar_kerja; i++){
        if( (strcmp(akunPerusahaan->username, semuaPekerjaanAppliedKePerusahaan[i].username_perusahaan)) == 0 ){
            if( strcmp(semuaPekerjaanAppliedKePerusahaan[i].status, "applied") == 0){
                cek = 1;
                jumlah_pelamar_applied_to_perusahaan += 1; x+=1;
                pelamar_kerja_id[(jumlah_pelamar_applied_to_perusahaan-1)] = i+1;

                strcpy(pekerjaanAppliedKePerusahaan[x].username_pekerja, semuaPekerjaanAppliedKePerusahaan[i].username_pekerja);
                strcpy(pekerjaanAppliedKePerusahaan[x].username_perusahaan, semuaPekerjaanAppliedKePerusahaan[i].username_perusahaan);
                strcpy(pekerjaanAppliedKePerusahaan[x].nama, semuaPekerjaanAppliedKePerusahaan[i].nama);
                strcpy(pekerjaanAppliedKePerusahaan[x].tanggal_lahir, semuaPekerjaanAppliedKePerusahaan[i].tanggal_lahir);
                strcpy(pekerjaanAppliedKePerusahaan[x].kewarganegaraan, semuaPekerjaanAppliedKePerusahaan[i].kewarganegaraan);
                strcpy(pekerjaanAppliedKePerusahaan[x].nomor_telepon, semuaPekerjaanAppliedKePerusahaan[i].nomor_telepon);
                strcpy(pekerjaanAppliedKePerusahaan[x].pref_gaji, semuaPekerjaanAppliedKePerusahaan[i].pref_gaji);
                strcpy(pekerjaanAppliedKePerusahaan[x].sd , semuaPekerjaanAppliedKePerusahaan[i].sd);
                strcpy(pekerjaanAppliedKePerusahaan[x].smp , semuaPekerjaanAppliedKePerusahaan[i].smp);
                strcpy(pekerjaanAppliedKePerusahaan[x].sma , semuaPekerjaanAppliedKePerusahaan[i].sma);
                strcpy(pekerjaanAppliedKePerusahaan[x].sarjana , semuaPekerjaanAppliedKePerusahaan[i].sarjana);
                strcpy(pekerjaanAppliedKePerusahaan[x].pengalaman_kerja , semuaPekerjaanAppliedKePerusahaan[i].pengalaman_kerja);
                strcpy(pekerjaanAppliedKePerusahaan[x].namaPerusahaan , semuaPekerjaanAppliedKePerusahaan[i].namaPerusahaan);
                strcpy(pekerjaanAppliedKePerusahaan[x].nama_pekerjaan , semuaPekerjaanAppliedKePerusahaan[i].nama_pekerjaan);
                strcpy(pekerjaanAppliedKePerusahaan[x].status , semuaPekerjaanAppliedKePerusahaan[i].status);
                strcpy(pekerjaanAppliedKePerusahaan[x].pesan , semuaPekerjaanAppliedKePerusahaan[i].pesan);
            }
        }
    }

    if(cek == 1){
        printf("\n\t\t\t==Pelamar Kerja Ke Perusahaan==\n\n");
        for(int i = 0; i<jumlah_pelamar_applied_to_perusahaan; i++){
            konversi_underscore_ke_spasi_ListKerja(pekerjaanAppliedKePerusahaan[i].nama);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanAppliedKePerusahaan[i].kewarganegaraan);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanAppliedKePerusahaan[i].sd);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanAppliedKePerusahaan[i].smp);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanAppliedKePerusahaan[i].sma);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanAppliedKePerusahaan[i].sarjana);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanAppliedKePerusahaan[i].pengalaman_kerja);
            konversi_underscore_ke_spasi_ListKerja(pekerjaanAppliedKePerusahaan[i].nama_pekerjaan);

            printf("%3d Nama Pelamar Kerja : %s\n", i+1, pekerjaanAppliedKePerusahaan[i].nama);
            printf("    Tanggal Lahir : %s\n", pekerjaanAppliedKePerusahaan[i].tanggal_lahir);
            printf("    Kewarganegaraan : %s\n", pekerjaanAppliedKePerusahaan[i].kewarganegaraan);
            printf("    Nomor Telepon : %s\n", pekerjaanAppliedKePerusahaan[i].nomor_telepon);
            printf("    Preferensi Gaji : %s\n", pekerjaanAppliedKePerusahaan[i].pref_gaji);
            printf("    SD : %s\n", pekerjaanAppliedKePerusahaan[i].sd);
            printf("    SMP : %s\n", pekerjaanAppliedKePerusahaan[i].smp);
            printf("    SMA : %s\n", pekerjaanAppliedKePerusahaan[i].sma);
            printf("    Sarjana : %s\n", pekerjaanAppliedKePerusahaan[i].sarjana);
            printf("    Pengalaman Kerja : %s\n", pekerjaanAppliedKePerusahaan[i].pengalaman_kerja);
            printf("    Pekerjaan yang dilamar : %s\n\n", pekerjaanAppliedKePerusahaan[i].nama_pekerjaan);

        }

        int menu_setelah_lihat_daftar;
        printf("\n\nJika ingin ACC Lamaran Kerja, ketik \" 1 \"\n");
        printf("Cari Pelamar kerja berdasarkan Nama Pekerjaan yang dilamar, ketik \" 2 \"\n");
        printf("Kembali ke menu utama, ketik \" 3 \"\n");
        scanf("%d", &menu_setelah_lihat_daftar);
        getchar();
        if(menu_setelah_lihat_daftar == 1){
            int indeks_pelamar_kerja;
            printf("Pilih Pelamar Kerja yang akan di ACC (ex:1) : ");
            scanf("%d", &indeks_pelamar_kerja);
            printf("\n");
            fflush(stdin);
            accPelamarKerja(&pelamar_kerja_id[(indeks_pelamar_kerja-1)], &semuaPekerjaanAppliedKePerusahaan, akunPerusahaan);
        }else if(menu_setelah_lihat_daftar == 2){
            daftar_pelamar_kerja_berdasarkanNamaPekerjaan(akunPerusahaan, &semuaPekerjaanAppliedKePerusahaan);
        }else if(menu_setelah_lihat_daftar == 3){
            system("cls");
            main_menu_perusahaan(akunPerusahaan);
        }

    }else{
        printf("\nMaaf belum ada Pelamar Kerja ke Perusahaan\n");
        printf("\n1. Kembali ke menu utama \t 2.Logout\n");
        int menu_setelah;
        scanf("%d", &menu_setelah);
        getchar();
        if(menu_setelah == 1){
            system("cls");
            main_menu_perusahaan(akunPerusahaan);
        }else if(menu_setelah == 2){
            system("cls");
            printf("Berhasil Logout\n");
            main();
        }
    }

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
        printf("Nama Pekerjaan\t\tDeskripsi Pekerjaan\t\t\t\tGaji Pekerjaan\t\tJenis Pekerjaan\n");

        for(int i = 0; i<jumlah_list_kerja_perusahaan; i++){
            if( strcmp(akunPerusahaan->username, semuaListKerja[i].username ) == 0 ){

                counter += 1;

                konversi_underscore_ke_spasi_ListKerja(semuaListKerja[i].nama_pekerjaan);
                konversi_underscore_ke_spasi_ListKerja(semuaListKerja[i].deskripsi_pekerjaan);
                konversi_underscore_ke_spasi_ListKerja(semuaListKerja[i].gaji_pekerjaan);
                konversi_underscore_ke_spasi_ListKerja(semuaListKerja[i].jenis_pekerjaan);

                printf("%d.%-20s\t", counter, semuaListKerja[i].nama_pekerjaan);
                printf("%-50s", semuaListKerja[i].deskripsi_pekerjaan);
                printf("%s\t\t", semuaListKerja[i].gaji_pekerjaan);
                printf(" %s\t", semuaListKerja[i].jenis_pekerjaan);
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
