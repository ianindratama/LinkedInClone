#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "main_pekerja.h"
#include "main_list_kerja.h"
#include "profile_akun_pekerja.h"

struct structAkunPekerja{
    char username[50];char password[50];char nama[50];char tanggal_lahir[50];char kewarganegaraan[50];char pref_gaji[50];
    char sd[50];char smp[50];char sma[50];char sarjana[50];
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

void retrieveSemuaGabunganDataKerjaListAkunPerusahaan(struct structAkunPerusahaan * semuaAkunPerusahaan,
                                                      struct structLowonganKerja * semuaListKerja,
                                                      struct structCariKerjaList * semuaCariKerjaList){

    int jumlah_lowongan_pekerjaan = funcJumlahListKerja();
    int jumlah_akun_perusahaan = funcJumlahAkunPerusahaanProfile();
    int counter = 0;

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

    printf("haii %s\n", (semuaCariKerjaList+0)->namaPerusahaan);
    printf("haii %s\n", (semuaCariKerjaList+1)->namaPerusahaan);
    printf("haii %s\n", (semuaCariKerjaList+2)->namaPerusahaan);
    printf("haii %s\n", (semuaCariKerjaList+3)->namaPerusahaan);

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

		}else{
			if( (i == n-1)  && (cek == 0)){
				printf("\nData tidak ditemukan\n");
			}
		}
		i++;
	}

    int pilihan_menu_setelah_pencarian;

    printf("\n1.Apply Pekerjaan Ini \t 2. Kembali ke Menu Pekerja \t 2. Logout\n");
    scanf("%d", &pilihan_menu_setelah_pencarian);

    if(pilihan_menu_setelah_pencarian == 1){

    }else if(pilihan_menu_setelah_pencarian == 2){
        system("cls");
        main_menu_pekerja(akunPekerja);
    }else if(pilihan_menu_setelah_pencarian == 3){
        system("cls");
        printf("Berhasil Logout\n");
        main();
    }

}

void cari_pekerjaan_berdasarkan_perusahaan(struct structAkunPekerja * akunPekerja,struct structCariKerjaList * semuaCariKerjaList){

    char cari_nama_perusahaan[50];
    printf("Masukkan Nama Perusahaan Yang diinginkan : ");
    gets(cari_nama_perusahaan);

    int i = 0; int counter = 0;
    int n = funcJumlahListKerja();
    int cek = 0;

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

		}else{
			if( (i == n-1)  && (cek == 0)){
				printf("\nData tidak ditemukan\n");
			}
		}
		i++;
	}

    if(cek == 1){
        int pilihan_menu_setelah_pencarian;

        printf("\n1.Apply Pekerjaan Ini \t 2. Kembali ke Menu Pekerja \t 2. Logout\n");
        scanf("%d", &pilihan_menu_setelah_pencarian);

        if(pilihan_menu_setelah_pencarian == 1){

        }else if(pilihan_menu_setelah_pencarian == 2){
            system("cls");
            main_menu_pekerja(akunPekerja);
        }else if(pilihan_menu_setelah_pencarian == 3){
            system("cls");
            printf("Berhasil Logout\n");
            main();
        }
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
    int jumlah_akun_perusahaan = funcJumlahAkunPerusahaanProfile();
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
        printf("Cari pekerjaan berdasarkan Nama Perusahaan, ketik \" 3 \"\n");
        printf("Jika ingin Logout, ketik \" 4 \"\n");

        int menu_setelah_show_list_kerja;
        scanf("%d", &menu_setelah_show_list_kerja);
        fflush(stdin);

        if(menu_setelah_show_list_kerja == 1){

        }else if(menu_setelah_show_list_kerja == 2){
            cari_pekerjaan_berdasarkan_nama(akunPekerja, &semuaCariKerjaList);
        }else if(menu_setelah_show_list_kerja == 3){
            cari_pekerjaan_berdasarkan_perusahaan(akunPekerja, &semuaCariKerjaList);
        }else if(menu_setelah_show_list_kerja == 4){
            system("cls");
            printf("Anda Berhasil Logout\n");
            main();
        }

    }


}
