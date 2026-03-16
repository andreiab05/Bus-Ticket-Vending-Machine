#include "Repository.h"
#include <algorithm>

#include "ExceptionBancnoteInsuficiente.h"
#include "ExceptionBiletInexistent.h"

bool Repository::addItem(const Bilet& b) {
    abracadabra.push_back(b);
    return true;
}

bool Repository::findItem(const Bilet& b) {
    auto it = find(abracadabra.begin(), abracadabra.end(), b);
    return (it != abracadabra.end()) ? true : false;
}

bool Repository::updateItem(const Bilet& bVechi, const Bilet& bNou) {
    auto it = find(abracadabra.begin(), abracadabra.end(), bVechi);
    if (it != abracadabra.end()) {
        *it = bNou;
        return true;
    }
    return false;
}

bool Repository::deleteItem(const Bilet& b) {
    auto it = find(abracadabra.begin(), abracadabra.end(), b);
    if (it != abracadabra.end()) {
        abracadabra.erase(it);
        return true;
    }
    else {
        throw ExceptionBiletInexistent();
    }
    return false;
}

bool Repository::payItem(double bIntroduse, double bPret) {

    if (bIntroduse - bPret < 0.001) {
        throw ExceptionFonduriInsuficiente();
    }

    vector<double> bancnoteStandard = {500, 200, 100, 50, 20, 10, 5, 1};
    vector<double> bancnoteRest;

    double baniAutomat = bIntroduse;
    for (double b : bancnoteStandard) {
        while (baniAutomat >= b - 0.001) {
            bancnoteDisponibile.push_back(b);
            baniAutomat -= b;
        }
    }

    double restAutomat = bIntroduse - bPret;
    for (double b : bancnoteDisponibile) {
        if (b <= restAutomat + 0.001) {
            bancnoteRest.push_back(b);
            restAutomat -= b;
        }
        if (restAutomat <= 0.001) break;
    }

    if (restAutomat > 0.001) {
        throw ExceptionBancnoteInsuficiente();
    };

    for (double r : bancnoteRest) {
        auto it = find(bancnoteDisponibile.begin(), bancnoteDisponibile.end(), r);
        if (it != bancnoteDisponibile.end()) {
            bancnoteDisponibile.erase(it);
        }
    }
    return true;
}

void Repository::addBancnota(double b) {
    bancnoteDisponibile.push_back(b);
}

vector<Bilet> Repository::getAll() {
    return abracadabra;
}

vector<double> Repository::getAllBancnote() {
    return bancnoteDisponibile;
}
