#include "papan.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

papan::papan() {
    // Initialize the papan with zeros
    grid = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
}

void papan::print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void papan::loadChallenge(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                file >> grid[i][j];
            }
        }
        file.close();
    }
    else {
        std::cerr << "Failed to open the challenge file." << std::endl;
        exit(1);
    }
}

bool papan::isMoveValid(int row, int col, int value) {
    return isRowValid(row, value) && isColValid(col, value) && isSubgridValid(row, col, value);
}

bool papan::isRowValid(int row, int value) {
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == value) {
            return false;
        }
    }
    return true;
}

bool papan::isColValid(int col, int value) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == value) {
            return false;
        }
    }
    return true;
}

bool papan::isSubgridValid(int row, int col, int value) {
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (grid[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

void papan::updateMove(int row, int col, int value) {
    grid[row][col] = value;
}

int papan::getValue(int row, int col) {
    return grid[row][col];
}
