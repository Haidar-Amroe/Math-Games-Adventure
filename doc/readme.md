#Anggota Kelompok 8 :

1. Farrell Luthfi Adriansyah (L0125098)
2. Muhammad Haidar Amru (L0125025)
3. Satrio Unggul Prayogo (L0125114)

##Deskripsi Program:

Program "Math Games Adventure" adalah sebuah permainan edukasi berbasis konsol (Command Line Interface) yang menggabungkan elemen petualangan teks dengan kuis matematika. Pemain berperan sebagai seseorang yang terjebak di dalam gua dan harus menjawab tantangan matematika dari seorang Jin untuk bisa keluar dengan selamat. Program ini menguji kemampuan berhitung cepat serta ketelitian pemain melalui beberapa tingkatan level (stage).

##Mekanisme Kerja Program:

#Menu Utama:

1. Saat program dimulai, pengguna disuguhkan animasi intro dan menu utama.

2. Pengguna dapat memilih untuk Memulai Game, melihat High Score, atau Keluar (Exit).

#Alur Permainan (Gameplay):

1. Pemain diberikan modal awal berupa 3 nyawa.

2. Permainan terdiri dari 3 Level (Stage) dengan tingkat kesulitan yang meningkat.

3. Level 1: Soal aritmatika dasar (penjumlahan, pengurangan, perkalian, pembagian) yang di-generate secara acak.

4. Level 2: Soal isian singkat yang dibaca dari file eksternal (STAGE 2.txt).

5. Level 3: Soal logika atau visual yang dibaca dari file eksternal (STAGE 3.txt).

#Sistem Skor dan Nyawa:

1. Menjawab benar akan menambah skor (poin bervariasi tergantung kesulitan level).

2. Menjawab salah akan mengurangi skor dan mengurangi 1 nyawa.

3. Jika nyawa habis (0), permainan berakhir (Game Over) dan pemain harus mengulang dari awal, namun intro cerita akan dipersingkat.

#Penyimpanan Data:

1. Jika pemain mencapai skor tertinggi (Top 5), pemain diminta memasukkan username.

2. Data skor tertinggi disimpan secara permanen dalam file highscore.txt.

##Keterangan Fitur Program:

#Sistem Leveling:

1. Level 1 (Randomized): Program menggunakan fungsi rand() untuk menghasilkan angka acak, sehingga soal tidak selalu sama setiap kali bermain.

2. Level 2 & 3 (File Handling): Program membaca soal dari file teks eksternal, memungkinkan variasi soal yang lebih kompleks dan panjang (hingga 512 karakter).

#Leaderboard (High Score):

1. Menggunakan struct untuk menyimpan data nama dan skor.

2. Menggunakan algoritma sorting (Bubble Sort) untuk mengurutkan 5 skor tertinggi.

3. Data disimpan dan dibaca menggunakan operasi File I/O (fscanf, fprintf) agar data tidak hilang saat program ditutup.

#Antarmuka (Interface):

1. Animasi Teks: Menggunakan fungsi ketikPelan untuk memberikan efek mengetik seperti pada game RPG klasik.

2. Visualisasi: Menggunakan ASCII art untuk judul dan transisi antar level.

3. Navigasi: Penggunaan clearScreen dan delay (Sleep) untuk pengalaman pengguna yang lebih rapi dan nyaman.

#Validasi dan Kontrol:

1. Fitur pembersihan buffer (clearInputBuffer) untuk mencegah error saat input data.

2. Pengecekan kondisi nyawa (lives) di setiap soal untuk memastikan permainan berhenti segera setelah pemain kalah.

##Cara Menjalankan Program:

1. Pastikan file src.c, STAGE 2.txt, dan STAGE 3.txt berada dalam satu folder yang sama.

2. Buat file STAGE 2.txt dan STAGE 3.txt berisi daftar soal sesuai format yang diminta program jika belum ada.

3. Compile program dengan menggunakan kompiler C (seperti GCC). Contoh: gcc src.c -o game.

4. Jalankan executable file yang dihasilkan (game.exe pada Windows).

5. Penting: Program ini menggunakan library <windows.h>, sehingga disarankan untuk dijalankan di sistem operasi Windows.

6. Ikuti instruksi di layar untuk menavigasi menu dan menjawab soal.
