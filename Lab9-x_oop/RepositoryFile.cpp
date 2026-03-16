#include "RepositoryFile.h"
#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


void RepositoryFile::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cerr << "Can't open file " << filename << endl;
        return;
    }
    string line;
    while (getline(in, line)) {
        istringstream iss(line);
        int cod, pret;
        string denumire;

        replace(line.begin(), line.end(), ',', ' ');
        istringstream linestream(line);
        if (linestream >> cod >> denumire >> pret) {
            abracadabra.emplace_back(cod, denumire, pret);
        }
    }
    in.close();
}

void RepositoryFile::printAll() const {
    for (const auto& b : abracadabra) {
        cout << b.getCod() << " " << b.getDenumire() << " " << b.getPret() << endl;
    }
}

