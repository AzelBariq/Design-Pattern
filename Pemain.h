#ifndef PEMAIN_H
#define PEMAIN_H

#include <string>

class pemain {
public:
    pemain(); // Deklarasi konstruktor default.
    int makeMove();
    std::string getNama() const; // Deklarasi metode getNama() sebagai konstan.
    void setNama(const std::string& pemainNama); // Deklarasi metode setNama().

private:
    std::string nama; // Atribut string untuk menyimpan nama pemain.
};

#endif // PEMAIN_H
