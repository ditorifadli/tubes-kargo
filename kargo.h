#ifndef KARGO_H_INCLUDED
#define KARGO_H_INCLUDED

#include <iostream>
#include <windows.h>
using namespace std;

#define infoArmada(p) (p)->infoArmada
#define child(p) (p)->child
#define next(p) (p)->next
#define infoPaket(p) (p)->infoPaket
#define nextPaket(p) (p)->nextPaket
#define First(Kargo) (Kargo).First

struct armada {
	string jenisArmada;
	int id;
};

struct paket {
    string namaPaket;
    string idPaket;
    string namaPengirim;
    string alamatPengirim;
	string namaPenerima;
	string tujuan;
	double beratPaket;
	double ongkir;
};

typedef struct nodeArmada *adrParent;
typedef struct nodePaket *adrChild;

struct nodeArmada {
	armada infoArmada;
	adrChild child;
	adrParent next;
};

struct nodePaket {
	paket infoPaket;
	adrChild nextPaket;
};

struct Kargo {
	adrParent First;
};

void buatListKargo(Kargo &K);
adrParent newNodeArmada(string jenisArmada, int id);
adrChild newNodePaket(string namaPaket, string idPaket, string namaPengirim, string alamatPengirim, string namaPenerima, string tujuan, double beratPaket, double ongkir);
void tambahArmada(Kargo &K, adrParent armada);
void addRelation(Kargo &K, adrParent armada, adrChild paket);
adrParent searchArmada(Kargo K, int id);
adrChild searchPaket(Kargo K, string idPaket);
void showArmada(Kargo K);
void showArmadaForPaket(Kargo K);
int jumlahArmada(Kargo K);
void showPaket(Kargo K);
int jumlahPaket(Kargo K);
void showData(Kargo K);
void mostPaketArmada(Kargo K);
void leastPaketArmada(Kargo K);
void deleteArmada(Kargo &K, int id);
void deletePaket(Kargo &K, int id, string namaPaket, string idPaket);
void judulKargo();

#endif // KARGO_H_INCLUDED
