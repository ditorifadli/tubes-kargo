#include "kargo.h"

int main()
{
    Kargo K;
    adrParent a;
    adrChild b;
    paket p;
    armada q;

    buatListKargo(K);

    int choice;
    string tambah;
    string Back;

    while (true) {
        string username, password;
        judulKargo();
        cout <<"            LOGIN ADMIN KARGO META           " << endl;
        cout <<"-------------------------------------------------" << endl;
        cout << "Masukan Username: ";
        cin >> username;
        cout << "Masukan Password: ";
        cin >> password;

        if (username != "Admin" || password != "kargoMeta123") {
            cout << "\nLogin Tidak Berhasil." << endl;
        } else {
            system("cls");
            cout <<"\n\t\tLogin Berhasil.\n"<<endl;
            while (true){
                cout <<"-------------------------------------------------" << endl;
                cout <<"            PENGIRIMAN KARGO META           " << endl;
                cout <<"         Jalan Telekomunikasi No. 1,       " << endl;
                cout <<"              Terusan Buah Batu             " << endl;
                cout <<"-------------------------------------------------" << endl;
                cout << "Menu:" << endl;
                cout << "1.  Tampilkan Data Armada pengiriman" << endl;
                cout << "2.  Tambahkan Data Armada pengiriman" << endl;
                cout << "3.  Tambahkan Data Paket pengiriman" << endl;
                cout << "4.  Tampilkan Data Paket pengiriman" << endl;
                cout << "5.  Cari Paket menggunakan ID Paket" << endl;
                cout << "6.  Tampilkan Data pengiriman Kargo Meta" << endl;
                cout << "7.  Tampilkan Armada dengan Paket terbanyak" << endl;
                cout << "8.  Tampilkan Armada dengan Paket paling sedikit" << endl;
                cout << "9.  Hapus Armada pengiriman" << endl;
                cout << "10. Hapus Paket pengiriman" << endl;
                cout << "0.  Keluar" << endl;
                cout <<"-------------------------------------------------" << endl;
                cout << "Silahkan pilih, lalu enter: ";

                cin >> choice;
                if (cin.fail()) {
                    system("cls");
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "\n\t     Input tidak valid. \n  Masukan bilangan bulat untuk memilih menu.\n" << endl;
                    continue;
                }
                if (choice ==  1){
                    Back = "n";
                    system("cls");
                    while (Back!= "y"){
                        judulKargo();
                        cout <<"\tMenampilkan Data Armada Kargo Meta"<<endl;
                        cout <<"-------------------------------------------------" << endl;
                        showArmada(K);
                        cout <<"Jumlah Armada Kargo Meta : " << jumlahArmada(K) << endl;
                        cout <<"-------------------------------------------------" << endl;
                        cout << "Apakah ingin kembali ke Menu? (y/n): ";
                        cin>>Back;
                        system("cls");
                    }
                } else if (choice == 2){
                    tambah = "y";
                    system("cls");
                    while (tambah != "n"){
                        judulKargo();
                        cout <<"\tMenambahkan Data Armada Kargo Meta"<<endl;
                        cout <<"-------------------------------------------------" << endl;
                        string input;
                        cout << "Masukkan Jenis Armada\t: "; cin >> q.jenisArmada;
                        getline(cin, input);
                        cout << "Masukkan ID Armada\t: ";
                        getline(cin, input);
                        char *end;
                        long id = strtol(input.c_str(), &end, 10);
                        if (end == input.c_str()) {
                            cout << "\nInput tidak valid. Silakan masukkan bilangan \nbulat untuk ID Armada." << endl;
                        } else {
                            a = newNodeArmada(q.jenisArmada, id);
                            if (searchArmada(K, id) == NULL) {
                                tambahArmada(K, a);
                                cout << "\nArmada berhasil ditambahkan." << endl;
                            } else {
                                cout << "\nID sudah digunakan. \nArmada tidak berhasil ditambahkan." << endl;
                            }
                        }
                        cout <<"---------------------------------------------------" << endl;
                        cout <<"Apakah ingin menambahkan data Armada lagi? (y/n): ";
                        cin>>tambah;
                        system("cls");
                    }
                } else if (choice == 3){
                    tambah = "y";
                    system("cls");
                    while (tambah != "n"){
                        judulKargo();
                        cout <<"\tMenambahkan Data Paket Kargo Meta"<<endl;
                        cout <<"-------------------------------------------------" << endl;
                        cout <<"Berikut informasi Armada yang tersedia: "<<endl;
                        showArmadaForPaket(K);
                        cout <<"-------------------------------------------------" << endl;
                        string input;
                        cout << "Masukan Nama Paket\t: ";
                        cin >> p.namaPaket;
                        getline(cin, input);
                        cout << "Masukan ID Paket\t: ";
                        cin >> p.idPaket;
                        getline(cin, input);
                        cout << "Masukan Nama Pengirim\t: ";
                        cin >> p.namaPengirim;
                        getline(cin, input);
                        cout << "Masukan Alamat Pengirim\t: ";
                        cin >> p.alamatPengirim;
                        getline(cin, input);
                        cout << "Masukan Nama Penerima\t: ";
                        cin >> p.namaPenerima;
                        getline(cin, input);
                        cout << "Masukan Alamat Tujuan\t: ";
                        cin >> p.tujuan;
                        getline(cin, input);
                        cout << "Masukan Berat Paket(Kg)\t: ";
                        cin >> p.beratPaket;
                        cout << "Masukan Ongkir\t\t: Rp. ";
                        cin >> p.ongkir;
                        cout << endl;
                        cout << "Masukan ID Armada\t: ";
                        cin >> q.id;
                        getline(cin, input);
                        a = searchArmada(K, q.id);
                        if (a == NULL){
                            cout << "\nArmada tidak ada, paket tidak berhasil ditambahkan." << endl;
                        } else {
                            b = newNodePaket(p.namaPaket, p.idPaket, p.namaPengirim, p.alamatPengirim, p.namaPenerima, p.tujuan, p.beratPaket, p.ongkir);
                            if (searchPaket(K, p.idPaket) == NULL){
                                addRelation(K, a, b);
                                cout << "\nPaket Berhasil diTambahkan." << endl;
                            } else {
                                cout << "\nID paket sudah digunakan. \nPaket tidak berhasil ditambahkan." << endl;
                            }
                        }
                        cout <<"---------------------------------------------------" << endl;
                        cout <<"Apakah ingin menambahkan data Paket lagi? (y/n): ";
                        cin>>tambah;
                        system("cls");
                    }
                } else if (choice == 4){
                    Back = "n";
                    system("cls");
                    while (Back != "y"){
                        judulKargo();
                        cout <<"\tMenampilkan Data Paket Kargo Meta"<<endl;
                        cout <<"-------------------------------------------------" << endl;
                        showPaket(K);
                        cout << endl;
                        cout << "Jumlah Paket Pengiriman Kargo Meta : " << jumlahPaket(K) << endl;
                        cout <<"-------------------------------------------------" << endl;
                        cout << "Apakah ingin kembali ke Menu? (y/n): ";
                        cin>>Back;
                        system("cls");
                    }
                } else if (choice == 5){
                    string cari;
                    cari = "y";
                    system("cls");
                    while (cari != "n"){
                        judulKargo();
                        string idPaket;
                        cout << "Masukkan ID paket yang ingin dicari: ";
                        cin >> idPaket;
                        adrChild paket = searchPaket(K, idPaket);
                        cout << endl;
                        if (paket == NULL){
                            cout << "Paket tidak ditemukan." << endl;
                        } else {
                            cout << "Paket ditemukan, berikut data lengkapnya: " << endl;
                            cout << endl;
                            cout << "Nama paket\t: " << infoPaket(paket).namaPaket << endl;
                            cout << "ID paket\t: " << infoPaket(paket).idPaket << endl;
                            cout << "Nama pengirim\t: " << infoPaket(paket).namaPengirim << endl;
                            cout << "Alamat Pengirim\t: " << infoPaket(paket).alamatPengirim << endl;
                            cout << "Nama penerima\t: " << infoPaket(paket).namaPenerima << endl;
                            cout << "Alamat tujuan\t: " << infoPaket(paket).tujuan << endl;
                            cout << "Berat paket\t: " << infoPaket(paket).beratPaket << " Kg" << endl;
                            cout << "Ongkir\t\t: Rp. " << infoPaket(paket).ongkir << endl;
                        }
                        cout <<"---------------------------------------------------" << endl;
                        cout << "Apakah ingin mencari Paket yang lain? (y/n): ";
                        cin>>cari;
                        system("cls");
                    }
                } else if (choice == 6){
                    Back= "n";
                    system("cls");
                    while (Back != "y"){
                        judulKargo();
                        cout <<"Menampilkan semua Data pengiriman Kargo Meta"<<endl;
                        cout <<"-------------------------------------------------" << endl;
                        showData(K);
                        cout <<"-------------------------------------------------" << endl;
                        cout << "Apakah ingin kembali ke Menu? (y/n): ";
                        cin>>Back;
                        system("cls");
                    }
                } else if (choice == 7){
                    Back = "n";
                    system("cls");
                    while (Back != "y"){
                        judulKargo();
                        cout <<"  Menampilkan Data Armada dengan jumlah paket \n\t\t  terbanyak"<<endl;
                        cout <<"-------------------------------------------------" << endl;
                        mostPaketArmada(K);
                        cout <<"-------------------------------------------------" << endl;
                        cout << "Apakah ingin kembali ke Menu? (y/n): ";
                        cin>>Back;
                        system("cls");
                    }
                } else if (choice == 8){
                    Back = "n";
                    system("cls");
                    while (Back != "y"){
                        judulKargo();
                        cout <<"  Menampilkan Data Armada dengan jumlah paket \n\t\tpaling sedikit"<<endl;
                        cout <<"-------------------------------------------------" << endl;
                        leastPaketArmada(K);
                        cout <<"-------------------------------------------------" << endl;
                        cout << "Apakah ingin kembali ke Menu? (y/n): ";
                        cin>>Back;
                        system("cls");
                    }
                } else if (choice == 9){
                    system("cls");
                    if (First(K) == NULL){
                        Back = "n";
                        while (Back != "y"){
                            judulKargo();
                            cout << "Tidak ada Armada yang dapat dihapus." << endl;
                            cout <<"-------------------------------------------------" << endl;
                            cout << "Apakah ingin kembali ke Menu? (y/n): ";
                            cin >> Back;
                            system("cls");
                        }
                    } else {
                        tambah = "y";
                        while (tambah != "n"){
                            judulKargo();
                            cout <<"\tMenghapus Data Armada Kargo Meta"<<endl;
                            cout <<"-------------------------------------------------" << endl;
                            cout <<"Masukan ID Armada yang akan di hapus: ";
                            int id;
                            cin >> id;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout << "\nID tidak valid. Silakan masukkan bilangan \nbulat untuk ID Armada.\n" << endl;
                                cout <<"-------------------------------------------------" << endl;
                                continue;
                            }
                            cout << endl;
                            deleteArmada(K, id);
                            cout <<"---------------------------------------------------" << endl;
                            cout <<"Apakah ingin menghapus data Armada lagi? (y/n): ";
                            cin>>tambah;
                            system("cls");
                        }
                    }
                } else if (choice == 10){
                    system("cls");
                    if (First(K)==NULL){
                        Back = "n";
                        while (Back != "y"){
                            judulKargo();
                            cout << "Tidak ada Paket yang dapat dihapus." << endl;
                            cout <<"-------------------------------------------------" << endl;
                            cout << "Apakah ingin kembali ke Menu? (y/n): ";
                            cin >> Back;
                            system("cls");
                        }
                    } else {
                        tambah = "y";
                        while (tambah != "n"){
                            judulKargo();
                            cout <<"\tMenghapus Data Paket Kargo Meta"<<endl;
                            cout <<"-------------------------------------------------" << endl;
                            string input;
                            cout <<"Masukan Nama Paket : ";
                            getline(cin, input);
                            string namaPaket;
                            cin>>namaPaket;
                            cout <<"Masukan ID Paket   : ";
                            getline(cin, input);
                            string idPaket;
                            cin>>idPaket;
                            cout <<"Masukan ID Armada  : ";
                            getline(cin, input);
                            int id;
                            cin >> id;
                            cout << endl;
                            deletePaket(K, id, namaPaket, idPaket);
                            cout <<"---------------------------------------------------" << endl;
                            cout <<"Apakah ingin menghapus data Paket lagi? (y/n): ";
                            cin>>tambah;
                            system("cls");
                        }
                    }
                } else if (choice == 0){
                    cout <<"-------------------------------------------------" << endl;
                    cout << "Anda keluar dari program, terimakasih." << endl;
                    break;
                } else {
                    system("cls");
                    cout << endl;
                    cout << "\t\tMohon Maaf. \n\tPilihan tidak ada, coba lagi." << endl;
                    cout << endl;

                }
            }
            break;
        }
    }
    return 0;
}

