#ifndef PROFILE_AKUN_PERUSAHAAN_H_INCLUDED
#define PROFILE_AKUN_PERUSAHAAN_H_INCLUDED

void konversi_spasi_ke_underscore_profile_perusahaan(char * kata);
void konversi_underscore_ke_spasi_profile_perusahaan(char * kata);
void profile_akun_perusahaan(struct structAkunPerusahaan * akunPerusahaan);
int funcJumlahAkunPerusahaanProfile();
void retrieveSemuaDataPerusahaanDiFile(struct structAkunPerusahaan * semuaAkunPerusahaan);

#endif // PROFILE_AKUN_PERUSAHAAN_H_INCLUDED
