#ifndef PROFILE_AKUN_PEKERJA_H_INCLUDED
#define PROFILE_AKUN_PEKERJA_H_INCLUDED

void konversi_spasi_ke_underscore_profile(char * kata);
void konversi_underscore_ke_spasi_profile(char * kata);
void profile_akun_pekerja(struct structAkunPekerja * akunPekerja);
int funcJumlahAkunPekerjaProfile();
void retrieveSemuaDataPekerjaDiFile(struct structAkunPekerja * semuaAkunPekerja);

#endif // PROFILE_AKUN_PEKERJA_H_INCLUDED
