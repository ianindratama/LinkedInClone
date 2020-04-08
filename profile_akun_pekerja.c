#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_pekerja.h"

struct structAkunPekerja{
    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];
};

void inputUpdatedDataToStructSemuaPekerja(struct structAkunPekerja * akunPekerja, struct structAkunPekerja * semuaAkunPekerja);
void inputUpdatedDataToFile(struct structAkunPekerja * semuaAkunPekerja);

int funcJumlahAkunPekerjaProfile(){
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

void konversi_spasi_ke_underscore_profile(char * kata){
    int i = 0;
    while( *(kata+i)!= '\0' ){
        if( *(kata+i) == ' ' ){
            *(kata+i) = '_';
        }
        i++;
    }

}

void retrieveSemuaDataPekerjaDiFile(struct structAkunPekerja * semuaAkunPekerja){

    FILE * bukaFilePekerja = fopen("akun_pencarikerja.txt", "r");
    (bukaFilePekerja == NULL) ? exit(0) : NULL;

    for(int i = 0; i<funcJumlahAkunPekerjaProfile(); i++){
        fscanf(bukaFilePekerja, "%s %s %s %s %s %s %s %s %s %s %s %s"
           , (semuaAkunPekerja+i)->username, (semuaAkunPekerja+i)->password
           , (semuaAkunPekerja+i)->nama, (semuaAkunPekerja+i)->tanggal_lahir, (semuaAkunPekerja+i)->kewarganegaraan
           , (semuaAkunPekerja+i)->nomor_telepon, (semuaAkunPekerja+i)->pref_gaji
           , (semuaAkunPekerja+i)->sd, (semuaAkunPekerja+i)->smp, (semuaAkunPekerja+i)->sma, (semuaAkunPekerja+i)->sarjana
           , (semuaAkunPekerja+i)->pengalaman_kerja);
    }

    fclose(bukaFilePekerja);
    bukaFilePekerja = NULL;
}

void gantiProfilePekerja(struct structAkunPekerja * akunPekerja, struct structAkunPekerja * semuaAkunPekerja){

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
    konversi_spasi_ke_underscore_profile(akunPekerja->nama);
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
    konversi_spasi_ke_underscore_profile(akunPekerja->kewarganegaraan);
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
    konversi_spasi_ke_underscore_profile(akunPekerja->sd);
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
    konversi_spasi_ke_underscore_profile(akunPekerja->smp);
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
    konversi_spasi_ke_underscore_profile(akunPekerja->sma);
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
    konversi_spasi_ke_underscore_profile(akunPekerja->sarjana);
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
    }
    konversi_spasi_ke_underscore_profile(akunPekerja->pengalaman_kerja);

    inputUpdatedDataToStructSemuaPekerja(akunPekerja, semuaAkunPekerja);

}

void inputUpdatedDataToStructSemuaPekerja(struct structAkunPekerja * akunPekerja, struct structAkunPekerja * semuaAkunPekerja){

    int jumlahAkun = funcJumlahAkunPekerjaProfile();
    int cek, i;

    for( i = 0; i < jumlahAkun; i++){
        if( strcmp( akunPekerja->username, (semuaAkunPekerja+i)->username ) == 0 ){
            cek = 1;
            strcpy( (semuaAkunPekerja+i)->nama, akunPekerja->nama);
            strcpy( (semuaAkunPekerja+i)->tanggal_lahir, akunPekerja->tanggal_lahir);
            strcpy( (semuaAkunPekerja+i)->kewarganegaraan, akunPekerja->kewarganegaraan);
            strcpy( (semuaAkunPekerja+i)->nomor_telepon, akunPekerja->nomor_telepon);
            strcpy( (semuaAkunPekerja+i)->pref_gaji, akunPekerja->pref_gaji);
            strcpy( (semuaAkunPekerja+i)->sd, akunPekerja->sd);
            strcpy( (semuaAkunPekerja+i)->smp, akunPekerja->smp);
            strcpy( (semuaAkunPekerja+i)->sma, akunPekerja->sma);
            strcpy( (semuaAkunPekerja+i)->sarjana, akunPekerja->sarjana);
            strcpy( (semuaAkunPekerja+i)->pengalaman_kerja, akunPekerja->pengalaman_kerja);
            break;
        }else{
            cek = 1;
        }
    }

    if( (i == jumlahAkun) && (cek == 1) ){
        printf("Error Terjadi\n");
        exit(0);
    }

    inputUpdatedDataToFile(semuaAkunPekerja);

}

void inputUpdatedDataToFile(struct structAkunPekerja * semuaAkunPekerja){

    int print_sekali = 0;
    int jumlahAkun = funcJumlahAkunPekerjaProfile();
    FILE * bukaFilePekerja = fopen("akun_pencarikerja.txt", "w+");
    (bukaFilePekerja == NULL) ? exit(0) : NULL;

    for(int i = 0; i < jumlahAkun; i++){

        if((fprintf(bukaFilePekerja, "%s %s %s %s %s %s %s %s %s %s %s %s",
        (semuaAkunPekerja+i)->username, (semuaAkunPekerja+i)->password, (semuaAkunPekerja+i)->nama,
        (semuaAkunPekerja+i)->nomor_telepon, (semuaAkunPekerja+i)->tanggal_lahir, (semuaAkunPekerja+i)->kewarganegaraan
        , (semuaAkunPekerja+i)->pref_gaji, (semuaAkunPekerja+i)->sd, (semuaAkunPekerja+i)->smp, (semuaAkunPekerja+i)->sma
        , (semuaAkunPekerja+i)->sarjana, (semuaAkunPekerja+i)->pengalaman_kerja)) < 0){
            printf("gagal mengupdate profile akun");
            exit(0);
        }else{
            fputc('\n', bukaFilePekerja);
            if(print_sekali != 1){
                printf("Berhasil mengupdate profile akun");
                print_sekali += 1;
            }
        }
    }

    fclose(bukaFilePekerja);
    bukaFilePekerja = NULL;

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
    fflush(stdin);

    if(menu_profile_akun_pekerja == 1){

        struct structAkunPekerja semuaAkunPekerja[funcJumlahAkunPekerjaProfile()];

        retrieveSemuaDataPekerjaDiFile(&semuaAkunPekerja);

        gantiProfilePekerja(akunPekerja, &semuaAkunPekerja);

    }else if(menu_profile_akun_pekerja == 2){

    }else if(menu_profile_akun_pekerja == 3){
        system("cls");
        main_menu_pekerja(&akunPekerja);
    }
}
