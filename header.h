#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "boolean.h"
#define nil NULL
#define nama(P) (P)->nama
#define nim(P) (P)->nim
#define code(P) (P)->code
#define SKS(P) (P)->SKS
#define MK(P) (P)->MK
#define UTS(P) (P)->UTS
#define UAS(P) (P)->UAS
#define quiz(P) (P)->quiz
#define nilai(P) (P)->nilai
#define grade(P) (P)->grade
#define IP(P) (P)->IP
#define next(p) (p)->next
#define bawah(p) (p)->bawah
#define first(L) ((L).first)

typedef struct Mahasiswa *addressMhs;
typedef struct Matkul *addressMatkul;

typedef struct Mahasiswa
{
    char nama[35];
    char nim[25];
	float IP;
    addressMhs next;
	addressMatkul bawah;
}ElmMhs;

typedef struct Matkul
{
	char code[7];
	int SKS;
	char MK[30];
	char grade;
	float UTS;
	float UAS;
	float quiz;
	float nilai;
    addressMatkul next;
}ElmMatkul;

typedef struct
{
    addressMhs first;
}Mhs;

void clear(){
	system("cls");
}

addressMhs alokasiMhs(char nama[35],char nim[25],float IP);
addressMatkul alokasiMatkul(char code[7],int sks,char mk[30],char grade, float UTS, float UAS, float quiz,float total);
void createMhs(Mhs *M);
void tambahMhs(Mhs *M,char nama[35],char nim[25],float IP);
void cetakMhs(Mhs M);
void cetakDetail(Mhs M,addressMhs P);
void nilaiTotal(Mhs M,addressMhs P);
void tambah(Mhs *M);
addressMhs searchNama(Mhs M,char n[35]);
addressMhs searchNim(Mhs M,char n[15]);
void tambahMatkul(addressMhs *M,char code[7],int sks,char mk[30],char grade, float UTS, float UAS, float quiz,float total);
void hapusMhs(Mhs *M,char n[35]);
void deAlokasiMhs(addressMhs P);
void deAlokasiMatkul(addressMatkul P);
void batas(int garis1,int garis2,int kanan1,int kanan2,int kiri1,int kiri2);
void tabel();
void gotoxy(int x,int y);
void tabeltambah();
void tabeldetail();
void tabelcari();
void editMhs(addressMhs *P,char nama[35],char nim[25]);
void editNilai(addressMhs *P);
