#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <string>
#include "board.h"
#include "player.h"

class GameManager {
private:
    Board board;
    Player player;

public:
    void startGame(const std::string& challengeFile);
    bool isGameOver();
};

#endif // GAME_MANAGER_H