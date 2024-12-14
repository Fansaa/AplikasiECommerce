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

// Menghapus elemen Toko berdasarkan ID
void deleteToko(ListToko &LT, int Toko_ID) {
    if (first(LT) == nullptr) {
        cout << "List Toko kosong" << endl;
        return;
    }

    adrToko P = searchToko(LT, Toko_ID);
    if (P != nullptr) {
        string namaToko = info(P).namaToko;  // Simpan nama toko sebelum dihapus
        if (P == first(LT)) {
            first(LT) = next(P);
            if (first(LT) != nullptr) {
                prev(first(LT)) = nullptr;
            }
        } else {
            prev(P)->next = next(P);
            if (next(P) != nullptr) {
                prev(next(P)) = prev(P);
            }
        }
        cout << "Berhasil menghapus Toko " << namaToko << " (ID: " << Toko_ID << ")" << endl;
        delete P;
    }
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

// Menambahkan elemen Pembeli di awal List Pembeli
void insertFirstPembeli(ListPembeli &LP, adrPembeli PP) {
    if (first(LP) == nullptr) {
        first(LP) = PP;
    } else {
        next(PP) = first(LP);
        first(LP) = PP;
    }
    cout << "Berhasil menambahkan Pembeli " << info(PP).namaPembeli << " (ID: " << info(PP).idPembeli << ") di awal list" << endl;
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

// Menghapus elemen Pembeli berdasarkan ID
void deletePembeli(ListPembeli &LP, int Pembeli_ID) {
    if (first(LP) == nullptr) {
        cout << "List Pembeli kosong" << endl;
        return;
    }

    adrPembeli P = searchPembeli(LP, Pembeli_ID);
    if (P != nullptr) {
        string namaPembeli = info(P).namaPembeli;  // Simpan nama pembeli sebelum dihapus
        if (P == first(LP)) {
            first(LP) = next(P);
        } else {
            adrPembeli prev = first(LP);
            while (next(prev) != P) {
                prev = next(prev);
            }
            next(prev) = next(P);
        }
        cout << "Berhasil menghapus Pembeli " << namaPembeli << " (ID: " << Pembeli_ID << ")" << endl;
        delete P;
    }
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

    cout << "Berhasil menambahkan Transaksi antara Toko " << detailToko->info.namaToko
         << " (ID: " << detailToko->info.idToko << ") dan Pembeli "
         << detailPembeli->info.namaPembeli << " (ID: " << detailPembeli->info.idPembeli << ")" << endl;
}

// Menghapus Transaksi berdasarkan ID Toko dan ID Pembeli
void deleteTransaksi(ListTransaksi &LTR, int Toko_ID, int Pembeli_ID) {
    if (first(LTR) == nullptr) {
        cout << "List Transaksi kosong" << endl;
        return;
    }

    adrTransaksi P = first(LTR);
    adrTransaksi prev = nullptr;
    bool found = false;

    while (P != nullptr && !found) {
        if (P->detailToko->info.idToko == Toko_ID && P->detailPembeli->info.idPembeli == Pembeli_ID) {
            found = true;
            string namaToko = P->detailToko->info.namaToko;
            string namaPembeli = P->detailPembeli->info.namaPembeli;

            if (prev == nullptr) {
                first(LTR) = next(P);
            } else {
                prev->next = next(P);
            }

            cout << "Berhasil menghapus Transaksi antara Toko " << namaToko
                 << " (ID: " << Toko_ID << ") dan Pembeli "
                 << namaPembeli << " (ID: " << Pembeli_ID << ")" << endl;

            delete P;
        } else {
            prev = P;
            P = next(P);
        }
    }

    if (!found) {
        cout << "Transaksi dengan ID Toko " << Toko_ID
             << " dan ID Pembeli " << Pembeli_ID << " tidak ditemukan" << endl;
    }
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
        cout << "Toko       : " << P->detailToko->info.namaToko << " (ID: " << P->detailToko->info.idToko << ")" << endl;
        cout << "Pembeli    : " << P->detailPembeli->info.namaPembeli << " (ID: " << P->detailPembeli->info.idPembeli << ")" << endl;
        cout << "------------------------" << endl;
        P = next(P);
    }
    cout << "\nTotal Transaksi: " << count << endl;
    cout << "===================" << endl;
}
/*
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
*/
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
        if (temp->detailToko->info.idToko == Toko_ID) {
            namaToko = temp->detailToko->info.namaToko;
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
        if (P->detailToko->info.idToko == Toko_ID) {
            found = true;
            count++;
            cout << count << ". " << P->detailPembeli->info.namaPembeli
                 << " (ID: " << P->detailPembeli->info.idPembeli << ")" << endl;
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
        if (P->detailToko->info.idToko == Toko_ID) {
            count++;
        }
        P = next(P);
    }
    return count;
}

// Menghapus semua Pembeli yang terkait dengan Toko tertentu dan menghapus transaksi terkait
void deletePembeliByToko(ListPembeli &LP, ListTransaksi &LTR, int Toko_ID) {
    if (first(LP) == nullptr || first(LTR) == nullptr) {
        cout << "List Pembeli atau Transaksi kosong." << endl;
        return;
    }

    // Hapus hanya transaksi yang terkait dengan Toko_ID
    adrTransaksi P = first(LTR);
    adrTransaksi prev = nullptr;
    bool found = false;

    while (P != nullptr) {
        adrTransaksi next = P->next;
        if (P->detailToko->info.idToko == Toko_ID) {
            found = true;
            if (prev == nullptr) {
                first(LTR) = next;
            } else {
                prev->next = next;
            }
            delete P;
        } else {
            prev = P;
        }
        P = next;
    }

    if (found) {
        cout << "Berhasil menghapus transaksi yang terkait dengan Toko ID " << Toko_ID << endl;
    } else {
        cout << "Tidak ditemukan transaksi yang terkait dengan Toko ID " << Toko_ID << endl;
    }
}
/*
// Menghapus semua Toko yang terkait dengan Pembeli tertentu dan menghapus transaksi terkait
void deleteTokoByPembeli(ListToko &LT, ListTransaksi &LTR, int Pembeli_ID) {
    if (first(LT) == nullptr || first(LTR) == nullptr) {
        cout << "List Toko atau Transaksi kosong." << endl;
        return;
    }

    // Ambil ID Toko dari transaksi yang terkait dengan Pembeli_ID
    adrTransaksi P = first(LTR);
    while (P != nullptr) {
        if (P->detailPembeli->info.idPembeli == Pembeli_ID) {
            // Hapus Toko
            deleteToko(LT, P->detailToko->info.idToko);
        }
        P = next(P);
    }

    // Hapus semua transaksi yang terkait dengan Pembeli_ID
    P = first(LTR);
    adrTransaksi prev = nullptr;
    bool found = false;

    while (P != nullptr) {
        adrTransaksi next = P->next;
        if (P->detailPembeli->info.idPembeli == Pembeli_ID) {
            found = true;
            if (prev == nullptr) {
                first(LTR) = next;
            } else {
                prev->next = next;
            }
            delete P;
        } else {
            prev = P;
        }
        P = next;
    }

    if (found) {
        cout << "Berhasil menghapus Toko dan transaksi yang terkait dengan Pembeli ID " << Pembeli_ID << endl;
    } else {
        cout << "Tidak ditemukan transaksi yang terkait dengan Pembeli ID " << Pembeli_ID << endl;
    }
}
*/
// Menghapus Toko dan semua transaksi yang terkait dengan Toko tersebut
void deleteTokoDanTransaksiTerkait(ListToko &LT, ListTransaksi &LTR, int Toko_ID) {
    if (first(LT) == nullptr) {
        cout << "List Toko kosong" << endl;
        return;
    }

    // Cari Toko yang akan dihapus
    adrToko tokoToDelete = searchToko(LT, Toko_ID);
    if (tokoToDelete == nullptr) {
        return; // Toko tidak ditemukan, pesan error sudah ditampilkan di searchToko
    }

    // Hapus semua transaksi yang terkait dengan Toko_ID
    adrTransaksi P = first(LTR);
    adrTransaksi prev = nullptr;
    bool foundTransaksi = false;

    while (P != nullptr) {
        adrTransaksi next = P->next;
        if (P->detailToko->info.idToko == Toko_ID) {
            foundTransaksi = true;
            if (prev == nullptr) {
                first(LTR) = next;
            } else {
                prev->next = next;
            }
            delete P;
        } else {
            prev = P;
        }
        P = next;
    }

    // Hapus Toko dari list Toko
    if (tokoToDelete == first(LT)) {
        first(LT) = next(tokoToDelete);
        if (first(LT) != nullptr) {
            prev(first(LT)) = nullptr;
        }
    } else {
        prev(tokoToDelete)->next = next(tokoToDelete);
        if (next(tokoToDelete) != nullptr) {
            prev(next(tokoToDelete)) = prev(tokoToDelete);
        }
    }

    string namaToko = info(tokoToDelete).namaToko;
    delete tokoToDelete;

    cout << "Berhasil menghapus Toko " << namaToko << " (ID: " << Toko_ID << ")" << endl;
    if (foundTransaksi) {
        cout << "Berhasil menghapus semua transaksi yang terkait dengan Toko tersebut" << endl;
    } else {
        cout << "Tidak ada transaksi yang terkait dengan Toko tersebut" << endl;
    }
}
