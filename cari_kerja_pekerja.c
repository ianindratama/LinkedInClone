#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "main_pekerja.h"
#include "main_list_kerja.h"
#include "profile_akun_pekerja.h"
#include "profile_akun_perusahaan.h"

struct structPekerjaPerusahaan{

    char username_pekerja[50]; char username_perusahaan[50];

    char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];

    char namaPerusahaan[50]; char nama_pekerjaan[50];

    char status[50]; char pesan[50];
};

struct structAkunPekerja{
    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];
    char nomor_telepon[25]; char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50]; char pengalaman_kerja[50];
};

struct structLowonganKerja{
    char username[50]; char nama_pekerjaan[50]; char deskripsi_pekerjaan[50]; char gaji_pekerjaan[50]; char jenis_pekerjaan[50];
};

struct structAkunPerusahaan{
    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

struct structCariKerjaList{
    char username[50];char namaPerusahaan[50]; char kategoriPerusahaan[50];char nama_pekerjaan[50];
    char deskripsi_pekerjaan[50]; char gaji_pekerjaan[50]; char jenis_pekerjaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

int funcJumlahListKerjaApplied(){
    FILE * bukaFile = fopen("list_kerja_apply.txt", "a+");
    (bukaFile == NULL) ? exit(0) : NULL;
    //menghitung jumlah lowongan kerja yang di applied user
        char cek_jumlah_list_kerja_applied;
        int jumlah_list_kerja_applied = 0;
        while( (cek_jumlah_list_kerja_applied = fgetc(bukaFile)) != EOF ){
            if(cek_jumlah_list_kerja_applied == '\n'){
                jumlah_list_kerja_applied++;
            }
        }
        fclose(bukaFile);
        bukaFile = NULL;
    return jumlah_list_kerja_applied;
}

void apply_pekerjaan(int * id_pilihan_pekerjaan, struct structCariKerjaList * semuaCariKerjaList, struct structAkunPekerja * akunPekerja);

void retrieveSemuaGabunganDataKerjaListAkunPerusahaan(struct structAkunPerusahaan * semuaAkunPerusahaan,
                                                      struct structLowonganKerja * semuaListKerja,
                                                      struct structCariKerjaList * semuaCariKerjaList){

    int jumlah_lowongan_pekerjaan = funcJumlahListKerja();
    int jumlah_akun_perusahaan = funcJumlahAkunPerusahaanProfile();

    for(int i = 0; i<jumlah_akun_perusahaan; i++){
        for(int j = 0; j<jumlah_lowongan_pekerjaan; j++){
            if( (strcmp( (semuaAkunPerusahaan+i)->username, (semuaListKerja+j)->username )) == 0 ){

                strcpy( (semuaCariKerjaList+j)->username, (semuaAkunPerusahaan+i)->username );
                strcpy( (semuaCariKerjaList+j)->namaPerusahaan, (semuaAkunPerusahaan+i)->namaPerusahaan );
                strcpy( (semuaCariKerjaList+j)->kategoriPerusahaan, (semuaAkunPerusahaan+i)->kategoriPerusahaan );
                strcpy( (semuaCariKerjaList+j)->nama_pekerjaan, (semuaListKerja+j)->nama_pekerjaan );
                strcpy( (semuaCariKerjaList+j)->deskripsi_pekerjaan, (semuaListKerja+j)->deskripsi_pekerjaan );
                strcpy( (semuaCariKerjaList+j)->gaji_pekerjaan, (semuaListKerja+j)->gaji_pekerjaan );
                strcpy( (semuaCariKerjaList+j)->jenis_pekerjaan, (semuaListKerja+j)->jenis_pekerjaan );
                strcpy( (semuaCariKerjaList+j)->fasilitasPerusahaan, (semuaAkunPerusahaan+i)->fasilitasPerusahaan );
                strcpy( (semuaCariKerjaList+j)->alamatPerusahaan, (semuaAkunPerusahaan+i)->alamatPerusahaan );

            }
        }
    }
}

void sortingSemuaGabunganDataKerjaListAkunPerusahaan(struct structCariKerjaList * semuaCariKerjaList){

    int n = funcJumlahListKerja();
    int i,j;

    char temp_username[50];char temp_namaPerusahaan[50]; char temp_kategoriPerusahaan[50];char temp_nama_pekerjaan[50];
    char temp_deskripsi_pekerjaan[50]; char temp_gaji_pekerjaan[50]; char temp_jenis_pekerjaan[50]; char temp_alamatPerusahaan[50];
    char temp_fasilitasPerusahaan[50];

	for(i = 0; i<n-1; i++){
		for(j = 0; j<n-1; j++){
            int x = j+1;
			if( (strcmp((semuaCariKerjaList+j)->namaPerusahaan, (semuaCariKerjaList+x)->namaPerusahaan)) > 0 ){

                strcpy(temp_username, (semuaCariKerjaList+x)->username);
                strcpy(temp_namaPerusahaan, (semuaCariKerjaList+x)->namaPerusahaan);
                strcpy(temp_kategoriPerusahaan, (semuaCariKerjaList+x)->kategoriPerusahaan);
                strcpy(temp_nama_pekerjaan, (semuaCariKerjaList+x)->nama_pekerjaan);
                strcpy(temp_deskripsi_pekerjaan, (semuaCariKerjaList+x)->deskripsi_pekerjaan);
                strcpy(temp_gaji_pekerjaan, (semuaCariKerjaList+x)->gaji_pekerjaan);
                strcpy(temp_jenis_pekerjaan, (semuaCariKerjaList+x)->jenis_pekerjaan);
                strcpy(temp_alamatPerusahaan, (semuaCariKerjaList+x)->alamatPerusahaan);
                strcpy(temp_fasilitasPerusahaan, (semuaCariKerjaList+x)->fasilitasPerusahaan);

                strcpy((semuaCariKerjaList+x)->username, (semuaCariKerjaList+j)->username);
                strcpy((semuaCariKerjaList+x)->namaPerusahaan, (semuaCariKerjaList+j)->namaPerusahaan);
                strcpy((semuaCariKerjaList+x)->kategoriPerusahaan, (semuaCariKerjaList+j)->kategoriPerusahaan);
                strcpy((semuaCariKerjaList+x)->nama_pekerjaan, (semuaCariKerjaList+j)->nama_pekerjaan);
                strcpy((semuaCariKerjaList+x)->deskripsi_pekerjaan, (semuaCariKerjaList+j)->deskripsi_pekerjaan);
                strcpy((semuaCariKerjaList+x)->gaji_pekerjaan, (semuaCariKerjaList+j)->gaji_pekerjaan);
                strcpy((semuaCariKerjaList+x)->jenis_pekerjaan, (semuaCariKerjaList+j)->jenis_pekerjaan);
                strcpy((semuaCariKerjaList+x)->alamatPerusahaan, (semuaCariKerjaList+j)->alamatPerusahaan);
                strcpy((semuaCariKerjaList+x)->fasilitasPerusahaan, (semuaCariKerjaList+j)->fasilitasPerusahaan);

                strcpy((semuaCariKerjaList+j)->username, temp_username);
                strcpy((semuaCariKerjaList+j)->namaPerusahaan, temp_namaPerusahaan);
                strcpy((semuaCariKerjaList+j)->kategoriPerusahaan, temp_kategoriPerusahaan);
                strcpy((semuaCariKerjaList+j)->nama_pekerjaan, temp_nama_pekerjaan);
                strcpy((semuaCariKerjaList+j)->deskripsi_pekerjaan, temp_deskripsi_pekerjaan);
                strcpy((semuaCariKerjaList+j)->gaji_pekerjaan, temp_gaji_pekerjaan);
                strcpy((semuaCariKerjaList+j)->jenis_pekerjaan, temp_jenis_pekerjaan);
                strcpy((semuaCariKerjaList+j)->alamatPerusahaan, temp_alamatPerusahaan);
                strcpy((semuaCariKerjaList+j)->fasilitasPerusahaan, temp_fasilitasPerusahaan);

			}else if( (strcmp((semuaCariKerjaList+j)->namaPerusahaan, (semuaCariKerjaList+x)->namaPerusahaan)) == 0 ){
                if( (strcmp((semuaCariKerjaList+j)->nama_pekerjaan, (semuaCariKerjaList+x)->nama_pekerjaan)) > 0 ){
                    strcpy(temp_username, (semuaCariKerjaList+x)->username);
                    strcpy(temp_namaPerusahaan, (semuaCariKerjaList+x)->namaPerusahaan);
                    strcpy(temp_kategoriPerusahaan, (semuaCariKerjaList+x)->kategoriPerusahaan);
                    strcpy(temp_nama_pekerjaan, (semuaCariKerjaList+x)->nama_pekerjaan);
                    strcpy(temp_deskripsi_pekerjaan, (semuaCariKerjaList+x)->deskripsi_pekerjaan);
                    strcpy(temp_gaji_pekerjaan, (semuaCariKerjaList+x)->gaji_pekerjaan);
                    strcpy(temp_jenis_pekerjaan, (semuaCariKerjaList+x)->jenis_pekerjaan);
                    strcpy(temp_alamatPerusahaan, (semuaCariKerjaList+x)->alamatPerusahaan);
                    strcpy(temp_fasilitasPerusahaan, (semuaCariKerjaList+x)->fasilitasPerusahaan);

                    strcpy((semuaCariKerjaList+x)->username, (semuaCariKerjaList+j)->username);
                    strcpy((semuaCariKerjaList+x)->namaPerusahaan, (semuaCariKerjaList+j)->namaPerusahaan);
                    strcpy((semuaCariKerjaList+x)->kategoriPerusahaan, (semuaCariKerjaList+j)->kategoriPerusahaan);
                    strcpy((semuaCariKerjaList+x)->nama_pekerjaan, (semuaCariKerjaList+j)->nama_pekerjaan);
                    strcpy((semuaCariKerjaList+x)->deskripsi_pekerjaan, (semuaCariKerjaList+j)->deskripsi_pekerjaan);
                    strcpy((semuaCariKerjaList+x)->gaji_pekerjaan, (semuaCariKerjaList+j)->gaji_pekerjaan);
                    strcpy((semuaCariKerjaList+x)->jenis_pekerjaan, (semuaCariKerjaList+j)->jenis_pekerjaan);
                    strcpy((semuaCariKerjaList+x)->alamatPerusahaan, (semuaCariKerjaList+j)->alamatPerusahaan);
                    strcpy((semuaCariKerjaList+x)->fasilitasPerusahaan, (semuaCariKerjaList+j)->fasilitasPerusahaan);

                    strcpy((semuaCariKerjaList+j)->username, temp_username);
                    strcpy((semuaCariKerjaList+j)->namaPerusahaan, temp_namaPerusahaan);
                    strcpy((semuaCariKerjaList+j)->kategoriPerusahaan, temp_kategoriPerusahaan);
                    strcpy((semuaCariKerjaList+j)->nama_pekerjaan, temp_nama_pekerjaan);
                    strcpy((semuaCariKerjaList+j)->deskripsi_pekerjaan, temp_deskripsi_pekerjaan);
                    strcpy((semuaCariKerjaList+j)->gaji_pekerjaan, temp_gaji_pekerjaan);
                    strcpy((semuaCariKerjaList+j)->jenis_pekerjaan, temp_jenis_pekerjaan);
                    strcpy((semuaCariKerjaList+j)->alamatPerusahaan, temp_alamatPerusahaan);
                    strcpy((semuaCariKerjaList+j)->fasilitasPerusahaan, temp_fasilitasPerusahaan);
                }
			}
		}
	}

}

void cari_pekerjaan_berdasarkan_nama(struct structAkunPekerja * akunPekerja,struct structCariKerjaList * semuaCariKerjaList){

    char cari_nama_pekerjaan[50];
    printf("Masukkan Nama Pekerjaan Yang diinginkan : ");
    gets(cari_nama_pekerjaan);

    int i = 0; int counter = 0;
    int n = funcJumlahListKerja();
    int cek = 0;
    int indeks_kerja[funcJumlahListKerja()];
    indeks_kerja[0] = 0;

    while(i<=n-1){
		if( (strcmp( (semuaCariKerjaList+i)->nama_pekerjaan, cari_nama_pekerjaan ) ) == 0 ){
            cek = 1;
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->namaPerusahaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->kategoriPerusahaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->nama_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->deskripsi_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->gaji_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->jenis_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->fasilitasPerusahaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->alamatPerusahaan);

            printf("\n");counter +=1;
            printf("%3d Nama Perusahaan : %s\n", counter,  (semuaCariKerjaList+i)->namaPerusahaan);
            printf("    Kategori Perusahaan : %s\n",  (semuaCariKerjaList+i)->kategoriPerusahaan);
            printf("    Nama Pekerjaan : %s\n",  (semuaCariKerjaList+i)->nama_pekerjaan);
            printf("    Deskripsi Pekerjaan : %s\n",  (semuaCariKerjaList+i)->deskripsi_pekerjaan);
            printf("    Gaji Pekerjaan : %s\n",  (semuaCariKerjaList+i)->gaji_pekerjaan);
            printf("    Jenis Pekerjaan : %s\n",  (semuaCariKerjaList+i)->jenis_pekerjaan);
            printf("    Fasilitas Perusahaan : %s\n",  (semuaCariKerjaList+i)->fasilitasPerusahaan);
            printf("    Alamat Perusahaan : %s\n",  (semuaCariKerjaList+i)->alamatPerusahaan);

            indeks_kerja[counter] = i+1;

		}else{
			if( (i == n-1)  && (cek == 0)){
				printf("\nData tidak ditemukan\n");
			}
		}
		i++;
	}

    int pilihan_menu_setelah_pencarian;

    printf("\n1.Apply Pekerjaan \t 2. Kembali ke Menu Pekerja\n");
    scanf("%d", &pilihan_menu_setelah_pencarian);

    if(pilihan_menu_setelah_pencarian == 1){
            int id_pilihan_pekerjaan;
            printf("Pilih Pekerjaan yang igin Anda Apply (ex:1) : ");
            scanf("%d", &id_pilihan_pekerjaan);
            fflush(stdin);
            apply_pekerjaan(&indeks_kerja[id_pilihan_pekerjaan], semuaCariKerjaList, akunPekerja);
    }else if(pilihan_menu_setelah_pencarian == 2){
        system("cls");
        main_menu_pekerja(akunPekerja);
    }

}

void cari_pekerjaan_berdasarkan_kategori(struct structAkunPekerja * akunPekerja,struct structCariKerjaList * semuaCariKerjaList){

    char cari_kategori[50];
    printf("Masukkan Kategori Yang diinginkan : ");
    gets(cari_kategori);

    int i = 0; int counter = 0;
    int n = funcJumlahListKerja();
    int cek = 0;
    int indeks_kerja[funcJumlahListKerja()];
    indeks_kerja[0] = 0;

    while(i<=n-1){
		if( (strcmp( (semuaCariKerjaList+i)->kategoriPerusahaan, cari_kategori ) ) == 0 ){
            cek = 1;
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->namaPerusahaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->kategoriPerusahaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->nama_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->deskripsi_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->gaji_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->jenis_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->fasilitasPerusahaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->alamatPerusahaan);

            printf("\n");counter +=1;
            printf("%3d Nama Perusahaan : %s\n", counter,  (semuaCariKerjaList+i)->namaPerusahaan);
            printf("    Kategori Perusahaan : %s\n",  (semuaCariKerjaList+i)->kategoriPerusahaan);
            printf("    Nama Pekerjaan : %s\n",  (semuaCariKerjaList+i)->nama_pekerjaan);
            printf("    Deskripsi Pekerjaan : %s\n",  (semuaCariKerjaList+i)->deskripsi_pekerjaan);
            printf("    Gaji Pekerjaan : %s\n",  (semuaCariKerjaList+i)->gaji_pekerjaan);
            printf("    Jenis Pekerjaan : %s\n",  (semuaCariKerjaList+i)->jenis_pekerjaan);
            printf("    Fasilitas Perusahaan : %s\n",  (semuaCariKerjaList+i)->fasilitasPerusahaan);
            printf("    Alamat Perusahaan : %s\n",  (semuaCariKerjaList+i)->alamatPerusahaan);

            indeks_kerja[counter] = i+1;

		}else{
			if( (i == n-1)  && (cek == 0)){
				printf("\nData tidak ditemukan\n");
			}
		}
		i++;
	}

    int pilihan_menu_setelah_pencarian;

    printf("\n1.Apply Pekerjaan \t 2. Kembali ke Menu Pekerja\n");
    scanf("%d", &pilihan_menu_setelah_pencarian);

    if(pilihan_menu_setelah_pencarian == 1){
            int id_pilihan_pekerjaan;
            printf("Pilih Pekerjaan yang igin Anda Apply (ex:1) : ");
            scanf("%d", &id_pilihan_pekerjaan);
            fflush(stdin);
            apply_pekerjaan(&indeks_kerja[id_pilihan_pekerjaan], semuaCariKerjaList, akunPekerja);
    }else if(pilihan_menu_setelah_pencarian == 2){
        system("cls");
        main_menu_pekerja(akunPekerja);
    }

}

void cari_pekerjaan_berdasarkan_perusahaan(struct structAkunPekerja * akunPekerja,struct structCariKerjaList * semuaCariKerjaList){

    char cari_nama_perusahaan[50];
    printf("Masukkan Nama Perusahaan Yang diinginkan : ");
    gets(cari_nama_perusahaan);

    int i = 0; int counter = 0;
    int n = funcJumlahListKerja();
    int cek = 0;
    int indeks_kerja[funcJumlahListKerja()];
    indeks_kerja[0] = 0;

    while(i<=n-1){
		if( (strcmp( (semuaCariKerjaList+i)->namaPerusahaan, cari_nama_perusahaan ) ) == 0 ){
            cek = 1;
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->namaPerusahaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->kategoriPerusahaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->nama_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->deskripsi_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->gaji_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->jenis_pekerjaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->fasilitasPerusahaan);
            konversi_underscore_ke_spasi_profile( (semuaCariKerjaList+i)->alamatPerusahaan);

            printf("\n");counter +=1;
            printf("%3d Nama Perusahaan : %s\n", counter,  (semuaCariKerjaList+i)->namaPerusahaan);
            printf("    Kategori Perusahaan : %s\n",  (semuaCariKerjaList+i)->kategoriPerusahaan);
            printf("    Nama Pekerjaan : %s\n",  (semuaCariKerjaList+i)->nama_pekerjaan);
            printf("    Deskripsi Pekerjaan : %s\n",  (semuaCariKerjaList+i)->deskripsi_pekerjaan);
            printf("    Gaji Pekerjaan : %s\n",  (semuaCariKerjaList+i)->gaji_pekerjaan);
            printf("    Jenis Pekerjaan : %s\n",  (semuaCariKerjaList+i)->jenis_pekerjaan);
            printf("    Fasilitas Perusahaan : %s\n",  (semuaCariKerjaList+i)->fasilitasPerusahaan);
            printf("    Alamat Perusahaan : %s\n",  (semuaCariKerjaList+i)->alamatPerusahaan);

            indeks_kerja[counter] = i+1;

		}else{
			if( (i == n-1)  && (cek == 0)){
				printf("\nData tidak ditemukan\n");
			}
		}
		i++;
	}

    int pilihan_menu_setelah_pencarian;

    printf("\n1.Apply Pekerjaan \t 2. Kembali ke Menu Pekerja\n");
    scanf("%d", &pilihan_menu_setelah_pencarian);

    if(pilihan_menu_setelah_pencarian == 1){
            int id_pilihan_pekerjaan;
            printf("Pilih Pekerjaan yang igin Anda Apply (ex:1) : ");
            scanf("%d", &id_pilihan_pekerjaan);
            fflush(stdin);
            apply_pekerjaan(&indeks_kerja[id_pilihan_pekerjaan], semuaCariKerjaList, akunPekerja);
    }else if(pilihan_menu_setelah_pencarian == 2){
        system("cls");
        main_menu_pekerja(akunPekerja);
    }

}

void apply_pekerjaan(int * id_pilihan_pekerjaan, struct structCariKerjaList * semuaCariKerjaList, struct structAkunPekerja * akunPekerja){

    FILE * bukaFile = fopen("list_kerja_apply.txt", "a+");
    (bukaFile == NULL) ? exit(0) : NULL;

    konversi_spasi_ke_underscore_profile(akunPekerja->nama);
    konversi_spasi_ke_underscore_profile(akunPekerja->tanggal_lahir);
    konversi_spasi_ke_underscore_profile(akunPekerja->kewarganegaraan);
    konversi_spasi_ke_underscore_profile(akunPekerja->nomor_telepon);
    konversi_spasi_ke_underscore_profile(akunPekerja->pref_gaji);
    konversi_spasi_ke_underscore_profile(akunPekerja->sd);
    konversi_spasi_ke_underscore_profile(akunPekerja->smp);
    konversi_spasi_ke_underscore_profile(akunPekerja->sma);
    konversi_spasi_ke_underscore_profile(akunPekerja->sarjana);
    konversi_spasi_ke_underscore_profile(akunPekerja->pengalaman_kerja);
    konversi_spasi_ke_underscore_profile((semuaCariKerjaList+(*id_pilihan_pekerjaan-1))->namaPerusahaan);
    konversi_spasi_ke_underscore_profile((semuaCariKerjaList+(*id_pilihan_pekerjaan-1))->nama_pekerjaan);

    char status[50] = "applied";
    char pesan[50] = "belum ada pesan";
    konversi_spasi_ke_underscore_profile(pesan);

    if( fprintf(bukaFile, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                akunPekerja->username, (semuaCariKerjaList+(*id_pilihan_pekerjaan-1))->username, akunPekerja->nama,
                akunPekerja->tanggal_lahir, akunPekerja->kewarganegaraan,
                akunPekerja->nomor_telepon, akunPekerja->pref_gaji, akunPekerja->sd, akunPekerja->smp,
                akunPekerja->sma, akunPekerja->sarjana, akunPekerja->pengalaman_kerja,
                (semuaCariKerjaList+(*id_pilihan_pekerjaan-1))->namaPerusahaan,
                (semuaCariKerjaList+(*id_pilihan_pekerjaan-1))->nama_pekerjaan,
                status, pesan ) < 0 ){
        printf("\nError terjadi");
        exit(0);
    }else{
        fputc('\n', bukaFile);
        fclose(bukaFile);
        bukaFile = NULL;

        konversi_underscore_ke_spasi_profile((semuaCariKerjaList+(*id_pilihan_pekerjaan-1))->namaPerusahaan);
        konversi_underscore_ke_spasi_profile((semuaCariKerjaList+(*id_pilihan_pekerjaan-1))->nama_pekerjaan);

        int pilih_pekerjaan_lagi;

        printf("\nBerhasil mengApply Pekerjaan %s di %s\n\n", (semuaCariKerjaList+(*id_pilihan_pekerjaan-1))->nama_pekerjaan, (semuaCariKerjaList+(*id_pilihan_pekerjaan-1))->namaPerusahaan);
        printf("1. Apply Pekerjaan Lagi \t 2. Kembali ke Menu Utama\n");
        scanf("%d", &pilih_pekerjaan_lagi);
        fflush(stdin);
        if(pilih_pekerjaan_lagi == 1){
            int id_pilihan_pekerjaan;
            printf("Pilih Pekerjaan yang igin Anda Apply (ex:1) : ");
            scanf("%d", &id_pilihan_pekerjaan);
            fflush(stdin);
            apply_pekerjaan(&id_pilihan_pekerjaan, semuaCariKerjaList, akunPekerja);

        }else if(pilih_pekerjaan_lagi == 2){
            system("cls");
            main_menu_pekerja(akunPekerja);
        }

    }

}

void retrieveDataPekerjaanApplied(struct structPekerjaPerusahaan * semuaPekerjaanApplied){

    FILE * bukaFile = fopen("list_kerja_apply.txt", "a+");
    (bukaFile == NULL) ? exit(0) : NULL;

    for(int i = 0; i<funcJumlahListKerjaApplied(); i++){
        if( fscanf(bukaFile, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                   (semuaPekerjaanApplied+i)->username_pekerja,
                   (semuaPekerjaanApplied+i)->username_perusahaan,
                   (semuaPekerjaanApplied+i)->nama,
                   (semuaPekerjaanApplied+i)->tanggal_lahir,
                   (semuaPekerjaanApplied+i)->kewarganegaraan,
                   (semuaPekerjaanApplied+i)->nomor_telepon,
                   (semuaPekerjaanApplied+i)->pref_gaji,
                   (semuaPekerjaanApplied+i)->sd,
                   (semuaPekerjaanApplied+i)->smp,
                   (semuaPekerjaanApplied+i)->sma,
                   (semuaPekerjaanApplied+i)->sarjana,
                   (semuaPekerjaanApplied+i)->pengalaman_kerja,
                   (semuaPekerjaanApplied+i)->namaPerusahaan,
                   (semuaPekerjaanApplied+i)->nama_pekerjaan,
                   (semuaPekerjaanApplied+i)->status,
                   (semuaPekerjaanApplied+i)->pesan
                   ) < 0 ){
            printf("\nError terjadi");
            exit(0);
        }
    }

    fclose(bukaFile);
    bukaFile = NULL;

}

void cek_daftar_pekerjaan(struct structAkunPekerja * akunPekerja){

    int jumlah_pekerjaan_applied_user = 0;
    int cek = 0; int x = -1;
    int jumlah_list_kerja_applied = funcJumlahListKerjaApplied();

    //retrive data
    struct structPekerjaPerusahaan semuaPekerjaanApplied[jumlah_list_kerja_applied];
    retrieveDataPekerjaanApplied(&semuaPekerjaanApplied);

    //sortir data
    struct structPekerjaPerusahaan pekerjaanApplied[jumlah_list_kerja_applied];

    for(int i = 0; i<jumlah_list_kerja_applied; i++){
        if( (strcmp(akunPekerja->username, semuaPekerjaanApplied[i].username_pekerja)) == 0 ){

            cek = 1;
            jumlah_pekerjaan_applied_user += 1; x+=1;

            strcpy(pekerjaanApplied[x].username_pekerja, semuaPekerjaanApplied[i].username_pekerja);
            strcpy(pekerjaanApplied[x].username_perusahaan, semuaPekerjaanApplied[i].username_perusahaan);
            strcpy(pekerjaanApplied[x].nama, semuaPekerjaanApplied[i].nama);
            strcpy(pekerjaanApplied[x].tanggal_lahir, semuaPekerjaanApplied[i].tanggal_lahir);
            strcpy(pekerjaanApplied[x].kewarganegaraan, semuaPekerjaanApplied[i].kewarganegaraan);
            strcpy(pekerjaanApplied[x].nomor_telepon, semuaPekerjaanApplied[i].nomor_telepon);
            strcpy(pekerjaanApplied[x].pref_gaji, semuaPekerjaanApplied[i].pref_gaji);
            strcpy(pekerjaanApplied[x].sd , semuaPekerjaanApplied[i].sd);
            strcpy(pekerjaanApplied[x].smp , semuaPekerjaanApplied[i].smp);
            strcpy(pekerjaanApplied[x].sma , semuaPekerjaanApplied[i].sma);
            strcpy(pekerjaanApplied[x].sarjana , semuaPekerjaanApplied[i].sarjana);
            strcpy(pekerjaanApplied[x].pengalaman_kerja , semuaPekerjaanApplied[i].pengalaman_kerja);
            strcpy(pekerjaanApplied[x].namaPerusahaan , semuaPekerjaanApplied[i].namaPerusahaan);
            strcpy(pekerjaanApplied[x].nama_pekerjaan , semuaPekerjaanApplied[i].nama_pekerjaan);
            strcpy(pekerjaanApplied[x].status , semuaPekerjaanApplied[i].status);
            strcpy(pekerjaanApplied[x].pesan , semuaPekerjaanApplied[i].pesan);

        }
    }
    if(cek == 1){
        printf("\n\t\t\t==Pekerjaan yang Anda Applied==\n\n");
        printf(" No Nama Pekerjaan\tNama Perusahaan\t\tStatus\t\tPesan\n");
        for(int i = 0; i<jumlah_pekerjaan_applied_user; i++){

            konversi_underscore_ke_spasi_profile(pekerjaanApplied[i].nama_pekerjaan);
            konversi_underscore_ke_spasi_profile(pekerjaanApplied[i].namaPerusahaan);
            konversi_underscore_ke_spasi_profile(pekerjaanApplied[i].status);
            konversi_underscore_ke_spasi_profile(pekerjaanApplied[i].pesan);

            printf("%2d  %-20s%-20s\t%-8s\t%s\n", i+1, pekerjaanApplied[i].nama_pekerjaan, pekerjaanApplied[i].namaPerusahaan,
                                            pekerjaanApplied[i].status, pekerjaanApplied[i].pesan);
        }
    }else{
        printf("\nMaaf Anda belum pernah Apply Pekerjaan\n");
    }

    int menu_setelah_lihat_daftar;
    printf("\n1. Kembali ke menu utama \t 2. Logout\n");
    scanf("%d", &menu_setelah_lihat_daftar);
    getchar();
    system("cls");
    if(menu_setelah_lihat_daftar == 1){
        main_menu_pekerja(akunPekerja);
    }else{
        main();
    }


}

void tampilkan_semua_pekerjaan(struct structAkunPekerja * akunPekerja){

    FILE * bukaFileListKerja = fopen("list_kerja.txt", "a+");
    (bukaFileListKerja == NULL) ? exit(0) : NULL;

    //retrive lowongan kerja data
    struct structLowonganKerja semuaListKerja[funcJumlahListKerja()];
    retrieveSemuaListKerjaDiFile(&semuaListKerja);

    //retrive akun perusahaan data
    struct structAkunPerusahaan semuaAkunPerusahaan[funcJumlahAkunPerusahaanProfile()];
    retrieveSemuaDataPerusahaanDiFile(&semuaAkunPerusahaan);

    // struct yg menampung lowongan + perusahaan data
    struct structCariKerjaList semuaCariKerjaList[funcJumlahListKerja()];

    int jumlah_lowongan_pekerjaan = funcJumlahListKerja();
    //int jumlah_akun_perusahaan = funcJumlahAkunPerusahaanProfile();
    int counter = 0;

    printf("\n\nList Lowongan Pekerjaan Perusahaan\n\n");

    if( jumlah_lowongan_pekerjaan == 0 ){
        int tidak_ada_lowongan;
        printf("\nMohon Maaf, untuk saat ini tidak ada Lowongan Kerja tersedia\n");
        printf("1. Kembali ke Menu Pekerja \t 2. Logout\n");
        scanf("%d", &tidak_ada_lowongan);
        fflush(stdin);
        if( tidak_ada_lowongan == 1 ){
            system("cls");
            main_menu_pekerja(akunPekerja);
        }else if( tidak_ada_lowongan == 2 ){
            system("cls");
            printf("Anda Berhasil Logout\n");
            main();
        }
    }


    if( jumlah_lowongan_pekerjaan != 0 ){
        retrieveSemuaGabunganDataKerjaListAkunPerusahaan(&semuaAkunPerusahaan, &semuaListKerja, &semuaCariKerjaList);
        sortingSemuaGabunganDataKerjaListAkunPerusahaan(&semuaCariKerjaList);
        for(int i = 0; i<jumlah_lowongan_pekerjaan; i++){
            konversi_underscore_ke_spasi_profile(semuaCariKerjaList[i].namaPerusahaan);
            konversi_underscore_ke_spasi_profile(semuaCariKerjaList[i].kategoriPerusahaan);
            konversi_underscore_ke_spasi_profile(semuaCariKerjaList[i].nama_pekerjaan);
            konversi_underscore_ke_spasi_profile(semuaCariKerjaList[i].deskripsi_pekerjaan);
            konversi_underscore_ke_spasi_profile(semuaCariKerjaList[i].gaji_pekerjaan);
            konversi_underscore_ke_spasi_profile(semuaCariKerjaList[i].jenis_pekerjaan);
            konversi_underscore_ke_spasi_profile(semuaCariKerjaList[i].fasilitasPerusahaan);
            konversi_underscore_ke_spasi_profile(semuaCariKerjaList[i].alamatPerusahaan);

            printf("\n");counter +=1;
            printf("%3d Nama Perusahaan : %s\n", counter, semuaCariKerjaList[i].namaPerusahaan);
            printf("    Kategori Perusahaan : %s\n", semuaCariKerjaList[i].kategoriPerusahaan);
            printf("    Nama Pekerjaan : %s\n", semuaCariKerjaList[i].nama_pekerjaan);
            printf("    Deskripsi Pekerjaan : %s\n", semuaCariKerjaList[i].deskripsi_pekerjaan);
            printf("    Gaji Pekerjaan : %s\n", semuaCariKerjaList[i].gaji_pekerjaan);
            printf("    Jenis Pekerjaan : %s\n", semuaCariKerjaList[i].jenis_pekerjaan);
            printf("    Fasilitas Perusahaan : %s\n", semuaCariKerjaList[i].fasilitasPerusahaan);
            printf("    Alamat Perusahaan : %s\n", semuaCariKerjaList[i].alamatPerusahaan);
        }

        printf("\n");
        printf("Jika ingin apply pekerjaan, ketik \" 1 \"\n");
        printf("Cari pekerjaan berdasarkan Nama Pekerjaan, ketik \" 2 \"\n");
        printf("Cari pekerjaan berdasarkan Kategori Perusahaan, ketik \" 3 \"\n");
        printf("Cari pekerjaan berdasarkan Nama Perusahaan, ketik \" 4 \"\n");
        printf("Jika ingin Logout, ketik \" 5 \"\n");

        int menu_setelah_show_list_kerja;
        scanf("%d", &menu_setelah_show_list_kerja);
        fflush(stdin);

        if(menu_setelah_show_list_kerja == 1){
            int id_pilihan_pekerjaan;
            printf("Pilih Pekerjaan yang igin Anda Apply (ex:1) : ");
            scanf("%d", &id_pilihan_pekerjaan);
            fflush(stdin);
            apply_pekerjaan(&id_pilihan_pekerjaan, &semuaCariKerjaList, akunPekerja);
        }else if(menu_setelah_show_list_kerja == 2){
            cari_pekerjaan_berdasarkan_nama(akunPekerja, &semuaCariKerjaList);
        }else if(menu_setelah_show_list_kerja == 3){
            cari_pekerjaan_berdasarkan_kategori(akunPekerja, &semuaCariKerjaList);
        }else if(menu_setelah_show_list_kerja == 4){
            cari_pekerjaan_berdasarkan_perusahaan(akunPekerja, &semuaCariKerjaList);
        }else if(menu_setelah_show_list_kerja == 5){
            system("cls");
            printf("Anda Berhasil Logout\n");
            main();
        }

    }


}
