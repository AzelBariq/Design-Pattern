#include "board.cpp"
#include "player.cpp"
#include "game_manager.cpp"
#include <iostream>
#include <cstdlib> // Untuk menggunakan fungsi acak
#include <ctime>   // Untuk menginisialisasi generator acak

int main() {
    // Inisialisasi generator acak dengan seed waktu saat ini
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Daftar nama file tantangan
    std::string challengeFiles[] = {
        "C:\\Users\\Azel Bariq\\Desktop\\Design-Pattern\\Easy.txt",
        "C:\\Users\\Azel Bariq\\Desktop\\Design-Pattern\\kuncisudoku3.txt"
    };

    // Memilih secara acak file tantangan dari daftar
    int randomIndex = std::rand() % 2; // Angka 2 mengacu pada jumlah file dalam daftar (0 dan 1)

    std::string challengeFile = challengeFiles[randomIndex];

    GameManager gameManager;
    gameManager.startGame(challengeFile);

    return 0;
}
