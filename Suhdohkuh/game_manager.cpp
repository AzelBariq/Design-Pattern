#include "game_manager.h"
#include "board.h"
#include "player.h"
#include <iostream>

void GameManager::startGame(const std::string& challengeFile) {
    board.loadChallenge(challengeFile);
    bool gameOver = false; // Tambahkan variabel gameOver
    while (!gameOver) {
        board.print(); // Tampilkan status papan saat ini
        int value;
        int row, col;
        std::cout << "Enter value (1-9): ";
        std::cin >> value;
        while (value > 10 || value < 0)
        {
            std::cout << "invalid value. Try againt !!!";
            std::cout << "Enter value (1-9): ";
            std::cin >> value;
        }
        std::cout << "Enter the row and column to place the value: ";
        std::cin >> row >> col;

        if (row > 0 && row < 10 && col > 0 && col < 10) {
            if (board.isMoveValid(row - 1, col - 1, value)) {
                // Perbarui papan berdasarkan langkah pemain
                board.updateMove(row - 1, col - 1, value);

                // Periksa apakah permainan sudah selesai
                gameOver = isGameOver();
                if (gameOver) {
                    std::cout << "Congratulations! You've solved the Sudoku puzzle!" << std::endl;
                }
            }
            else {
                std::cout << "Invalid move! The Sudoku rule does not allow it. Try again." << std::endl;
            }
        }
        else {
            std::cout << "Invalid row or column. Please enter values between 1 and 9." << std::endl;
        }
    }
}

bool GameManager::isGameOver() {
    // Check if the puzzle is solved correctly
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board.getValue(i, j) == 0 && !board.isMoveValid(i, j, board.getValue(i, j))) {
                return false;
            }
        }
    }
    return true;
}