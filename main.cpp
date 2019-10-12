#include <stdio.h>
#include <stdlib.h>
#include "realisasi.c"

int main(){
	Mhs Mhs1;
	addressMhs P;
	addressMatkul Q;
	char nama[35],nim[25],code[7],matkul[30],grade,tmp[7],setuju;
	int i,sks,x,pil,j;
	float uts,uas,quiz,total;
//algoritma
	system("color F0");
	createMhs(&Mhs1);
	tabel();
	batas(1,2,79,2,0,2);
	gotoxy(18,5);printf("SELAMAT DATANG DI SISTEM AKADEMIK INFORMATIKA");
	gotoxy(25,6);printf("Mahasiswa belum terdaftar...");
	gotoxy(18,7);printf("Mohon daftarkan Mahasiswa terlebih dahulu...");
	gotoxy(18,8);printf("Tekan Enter untuk Mendaftarkan Mahasiswa...");
	getch();
	clear();
	tabel();
	batas(1,2,79,2,0,2);
	tambah(&Mhs1);
	getch();
	//menu
	menu:
	clear();
	tabel();
	batas(1,2,79,2,0,2);
	gotoxy(2,3);printf("MAIN MENU");
	batas(1,4,79,4,0,4);
	gotoxy(2,6);printf("1. Tambah Data Mahasiswa");
	gotoxy(2,7);printf("2. Hapus Data Mahasiswa");
	gotoxy(2,8);printf("3. Cari Data Mahasiswa");
	gotoxy(2,9);printf("4. Lihat Data Mahasiswa");
	gotoxy(2,10);printf("5. Exit");
	gotoxy(2,11);printf("Pilihan : ");
	scanf("%i",&pil);
	fflush(stdin);
	switch(pil){
		case 1: clear();tambah(&Mhs1);break;
		case 2: goto hapus;break;
		case 3: goto cari;break;
		case 4: goto cetak;break;
		case 5: goto exit;break;
		default : printf("Pilihan Salah!");getch();goto menu;
	}
	cetak:
	clear();
	cetakMhs(Mhs1);
	if(first(Mhs1)!=nil){
		gotoxy(2,22);printf("1. Detail  2. Edit  3. Kembali : ");scanf("%i",&pil);fflush(stdin);
		switch(pil){
			case 1: clear();
					cetakMhs(Mhs1);
					gotoxy(2,22);printf("Masukkan NIM : ");
					gets(nim);
					fflush(stdin);
					P=searchNim(Mhs1,nim);
					clear();
					tabel();
					cetakDetail(Mhs1,P);
					gotoxy(2,21);printf("1. Kembali  2. Menu Utama : ");
					scanf("%i",&pil);
					fflush(stdin);
					switch(pil){
						case 1: goto cetak;break;
						case 2: goto menu;break;
						default: goto menu;
					}
			case 2: goto edit;break;
			case 3:goto menu;break;
			default: gotoxy(37,22);printf("Pilihan Salah! Silahkan coba kembali...");getch();goto cetak;				
		}
	}else{
		gotoxy(2,22);printf("Tekan Enter untuk ke Menu utama...");getch();goto menu;
	}
	edit:
	clear();
	tabel();
	batas(1,2,79,2,0,2);
	gotoxy(2,3);printf("EDIT DATA MAHASISWA");
	batas(1,4,79,4,0,4);
	gotoxy(2,5);printf("1. Edit Data Pribadi\n");
	gotoxy(2,6);printf("2. Edit Nilai Mahasiswa\n");
	gotoxy(2,7);printf("Pilihan : ");
	scanf("%i",&pil);fflush(stdin);
	switch(pil){
		case 1: editnama:
				batas(1,8,79,8,0,8);
				gotoxy(2,9);printf("Masukkan NIM yang akan diedit : ");gets(nim);fflush(stdin);
				P=searchNim(Mhs1,nim);
				batas(1,10,79,10,0,10);
				if(P!=nil){
					gotoxy(2,11);printf("Nama : %s",nama(P));
					gotoxy(2,12);printf("NIM : %s",nim(P));
					batas(1,13,79,13,0,13);
					gotoxy(2,14);printf("Nama Baru : ");gets(nama);fflush(stdin);
					gotoxy(2,15);printf("NIM Baru : ");gets(nim);fflush(stdin);
					batas(1,16,79,16,0,16);
					gotoxy(2,17);printf("Apakah Anda yakin akan mengganti");
					gotoxy(2,18);printf("Nama : %s	NIM : %s",nama(P),nim(P));
					gotoxy(2,19);printf("Dengan");
					gotoxy(2,20);printf("Nama : %s	NIM : %s",nama,nim);
					gotoxy(2,21);printf("Pilihan (y/t) : ");scanf("%c",&setuju);fflush(stdin);
					switch(setuju){
						case 'y':
						case 'Y':
							editMhs(&P,nama,nim);
							gotoxy(2,22);printf("Edit Data Personal berhasil! 1. Lihat Data 2. Menu : ");scanf("%i",&pil);fflush(stdin);
							switch(pil){
								case 1: goto cetak;break;
								case 2: goto menu;break;
							}
							break;
						case 't':
						case 'T':
							gotoxy(2,22);printf("Anda membatalkan pengeditan... Tekan Enter untuk kembali ke menu utama...");getch();goto menu;break;
					}
				}else{
					gotoxy(2,11);printf("NIM salah atau tidak ada! Silahkan coba kembali...");getch();goto editnama;
				}
				
		case 2: editnilai:
				batas(1,8,79,8,0,8);
				gotoxy(2,9);printf("Masukkan NIM yang akan diedit : ");gets(nim);fflush(stdin);
				batas(1,10,79,10,0,10);
				P=searchNim(Mhs1,nim);
				if(P!=nil){
					clear();
					gotoxy(10,3);printf("Nama : %s\n",nama(P));
					gotoxy(10,4);printf("NIM : %s\n",nim(P));
					tabel();
					batas(1,2,79,2,0,2);
					batas(1,7,79,7,0,7);
					batas(1,19,79,19,0,19);
					batas(1,5,79,5,0,5);
					tabeldetail();
					gotoxy(3,20);printf("Kode IF1111 = Struktur Data");
					gotoxy(3,21);printf("Kode IF1112 = Logika Matematika");
					gotoxy(3,22);printf("Kode IF1113 = Aljabar Linier");
					gotoxy(38,20);printf("Kode IF1114 = Organisasi Komputer\n");
					gotoxy(38,21);printf("Kode IF1115 = Teknologi Informasi\n");
					gotoxy(38,22);printf("Kode IF1116 = Pancasila");
					editNilai(&P);
				}else{
					gotoxy(2,11);printf("NIM salah atau tidak ada! Silahkan coba kembali...");getch();goto editnilai;
				}
	}
	cari:
	clear();
	tabel();
	batas(1,2,79,2,0,2);
	batas(1,4,79,4,0,4);
	gotoxy(2,3);printf("CARI DATA MAHASISWA");
	gotoxy(2,5);printf("1. Cari Berdasarkan NIM");
	gotoxy(2,6);printf("2. Cari Berdasarkan Nama");
	gotoxy(2,7);printf("Pilihan : ");
	scanf("%i",&pil);
	fflush(stdin);
	clear();
	switch(pil){
				case 1 :tabelcari();
				gotoxy(2,3);printf("CARI DATA MAHASISWA");
				gotoxy(2,5);printf("Masukkan NIM yang ingin dicari : ");
				gets(nim);
				fflush(stdin);
				P=searchNim(Mhs1,nim);
				if(P!=nil){
					adanim:
					gotoxy(2,5);printf("Mahasiswa yang dicari ada didalam database!");
					gotoxy(7,9);printf("%s",nim(P));
					gotoxy(25,9);printf("%s",nama(P));
					gotoxy(65,9);printf("%2.1f",IP(P));
					gotoxy(2,22);printf("1. Hapus 2. Edit 3. Menu : ");
					scanf("%i",&pil);fflush(stdin);
					switch(pil){
						case 1: goto hapus;break;
						case 2: goto edit;break;
						case 3: goto menu;break;
						default: gotoxy(35,22);printf("Pilihan Salah! Silahkan ulangi kembali...");getch();goto adanim;
					}
				}else{
					gaadanim:
					gotoxy(2,5);printf("Mahasiswa yang dicari tidak ada didalam database!");
					gotoxy(2,22);printf("1. Cari Lagi 2. Menu : ");
					scanf("%i",&pil);fflush(stdin);
					switch(pil){
						case 1: goto cari;break;
						case 2: goto menu;break;
						default: gotoxy(30,22);printf("Pilihan Salah! Silahkan ulangi kembali...");getch();goto gaadanim;
					}
				}
				getch();
				goto menu;
		case 2 :clear(); 
				tabelcari();
				gotoxy(2,3);printf("CARI DATA MAHASISWA");
				gotoxy(2,5);printf("Masukkan NAMA yang ingin dicari : ");
				gets(nama);
				fflush(stdin);
				P=searchNama(Mhs1,nama);
				if(P!=nil){
					adanama:
					gotoxy(2,5);printf("Mahasiswa yang dicari ada didalam database!");
					gotoxy(7,9);printf("%s",nim(P));
					gotoxy(25,9);printf("%s",nama(P));
					gotoxy(65,9);printf("%2.1f",IP(P));
					gotoxy(2,22);printf("1. Hapus 2. Edit 3. Menu : ");
					scanf("%i",&pil);fflush(stdin);
					switch(pil){
						case 1: goto hapus;break;
						case 2: goto edit;break;
						case 3: goto menu;break;
						default: gotoxy(35,22);printf("Pilihan Salah! Silahkan ulangi kembali...");getch();goto adanama;
					}
				}else{
					gaadanama:
					gotoxy(2,5);printf("Mahasiswa yang dicari tidak ada didalam database!");
					gotoxy(2,22);printf("1. Cari Lagi 2. Menu : ");
					scanf("%i",&pil);fflush(stdin);
					switch(pil){
						case 1: goto cari;break;
						case 2: goto menu;break;
						default: gotoxy(30,22);printf("Pilihan Salah! Silahkan ulangi kembali...");getch();goto gaadanama;
					}
				}
				getch();
				goto menu;
	}
	hapus:
	clear();
	tabel();
	batas(1,2,79,2,0,2);
	batas(1,6,79,6,0,6);
	batas(1,4,79,4,0,4);
	gotoxy(2,3);printf("HAPUS MAHASISWA");
	gotoxy(2,5);printf("Masukkan NIM yang ingin dihapus : ");
	gets(nim);
	fflush(stdin);
	P=searchNim(Mhs1,nim);
	if(P!=nil){
		gotoxy(2,7);printf("Nama : %s",nama(P));
		gotoxy(2,8);printf("NIM : %s",nim(P));
		batas(1,10,79,10,0,10);
		gotoxy(2,9);printf("Apakah anda yakin akan menghapus Mahasiswa tersebut? (y/t)");scanf("%c",&setuju);fflush(stdin);
		switch(setuju){
			case 'y':
			case 'Y':
				hapusMhs(&Mhs1,nim);
				gotoxy(2,11);printf("Mahasiswa berhasil dihapus!");
				gotoxy(2,12);printf("1. Kembali ke Menu utama");
				gotoxy(2,13);printf("2. Lihat Data Mahasiswa");
				gotoxy(2,14);printf("Pilihan : ");scanf("%i",&pil);fflush(stdin);
				switch(pil){
					case 1: goto menu;break;
					case 2: goto cetak;break;
					default:gotoxy(14,14);printf("Pilihan Salah! Anda akan dialihkan ke menu utama...");getch();goto menu;
				}
				break;
			case 't':
			case 'T':
				gotoxy(2,10);printf("Anda membatalkan penghapusan Mahasiswa...");
				gotoxy(2,11);printf("1. Hapus Lagi");
				gotoxy(2,12);printf("2. Menu");
				gotoxy(2,13);printf("Pilihan : ");scanf("%i",&pil);fflush(stdin);
				switch(pil){
					case 1: goto hapus;break;
					case 2: goto menu;break;
					default: gotoxy(2,14);printf("Pilihan salah! Anda akan dialihkan ke menu utama...");getch();goto menu;
				}
				break;
		}	
	}
	exit:
	tabel();
	batas(1,2,79,2,0,2);
	gotoxy(19,5);printf("TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI!");
	gotoxy(13,6);printf("PROGRAM INI DIBUAT UNTUK MEMENUHI TUGAS BESAR STRUKTUR DATA");
	gotoxy(26,10);printf("PROGRAM INI DIBUAT OLEH : ");
	gotoxy(20,11);printf("NADIA KURNIA 		3411151122");
	gotoxy(20,12);printf("IQBAL FAUZI MUCHLISIN 	3411151128");
	gotoxy(20,13);printf("HENDRI MUHAMAD HADINATA	3411151123");
	getch();
	return 0;
}
