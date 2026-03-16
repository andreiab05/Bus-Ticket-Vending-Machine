#include "testRepositoryFile.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include "RepositoryFile.h"
using namespace std;

void testRepositoryFile() {
    ofstream out("test_bilete.txt");
    out << "1 Urban 3\n";
    out << "2 Interurban 6\n";
    out.close();

    RepositoryFile repo;
    repo.loadFromFile("test_bilete.txt");

    const vector<Bilet>& all = repo.getAll();

    assert(all.size() == 2);
    assert(all[0] == Bilet(1, "Urban", 3));
    assert(all[1] == Bilet(2 , "Interurban", 6)); //test loadFromFile
}
