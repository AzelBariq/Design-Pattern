#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "board.h"
#include "player.h"
#include <string>

class GameManager {
private:
    Board board;
    Player player;

public:
    void startGame(const std::string& challengeFile);
    bool isGameOver();
    void setPlayerName(const std::string& playerName); // Deklarasi metode setPlayerName().
    std::string getPlayerName() const; // Deklarasi metode getPlayerName() sebagai konstan.
};

#endif // GAME_MANAGER_H
