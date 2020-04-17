#ifndef MAIN_LIST_KERJA_H_INCLUDED
#define MAIN_LIST_KERJA_H_INCLUDED

void menu_list_kerja(struct structAkunPerusahaan * akunPerusahaan);
int funcJumlahListKerja();
void retrieveSemuaListKerjaDiFile(struct structLowonganKerja * semuaListKerja);
void daftar_pelamar_kerja(struct structAkunPerusahaan * akunPerusahaan);
void daftar_pelamar_kerja_yang_telah_diterima(struct structAkunPerusahaan * akunPerusahaan);

#endif // MAIN_LIST_KERJA_H_INCLUDED
