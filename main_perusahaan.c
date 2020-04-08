#include <stdio.h>
#include <stdlib.h>
#include "login.h"

struct structAkunPerusahaan{
    char username[50]; char password[50];
    char namaPerusahaan[50]; char kategoriPerusahaan[50]; char alamatPerusahaan[50]; char fasilitasPerusahaan[50];
};

void main_menu_perusahaan(struct structAkunPerusahaan * akunPerusahaan){

    printf("success, selamat datang %s", akunPerusahaan->namaPerusahaan);


}
