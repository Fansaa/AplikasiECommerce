#include "ecommerce.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    ListToko LT;
    ListPembeli LP;
    ListTransaksi LTR;

    createListToko(LT);    // Membuat list Toko kosong
    createListPembeli(LP); // Membuat list Pembeli kosong
    createListTransaksi(LTR);  // Membuat list Transaksi kosong

    // Memasukkan data dummy
    isiDataDummy(LT, LP, LTR);

    int pilihan;
    int tokoID, pembeliID, jumlahBeli;
    string namaToko, namaPembeli;

    do {
        cout << "\nMenu Aplikasi E-Commerce:\n";
        cout << "1. Tambah Data Toko (Depan/Belakang)\n";
        cout << "2. Tampilkan Semua Data Toko\n";
        cout << "3. Hapus Data Toko dan Transaksi Terkait\n";
        cout << "4. Cari Data Toko\n";
        cout << "5. Cari Data Pembeli\n";
        cout << "6. Tambah Data Pembeli\n";
        cout << "7. Hubungkan Toko dengan Pembeli (Transaksi)\n";
        cout << "8. Tampilkan Semua Data Transaksi\n";
        cout << "9. Tampilkan Pembeli Berdasarkan Toko\n";
        cout << "10. Hapus Pembeli Berdasarkan Toko yang terkait\n";
        cout << "11. Hitung Jumlah Pembeli pada Toko Tertentu\n";
        cout << "12. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int pilihanToko;
                cout << "1. Tambah Toko di Depan\n";
                cout << "2. Tambah Toko di Belakang\n";
                cout << "Pilih: ";
                cin >> pilihanToko;

                if (pilihanToko == 1) {
                    cout << "Masukkan ID Toko: ";
                    cin >> tokoID;
                    cin.ignore();  // Menghapus karakter baris baru dari buffer input
                    cout << "Masukkan Nama Toko: ";
                    getline(cin, namaToko);
                    cout << "Masukkan Jumlah Produk: ";
                    cin >> jumlahBeli;

                    bool cek = isIDTokoExist(LT, tokoID);
                    if (cek == true) {
                        cout << endl;
                        cout << "ID sudah ada, tidak bisa menambahkan Toko" << endl;
                        break;
                    }

                    Toko toko = {tokoID, namaToko, jumlahBeli};
                    ElemenToko* P = createNewElmToko(toko);
                    insertFirstToko(LT, P);  // Masukkan di bagian depan
                } else if (pilihanToko == 2) {
                    cout << "Masukkan ID Toko: ";
                    cin >> tokoID;
                    cin.ignore();  // Menghapus karakter baris baru dari buffer input
                    cout << "Masukkan Nama Toko: ";
                    getline(cin, namaToko);
                    cout << "Masukkan Jumlah Produk: ";
                    cin >> jumlahBeli;

                    bool cek = isIDTokoExist(LT, tokoID);
                    if (cek == true) {
                        cout << endl;
                        cout << "ID sudah ada, tidak bisa menambahkan Toko" << endl;
                        break;
                    }

                    Toko toko = {tokoID, namaToko, jumlahBeli};
                    ElemenToko* P = createNewElmToko(toko);

                    insertLastToko(LT, P);  // Masukkan di bagian belakang
                } else {
                    cout << "Pilihan Tidak Valid" << endl;
                }
                break;
            }

            case 2: {
                showToko(LT); // Menampilkan seluruh data Toko
                break;
            }

            case 3: {
                cout << "Masukkan ID Toko yang ingin dihapus semua transaksi terkaitnya: ";
                cin >> tokoID;
                ElemenToko* P = searchToko(LT, tokoID);
                if (P != NULL) {
                    deleteTokoDanTransaksiTerkait(LT,LTR,tokoID);  // Menghapus Toko dan Transaksi terkait
                } else {
                    cout << "Toko tidak ditemukan.\n";
                }
                break;
            }

            case 4: {
                cout << "Masukkan ID Toko yang ingin dicari: ";
                cin >> tokoID;
                ElemenToko* P = searchToko(LT, tokoID);
                if (P != NULL) {
                    cout << "Toko Ditemukan: " << info(P).namaToko << endl;
                    cout << "ID Toko: " << info(P).idToko << endl;
                    cout << "Jumlah Produk: " << info(P).jumlahProduk << endl;
                }
                break;
            }

            case 5: {
                cout << "Masukkan ID Pembeli yang ingin dicari: ";
                cin >> pembeliID;
                ElemenPembeli* pembeli = searchPembeli(LP, pembeliID);
                if (pembeli != NULL) {
                    cout << "Pembeli Ditemukan: " << info(pembeli).namaPembeli << endl;
                    cout << "ID Pembeli: " << info(pembeli).idPembeli << endl;
                }
                break;
            }

            case 6: {
                cout << "Masukkan ID Pembeli: ";
                cin >> pembeliID;
                cin.ignore();  // Menghapus karakter baris baru dari buffer input
                cout << "Masukkan Nama Pembeli: ";
                getline(cin, namaPembeli);

                bool cek = isIDPembeliExist(LP, pembeliID);
                if (cek == true) {
                    cout << endl;
                    cout << "ID sudah ada, tidak bisa menambahkan Pembeli" << endl;
                    break;
                }

                Pembeli pembeli = {pembeliID, namaPembeli};
                ElemenPembeli* P = createNewElmPembeli(pembeli);
                insertLastPembeli(LP, P);  // Masukkan Pembeli di bagian belakang
                break;
            }

            case 7: {
                cout << "Masukkan ID Toko: ";
                cin >> tokoID;
                cout << "Masukkan ID Pembeli: ";
                cin >> pembeliID;

                ElemenToko* toko = searchToko(LT, tokoID);
                ElemenPembeli* pembeli = searchPembeli(LP, pembeliID);

                if (toko != NULL && pembeli != NULL) {
                    insertTransaksi(LTR, toko, pembeli); // Menghubungkan transaksi
                } else {
                    cout << "Transaksi tidak bisa dilakukan.\n";
                }
                break;
            }

            case 8: {
                showAllData(LTR); // Menampilkan seluruh data transaksi
                break;
            }

            case 9: {
                cout << "Masukkan ID Toko untuk melihat Pembeli: ";
                cin >> tokoID;
                bool cek = isIDTokoExist(LT, tokoID);
                if (cek == false) {
                    cout << endl;
                    cout << "ID tidak ditemukan, tidak bisa melihat daftar pembeli" << endl;
                    break;
                }
                showPembeliByToko(LTR, tokoID); // Menampilkan pembeli berdasarkan toko
                break;
            }

            case 10: {
                cout << "Masukkan ID Toko untuk menghapus pembeli: ";
                cin >> tokoID;
                bool cek = isIDTokoExist(LT, tokoID);
                if (cek == false) {
                    cout << endl;
                    cout << "ID tidak ditemukan, tidak bisa menghapus daftar pembeli yang terkait" << endl;
                    break;
                }
                deletePembeliByToko(LP, LTR, tokoID); // Menghapus pembeli berdasarkan toko
                break;
            }

            case 11: {
                cout << "Masukkan ID Toko untuk menghitung jumlah pembeli: ";
                cin >> tokoID;
                bool cek = isIDTokoExist(LT, tokoID);
                if (cek == false) {
                    cout << endl;
                    cout << "ID tidak ditemukan, tidak bisa menghitung jumlah pembeli" << endl;
                    break;
                }
                int count = countPembeli(LTR, tokoID); // Menghitung jumlah pembeli
                cout << "Jumlah pembeli pada Toko ID " << tokoID << ": " << count << endl;
                break;
            }

            case 12: {
                cout << "Keluar dari program.\n";
                break;
            }

            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 12);

    return 0;
}
