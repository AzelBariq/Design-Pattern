#ifndef PAPAN_H
#define PAPAN_H

#include <vector>
#include <string>

class Board {
private:
    std::vector<std::vector<int>> grid;

public:
    Board();
    void print();
    void loadChallenge(const std::string& filename);
    bool isMoveValid(int row, int col, int value);
    bool isRowValid(int row, int value);
    bool isColValid(int col, int value);
    bool isSubgridValid(int row, int col, int value);
    void updateMove(int row, int col, int value);
    int getValue(int row, int col);
};

#endif // PAPAN_H
