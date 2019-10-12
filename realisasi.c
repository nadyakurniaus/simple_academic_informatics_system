#include "header.h"

addressMhs alokasiMhs(char nama[35],char nim[25],float IP)
{
    addressMhs P;
    P=(addressMhs)malloc(sizeof(ElmMhs));
    strcpy(nama(P),nama);
	strcpy(nim(P),nim);
	IP(P)=IP;
    next(P)=nil;
    bawah(P)=nil;
    return P;
}

addressMatkul alokasiMatkul(char code[7],int sks,char mk[30],char grade, float uts, float uas, float quiz,float total)
{
    addressMatkul P;
    P=(addressMatkul)malloc(sizeof(ElmMatkul));
	strcpy(code(P),code);
    SKS(P)=sks;
    strcpy(MK(P),mk);
    grade(P)=grade;
    UTS(P)=uts;
    UAS(P)=uas;
    quiz(P)=quiz;
    nilai(P)=total;
	next(P)=nil;
    return P;
}

void createMhs(Mhs *M)
{
    first(*M)=nil;
}

void tambahMhs(Mhs *M,char nama[35],char nim[25],float IP)
{
	//kamus
	addressMhs Px,awal;
//Algoritma
	Px=alokasiMhs(nama,nim,IP);
	awal=first(*M);
	if(awal==nil){
		first(*M)=Px;
	}else{
		while(next(awal)!=nil){
			awal=next(awal);
		}
		next(awal)=Px;
	}
}

void cetakMhs(Mhs M)
{
    addressMhs awal;
    int i,j;
//Algoritma
	tabel();
	if(first(M)!=nil){
	batas(1,2,79,2,0,2);
	gotoxy(2,3);printf("DAFTAR MAHASISWA AKTIF");
	batas(1,4,79,4,0,4);
	gotoxy(10,5);printf("NIM\t\t\t    NAMA\t\t\t IPK");
	batas(1,6,79,6,0,6);
	for(i=1;i<=2;i++){
		for(j=1;j<=16;j++){
			gotoxy(23,4+j);printf("%c",186);
		}
	}
	for(i=1;i<=2;i++){
		for(j=1;j<=16;j++){
			gotoxy(53,4+j);printf("%c",186);
		}
	}
	gotoxy(23,4);printf("%c",203);
	gotoxy(53,4);printf("%c",203);
	gotoxy(23,6);printf("%c",206);
	gotoxy(53,6);printf("%c",206);
	batas(1,21,79,21,0,21);
	gotoxy(23,21);printf("%c",202);
	gotoxy(53,21);printf("%c",202);
	awal=first(M);
	i=0;
	while(awal!=nil){
		gotoxy(7,7+i);printf("%s",nim(awal));
		gotoxy(25,7+i);printf("%s",nama(awal));
		gotoxy(65,7+i);printf("%2.1f",IP(awal));
		awal=next(awal);
		i++;
	}
}else{
	batas(1,2,79,2,0,2);
	gotoxy(2,3);printf("TIDAK ADA MAHASISWA YANG TERDAFTAR!");
	batas(1,4,79,4,0,4);
}
}

void cetakDetail(Mhs M,addressMhs P){
	addressMatkul awal;
	tabeldetail();
	batas(1,2,79,2,0,2);
	batas(1,7,79,7,0,7);
	batas(1,19,79,19,0,19);
	batas(1,5,79,5,0,5);
	gotoxy(29,3);printf("Nama : %s",nama(P));
	gotoxy(29,4);printf("NIM  : %s",nim(P));
	gotoxy(33,16);printf("IPK Anda %2.1f",IP(P));
	awal=bawah(P);
	int i=1;
	while(awal!=nil){
		gotoxy(17,7+i);printf("%s",MK(awal));
		gotoxy(2,7+i);printf("%s",code(awal));
		gotoxy(41,7+i);printf("%i",SKS(awal));
		gotoxy(48,7+i);printf("%1.0f",UTS(awal));
		gotoxy(54,7+i);printf("%1.0f",UAS(awal));
		gotoxy(61,7+i);printf("%1.0f",quiz(awal));
		gotoxy(67,7+i);printf("%2.1f",nilai(awal));
		gotoxy(76,7+i);printf("%c",grade(awal));
		i++;
		awal=next(awal);
	}
}

addressMhs searchNim(Mhs M,char n[15]){
/* mengirim address yang bersangkutan jika Nim ditemukan pada List Mahasiswa,
	nil jika tidak ditemukan
*/
//Kamus
	boolean cari;
	addressMhs awal;
//Algoritma
	cari = false;
	awal=first(M);
		while(awal!=nil && !cari){
			if(strcmp(nim(awal),n)==0){ //strcmp untuk membandingkan string. 0 artinya sama
				cari = true;
			}else{
				awal=next(awal);		
			}
		}
	return awal;
}

void tambahMatkul(addressMhs *P,char code[7],int sks,char mk[30],char grade, float uts, float uas, float quiz,float total)
{
	//kamus
	addressMatkul Px,awal;
//Algoritma
	Px=alokasiMatkul(code,sks,mk,grade,uts,uas,quiz,total);
	awal=bawah(*P);
/*	if(awal==nil){
		bawah(*P)=Px;
	}else{
		while(next(awal)!=nil){
			awal=next(awal);
		}
		next(awal)=Px;
	}
*/
    if(bawah(*P)==nil){
        bawah(*P)=Px;
        next(Px)=nil;
    }else{
		while(next(awal)!=nil){
			awal=next(awal);
		}
		next(awal)=Px;
		next(Px)=nil;
        }
}

void tambah(Mhs *M){
	addressMhs P;
	addressMatkul Q;
	char nama[35],nim[15],code[7],matkul[30],grade;
	int sks,j,totsks,totmutu,mutu;
	float uts,uas,quiz,total,IP;
//algoritma
	tabeltambah();
	gotoxy(9,3);gets(nama);fflush(stdin);
	gotoxy(9,4);gets(nim);fflush(stdin);
	totsks=0;
	totmutu=0;
	tambahMhs(M,nama,nim,IP);
	for(j=1;j<=6;j++){
		gotoxy(2,7+j);gets(code);
		fflush(stdin);
		if(strcmp(code,"IF1111")==0){
			strcpy(matkul,"Struktur Data");
			sks=4;
			totsks=totsks+sks;
		}else{
			if(strcmp(code,"IF1112")==0){
				strcpy(matkul,"Logika Matematika");
				sks=2;
				totsks=totsks+sks;
			}else{
				if(strcmp(code,"IF1113")==0){
					strcpy(matkul,"Aljabar Linier");
					sks=2;
					totsks=totsks+sks;
				}else{
					if(strcmp(code,"IF1114")==0){
						strcpy(matkul,"Organisasi Komputer");
						sks=2;
						totsks=totsks+sks;
					}else{
						if(strcmp(code,"IF1115")==0){
							strcpy(matkul,"Teknologi Informasi");
							sks=2;
							totsks=totsks+sks;
						}else{
							if(strcmp(code,"IF1116")==0){
								strcpy(matkul,"Pancasila");
								sks=2;
								totsks=totsks+sks;
							}else{
								if(strcmp(code,"IF1117")==0){
									strcpy(matkul,"Bahasa Inggris");
									sks=2;
									totsks=totsks+sks;
								}
							}
						}
					}
				}
			}
		}
		gotoxy(17,7+j);printf("%s",matkul);
		gotoxy(41,7+j);printf("%i",sks);
		gotoxy(48,7+j);scanf("%f",&uts);fflush(stdin);
		gotoxy(54,7+j);scanf("%f",&uas);fflush(stdin);
		gotoxy(61,7+j);scanf("%f",&quiz);fflush(stdin);
		total=(uts*40/100)+(uas*40/100)+(quiz*20/100);
		if(total>89){
		grade='A';
		mutu=4;
		totmutu=totmutu+(mutu*sks);
		}else{
			if(total>69&&total<90){
				grade='B';
				mutu=3;
				totmutu=totmutu+(mutu*sks);
			}else{
				if(total>49&&total<70){
					grade='C';
					mutu=2;
					totmutu=totmutu+(mutu*sks);
				}else{
					if(total>29&&total<60){
						grade='D';
						mutu=1;
						totmutu=totmutu+(mutu*sks);
					}else{
						if(total>0&&total<30){
							grade='E';
							mutu=0;
							totmutu=totmutu+(mutu*sks);
						}
					}
				}
			}
		}
		gotoxy(67,7+j);printf("%2.1f",total);
		gotoxy(75,7+j);printf("%c",grade);
		P=searchNim(*M,nim);
		tambahMatkul(&P,code,sks,matkul,grade,uts,uas,quiz,total);
 }
	IP(P)=totmutu/totsks;
	gotoxy(33,16);printf("IPK Anda %2.1f",IP(P));
	gotoxy(6,18);printf("Mahasiswa Berhasil didaftarkan! Tekan Enter untuk menuju menu utama...");
}

addressMhs searchNama(Mhs M,char n[35]){
/* mengirim address yang bersangkutan jika Nama ditemukan pada List Mahasiswa,
	nil jika tidak ditemukan
*/
//Kamus
	boolean cari;
	addressMhs awal;
//Algoritma
	cari = false;
	awal=first(M);
		while(awal!=nil && !cari){
			if(strcmp(nama(awal),n)==0){ //strcmp untuk membandingkan string. 0 artinya sama
				cari = true;
			}else{
				awal=next(awal);		
			}
		}
	return awal;
}

void deAlokasiMhs(addressMhs P){
	free(P);
}

void deAlokasiMatkul(addressMatkul P){
	free(P);
}

void hapusMhs(Mhs *M,char n[25]){
/*	awal=bawah(P);
	deAlokasiMhs(P);
	while(awal!=nil){
		deAlokasiMatkul(awal);
		awal=next(awal);
	}
*/	
	addressMhs awal;
    addressMhs prev;
    addressMatkul awalMatkul;
    addressMatkul tmp;
    boolean ketemu;
//algoritma
    awal=first(*M);
    prev=nil;
	ketemu=false;
	while(awal!=nil && !ketemu){
		if(strcmp(nim(awal),n)==0){
			ketemu=true;
		}else{
			prev=awal;
			awal=next(awal);
		}
	}
	if(ketemu){
		if(awal==first(*M)){
			awalMatkul=bawah(awal);
			deAlokasiMhs(awal);
			first(*M)=next(awal);
			while(awalMatkul!=nil){
				tmp=awalMatkul;
				awalMatkul=next(awalMatkul);
				deAlokasiMatkul(tmp);
			}
		}else{
			next(prev)=next(awal);
			awalMatkul=bawah(awal);
			deAlokasiMhs(awal);
			while(awalMatkul!=nil){
				tmp=awalMatkul;
				awalMatkul=next(awalMatkul);
				deAlokasiMatkul(tmp);
			}
		}
	}
}
void gotoxy(int x,int y){
//kamus
	COORD coord;
//algoritma
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tabel()
{
	int i,j;
	gotoxy(25,1);
	printf("SISTEM AKADEMIK INFORMATIKA");
	gotoxy(1,0);
	for(i=1;i<=78;i++){
		printf("%c",205);
	}
	gotoxy(0,0);printf("%c",201);
	for(i=1;i<=50;i++){
		for(j=1;j<=22;j++){
			gotoxy(0,0+j);printf("%c",186);
		}
	}
	gotoxy(1,23);
	for(i=1;i<=78;i++){
		printf("%c",205);
	}
	gotoxy(0,23);printf("%c",200);
	gotoxy(79,0);printf("%c",187);
	gotoxy(79,23);printf("%c",188);
	for(i=1;i<=50;i++){
		for(j=1;j<=22;j++){
			gotoxy(79,0+j);printf("%c",186);
		}
	}
	gotoxy(27,24);printf("Copyright Informatika 2015");
}

void batas(int garis1,int garis2,int kanan1,int kanan2,int kiri1,int kiri2)
{
	int i;
	gotoxy(kiri1,kiri2);printf("%c",204);  //siku kiri 0,2
	gotoxy(garis1,garis2); //garis 1,2
	for(i=1;i<=78;i++){
		printf("%c",205);
	}
	gotoxy(kanan1,kanan2);printf("%c",185); //siku kanan 79,2
}

void tabeltambah(){
	int i,j;
	tabel();
	
	batas(1,2,79,2,0,2);
	batas(1,7,79,7,0,7);
	batas(1,19,79,19,0,19);
	batas(1,5,79,5,0,5);
	gotoxy(2,3);printf("Nama : ");
		gotoxy(2,4);printf("NIM  : ");
	
		tabeldetail();
		gotoxy(3,20);printf("Kode IF1111 = Struktur Data");
		gotoxy(3,21);printf("Kode IF1112 = Logika Matematika");
		gotoxy(3,22);printf("Kode IF1113 = Aljabar Linier");
		gotoxy(38,20);printf("Kode IF1114 = Organisasi Komputer\n");
		gotoxy(38,21);printf("Kode IF1115 = Teknologi Informasi\n");
		gotoxy(38,22);printf("Kode IF1116 = Pancasila");
}

void tabeldetail(){
	int i,j;
		for(i=1;i<=2;i++){
		for(j=1;j<=9;j++){
			gotoxy(15,4+j);printf("%c",186);
		}
	}
	gotoxy(15,5);printf("%c",203);
	gotoxy(15,7);printf("%c",206);
		for(i=1;i<=2;i++){
			for(j=1;j<=9;j++){
				gotoxy(38,4+j);printf("%c",186);
			}
		}
		gotoxy(38,5);printf("%c",203);
		gotoxy(38,7);printf("%c",206);
		for(i=1;i<=2;i++){
			for(j=1;j<=9;j++){
				gotoxy(45,4+j);printf("%c",186);
			}
		}
		gotoxy(45,5);printf("%c",203);
		gotoxy(45,7);printf("%c",206);
		for(i=1;i<=2;i++){
			for(j=1;j<=9;j++){
				gotoxy(58,4+j);printf("%c",186);
			}
		}
		gotoxy(58,5);printf("%c",203);
		gotoxy(58,7);printf("%c",206);
		for(i=1;i<=2;i++){
			for(j=1;j<=9;j++){
				gotoxy(51,4+j);printf("%c",186);
			}
		}
		gotoxy(51,5);printf("%c",203);
		gotoxy(51,7);printf("%c",206);
		for(i=1;i<=2;i++){
			for(j=1;j<=9;j++){
				gotoxy(64,4+j);printf("%c",186);
			}
		}
		gotoxy(64,5);printf("%c",203);
		gotoxy(64,7);printf("%c",206);
		for(i=1;i<=2;i++){
			for(j=1;j<=9;j++){
				gotoxy(72,4+j);printf("%c",186);
			}
		}
		gotoxy(72,5);printf("%c",203);
		gotoxy(72,7);printf("%c",206);
		gotoxy(2,6);printf("Kode Matkul");
		gotoxy(20,6);printf("Mata Kuliah");
		gotoxy(40,6);printf("SKS");
		gotoxy(47,6);printf("UTS");
		gotoxy(53,6);printf("UAS");
		gotoxy(60,6);printf("Quiz");
		gotoxy(66,6);printf("Total");
		gotoxy(74,6);printf("Grade");
		batas(1,14,79,14,0,14);
		gotoxy(15,14);printf("%c",202);
		gotoxy(38,14);printf("%c",202);
		gotoxy(45,14);printf("%c",202);
		gotoxy(51,14);printf("%c",202);
		gotoxy(58,14);printf("%c",202);
		gotoxy(64,14);printf("%c",202);
		gotoxy(72,14);printf("%c",202);
		gotoxy(33,15);
		for(i=1;i<=12;i++){
			printf("%c",205);
		}
		gotoxy(45,15);printf("%c",187);
		gotoxy(32,15);printf("%c",201);
		gotoxy(33,17);
		for(i=1;i<=12;i++){
			printf("%c",205);
		}
		gotoxy(45,17);printf("%c",188);
		gotoxy(32,17);printf("%c",200);
		gotoxy(45,16);printf("%c",186);
		gotoxy(32,16);printf("%c",186);
}

void tabelcari(){
	int i,j;
	tabel();
	batas(1,2,79,2,0,2);
	batas(1,4,79,4,0,4);
	batas(1,6,79,6,0,6);
	gotoxy(10,7);printf("NIM\t\t\t    NAMA\t\t\t IPK");
	for(i=1;i<=14;i++){
		gotoxy(23,6+i);printf("%c",186);
	}
	for(i=1;i<=14;i++){
		gotoxy(53,6+i);printf("%c",186);
	}
	batas(1,8,79,8,0,8);
	batas(1,21,79,21,0,21);
	gotoxy(23,6);printf("%c",203);
	gotoxy(53,6);printf("%c",203);
	gotoxy(23,8);printf("%c",206);
	gotoxy(53,8);printf("%c",206);
	gotoxy(23,21);printf("%c",202);
	gotoxy(53,21);printf("%c",202);
}

void editMhs(addressMhs *P,char nama[35],char nim[25]){
//kamus
//algoritma
	strcpy(nama(*P),nama);
	strcpy(nim(*P),nim);
}

void editNilai(addressMhs *P){
//kamus
	addressMatkul awal;
	int j,totsks,mutu,totmutu;
	totsks=0;
	totmutu=0;
//algoritma
	awal=bawah(*P);
	j=1;
	while(awal!=nil){
		gotoxy(2,7+j);gets(code(awal));
		fflush(stdin);
		if(strcmp(code(awal),"IF1111")==0){
			strcpy(MK(awal),"Struktur Data");
			SKS(awal)=4;
			totsks=totsks+SKS(awal);
		}else{
			if(strcmp(code(awal),"IF1112")==0){
				strcpy(MK(awal),"Logika Matematika");
				SKS(awal)=2;
				totsks=totsks+SKS(awal);
			}else{
				if(strcmp(code(awal),"IF1113")==0){
					strcpy(MK(awal),"Aljabar Linier");
					SKS(awal)=2;
					totsks=totsks+SKS(awal);
				}else{
					if(strcmp(code(awal),"IF1114")==0){
						strcpy(MK(awal),"Organisasi Komputer");
						SKS(awal)=2;
						totsks=totsks+SKS(awal);
					}else{
						if(strcmp(code(awal),"IF1115")==0){
							strcpy(MK(awal),"Teknologi Informasi");
							SKS(awal)=2;
							totsks=totsks+SKS(awal);
						}else{
							if(strcmp(code(awal),"IF1116")==0){
								strcpy(MK(awal),"Pancasila");
								SKS(awal)=2;
								totsks=totsks+SKS(awal);
							}else{
								if(strcmp(code(awal),"IF1117")==0){
									strcpy(MK(awal),"Bahasa Inggris");
									SKS(awal)=2;
									totsks=totsks+SKS(awal);
								}
							}
						}
					}
				}
			}
		}
		gotoxy(17,7+j);printf("%s",MK(awal));
		gotoxy(41,7+j);printf("%i",SKS(awal));
		gotoxy(48,7+j);scanf("%f",&UTS(awal));fflush(stdin);
		gotoxy(54,7+j);scanf("%f",&UAS(awal));fflush(stdin);
		gotoxy(61,7+j);scanf("%f",&quiz(awal));fflush(stdin);
		nilai(awal)=(UTS(awal)*40/100)+(UAS(awal)*40/100)+(quiz(awal)*20/100);
		if(nilai(awal)>89){
		grade(awal)='A';
		mutu=4;
		totmutu=totmutu+(mutu*SKS(awal));
		}else{
			if(nilai(awal)>69&&nilai(awal)<90){
				grade(awal)='B';
				mutu=3;
				totmutu=totmutu+(mutu*SKS(awal));
			}else{
				if(nilai(awal)>49&&nilai(awal)<70){
					grade(awal)='C';
					mutu=2;
					totmutu=totmutu+(mutu*SKS(awal));
				}else{
					if(nilai(awal)>29&&nilai(awal)<60){
						grade(awal)='D';
						mutu=1;
						totmutu=totmutu+(mutu*SKS(awal));
					}else{
						if(nilai(awal)>0&&nilai(awal)<30){
							grade(awal)='E';
							mutu=0;
							totmutu=totmutu+(mutu*SKS(awal));
						}
					}
				}
			}
		}
		gotoxy(67,7+j);printf("%2.1f",nilai(awal));
		gotoxy(75,7+j);printf("%c",grade(awal));
		j++;
		awal=next(awal);
 	}
	IP(*P)=totmutu/totsks;
}
