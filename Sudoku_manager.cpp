#include "sudoku_manager.h"
#include "papan.h"
#include "pemain.h"
#include <iostream>

void SudokuManager::startSudoku(const std::string& challengeFile) {
    // Meminta pemain memasukkan namanya
    std::string pemainName;
    std::cout << "Enter your name: ";
    std::cin >> pemainName;
    setpemainName(pemainName); // Mengatur nama pemain

    papan.loadChallenge(challengeFile);

    while (!isSudokuOver()) {
        papan.print(); // Tampilkan papan saat ini.

        int row, col, value;

        std::cout << "Enter the row (1-9) and column (1-9) to place the value: ";
        std::cin >> row >> col;

        // Validasi input
        if (row >= 1 && row <= 9 && col >= 1 && col <= 9) {
            // Konversi baris dan kolom menjadi indeks papan yang sesuai.
            int papanRow = row - 1;
            int papanCol = col - 1;

            std::cout << "Enter the value (1-9) to place in row " << row << " and column " << col << ": ";
            std::cin >> value;

            // Validasi angka yang dimasukkan oleh pemain.
            if (value >= 1 && value <= 9) {
                if (papan.isMoveValid(papanRow, papanCol, value)) {
                    if (papan.getValue(papanRow, papanCol) == 0) {
                        // Update the board based on the player's move
                        papan.updateMove(papanRow, papanCol, value);
                    } else {
                        std::cout << "Cell is already filled. Try again." << std::endl;
                    }
                } else {
                    std::cout << "Invalid move! Try again." << std::endl;
                }
            } else {
                std::cout << "Invalid value! Please enter a value between 1 and 9." << std::endl;
            }
        } else {
            std::cout << "Invalid row or column. Please enter values between 1 and 9." << std::endl;
        }
    }
    std::cout << "Selamat Buat Kamu " << getpemainName() << "! Kamu keren abissss :v !" << std::endl;
}
bool SudokuManager::isSudokuOver() {
    // Check if there are any empty cells on the Sudoku board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (papan.getValue(i, j) == 0) {
                return false;
            }
        }
    }
    return true;
}


// Implementasi metode getpemainName() untuk mengambil nama pemain.
std::string SudokuManager::getpemainName() const {
    return pemain.getNama();
}

// Implementasi metode setpemainName().
void SudokuManager::setpemainName(const std::string& pemainName) {
    pemain.setNama(pemainName);
}
