#include "ecommerce.h"
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk membuat list Toko
void createListToko(ListToko &LT) {
    first(LT) = nullptr;
    last(LT) = nullptr;
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
    detailToko(newTransaksi) = detailToko;
    detailPembeli(newTransaksi) = detailPembeli;
    next(newTransaksi) = nullptr;
    return newTransaksi;
}

// Fungsi untuk mengecek apakah ID sudah ada di dalam List Toko
bool isIDTokoExist(ListToko LT, int id) {
    adrToko temp = first(LT);
    while (temp != nullptr) {
        if (info(temp).idToko == id) {
            return true;
        }
        temp = next(temp);
    }
    return false;
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
    cout << "Berhasil menambahkan Toko " << info(PT).namaToko << " (ID: " << info(PT).idToko << ") di awal list" << endl;
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
    cout << "Berhasil menambahkan Toko " << info(PT).namaToko << " (ID: " << info(PT).idToko << ") di akhir list" << endl;
}

// Mencari Toko berdasarkan ID
adrToko searchToko(ListToko &LT, int Toko_ID) {
    adrToko P = first(LT);
    while (P != nullptr && info(P).idToko != Toko_ID) {
        P = next(P);
    }
    if (P == nullptr) {
        cout << "Toko dengan ID " << Toko_ID << " tidak ditemukan." << endl;
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
        cout << "------------------------" << endl;
        P = next(P);
    }
}

// Fungsi untuk mengecek apakah ID sudah ada di dalam List Pembeli
bool isIDPembeliExist(ListPembeli LP, int id) {
    adrPembeli temp = first(LP);
    while (temp != nullptr) {
        if (info(temp).idPembeli == id) {
            return true;
        }
        temp = next(temp);
    }
    return false;
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
    cout << "Berhasil menambahkan Pembeli " << info(PP).namaPembeli << " (ID: " << info(PP).idPembeli << ") di akhir list" << endl;
}

// Mencari Pembeli berdasarkan ID
adrPembeli searchPembeli(ListPembeli &LP, int Pembeli_ID) {
    adrPembeli P = first(LP);
    while (P != nullptr && info(P).idPembeli != Pembeli_ID) {
        P = next(P);
    }
    if (P == nullptr) {
        cout << "Pembeli dengan ID " << Pembeli_ID << " tidak ditemukan." << endl;
    }
    return P;
}

// Menambahkan Transaksi (Relasi Toko dan Pembeli)
void insertTransaksi(ListTransaksi &LTR, adrToko detailToko, adrPembeli detailPembeli) {
    adrTransaksi PT = createNewElmTransaksi(detailToko, detailPembeli);

    // Jika list kosong, elemen pertama dan terakhir adalah PT
    if (first(LTR) == nullptr) {
        first(LTR) = PT;
    } else {
        // Mencari elemen terakhir dalam list
        adrTransaksi last = first(LTR);
        while (next(last) != nullptr) {
            last = next(last);
        }
        // Menyisipkan elemen PT di akhir list
        next(last) = PT;
    }

    cout << "Berhasil menambahkan Transaksi antara Toko " << info(detailToko).namaToko
         << " (ID: " << info(detailToko).idToko << ") dan Pembeli "
         << info(detailPembeli).namaPembeli << " (ID: " << info(detailPembeli).idPembeli << ")" << endl;
}

// Menampilkan seluruh data Transaksi
void showAllData(ListTransaksi &LTR) {
    if (first(LTR) == nullptr) {
        cout << "\n=== DATA TRANSAKSI ===" << endl;
        cout << "List Transaksi masih kosong" << endl;
        cout << "===================" << endl;
        return;
    }

    cout << "\n=== DATA TRANSAKSI ===" << endl;
    int count = 0;
    adrTransaksi P = first(LTR);
    while (P != nullptr) {
        count++;
        cout << "\nTransaksi ke-" << count << endl;
        cout << "Toko       : " << info(detailToko(P)).namaToko << " (ID: " << info(detailToko(P)).idToko << ")" << endl;
        cout << "Pembeli    : " << info(detailPembeli(P)).namaPembeli << " (ID: " << info(detailPembeli(P)).idPembeli << ")" << endl;
        cout << "------------------------" << endl;
        P = next(P);
    }
    cout << "\nTotal Transaksi: " << count << endl;
    cout << "===================" << endl;
}

// Menampilkan daftar Pembeli berdasarkan Toko tertentu
void showPembeliByToko(ListTransaksi &LTR, int Toko_ID) {
    if (first(LTR) == nullptr) {
        cout << "\n=== DAFTAR PEMBELI TOKO ID " << Toko_ID << " ===" << endl;
        cout << "List Transaksi masih kosong" << endl;
        cout << "===================" << endl;
        return;
    }

    bool found = false;
    int count = 0;
    string namaToko = "";

    // Mencari nama toko untuk header
    adrTransaksi temp = first(LTR);
    while (temp != nullptr) {
        if (info(detailToko(temp)).idToko == Toko_ID) {
            namaToko = info(detailToko(temp)).namaToko;
            break;
        }
        temp = next(temp);
    }

    cout << "\n=== DAFTAR PEMBELI TOKO ";
    if (namaToko != "") {
        cout << namaToko << " (ID: " << Toko_ID << ")";
    } else {
        cout << "ID " << Toko_ID;
    }
    cout << " ===" << endl;

    adrTransaksi P = first(LTR);
    while (P != nullptr) {
        if (info(detailToko(P)).idToko == Toko_ID) {
            found = true;
            count++;
            cout << count << ". " << info(detailPembeli(P)).namaPembeli
                 << " (ID: " << info(detailPembeli(P)).idPembeli << ")" << endl;
        }
        P = next(P);
    }

    if (!found) {
        cout << "Tidak ada pembeli yang ditemukan untuk Toko ini" << endl;
    } else {
        cout << "\nTotal Pembeli: " << count << endl;
    }
    cout << "===================" << endl;
}

// Menghitung jumlah Pembeli pada Toko tertentu
int countPembeli(ListTransaksi &LTR, int Toko_ID) {
    int count = 0;
    adrTransaksi P = first(LTR);
    while (P != nullptr) {
        if (info(detailToko(P)).idToko == Toko_ID) {
            count++;
        }
        P = next(P);
    }
    return count;
}

// Fungsi untuk menghapus semua pembeli yang terkait dengan toko tertentu
void deletePembeliByToko(ListPembeli &LP, ListTransaksi &LTR, int Toko_ID) {
    // Jika list pembeli atau list transaksi kosong, tampilkan pesan dan keluar dari fungsi
    if (first(LP) == nullptr || first(LTR) == nullptr) {
        cout << "List Pembeli atau Transaksi kosong." << endl;
        return;
    }

    // Hapus hanya transaksi yang terkait dengan Toko_ID
    adrTransaksi P = first(LTR);  // Pointer untuk iterasi list transaksi
    adrTransaksi sebelum = nullptr; // Pointer untuk menyimpan elemen sebelumnya
    bool found = false; // Penanda apakah transaksi terkait ditemukan

    // Iterasi melalui list transaksi
    while (P != nullptr) {
        adrTransaksi setelah = next(P); // Simpan elemen berikutnya untuk iterasi
        // Jika transaksi terkait dengan Toko_ID
        if (info(detailToko(P)).idToko == Toko_ID) {
            found = true; // Tandai bahwa transaksi ditemukan
            if (sebelum == nullptr) {
                // Jika transaksi yang dihapus adalah elemen pertama
                first(LTR) = setelah;
            } else {
                // Jika bukan elemen pertama
                next(sebelum) = setelah;
            }
            delete P; // Hapus elemen transaksi dari memori
        } else {
            sebelum = P; // Update pointer 'sebelum' untuk iterasi berikutnya
        }
        P = setelah; // Lanjutkan iterasi ke elemen berikutnya
    }

    // Tampilkan pesan keberhasilan atau jika tidak ditemukan transaksi
    if (found) {
        cout << "Berhasil menghapus transaksi yang terkait dengan Toko ID " << Toko_ID << endl;
    } else {
        cout << "Tidak ditemukan transaksi yang terkait dengan Toko ID " << Toko_ID << endl;
    }
}


// Fungsi untuk menghapus toko dan semua transaksi yang terkait dengan toko tersebut
void deleteTokoDanTransaksiTerkait(ListToko &LT, ListTransaksi &LTR, int Toko_ID) {
    // Jika list toko kosong, tampilkan pesan dan keluar dari fungsi
    if (first(LT) == nullptr) {
        cout << "List Toko kosong" << endl;
        return;
    }

    // Mencari toko yang akan dihapus berdasarkan Toko_ID
    adrToko tokoToDelete = searchToko(LT, Toko_ID);
    // Jika toko tidak ditemukan, keluar dari fungsi
    if (tokoToDelete == nullptr) {
        return; // Toko tidak ditemukan, pesan error sudah ditampilkan di searchToko
    }

    // Menghapus semua transaksi yang terkait dengan Toko_ID
    adrTransaksi P = first(LTR);  // Pointer untuk iterasi list transaksi
    adrTransaksi sebelum = nullptr; // Pointer untuk menyimpan elemen sebelumnya
    bool foundTransaksi = false; // Penanda apakah ada transaksi yang ditemukan

    // Iterasi melalui list transaksi
    while (P != nullptr) {
        adrTransaksi setelah = next(P); // Simpan elemen berikutnya
        // Jika transaksi terkait dengan Toko_ID
        if (info(detailToko(P)).idToko == Toko_ID) {
            foundTransaksi = true; // Tandai bahwa transaksi ditemukan
            if (sebelum == nullptr) {
                // Jika transaksi yang dihapus adalah elemen pertama
                first(LTR) = setelah;
            } else {
                // Jika bukan elemen pertama
                next(sebelum) = setelah;
            }
            delete P; // Hapus elemen transaksi
        } else {
            sebelum = P; // Update pointer 'sebelum' untuk iterasi berikutnya
        }
        P = setelah; // Lanjutkan iterasi ke elemen berikutnya
    }

    // Menghapus toko dari list toko
    if (tokoToDelete == first(LT)) {
        // Jika toko yang dihapus adalah elemen pertama
        first(LT) = next(tokoToDelete);
        if (first(LT) != nullptr) {
            // Update pointer prev elemen pertama jika ada
            prev(first(LT)) = nullptr;
        }
    } else {
        // Jika toko bukan elemen pertama
        next(prev(tokoToDelete)) = next(tokoToDelete);
        if (next(tokoToDelete) != nullptr) {
            // Update pointer prev elemen berikutnya jika ada
            prev(next(tokoToDelete)) = prev(tokoToDelete);
        }
    }

    // Simpan nama toko untuk pesan keberhasilan
    string namaToko = info(tokoToDelete).namaToko;
    delete tokoToDelete; // Hapus elemen toko dari memori

    // Tampilkan pesan keberhasilan
    cout << "Berhasil menghapus Toko " << namaToko << " (ID: " << Toko_ID << ")" << endl;
    if (foundTransaksi) {
        // Jika ada transaksi yang terkait, tampilkan pesan keberhasilan
        cout << "Berhasil menghapus semua transaksi yang terkait dengan Toko tersebut" << endl;
    } else {
        // Jika tidak ada transaksi yang terkait, tampilkan pesan
        cout << "Tidak ada transaksi yang terkait dengan Toko tersebut" << endl;
    }
}
