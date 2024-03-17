#include "player.h"

Player::Player() {
    // Konstruktor default, tidak ada inisialisasi khusus.
}

int Player::makeMove() {
    // Implementasi metode makeMove() seperti sebelumnya.
    // ...
    return 0;
}

std::string Player::getNama() const {
    return nama;
}

void Player::setNama(const std::string& playerName) {
    nama = playerName;
}
