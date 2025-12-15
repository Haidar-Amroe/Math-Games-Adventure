# 🎮 Math Adventure: The Mysterious Cave
Math Adventure: The Mysterious Cave adalah permainan berbasis konsol (Command Line Interface) yang menggabungkan elemen cerita petualangan RPG dengan tantangan matematika. Pemain terjebak di dalam gua misterius dan harus menjawab teka-teki dari sesosok Jin untuk bisa selamat. Game ini dirancang untuk mengasah kemampuan berhitung cepat dan logika di bawah tekanan.

# ✨ Fitur Utama
Game ini memiliki berbagai fitur teknis dan gameplay yang membuatnya menarik:

1. Storytelling & Atmosfer Imersif 🧞‍♂️
    <ul>
        <li><strong>Intro Animasi:</strong> Menggunakan efek <em>typewriter</em> (fungsi <code>ketikPelan</code>) untuk membangun suasana tegang saat menceritakan kisah pembuka.</li>
        <li><strong>Karakter Interaktif:</strong> Pemain berinteraksi dengan karakter "Jin" yang memberikan respon berbeda tergantung pada keberhasilan atau kegagalan pemain.</li>
    </ul>

2. Sistem Level Progresif (3 Stage) 📈
    <p>Tingkat kesulitan meningkat seiring permainan berjalan:</p>
    <ul>
        <li><strong>Stage 1 (Randomized):</strong> Soal aritmatika dasar (Jumlah, Kurang, Kali, Bagi) yang diacak menggunakan fungsi <code>rand()</code>, sehingga soal tidak pernah sama.</li>
        <li><strong>Stage 2 (File Handling):</strong> Soal isian singkat yang dibaca dari database eksternal (<code>STAGE 2.txt</code>), memungkinkan soal yang lebih kompleks.</li>
        <li><strong>Stage 3 (Logic & Visual):</strong> Soal logika yang mendukung format visual khusus (seperti pemisah baris <code>|</code>) untuk variasi tantangan.</li>
    </ul>

3. Sistem High Score (Leaderboard) 🏆
    <ul>
        <li><strong>Penyimpanan Permanen:</strong> Skor tertinggi tidak akan hilang saat game ditutup karena disimpan dalam file <code>highscore.txt</code>.</li>
        <li><strong>Kompetitif:</strong> Hanya 5 pemain terbaik yang akan masuk ke papan peringkat (Top 5 Leaderboard).</li>
        <li><strong>Sorting Otomatis:</strong> Sistem secara otomatis mengurutkan skor dari tertinggi ke terendah setiap kali ada rekor baru menggunakan algoritma <em>Bubble Sort</em>.</li>
    </ul>

4. Manajemen Nyawa (Lives System) ❤️
    <ul>
        <li>Pemain diberikan modal <strong>3 nyawa</strong> di awal permainan.</li>
        <li>Setiap jawaban salah akan mengurangi 1 nyawa. Jika nyawa habis, permainan berakhir (<em>Game Over</em>) dan pemain harus mengulang dari awal.</li>
    </ul>

5. Validasi Input & UI 🛡️
    <ul>
        <li>Menggunakan <code>clearInputBuffer</code> untuk mencegah error saat pengguna memasukkan input yang tidak sesuai.</li>
        <li>Transisi antar layar yang rapi menggunakan <code>clearScreen</code> dan <code>delay</code> agar pemain dapat membaca dialog dengan nyaman.</li>
    </ul>
Menggunakan clearInputBuffer untuk mencegah error saat pengguna memasukkan input yang tidak sesuai.
Transisi antar layar yang rapi menggunakan clearScreen dan delay agar pemain dapat membaca dialog dengan nyaman.
