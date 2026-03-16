#include "UI.h"
#include <iostream>
#include "RepositoryFile.h"
#include "ValidatorDenumire.h"

void UI::adaugareBilet() {
    cout << "Adaugati un nou bilet: " << endl;
    int cod, pret;
    string denumire;
    cout << "Codul biletului: " << endl;
    cin >> cod;
    cout << "Denumirea biletului: " << endl;
    cin.ignore();
    getline(cin, denumire);
    cout << "Pretul biletului: " << endl;
    cin >> pret;
    serv.addItemServ(cod, denumire, pret);
}

void UI::cautareBilet() {
    cout << "Cautarea unui bilet: " << endl;
    int cod, pret;
    string denumire;
    cout << "Codul biletului: " << endl;
    cin >> cod;
    cout << "Denumirea biletului: " << endl;
    cin.ignore();
    getline(cin, denumire);
    cout << "Pretul biletului: " << endl;
    cin >> pret;
    bool gasit = serv.findItemServ(cod, denumire, pret);
    if (gasit) {
        cout << "Biletul a fost gasit. " << endl;
    }
    else {
        cout << "Biletul NU a fost gasit. " << endl;
    }
}

void UI::actualizareBilet() {
    cout << "Modificarea datelor unui bilet cu informatiile: " << endl;
    int codVechi, pretVechi;
    string denumireVeche;
    cout << "Codul biletului: " << endl;
    cin >> codVechi;
    cout << "Denumirea biletului: " << endl;
    cin.ignore();
    getline(cin, denumireVeche);
    cout << "Pretul biletului: " << endl;
    cin >> pretVechi;
    cout << "Cu noile informatii: " << endl;
    int codNou, pretNou;
    string denumireNoua;
    cout << "Codul biletului: " << endl;
    cin >> codNou;
    cout << "Denumirea biletului: " << endl;
    cin.ignore();
    getline(cin, denumireNoua);
    cout << "Pretul biletului: " << endl;
    cin >> pretNou;
    bool actualizat = serv.updateItemServ(codVechi, denumireVeche, pretVechi, codNou, denumireNoua, pretNou);
    if (actualizat) {
        cout << "Biletul a fost actualizat. " << endl;
    }
    else {
        cout << "Biletul NU a fost actualizat. " << endl;
    }
}

void UI::stergereBilet() {
    cout << "Stergerea unui bilet: " << endl;
    int cod, pret;
    string denumire;
    cout << "Codul biletului: " << endl;
    cin >> cod;
    cout << "Denumirea biletului: " << endl;
    cin.ignore();
    getline(cin, denumire);
    cout << "Pretul biletului: " << endl;
    cin >> pret;
    try {
        serv.deleteItemServ(cod, denumire, pret);
        cout << "Biletul a fost sters. " << endl;
    }
    catch (const ExceptionBiletInexistent& e) {
        cout << "Eroare: " << e.what() << endl;
    }
}

void UI::cumparareBilet() {
    cout << "Automatul dispune de bancnotele/monezile: " << endl;
    vector<double> all = serv.getAllBancnotaServ();
    for(double crt:all)
    {
        cout << crt << ", ";
    }
    cout << endl << "Si de biletele: " << endl;
    vector<Bilet> all2 = serv.getAllServ();
    int i = 0;
    for(Bilet crt:all2)
    {
        ++i;
        cout << crt.toString() << ", ";
        if (i % 5 == 0) {
            cout << endl;
        }
    }
    cout << endl << "Ce fel de bilet doriti? " << endl;
    int cod, pret, numerar;
    string denumire;
    ValidatorBilet validareBilet;
    ValidatorDenumire validareDenumire;
    cout << "Codul biletului: " << endl;
    cin >> cod;
    cout << "Denumirea biletului: " << endl;
    cin.ignore();
    getline(cin, denumire);
    cout << "Pretul biletului: " << endl;
    cin >> pret;

    if (!validareDenumire.validate(denumire)) {
        cout << "Denumire invalida. " << endl;
        return;
    }

    if (!validareBilet.validate(cod, denumire, pret)) {
        cout << "Bilet invalid. " << endl;
        return;
    }

    cout << "Introduceti numerar: " << endl;
    cin >> numerar;

    try {
        bool reusit = serv.payItemServ(numerar, pret);
        if (reusit) {
            cout << "Achizitie acceptata! " << endl;
            cout << "Restul Dumneavoastra este de " << numerar - pret << " lei." << endl;
            serv.deleteItemServ(cod, denumire, pret);
        }
        else {
            cout << "Tranzactia a esuat din motive tehnice. " << endl;
        }
    }
    catch (const ExceptionBiletInexistent& e) {
        cout << "Eroare: " << e.what() << endl;
    }
    catch (const ExceptionFonduriInsuficiente& e) {
        cout << "Eroare: " << e.what() << endl;
    }
    catch (const Exception& e) {
        cout << "Eroare generala: " << e.what() << endl;
    }
}

UI::UI(const Service& s) : serv(s) {}

void afisareMeniu() {
    cout << "0. Exit " << endl;
    cout << "1. Adaugare bilet. " << endl;
    cout << "2. Cautare bilet. " << endl;
    cout << "3. Actualizare bilet. " << endl;
    cout << "4. Stergere bilet. " << endl;
    cout << "5. Cumparare bilet. " << endl;
    cout << "Introduceti optiunea: " << endl;
}

void UI::showMenu() {
    afisareMeniu() ;
    RepositoryFile RepoFile;
    RepoFile.loadFromFile("bilete.txt");
    RepoFile.printAll();
    int opt;
    for (int i = 0 ; i < 20 ; ++i)
        serv.addBancnotaServ(1);
    for (int i = 0 ; i < 20 ; ++i)
        serv.addBancnotaServ(5);
    for (int i = 0 ; i < 20 ; ++i)
        serv.addBancnotaServ(10);
    for (int i = 0 ; i < 20 ; ++i)
        serv.addBancnotaServ(20);
    for (int i = 0 ; i < 20 ; ++i)
        serv.addBancnotaServ(50);
    for (int i = 0; i < 5; ++i)
        serv.addItemServ(1, "Urban", 3);
    for (int i = 0; i < 5; ++i)
        serv.addItemServ(2, "Interurban", 6);
    for (int i = 0; i < 5; ++i)
        serv.addItemServ(3, "Abonament zilnic", 10);
    for (int i = 0; i < 5; ++i)
        serv.addItemServ(4, "Abonament saptamanal", 40);
    cin >> opt;
    while (opt != 0) {
        switch (opt) {
            case 1:
                adaugareBilet();
                break;
            case 2:
                cautareBilet();
                break;
            case 3:
                actualizareBilet();
                break;
            case 4:
                stergereBilet();
                break;
            case 5:
                cumparareBilet();
            default:
                break;
        }
        afisareMeniu();
        cin >> opt;
    }
    if (opt == 0)
        cout << "Inchidere aplicatie. " << endl;
}
