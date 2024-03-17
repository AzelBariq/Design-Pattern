#include "board.h"
#include "player.h"
#include "game_manager.h"
#include <iostream>
#include <ctime>

int main() {
    std::srand(std::time(nullptr)); // Seed the random number generator
    std::string challengeFile = "C:\\Users\\Azel Bariq\\Desktop\\sdk\\Suhdohkuh\\Suhdohkuh\\Suhdohkuh\\sudoku3.txt"; // Replace with the actual file path

    GameManager gameManager;
    gameManager.startGame(challengeFile);

    return 0;
}