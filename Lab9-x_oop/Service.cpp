//
// Created by albaa on 5/7/2025.
//

#include "Service.h"

Service::Service(Repository* r) {
    this -> repo = r;
}

bool Service::addItemServ(int c, string d, int p) {
    Bilet b(c, d, p);
    repo -> addItem(b);
    return true;
}

bool Service::findItemServ(int c, string d, int p) {
    Bilet b(c, d, p);
    return repo -> findItem(b);
}

bool Service::updateItemServ(int cVechi, string dVeche, int pVechi, int cNou, string dNoua, int pNou) {
    Bilet vechi(cVechi, dVeche, pVechi);
    Bilet nou(cNou, dNoua, pNou);
    return repo -> updateItem(vechi, nou);
}

bool Service::deleteItemServ(int c, string d, int p) {
    Bilet b(c, d, p);
    return repo -> deleteItem(b);
}

bool Service::payItemServ(double n, double p) {
    return repo -> payItem(n, p);
}

void Service::addBancnotaServ(double p) {
    return repo -> addBancnota(p);
}

vector<Bilet> Service::getAllServ() {
    return repo -> getAll();
}

vector<double> Service::getAllBancnotaServ() {
    return repo -> getAllBancnote();
}
