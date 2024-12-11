#include "ecommerce.h"
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk membuat list Toko
void createListToko(ListToko &LT) {
    first(LT) = nullptr;
}

// Fungsi untuk membuat list Pembeli
void createListPembeli(ListPembeli &LP) {
    first(LP) = nullptr;
}

// Fungsi untuk membuat list Transaksi
void createListTransaksi(ListTransaksi &LTR) {
    first(LTR) = nullptr;
}

// Fungsi untuk membuat elemen baru pada list Toko
adrToko createNewElmToko(infotypeToko data) {
    adrToko newToko = new ElemenToko;
    info(newToko) = data;
    next(newToko) = nullptr;
    prev(newToko) = nullptr;
    return newToko;
}

// Fungsi untuk membuat elemen baru pada list Pembeli
adrPembeli createNewElmPembeli(infotypePembeli data) {
    adrPembeli newPembeli = new ElemenPembeli;
    info(newPembeli) = data;
    next(newPembeli) = nullptr;
    return newPembeli;
}

// Fungsi untuk membuat elemen baru pada list Transaksi
adrTransaksi createNewElmTransaksi(adrToko detailToko, adrPembeli detailPembeli) {
    adrTransaksi newTransaksi = new ElemenTransaksi;
    newTransaksi->detailToko = detailToko;
    newTransaksi->detailPembeli = detailPembeli;
    next(newTransaksi) = nullptr;
    return newTransaksi;
}

// Menambahkan elemen baru di awal List Toko
void insertFirstToko(ListToko &LT, adrToko PT) {
    if (first(LT) == nullptr) {
        first(LT) = PT;
    } else {
        next(PT) = first(LT);
        prev(first(LT)) = PT;
        first(LT) = PT;
    }
}

// Menambahkan elemen baru di akhir List Toko
void insertLastToko(ListToko &LT, adrToko PT) {
    if (first(LT) == nullptr) {
        first(LT) = PT;
    } else {
        adrToko last = first(LT);
        while (next(last) != nullptr) {
            last = next(last);
        }
        next(last) = PT;
        prev(PT) = last;
    }
}

// Menghapus elemen Toko berdasarkan ID
void deleteToko(ListToko &LT, int Toko_ID) {
    adrToko P = searchToko(LT, Toko_ID);
    if (P != nullptr) {
        if (P == first(LT)) {
            first(LT) = next(P);
            if (first(LT) != nullptr) first(LT)->prev = nullptr;
        } else {
            prev(P)->next = next(P);
            if (next(P) != nullptr) next(P)->prev = prev(P);
        }
        delete P;
    }
}

// Mencari Toko berdasarkan ID
adrToko searchToko(ListToko &LT, int Toko_ID) {
    adrToko P = first(LT);
    while (P != nullptr && info(P).idToko != Toko_ID) {
        P = next(P);
    }
    return P;
}

// Menampilkan semua data Toko
void showToko(ListToko &LT) {
    adrToko P = first(LT);
    while (P != nullptr) {
        cout << "ID Toko: " << info(P).idToko << endl;
        cout << "Nama Toko: " << info(P).namaToko << endl;
        cout << "Jumlah Produk: " << info(P).jumlahProduk << endl;
        cout << "Total Penjualan: " << info(P).totalPenjualan << endl;
        cout << "------------------------" << endl;
        P = next(P);
    }
}

// Menambahkan elemen Pembeli di awal List Pembeli
void insertFirstPembeli(ListPembeli &LP, adrPembeli PP) {
    if (first(LP) == nullptr) {
        first(LP) = PP;
    } else {
        next(PP) = first(LP);
        first(LP) = PP;
    }
}

// Menambahkan elemen Pembeli di akhir List Pembeli
void insertLastPembeli(ListPembeli &LP, adrPembeli PP) {
    if (first(LP) == nullptr) {
        first(LP) = PP;
    } else {
        adrPembeli last = first(LP);
        while (next(last) != nullptr) {
            last = next(last);
        }
        next(last) = PP;
    }
}

// Menghapus elemen Pembeli berdasarkan ID
void deletePembeli(ListPembeli &LP, int Pembeli_ID) {
    adrPembeli P = searchPembeli(LP, Pembeli_ID);
    if (P != nullptr) {
        if (P == first(LP)) {
            first(LP) = next(P);
        } else {
            next(P) = next(P);
        }
        delete P;
    }
}

// Mencari Pembeli berdasarkan ID
adrPembeli searchPembeli(ListPembeli &LP, int Pembeli_ID) {
    adrPembeli P = first(LP);
    while (P != nullptr && info(P).idPembeli != Pembeli_ID) {
        P = next(P);
    }
    return P;
}

// Menambahkan Transaksi (Relasi Toko dan Pembeli)
void insertTransaksi(ListTransaksi &LTR, adrToko detailToko, adrPembeli detailPembeli) {
    adrTransaksi PT = createNewElmTransaksi(detailToko, detailPembeli);
    if (first(LTR) == nullptr) {
        first(LTR) = PT;
    } else {
        next(PT) = first(LTR);
        first(LTR) = PT;
    }
}

// Menghapus Transaksi berdasarkan ID Toko dan ID Pembeli
void deleteTransaksi(ListTransaksi &LTR, int Toko_ID, int Pembeli_ID) {
    adrTransaksi P = first(LTR);
    adrTransaksi prev = nullptr;
    while (P != nullptr && (P->detailToko->info.idToko != Toko_ID || P->detailPembeli->info.idPembeli != Pembeli_ID)) {
        prev = P;
        P = next(P);
    }
    if (P != nullptr) {
        if (prev == nullptr) {
            first(LTR) = next(P);
        } else {
            prev->next = next(P);
        }
        delete P;
    }
}

// Menampilkan seluruh data Transaksi
void showAllData(ListTransaksi &LTR) {
    adrTransaksi P = first(LTR);
    while (P != nullptr) {
        cout << "Toko ID: " << P->detailToko->info.idToko << " - " << P->detailToko->info.namaToko << endl;
        cout << "Pembeli ID: " << P->detailPembeli->info.idPembeli << " - " << P->detailPembeli->info.namaPembeli << endl;
        cout << "------------------------" << endl;
        P = next(P);
    }
}

// Menampilkan daftar Toko berdasarkan Pembeli tertentu
void showTokoByPembeli(ListTransaksi &LTR, int Pembeli_ID) {
    adrTransaksi P = first(LTR);
    while (P != nullptr) {
        if (P->detailPembeli->info.idPembeli == Pembeli_ID) {
            cout << "Toko ID: " << P->detailToko->info.idToko << " - " << P->detailToko->info.namaToko << endl;
        }
        P = next(P);
    }
}

// Menampilkan daftar Pembeli berdasarkan Toko tertentu
void showPembeliByToko(ListTransaksi &LTR, int Toko_ID) {
    adrTransaksi P = first(LTR);
    while (P != nullptr) {
        if (P->detailToko->info.idToko == Toko_ID) {
            cout << "Pembeli ID: " << P->detailPembeli->info.idPembeli << " - " << P->detailPembeli->info.namaPembeli << endl;
        }
        P = next(P);
    }
}

// Menghitung jumlah Pembeli pada Toko tertentu
int countPembeli(ListTransaksi &LTR, int Toko_ID) {
    int count = 0;
    adrTransaksi P = first(LTR);
    while (P != nullptr) {
        if (P->detailToko->info.idToko == Toko_ID) {
            count++;
        }
        P = next(P);
    }
    return count;
}

// Menghapus semua Pembeli yang terkait dengan Toko tertentu dan menghapus transaksi terkait
void deletePembeliByToko(ListPembeli &LP, ListTransaksi &LTR, int Toko_ID) {
    adrPembeli PP = first(LP);  // Mulai dari Pembeli pertama
    adrPembeli tempPembeli;

    // Loop untuk mencari Pembeli yang terkait dengan Toko tertentu
    while (PP != nullptr) {
        bool foundInTransaksi = false;
        adrTransaksi PT = first(LTR);

        // Cek apakah Pembeli ini ada dalam transaksi dengan Toko tertentu
        while (PT != nullptr) {
            if (PT->detailToko->info.idToko == Toko_ID && PT->detailPembeli->info.idPembeli == PP->info.idPembeli) {
                foundInTransaksi = true;
                break;  // Pembeli ditemukan dalam transaksi, berhenti mencari
            }
            PT = next(PT);
        }

        // Jika Pembeli ditemukan dalam transaksi dengan Toko tertentu, hapus Pembeli tersebut
        if (foundInTransaksi) {
            tempPembeli = PP;
            PP = next(PP);

            // Hapus Pembeli tersebut dari list Pembeli
            delete tempPembeli;

            // Hapus semua transaksi yang menghubungkan Toko ini dengan Pembeli tersebut
            deleteTransaksi(LTR, Toko_ID, PP->info.idPembeli);
        } else {
            PP = next(PP);  // Lanjutkan ke Pembeli berikutnya
        }
    }
}

