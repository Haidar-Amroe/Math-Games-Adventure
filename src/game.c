#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>
#include <windows.h>

#define FILE_HIGHSCORE "highscore.txt"
#define MAX_SOAL_2 8
#define MAX_SOAL_3 5
#define PANJANG_SOAL 512
#define LEBAR_KOTAK 70

// Variabel global untuk skor dan nyawa
int lives = 3;
int score = 0;
int death = 0;

struct highScore {
    char username[50];
    int score;
}; //Struct untuk highscore

struct highScore topLeaderboard[5];

//Fungsi clear buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//Fungsi delay
void delay(int milliseconds) {
    Sleep(milliseconds);
}

// Fungsi untuk mencetak teks per karakter (animasi)
void ketikPelan(char *teks, int kecepatan) {
    // Loop sampai akhir string (karakter '\0')
    while (*teks != '\0') {
        printf("%c", *teks);     
        fflush(stdout);          
        delay(kecepatan);        
        teks++;                   
    }
}

//Fungsi clear screen
void clearScreen() {
        system("cls");
}
   

//Fungsi menyimpan skor
void saveHighScore(){
    FILE *fp = fopen(FILE_HIGHSCORE, "w");
    if (fp == NULL) {
        printf("Error opening file for writing high scores.\n");
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        if (strlen(topLeaderboard[i].username) == 0) {
            fprintf(fp, "EMPTY 0\n"); 
        }
        else {
            fprintf(fp, "%s %d\n", topLeaderboard[i].username, topLeaderboard[i].score);
        }        
    }
    
    fclose(fp);
}

//Fungsi memasukkan high score
void loadHighScore(){
    FILE *fp = fopen(FILE_HIGHSCORE, "r");
    
    // Jika file tidak ada, isi dengan data kosong (EMPTY)
    if (fp == NULL) {
        for(int i=0; i<5; i++){
            strcpy(topLeaderboard[i].username, "EMPTY");
            topLeaderboard[i].score = 0;
        }
        return;
    }

    for (int i = 0; i < 5; i++) {
        fscanf(fp, "%s %d", topLeaderboard[i].username, &topLeaderboard[i].score);
    }
    fclose(fp);
}

//Fungsi update high score
void updateHighScore(int skorBaru) {
    loadHighScore();
    
    if (skorBaru > topLeaderboard[4].score || strcmp(topLeaderboard[4].username, "EMPTY") == 0) {
        printf("Selamat! Anda mendapatkan High Score baru!\n");
        
        char namaBaru[50];
        printf("Masukkan username Anda (satu kata): ");
        scanf("%s", namaBaru);

        strcpy(topLeaderboard[4].username, namaBaru);
        topLeaderboard[4].score = skorBaru;

        struct highScore temp;
        for (int i = 0; i < 5 - 1; i++) {
            for (int j = 0; j < 5 - i - 1; j++) {
                if (topLeaderboard[j].score < topLeaderboard[j + 1].score) {
                    temp = topLeaderboard[j];
                    topLeaderboard[j] = topLeaderboard[j + 1];
                    topLeaderboard[j + 1] = temp;
                }
            }
        }
        saveHighScore();
        printf("High Score berhasil diperbarui!\n");
    } else {
        printf("Maaf, Anda tidak masuk dalam Top 5 High Score.\n");
}
}

//Fungsi menampilkan leaderbo
void showLeaderboard() {
    loadHighScore();
    
    printf("===== TOP 5 HIGH SCORE =====\n");
    printf("Rank  %-15s Score\n", "Username");
    printf("------------------------------");

    for (int i = 0; i < 5; i++)
    {
        printf("\n%d.    %-15s %d\n", i + 1, topLeaderboard[i].username, topLeaderboard[i].score);
    }
    printf("------------------------------");
    
}

//Fungsi soal penjumlahan
void soalPenjumlahan() {
    if (lives <= 0) {
        return; 
    }
    int x, y, jawaban, kunciJawaban;
    x = (rand()% 201 )- 100;
    y = (rand()% 201 )- 100;

    printf ("Hasil dari %d + %d adalah : ",x, y);
    scanf("%d", &jawaban);

    clearInputBuffer(); 

    kunciJawaban = x + y;
    if (jawaban == kunciJawaban) {
        printf("Selamat jawaban Anda benar!\n");
        score += 1;
    }  
    else {
        printf("Maaf jawaban Anda salah. Jawaban yang benar adalah %d\n", kunciJawaban);
        score -= 1;
        lives --;
    }
}

//Fungsi soal pengurangan
void soalPengurangan() {
    if (lives <= 0) {
        return; 
    }
    int x, y, jawaban, kunciJawaban;
    x = (rand()% 201 )- 100;
    y = (rand()% 201 )- 100;

    printf ("Hasil dari %d - %d adalah : ",x, y);
    scanf("%d", &jawaban);

    clearInputBuffer(); 

    kunciJawaban = x - y;
    if (jawaban == kunciJawaban) {
        printf("Selamat jawaban Anda benar!\n");
        score += 1;
    }  
    else {
        printf("Maaf jawaban Anda salah. Jawaban yang benar adalah %d\n", kunciJawaban);
        score -= 1;
        lives --;
    }
}

//Fungsi soal Perkalian
void soalPerkalian() {
    if (lives <= 0) {
        return; 
        }
    int x, y, jawaban, kunciJawaban;
    x = (rand()% 21 )- 10;
    y = (rand()% 21 )- 10;

    printf ("Hasil dari %d x %d adalah : ",x, y);
    scanf("%d", &jawaban);

    clearInputBuffer(); 

    kunciJawaban = x * y;
    if (jawaban == kunciJawaban) {
        printf("Selamat jawaban Anda benar!\n");
        score += 2;
    }  
    else {
        printf("Maaf jawaban Anda salah. Jawaban yang benar adalah %d\n", kunciJawaban);
        score -= 1;
        lives --;
    }
}

//Fungsi soal pembagian
void soalPembagian() {
    if (lives <= 0) {
    return; 
    }
    int x, y, jawaban, kunciJawaban;
    do{
        y = (rand()% 21 )- 10;
    } while (y == 0); 

    kunciJawaban = (rand()% 21 )- 10;
    x = y * kunciJawaban;

    printf ("Hasil dari %d : %d adalah : ",x, y);
    scanf("%d", &jawaban);

    clearInputBuffer(); 

    if (jawaban == kunciJawaban) {
        printf("Selamat jawaban Anda benar!\n");
        score += 2;
    }  
    else {
        printf("Maaf jawaban Anda salah. Jawaban yang benar adalah %d\n", kunciJawaban);
        score -= 1;
        lives --;
    }
}

//Soal stage 2
int stage2() {
    // Array untuk menyimpan soal yang dibaca dari file
    char questions[MAX_SOAL_2][PANJANG_SOAL];
    
    // Array untuk menyimpan jawaban yang benar
    char *answers[MAX_SOAL_2] = {
        "4",     // Jawaban Soal 1 
        "-13",   // Jawaban Soal 2
        "12",    // Jawaban Soal 3
        "66",    // Jawaban Soal 4
        "550",   // Jawaban Soal 5
        "342",   // Jawaban Soal 6
        "60",    // Jawaban Soal 7
        "25",    // Jawaban Soal 8
    };

    char jawabanUser[50];
    int i;

    // --- BACA SOAL DARI FILE ---
    FILE *file = fopen("STAGE 2.txt", "r");

    if (file == NULL) {
        printf("Error: Tidak bisa membuka file soal.txt.\n");
        printf("Pastikan file soal.txt ada di folder yang sama dengan program ini.\n");
        return 1;
    }

    for (i = 0; i < MAX_SOAL_2; i++) {
        if (fgets(questions[i], PANJANG_SOAL, file) == NULL) {
            break;
        }
    }
    fclose(file);
    // --- SELESAI BACA FILE ---
    
    for (i = 0; i < MAX_SOAL_2; i++) {
        if (lives <= 0) return 0;

        printf("Soal no. %d\n", i + 1);
        
        // Cetak soal ke dalam interface kotak
        printf("%s", questions[i]);
        
        printf("Jawaban Anda: ");
        scanf("%s", jawabanUser);
        clearInputBuffer();
        printf("\n");
        
        if (strcmp(jawabanUser, answers[i]) == 0) {
            printf("Selamat jawaban Anda benar!\n\n");
            score += 3;
        } else { 
            printf("Maaf jawaban Anda salah. Jawaban yang benar adalah %s\n\n", answers[i]);
            score -= 1;
            lives--;
    }
    }
}

//Soal stage 3
int stage3() {
    // Array untuk menyimpan soal yang dibaca dari file
    char questions[MAX_SOAL_3][PANJANG_SOAL];
    
    // Array untuk menyimpan jawaban yang benar
    char *answers[MAX_SOAL_3] = {
        "3",       // Jawaban Soal 1
        "105000",  // Jawaban Soal 2
        "175",     // Jawaban Soal 3
        "90",      // Jawaban Soal 4
        "1400"     // Jawaban Soal 5
    };

    char jawabanUser[50];
    int i;

    // --- BACA SOAL DARI FILE ---
    FILE *file = fopen("STAGE 3.txt", "r");

    if (file == NULL) {
        printf("Error: Tidak bisa membuka file soal.txt.\n");
        printf("Pastikan file soal.txt ada di folder yang sama dengan program ini.\n");
        return 1;
    }

    for (i = 0; i < MAX_SOAL_3; i++) {
        if (fgets(questions[i], PANJANG_SOAL, file) == NULL) {
            break;
        }
    }
    fclose(file);
    // --- SELESAI BACA FILE ---
    
for (i = 0; i < MAX_SOAL_3; i++) {
        // Cek nyawa 
        if (lives <= 0) return 0;

        printf("Soal no. %d\n", i + 1);
    
        //untuk merapikan di terminal
        for (int k = 0; questions[i][k] != '\0'; k++) {
            if (questions[i][k] == '|') {
                printf("\n"); 
            } else {
                printf("%c", questions[i][k]); 
            }
        }
        printf("\n"); 
        
        printf("Jawaban Anda: ");
        scanf("%s", jawabanUser);
        clearInputBuffer();
        printf("\n");
        
        if (strcmp(jawabanUser, answers[i]) == 0) {
            printf("Selamat jawaban Anda benar!\n\n");
            score += 5;
        } else {
            printf("Maaf jawaban Anda salah. Jawaban yang benar adalah %s\n\n", answers[i]);
            score -= 1;
            lives--;
        }
        
        delay(1000); 
    } 

    if (lives > 0) {
        printf("\nSelamat! Kamu berhasil menyelesaikan semua stage dengan skor: %d\n", score);
    }

    return 0;
}

//Intro game
int main() {    

    ketikPelan("  __  __    _    _____  _   _      ____    _    __  __  _____  ____  \n", 1);
    ketikPelan(" |  \\/  |  / \\  |_   _|| | | |    / ___|  / \\  |  \\/  | | ____|/ ___| \n", 1);
    ketikPelan(" | |\\/| | / _ \\   | |  | |_| |   | |  _  / _ \\ | |\\/| | |  _|  \\___ \\ \n", 1);
    ketikPelan(" | |  | |/ ___ \\  | |  |  _  |   | |_| |/ ___ \\| |  | | | |___  ___) |\n", 1);
    ketikPelan(" |_|  |_/_/   \\_\\ |_|  |_| |_|    \\____/_/   \\_\\_|  |_| |_____||____/ \n", 1);
    ketikPelan("    _    ____  __     __ _____ _   _ _____ _   _ ____  _____ \n", 5);
    ketikPelan("   / \\  |  _ \\ \\ \\   / /| ____| \\ | |_   _| | | |  _ \\| ____|\n", 5);
    ketikPelan("  / _ \\ | | | | \\ \\ / / |  _| |  \\| | | | | | | | |_) |  _|  \n", 5);
    ketikPelan(" / ___ \\| |_| |  \\ V /  | |___| |\\  | | | | |_| |  _ <| |___ \n", 5);
    ketikPelan("/_/   \\_\\____/    \\_/   |_____|_| \\_| |_|  \\___/|_| \\_\\_____|\n", 5);
    printf("\n"); // Baris kosong biasa (tidak perlu animasi)
    
    ketikPelan("                       BY Kelompok 8                       \n", 20);
    ketikPelan("                 Version 1.0.0 - December 2025                  \n", 20);
    printf("\n");

    ketikPelan("Press Enter to continue...", 50);  
    getchar(); 
    clearScreen();
    
    int pilihan;
    char pilUlang; 
    srand(time(NULL));
//------------------------------------------------------------

//Menampilkan main menu
    do
    {
    ketikPelan("=================================\n", 10);
    ketikPelan("            GAME STARTED         \n", 10);
    ketikPelan("=================================\n", 10);
    
    printf("Silakan pilih menu dibawah ini:\n");
    printf("1. Mulai Game\n");
    printf("2. High Score\n");
    printf("3. Exit\n");
    
    printf("\nPilihan Anda: ");
    scanf("%d", &pilihan);
    

    clearScreen();
    switch (pilihan)
    {
    case 1:
        // Memulai game
        lives = 3;
        score = 0;

        ketikPelan("Suatu hari anda terbangun di Gua misterius...\n", 10);
        delay(1000);
        ketikPelan("Tiba-tiba seorang Jin mendatangi anda.\n", 10);
        ketikPelan("\nPress Enter to continue...", 50);  
        while(getchar() != '\n');
        getchar(); 
        clearScreen();

        //New game
        if(death == 0) {
        
        ketikPelan("Jin : Selamat datang di Gua Misterius!\n", 10);
        ketikPelan("Untuk keluar dari sini, kamu harus menyelesaikan tantangan matematika yang aku berikan.\n", 10);
        ketikPelan("Setiap jawaban yang benar akan memberimu poin, \n", 10);
        ketikPelan("tapi hati-hati, jawaban yang salah akan mengurangi nyawamu! Kamu punya 3 nyawa.\n", 10);
    
        printf("\nJawabanmu? (y/n): ");
        scanf(" %c", &pilUlang);
        clearScreen();
        if(pilUlang == 'n' || pilUlang == 'N') {
            ketikPelan("Jin: Baiklah, sampai jumpa lain waktu!\n", 10);
            delay(1000);
            clearScreen();
            break;
        }
    }
        //Apabila sudah pernah mati
        else {
        ketikPelan("Jin: Kita bertemu lagi nak, apakah kamu siap untuk mengulang tantanganku?\n", 10);
        printf("Jawabanmu? (y/n): ");
        scanf(" %c", &pilUlang);
        clearScreen();
        if(pilUlang == 'n' || pilUlang == 'N') {
            ketikPelan("Jin: 'Baiklah, sampai jumpa lain waktu!'\n", 10);
            delay(1000);
            clearScreen();
            break;
        }
    }
        //evel 1 start
        ketikPelan("Game dimulai! Semoga beruntung!\n", 10);
        printf("Anda memiliki %d nyawa dan skor awal %d.\n\n", lives, score);
        delay(1000);
        clearScreen();

        printf("Soal No. 1 :\n");
        soalPenjumlahan();
        delay(1000);

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        printf("\nSoal No. 2 :\n");
        soalPenjumlahan();
        delay(1000);

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        printf("\nSoal No. 3 :\n");
        soalPengurangan();
        delay(1000);

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        printf("\nSoal No. 4 :\n");
        soalPengurangan();
        delay(1000);

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        printf("\nSoal No. 5 :\n");
        soalPerkalian();
        delay(1000);  

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        printf("\nSoal No. 6 :\n");     
        soalPerkalian();
        delay(1000);

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        printf("\nSoal No. 7 :\n");   
        soalPerkalian();
        delay(1000);

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        printf("\nSoal No. 8 :\n");
        soalPembagian();
        delay(1000);

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        printf("\nSoal No. 9 :\n");
        soalPembagian(); 
        delay(1000);  

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        printf("\nSoal No. 10 :\n");
        soalPembagian();
        delay(1000);

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        clearScreen();
        printf("\nSelamat! Level 1 Selesai.\n");
        printf("\nPress enter to continue...");
        getchar();
        clearScreen();

        ketikPelan("Jin : Selamat sudah menyelesaikan level pertama!\n", 10);
        ketikPelan("Namun perjalananmu belum selesai, masih ada tantangan yang lebih sulit\n", 10);
        ketikPelan("Apakah kamu siap untuk melanjutkan?", 10);
        printf("\nPress enter to continue...");
        getchar();
        clearScreen();

        //level 2 start
        ketikPelan("Level 2 dimulai!\n", 10);
        printf("Anda memiliki %d nyawa dan skor %d.\n", lives, score);
        delay(2000);
        clearScreen();

  
        stage2();
        delay(2000);

        if(lives <= 0) {
                goto cekGameOver;
                delay(1000);
            }

        clearScreen();
        printf("\nSelamat! Level 2 Selesai.\n");
        printf("\nPress enter to continue...");
        getchar();
        clearScreen();

        ketikPelan("Jin : Hebat, kamu sudah menyelesaikan level kedua!\n", 10);
        ketikPelan("Sampailah kamu di level terakhir, semangat!\n", 10);
        printf("\nPress enter to continue...");
        getchar();
        clearScreen();

        //level 3 start
        ketikPelan("Level 3 dimulai!\n", 10);
        printf("Anda memiliki %d nyawa dan skor %d.\n", lives, score);
        delay(2000);
        clearScreen();
        
        stage3();
        delay(2000);
        clearScreen();

        cekGameOver:
        
        delay(1000);
        clearScreen();

        if(lives > 0) {
            ketikPelan("Jin : Nampaknya kamu telah menyelesaikan seluruh tantanganku.\n", 5);
            ketikPelan("Selamat! Pintu keluar Gua ada di belakangku.", 5);
            delay(2000);
            clearScreen();

            printf("============================================\n");
            printf(" ANDA KELUAR DARI GUA DENGAN SELAMAT \n");
            printf("============================================\n");
        } else {
            printf("Kamu pingsan dan terbangun kembali di awal gua.\n");
            death = 1; 
        }

        printf("Skor Akhir Anda: %d\n", score);
        updateHighScore(score);

        printf("\nPress enter to return to menu...");
        getchar();
        clearScreen();
        break;
        
    case 2:
        clearScreen();
        showLeaderboard();
        printf("\nPress enter to return to menu...");
        while(getchar() != '\n');
        getchar();
        clearScreen();

        break;
    case 3:
        ketikPelan("Terima kasih telah bermain! Sampai jumpa lagi!\n", 10);
        printf("\nPress enter to continue...");
        while(getchar() != '\n');
        getchar();
        clearScreen();
        exit(0);
        break;

    default:
        ketikPelan("Pilihan tidak valid. Silakan coba lagi.\n", 10);
        break;
    }

} while (pilihan != 3);
    return 0;
}