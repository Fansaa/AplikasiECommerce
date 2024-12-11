# README for E-Commerce Application

## Deskripsi

Aplikasi ini adalah sebuah sistem sederhana untuk mengelola data e-commerce yang mencakup toko, pembeli, dan transaksi. Aplikasi ini menggunakan konsep **list linked** untuk menyimpan data dan memberikan beberapa fungsi seperti penambahan, pencarian, dan penghapusan data toko dan pembeli, serta pengelolaan transaksi antara toko dan pembeli.

## Fitur Utama

- **Tambah Data Toko**: Menambahkan data toko baru, baik di depan maupun di belakang list toko.
- **Tampilkan Semua Data Toko**: Menampilkan seluruh data toko yang ada.
- **Hapus Data Toko**: Menghapus data toko beserta transaksi terkait jika toko tersebut dihapus.
- **Cari Data Toko**: Mencari toko berdasarkan ID toko.
- **Cari Data Pembeli**: Mencari pembeli berdasarkan ID pembeli.
- **Tambah Data Pembeli**: Menambahkan pembeli baru ke dalam list pembeli.
- **Hubungkan Toko dengan Pembeli (Transaksi)**: Menambah transaksi antara pembeli dan toko.
- **Tampilkan Semua Data Transaksi**: Menampilkan seluruh transaksi yang telah terjadi antara pembeli dan toko.
- **Tampilkan Pembeli Berdasarkan Toko**: Menampilkan daftar pembeli yang telah bertransaksi dengan toko tertentu.
- **Hapus Pembeli Berdasarkan Toko**: Menghapus pembeli yang terhubung dengan toko tertentu.
- **Hitung Jumlah Pembeli pada Toko Tertentu**: Menghitung jumlah pembeli yang telah bertransaksi dengan toko tertentu.

## Prasyarat

- **C++ Compiler**: Aplikasi ini ditulis dalam bahasa C++ dan memerlukan kompiler C++ seperti **g++**.
- **C++ Standard Library**: Program ini menggunakan pustaka standar C++ seperti `<iostream>`, `<string>`, dan struktur data list.

## Struktur Program

1. **ListToko**: Menyimpan data toko, yang meliputi ID toko, nama toko, jumlah produk, dan jumlah transaksi.
2. **ListPembeli**: Menyimpan data pembeli, yang meliputi ID pembeli dan nama pembeli.
3. **ListTransaksi**: Menyimpan data transaksi antara toko dan pembeli, yang meliputi toko yang terlibat dan pembeli yang melakukan transaksi.

## Penggunaan

### Menjalankan Aplikasi

1. **Compile Program**: 
   Untuk meng-compile program, buka terminal dan jalankan perintah berikut:
   ```bash
   g++ -o ecommerce ecommerce.cpp
   ```

2. **Jalankan Program**: 
   Setelah berhasil di-compile, jalankan program menggunakan perintah berikut:
   ```bash
   ./ecommerce
   ```

### Menu Pilihan

Program ini menampilkan menu dengan berbagai pilihan sebagai berikut:

1. **Tambah Data Toko (Depan/Belakang)**: Menambahkan toko ke dalam list baik di depan atau di belakang list toko.
2. **Tampilkan Semua Data Toko**: Menampilkan seluruh data toko yang terdaftar.
3. **Hapus Data Toko dan Transaksi Terkait**: Menghapus toko dan seluruh transaksi terkait.
4. **Cari Data Toko**: Mencari toko berdasarkan ID toko.
5. **Cari Data Pembeli**: Mencari pembeli berdasarkan ID pembeli.
6. **Tambah Data Pembeli**: Menambahkan pembeli baru ke dalam list pembeli.
7. **Hubungkan Toko dengan Pembeli (Transaksi)**: Menambahkan transaksi antara toko dan pembeli.
8. **Tampilkan Semua Data Transaksi**: Menampilkan seluruh data transaksi yang tercatat.
9. **Tampilkan Pembeli Berdasarkan Toko**: Menampilkan pembeli yang bertransaksi dengan toko tertentu.
10. **Hapus Pembeli Berdasarkan Toko**: Menghapus pembeli yang terhubung dengan toko tertentu.
11. **Hitung Jumlah Pembeli pada Toko Tertentu**: Menghitung jumlah pembeli yang telah bertransaksi dengan toko tertentu.
12. **Keluar**: Keluar dari aplikasi.

### Input dan Output

- Pengguna akan diminta untuk memasukkan ID toko, ID pembeli, nama toko, nama pembeli, dan jumlah produk.
- Hasil dari operasi seperti pencarian atau penghapusan akan ditampilkan langsung di layar.

## Penjelasan Kode

1. **createListToko(LT)**, **createListPembeli(LP)**, dan **createListTransaksi(LTR)**: Fungsi ini digunakan untuk membuat list kosong untuk toko, pembeli, dan transaksi.
2. **insertFirstToko(LT, P)** dan **insertLastToko(LT, P)**: Menambahkan data toko pada list toko, baik di depan atau belakang.
3. **deleteToko(LT, tokoID)**: Menghapus data toko berdasarkan ID toko yang diberikan dan juga transaksi terkait.
4. **insertTransaksi(LTR, toko, pembeli)**: Menghubungkan pembeli dengan toko untuk mencatat transaksi.
5. **searchToko(LT, tokoID)**, **searchPembeli(LP, pembeliID)**: Mencari data toko dan pembeli berdasarkan ID yang diberikan.
6. **showToko(LT)** dan **showAllData(LTR)**: Menampilkan semua data toko dan transaksi.

## Contoh Interaksi

1. Menambahkan toko:
   ```
   Masukkan ID Toko: 101
   Masukkan Nama Toko: Toko A
   Masukkan Jumlah Produk: 50
   ```

2. Mencari toko berdasarkan ID:
   ```
   Masukkan ID Toko yang ingin dicari: 101
   Toko Ditemukan: Toko A
   ```

3. Menambahkan pembeli:
   ```
   Masukkan ID Pembeli: 201
   Masukkan Nama Pembeli: Pembeli X
   ```

4. Menghubungkan toko dan pembeli dalam transaksi:
   ```
   Masukkan ID Toko: 101
   Masukkan ID Pembeli: 201
   ```

## Kontribusi

Jika Anda ingin berkontribusi pada proyek ini, silakan buat pull request atau buka issue jika menemukan bug.

## Lisensi

Aplikasi ini dirilis di bawah lisensi MIT. Anda dapat menggunakan, memodifikasi, atau mendistribusikan ulang aplikasi ini sesuai kebutuhan Anda.

---

Terima kasih telah menggunakan aplikasi e-commerce sederhana ini!
