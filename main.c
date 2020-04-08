#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "login.h"
#include "register.h"

int main(){

    //Deklarasi Variable
    int menu;

    // Main Program
    menu:
    printf("==CARI KERJA==\n");
    printf("1.Login 2.Register\n");
    printf("Pilih menu yang diinginkan : ");
    menu = getchar();

    system("cls");
    if(menu == '1'){
        login_form();
    }else if(menu == '2'){
        register_form();
    }else{
        printf("Menu yang anda masukkan salah\n");
        goto menu;
    }

    printf("\n\n");
    return 0;
}
