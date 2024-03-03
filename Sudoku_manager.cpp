#include "game_manager.h"
#include "board.h"
#include "player.h"
#include <iostream>

void GameManager::startGame(const std::string& challengeFile) {
    // Meminta pemain memasukkan namanya
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;
    setPlayerName(playerName); // Mengatur nama pemain

    board.loadChallenge(challengeFile);

    while (!isGameOver()) {
        board.print(); // Tampilkan papan saat ini.

        int row, col, value;

        std::cout << "Enter the row (1-9) and column (1-9) to place the value: ";
        std::cin >> row >> col;

        // Validasi input
        if (row >= 1 && row <= 9 && col >= 1 && col <= 9) {
            // Konversi baris dan kolom menjadi indeks papan yang sesuai.
            int boardRow = row - 1;
            int boardCol = col - 1;

            std::cout << "Enter the value (1-9) to place in row " << row << " and column " << col << ": ";
            std::cin >> value;

            // Validasi angka yang dimasukkan oleh pemain.
            if (value >= 1 && value <= 9) {
                if (board.isMoveValid(boardRow, boardCol, value)) {
                    if (board.getValue(boardRow, boardCol) == 0) {
                        // Update the board based on the player's move
                        board.updateMove(boardRow, boardCol, value);
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
    std::cout << "Selamat Buat Kamu " << getPlayerName() << "! Kamu keren abissss :v !" << std::endl;
}
bool GameManager::isGameOver() {
    // Check if there are any empty cells on the Sudoku board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board.getValue(i, j) == 0) {
                return false;
            }
        }
    }
    return true;
}


// Implementasi metode getPlayerName() untuk mengambil nama pemain.
std::string GameManager::getPlayerName() const {
    return player.getNama();
}

// Implementasi metode setPlayerName().
void GameManager::setPlayerName(const std::string& playerName) {
    player.setNama(playerName);
}
