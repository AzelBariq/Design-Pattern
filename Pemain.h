#ifndef PEMAIN_H
#define PEMAIN_H

#include <string>

class Player {
public:
    Player(); // Deklarasi konstruktor default.
    int makeMove();
    std::string getNama() const; // Deklarasi metode getNama() sebagai konstan.
    void setNama(const std::string& playerName); // Deklarasi metode setNama().

private:
    std::string nama; // Atribut string untuk menyimpan nama pemain.
};

#endif // PEMAIN_H
