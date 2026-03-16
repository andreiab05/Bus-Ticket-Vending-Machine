#include "Bilet.h"

Bilet::Bilet() {
    this -> cod = 0;
    this -> denumire = "";
    this -> pret = 0;
}

Bilet::Bilet(int c, string d, int p) {
    this -> cod = c;
    this -> denumire = d;
    this -> pret = p;
}

bool Bilet::operator==(const Bilet& other) const {
    return(cod == other.cod && denumire == other.denumire && pret == other.pret);
}

string Bilet::toString() const {
    string s;
    s = to_string(this -> cod);
    s += " ";
    s += this -> denumire;
    s += " ";
    s += to_string(this -> pret);
    return s;
}

int Bilet::getCod() const {
    return cod;
}

string Bilet::getDenumire() const {
    return denumire;
}

int Bilet::getPret() const {
    return pret;
}

ostream & operator<<(ostream &os, const Bilet &b) {
    os << b.cod << " " << b.denumire << " " << b.pret;
    return os;
}
