#ifndef ECOMMERCE_H_INCLUDED
#define ECOMMERCE_H_INCLUDED

//  Tubes Kelompok 1
//  Fathan Fardian Sanum            103012330106
//  Fransisca Anggraeni Hartakaadi  103012300366
//  Tipe B (MLL)
//  Parent = Toko (DLL)
//  Relasi = Transaksi (SLL)
//  Child = Pembeli (SLL)
//  Topik = Aplikasi E-Commerce

#include <iostream>
#include <string>

#define first(L) ((L).first)
#define last(L) ((L).last)
#define info(P) (P->info)
#define next(P) (P->next)
#define prev(P) (P->prev)
#define detailToko(newTransaksi) (newTransaksi->detailToko)
#define detailPembeli(newTransaksi) (newTransaksi->detailPembeli)

using namespace std;

// Definisi struktur data
struct Toko {
    int idToko;
    string namaToko;
    int jumlahProduk;
};

struct Pembeli {
    int idPembeli;
    string namaPembeli;
};

typedef struct ElemenToko* adrToko;
typedef struct ElemenPembeli* adrPembeli;
typedef struct ElemenTransaksi* adrTransaksi;

typedef Toko infotypeToko;
typedef Pembeli infotypePembeli;

// Pointer List Toko (DLL)
struct ElemenToko {
    infotypeToko info;
    adrToko prev;  // Double Linked List (DLL)
    adrToko next;
};

// Pointer List Pembeli (SLL)
struct ElemenPembeli {
    infotypePembeli info;
    adrPembeli next;  // Single Linked List (SLL)
};

// Pointer List Transaksi
struct ElemenTransaksi {
    adrToko detailToko;
    adrPembeli detailPembeli;
    adrTransaksi next;
};

// List Toko (DLL)
struct ListToko {
    adrToko first;
    adrToko last;
};

// List Pembeli (SLL)
struct ListPembeli {
    adrPembeli first;
};

// List Transaksi (Relasi Toko dan Pembeli) (SLL)
struct ListTransaksi {
    adrTransaksi first;
};
// Fungsi dan prosedur yang akan diimplementasikan

// Inisialisasi List Toko
void createListToko(ListToko &LT);

// Inisialisasi List Pembeli
void createListPembeli(ListPembeli &LP);

// Inisialisasi List Transaksi
void createListTransaksi(ListTransaksi &LTR);

// Membuat elemen baru pada List Toko
adrToko createNewElmToko(infotypeToko data);

// Membuat elemen baru pada List Pembeli
adrPembeli createNewElmPembeli(infotypePembeli data);

// Membuat elemen baru pada List Transaksi
adrTransaksi createNewElmTransaksi(adrToko detailToko, adrPembeli detailPembeli);

// Fungsi untuk mengecek apakah ID sudah ada di dalam List Toko
bool isIDTokoExist(ListToko LT, int id);

// Menambahkan elemen baru di awal List Toko
void insertFirstToko(ListToko &LT, adrToko PT);

// Menambahkan elemen baru di akhir List Toko
void insertLastToko(ListToko &LT, adrToko PT);

// Mencari Toko berdasarkan ID
adrToko searchToko(ListToko &LT, int Toko_ID);

// Menampilkan semua data Toko
void showToko(ListToko &LT);

// Fungsi untuk mengecek apakah ID sudah ada di dalam List Pembeli
bool isIDPembeliExist(ListPembeli LP, int id);

// Menambahkan elemen Pembeli di akhir List Pembeli
void insertLastPembeli(ListPembeli &LP, adrPembeli PP);

// Mencari Pembeli berdasarkan ID
adrPembeli searchPembeli(ListPembeli &LP, int Pembeli_ID);

// Menambahkan Transaksi (Relasi Toko dan Pembeli)
void insertTransaksi(ListTransaksi &LTR, adrToko detailToko, adrPembeli detailPembeli);

// Menampilkan seluruh data Transaksi
void showAllData(ListTransaksi &LTR);

// Menampilkan daftar Pembeli berdasarkan Toko tertentu
void showPembeliByToko(ListTransaksi &LTR, int Toko_ID);

// Menghitung jumlah Pembeli pada Toko tertentu
int countPembeli(ListTransaksi &LTR, int Toko_ID);

// Menghapus semua Pembeli yang terkait dengan Toko tertentu
void deletePembeliByToko(ListPembeli &LP, ListTransaksi &LTR, int Toko_ID);

// Menghapus Toko dan semua transaksi yang terkait dengan Toko tersebut
void deleteTokoDanTransaksiTerkait(ListToko &LT, ListTransaksi &LTR, int Toko_ID);

void isiDataDummy(ListToko &LT, ListPembeli &LP, ListTransaksi &LTR);

#endif // ECOMMERCE_H_INCLUDED
