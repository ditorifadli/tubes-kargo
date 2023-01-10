#include "kargo.h"

void buatListKargo(Kargo &K){
    First(K) = NULL;
}
adrParent newNodeArmada(string jenisArmada, int id){
    adrParent p = new nodeArmada;
    infoArmada(p).jenisArmada = jenisArmada;
    infoArmada(p).id = id;
    child(p) = NULL;
    next(p) = NULL;
    return p;
}
adrChild newNodePaket(string namaPaket, string idPaket, string namaPengirim, string alamatPengirim, string namaPenerima, string tujuan, double beratPaket, double ongkir){
    adrChild p = new nodePaket;
    infoPaket(p).namaPaket = namaPaket;
    infoPaket(p).idPaket = idPaket;
    infoPaket(p).namaPengirim = namaPengirim;
    infoPaket(p).alamatPengirim = alamatPengirim;
    infoPaket(p).namaPenerima = namaPenerima;
    infoPaket(p).tujuan = tujuan;
    infoPaket(p).beratPaket = beratPaket;
    infoPaket(p).ongkir = ongkir;
    nextPaket(p) = NULL;
    return p;
}
adrParent searchArmada(Kargo K, int id){
    adrParent p = First(K);
    while (p != NULL && infoArmada(p).id != id){
        p = next(p);
    }
    return p;
}
adrChild searchPaket(Kargo K, string idPaket){
    adrParent p = First(K);
    while (p != NULL){
        adrChild q = child(p);
        while (q != NULL){
            if (infoPaket(q).idPaket == idPaket){
                return q;
            }
            q = nextPaket(q);
        }
        p = next(p);
    }
    return NULL;
}

void tambahArmada(Kargo &K, adrParent armada){
    if (First(K) == NULL){
        First(K) = armada;
    } else {
        next(armada) = First(K);
        First(K) = armada;
    }
}
void addRelation(Kargo &K, adrParent armada, adrChild paket){
    if (armada == NULL){
        cout << "Armada Tidak Tersedia." << endl;
    } else if (paket == NULL){
        cout << "Paket Tidak Tersedia." << endl;
    } else {
        if (child(armada) == NULL) {
            child(armada) = paket;
        } else {
            nextPaket(paket) = child(armada);
            child(armada) = paket;
        }
    }
}
void showArmada(Kargo K){
    adrParent p = First(K);
    bool ada = false;
    while (p != NULL){
        cout << "Jenis Armada\t: " << infoArmada(p).jenisArmada << endl;
        cout << "ID Armada\t: " <<infoArmada(p).id <<endl;
        cout << endl;
        p = next(p);
        ada = true;
    }
    if (!ada) {
        cout << "Armada Pengiriman tidak tersedia." << endl;
    }
}
void showArmadaForPaket(Kargo K){
    adrParent p = First(K);
    bool ada = false;
    while (p != NULL){
        cout << "Jenis Armada\t: " << infoArmada(p).jenisArmada << endl;
        cout << "ID Armada\t: " <<infoArmada(p).id <<endl;
        p = next(p);
        ada = true;
    }
    if (!ada) {
        cout << "Armada Pengiriman tidak tersedia." << endl;
    }
}
int jumlahArmada(Kargo K) {
    int count = 0;
    adrParent p = First(K);
    while (p != NULL) {
        count++;
        p = next(p);
    }
    return count;
}
void showPaket(Kargo K) {
    adrParent p = First(K);
    bool ada = false;
    while (p != NULL) {
        adrChild c = child(p);
        while (c != NULL) {
            cout << "Nama Paket\t: " << infoPaket(c).namaPaket << endl;
            cout << "ID Paket\t: " << infoPaket(c).idPaket << endl;
            cout << "Nama pengirim\t: " << infoPaket(c).namaPengirim << endl;
            cout << "Alamat Pengirim\t: " << infoPaket(c).alamatPengirim << endl;
            cout << "Nama penerima\t: " << infoPaket(c).namaPenerima << endl;
            cout << "Alamat Penerima\t: " << infoPaket(c).tujuan << endl;
            cout << "Berat paket\t: " << infoPaket(c).beratPaket << " Kg" << endl;
            cout << "Ongkir\t\t: Rp." << infoPaket(c).ongkir << endl << endl;
            c = nextPaket(c);
            ada = true;
        }
        p = next(p);
    }
    if (!ada) {
        cout << "Tidak ada Paket Pengiriman." << endl;
    }
}
int jumlahPaket(Kargo K) {
    int count = 0;
    adrParent p = First(K);
    while (p != NULL) {
        adrChild c = child(p);
        while (c != NULL) {
            count++;
            c = nextPaket(c);
        }
        p = next(p);
    }
    return count;
}
void showData(Kargo K) {
    adrParent p = First(K);
    if (p == NULL){
        cout << "Armada & Paket Pengiriman Tidak Tersedia." << endl;
    } else {
        while (p != NULL) {
            cout << "Jenis Armada\t: " << infoArmada(p).jenisArmada << "(" << infoArmada(p).id<<")"<< endl;
            adrChild q = child(p);
            if (q == NULL){
                cout << "Tidak ada paket di Armada ini.";

            } else {
                cout << "Nama Paket\t: ";
            }
            int count = 0;
            while (q != NULL) {
                cout <<infoPaket(q).namaPaket << "(" << infoPaket(q).idPaket<<")";
                q = nextPaket(q);
                count++;
                if ( q != NULL){
                    cout << ", ";
                } else {
                    cout <<". ";
                }
            }
            cout << endl << endl;
            p = next(p);

        }
    }
}
void mostPaketArmada(Kargo K){
    int maxPaket = 0;
    adrParent mostPaket = NULL;
    adrParent p = First(K);
    bool sama = false;
    while (p != NULL){
        int count = 0;
        adrChild q = child(p);
        while (q != NULL){
            count++;
            q = nextPaket(q);
        }
        if (count > maxPaket){
            maxPaket = count;
            mostPaket = p;
            sama = false;
        } else if (count == maxPaket){
            sama = true;
        }
        p = next(p);
    }
    if (mostPaket == NULL){
        cout << "Armada tidak memiliki Paket." << endl;
        return;
    }
    if (!sama){
        cout << infoArmada(mostPaket).jenisArmada << " (ID: " << infoArmada(mostPaket).id << ")";
        cout <<" dengan jumlah paket: "<< maxPaket << endl;
    } else {
        cout << "Tidak ada armada dengan paket terbanyak, \njumlah paket sama." << endl;
    }
}

void leastPaketArmada(Kargo K){
    int minPaket = INT_MAX;
    adrParent leastPaket = NULL;
    adrParent p = First(K);
    bool sama = false;
    while (p != NULL){
        int count = 0;
        adrChild q = child(p);
        while (q != NULL){
            count++;
            q = nextPaket(q);
        }
        if (count < minPaket){
            minPaket = count;
            leastPaket = p;
            sama = false;
        } else if (count == minPaket){
            sama = true;
        }
        p = next(p);
    }
    if (leastPaket == NULL){
        cout << "Armada tidak memiliki Paket." << endl;
        return;
    }
    if (!sama){
        cout << infoArmada(leastPaket).jenisArmada << " (ID: " << infoArmada(leastPaket).id << ")";
        cout <<" dengan jumlah paket: "<< minPaket << endl;
    } else {
        cout << "Tidak ada armada dengan paket paling sedikit, \njumlah paket sama." << endl;
    }
}
void deleteArmada(Kargo &K, int id) {
    if (First(K) == NULL) {
        cout << "Tidak ada Armada yang dapat dihapus." << endl;
    } else {
        adrParent p = First(K);
        adrParent q = NULL;
        while (p != NULL && infoArmada(p).id != id) {
            q = p;
            p = next(p);
        }
        if (p == NULL) {
            cout << "Armada dengan ID " << id << " tidak ditemukan." << endl;
        } else {
            if (q == NULL) {
                First(K) = next(p);
            } else {
                next(q) = next(p);
            }
            delete p;
            cout << "Armada dengan ID " << id << " berhasil dihapus." << endl;
        }
    }
}
void deletePaket(Kargo &K, int id, string namaPaket, string idPaket) {
    if (First(K) == NULL) {
        cout << "Tidak ada Paket yang dapat dihapus." << endl;
    } else {
        adrParent p = First(K);
        while (p != NULL && infoArmada(p).id != id) {
            p = next(p);
        }
        if (p == NULL) {
            cout << "Armada dengan ID " << id << " tidak ditemukan." << endl;
        } else {
            adrChild c = child(p);
            adrChild q = NULL;
            while (c != NULL && (infoPaket(c).namaPaket != namaPaket || infoPaket(c).idPaket != idPaket)) {
                q = c;
                c = nextPaket(c);
            }
            if (c == NULL) {
                cout << "Paket dengan Nama " << namaPaket << " dan ID Paket " << idPaket << " \ntidak ditemukan." << endl;
            } else {
                if (q == NULL) {
                    child(p) = nextPaket(c);
                } else {
                    nextPaket(q) = nextPaket(c);
                }
                delete c;
                cout << "Paket dengan Nama " << namaPaket << " dan ID Paket " << idPaket << " \nberhasil dihapus." << endl;
            }
        }
    }
}

void judulKargo(){
    cout <<"=================================================" << endl;
    cout <<"            PENGIRIMAN KARGO META           " << endl;
    cout <<"         Jalan Telekomunikasi No. 1,       " << endl;
    cout <<"              Terusan Buah Batu             " << endl;
    cout <<"=================================================" << endl;
}

