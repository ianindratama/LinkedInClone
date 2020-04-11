#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_perusahaan.h"
#include "main.h"

struct structAkunPerusahaan{
    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

void konversi_spasi_ke_underscore_profile_perusahaan(char * kata){
    int i = 0;
    while( *(kata+i)!= '\0' ){
        if( *(kata+i) == ' ' ){
            *(kata+i) = '_';
        }
        i++;
    }

}

void konversi_underscore_ke_spasi_profile_perusahaan(char * kata){
    int i = 0;
    while( *(kata+i)!= '\0' ){
        if( *(kata+i) == '_' ){
            *(kata+i) = ' ';
        }
        i++;
    }

}

int funcJumlahAkunPerusahaanProfile(){
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

void retrieveSemuaDataPerusahaanDiFile(struct structAkunPerusahaan * semuaAkunPerusahaan){

    FILE * bukaFilePerusahaan = fopen("akun_perusahaan.txt", "r");
    (bukaFilePerusahaan == NULL) ? exit(0) : NULL;

    for(int i = 0; i<funcJumlahAkunPerusahaanProfile(); i++){
        fscanf(bukaFilePerusahaan, "%s %s %s %s %s %s"
            , (semuaAkunPerusahaan+i)->username
            , (semuaAkunPerusahaan+i)->password
            , (semuaAkunPerusahaan+i)->namaPerusahaan
            , (semuaAkunPerusahaan+i)->kategoriPerusahaan
            , (semuaAkunPerusahaan+i)->alamatPerusahaan
            , (semuaAkunPerusahaan+i)->fasilitasPerusahaan
        );
    }

    fclose(bukaFilePerusahaan);
    bukaFilePerusahaan = NULL;
}

void inputUpdatedPasswordPerusahaanToFile(struct structAkunPerusahaan * semuaAkunPerusahaan){

    int print_sekali = 0;
    int jumlahAkun = funcJumlahAkunPerusahaanProfile();
    FILE * bukaFilePerusahaan = fopen("akun_perusahaan.txt", "w+");
    (bukaFilePerusahaan == NULL) ? exit(0) : NULL;

    for(int i = 0; i < jumlahAkun; i++){

        if((fprintf(bukaFilePerusahaan, "%s %s %s %s %s %s",
            (semuaAkunPerusahaan+i)->username,
            (semuaAkunPerusahaan+i)->password,
            (semuaAkunPerusahaan+i)->namaPerusahaan,
            (semuaAkunPerusahaan+i)->kategoriPerusahaan,
            (semuaAkunPerusahaan+i)->alamatPerusahaan,
            (semuaAkunPerusahaan+i)->fasilitasPerusahaan)) < 0){
            printf("gagal mengupdate profile akun");
            exit(0);
        }else{
            fputc('\n', bukaFilePerusahaan);
            if(print_sekali != 1){
                printf("Berhasil mengupdate Password akun Anda");
                print_sekali += 1;
            }
        }
    }

    fclose(bukaFilePerusahaan);
    bukaFilePerusahaan = NULL;

    system("cls");
    printf("\nSilahkan Login kembali menggunakan Password baru Anda\n");
    main();

}

void func_ubah_password_perusahaan(struct structAkunPerusahaan * akunPerusahaan, struct structAkunPerusahaan * semuaAkunPerusahaan){

    int jumlahAkun = funcJumlahAkunPerusahaanProfile();
    int i;

    char current_password[50];
    char new_password[50];
    password_menu:
    printf("Masukkan Password anda saat ini : ");
    gets(current_password);

    if( (strcmp( current_password, akunPerusahaan->password )) == 0 ){
        password_menu_1:
        printf("Masukkan Password Baru Anda : ");
        gets(new_password);
        if( (strcmp(new_password, current_password)) != 0 ){
            strcpy(akunPerusahaan->password, new_password);
        }else{
            printf("Password baru yang anda masukkan sama dengan password lama Anda, Silahkan gunakan password Lain\n");
            goto password_menu_1;
        }
    }else{
        printf("Password yang anda masukkan salah,Silahkan masukkan kembali password Anda saat ini\n");
        goto password_menu;
    }

    for( i = 0; i < jumlahAkun; i++){
        if( strcmp( akunPerusahaan->username, (semuaAkunPerusahaan+i)->username ) == 0 ){
            strcpy( (semuaAkunPerusahaan+i)->password, akunPerusahaan->password);
            break;
        }
    }

    if( i == jumlahAkun ){
        printf("Error Terjadi\n");
        exit(0);
    }

    inputUpdatedPasswordPerusahaanToFile(semuaAkunPerusahaan);

}

void ubah_password_perusahaan(struct structAkunPerusahaan * akunPerusahaan){

    struct structAkunPerusahaan semuaAkunPerusahaan[funcJumlahAkunPerusahaanProfile()];

    retrieveSemuaDataPerusahaanDiFile(&semuaAkunPerusahaan);

    int peringatan_ubah_pw;
    system("cls");
    printf("\n==UBAH PASSWORD==\n\n");
    printf("Peringatan, apakah anda benar ingin mengubah password ? (1.ya 2.tidak) : ");
    scanf("%d", &peringatan_ubah_pw);
    fflush(stdin);

    if(peringatan_ubah_pw == 1){
        func_ubah_password_perusahaan(akunPerusahaan, &semuaAkunPerusahaan);
    }else if(peringatan_ubah_pw == 2){
        main_menu_perusahaan(akunPerusahaan);
    }

}

void inputUpdatedDataPerusahaanToFile(struct structAkunPerusahaan * akunPerusahaan, struct structAkunPerusahaan * semuaAkunPerusahaan){

    int print_sekali = 0;
    int jumlahAkun = funcJumlahAkunPerusahaanProfile();
    FILE * bukaFilePerusahaan = fopen("akun_perusahaan.txt", "w+");
    (bukaFilePerusahaan == NULL) ? exit(0) : NULL;

    for(int i = 0; i < jumlahAkun; i++){

        if((fprintf(bukaFilePerusahaan, "%s %s %s %s %s %s",
            (semuaAkunPerusahaan+i)->username,
            (semuaAkunPerusahaan+i)->password,
            (semuaAkunPerusahaan+i)->namaPerusahaan,
            (semuaAkunPerusahaan+i)->kategoriPerusahaan,
            (semuaAkunPerusahaan+i)->alamatPerusahaan,
            (semuaAkunPerusahaan+i)->fasilitasPerusahaan)) < 0){
            printf("gagal mengupdate profile akun");
            exit(0);
        }else{
            fputc('\n', bukaFilePerusahaan);
            if(print_sekali != 1){
                printf("Berhasil mengupdate profile akun anda");
                print_sekali += 1;
            }
        }
    }

    fclose(bukaFilePerusahaan);
    bukaFilePerusahaan = NULL;

    int setelah_update_profile;
    printf("\n1. Kembali ke Menu Perusahaan \t 2. Logout\n");
    scanf("%d", &setelah_update_profile);
    if(setelah_update_profile == 1){
        system("cls");
        main_menu_perusahaan(akunPerusahaan);
    }else if(setelah_update_profile == 2){
        main();
    }

}

void inputUpdatedDataToStructSemuaPerusahaan(struct structAkunPerusahaan * akunPerusahaan, struct structAkunPerusahaan * semuaAkunPerusahaan){

    int jumlahAkun = funcJumlahAkunPerusahaanProfile();
    int cek, i;

    for( i = 0; i < jumlahAkun; i++){
        if( strcmp( akunPerusahaan->username, (semuaAkunPerusahaan+i)->username ) == 0 ){
            cek = 1;
            strcpy( (semuaAkunPerusahaan+i)->namaPerusahaan, akunPerusahaan->namaPerusahaan);
            strcpy( (semuaAkunPerusahaan+i)->kategoriPerusahaan, akunPerusahaan->kategoriPerusahaan);
            strcpy( (semuaAkunPerusahaan+i)->alamatPerusahaan, akunPerusahaan->alamatPerusahaan);
            strcpy( (semuaAkunPerusahaan+i)->fasilitasPerusahaan, akunPerusahaan->fasilitasPerusahaan);
            break;
        }else{
            cek = 1;
        }
    }

    if( (i == jumlahAkun) && (cek == 1) ){
        printf("Error Terjadi\n");
        exit(0);
    }

    inputUpdatedDataPerusahaanToFile(akunPerusahaan, semuaAkunPerusahaan);

}

void gantiProfilePerusahaan(struct structAkunPerusahaan * akunPerusahaan, struct structAkunPerusahaan * semuaAkunPerusahaan){

    char buffer[50];
    printf("\n\n");
    printf("Ganti Profile Perusahaan (gunakan tanda \"-\" jika tidak ingin mengganti data tersebut)\n");
    printf("Profile Perusahaan : \n");

    //nama perusahaan
    printf("Nama Perusahaan : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPerusahaan->namaPerusahaan, buffer)) != akunPerusahaan->namaPerusahaan){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    konversi_spasi_ke_underscore_profile_perusahaan(akunPerusahaan->namaPerusahaan);

    //kategori perusahaan
    printf("Kategori Perusahaan : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPerusahaan->kategoriPerusahaan, buffer)) != akunPerusahaan->kategoriPerusahaan){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    konversi_spasi_ke_underscore_profile_perusahaan(akunPerusahaan->kategoriPerusahaan);

    //alamatPerusahaan
    printf("Alamat Perusahaan : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPerusahaan->alamatPerusahaan, buffer)) != akunPerusahaan->alamatPerusahaan){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    konversi_spasi_ke_underscore_profile(akunPerusahaan->alamatPerusahaan);

    //fasilitasPerusahaan
    printf("Fasilitas Perusahaan : ");
    gets(buffer);
    if(*(buffer+0) != '-'){
        if( (strcpy(akunPerusahaan->fasilitasPerusahaan, buffer)) != akunPerusahaan->fasilitasPerusahaan){
            printf("\nError terjadi");
            exit(0);
        }
        strcpy(buffer, "");
    }
    konversi_spasi_ke_underscore_profile(akunPerusahaan->fasilitasPerusahaan);

    inputUpdatedDataToStructSemuaPerusahaan(akunPerusahaan, semuaAkunPerusahaan);

}

void profile_akun_perusahaan(struct structAkunPerusahaan * akunPerusahaan){

    konversi_underscore_ke_spasi_profile_perusahaan(akunPerusahaan->namaPerusahaan);
    konversi_underscore_ke_spasi_profile_perusahaan(akunPerusahaan->kategoriPerusahaan);
    konversi_underscore_ke_spasi_profile_perusahaan(akunPerusahaan->alamatPerusahaan);
    konversi_underscore_ke_spasi_profile_perusahaan(akunPerusahaan->fasilitasPerusahaan);

    printf("Profile Perusahaan : \n");
    printf("Nama Perusahaan : %s\n", akunPerusahaan->namaPerusahaan);
    printf("Kategori Perusahaan : %s\n", akunPerusahaan->kategoriPerusahaan);
    printf("Alamat Perusahaan : %s\n", akunPerusahaan->alamatPerusahaan);
    printf("Fasilitas Perusahaan : %s\n", akunPerusahaan->fasilitasPerusahaan);

    int menu_profile_akun_perusahaan;
    printf("\n\nIngin melakukan apa ?\n");
    printf("1.Ganti Profile\n");
    printf("2.Ubah Password\n");
    printf("3.Kembali ke menu Perusahaan\n");
    scanf("%d", &menu_profile_akun_perusahaan);
    fflush(stdin);

    if(menu_profile_akun_perusahaan == 1){

        struct structAkunPerusahaan semuaAkunPerusahaan[funcJumlahAkunPerusahaanProfile()];

        retrieveSemuaDataPerusahaanDiFile(&semuaAkunPerusahaan);

        gantiProfilePerusahaan(akunPerusahaan, &semuaAkunPerusahaan);

    }else if(menu_profile_akun_perusahaan == 2){
        ubah_password_perusahaan(akunPerusahaan);
    }else if(menu_profile_akun_perusahaan == 3){
        system("cls");
        main_menu_perusahaan(akunPerusahaan);
    }

}
