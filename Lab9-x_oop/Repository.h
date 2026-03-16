#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Bilet.h"
#include <vector>
#include "Exception.h"
#include "ExceptionBiletInexistent.h"
#include "ExceptionFonduriInsuficiente.h"
#include "ValidatorBilet.h"
using namespace std;

class Repository {
protected:
    vector<Bilet> abracadabra;
    vector<double> bancnoteDisponibile;
public:
    bool addItem(const Bilet&);
    bool findItem(const Bilet&);
    bool updateItem(const Bilet&, const Bilet&);
    bool deleteItem(const Bilet&);
    bool payItem(double, double);
    void addBancnota(double);
    vector<Bilet> getAll();
    vector<double> getAllBancnote();
};



#endif //REPOSITORY_H
