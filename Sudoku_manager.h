#pragma once
#ifndef SUDOKU_MANAGER_H
#define SUDOKU_MANAGER_H

#include "papan.h"
#include "pemain.h"
#include <string>

class SudokuManager {
private:
    Papan papan;
    Pemain pemain;

public:
    void startSudoku(const std::string& challengeFile);
    bool isSudokuOver();
    void setPemainName(const std::string& pemainName); // Deklarasi metode setpemainName().
    std::string getPemainName() const; // Deklarasi metode getPemainName() sebagai konstan.
};

#endif // SUDOKU_MANAGER_H
