#include "testRepository.h"
#include "Repository.h"
#include <cassert>

void testRepository() {
    Repository repo;
    Bilet bilet1(1, "Bilet urban", 3);
    Bilet bilet2(2, "Bilet interurban", 6);
    Bilet bilet3(3, "Abonament zilnic", 10);
    Bilet bilet4(4, "Abonament saptamanal", 50);
    repo.addItem(bilet1);
    repo.addItem(bilet2);
    repo.addItem(bilet3);
    repo.addItem(bilet4); //test addItem
    assert(repo.findItem(bilet1) == true);
    assert(repo.findItem(bilet2) == true);
    assert(repo.findItem(bilet3) == true);
    assert(repo.findItem(bilet4) == true); //test findItem
    repo.deleteItem(bilet4);
    assert(repo.findItem(bilet4) == false); //test delItem
    repo.updateItem(bilet2, bilet3);
    vector<Bilet> automat = repo.getAll();
    assert(automat[0] == bilet1);
    assert(automat[1] == bilet3);
    assert(automat[2] == bilet3);
    assert(automat.size() == 3); //test getAll, addItem
    for (int i = 0 ; i < 20 ; ++i)
        repo.addBancnota(1);
    for (int i = 0 ; i < 20 ; ++i)
        repo.addBancnota(5);
    vector<double> bancnote = repo.getAllBancnote();
    // repo.payItem(20, 10);
    // assert(!repo.payItem(10, 20));
    // assert(repo.payItem(130, 0));
    // assert(!repo.payItem(10, 20));
    // assert(!repo.payItem(130, 1)); //test addBancnota, payItem
    for (int i = 0; i < 20 ; ++i)
        assert(bancnote[i] == 1);
    for (int i = 20 ; i < 40 ; ++i)
        assert(bancnote[i] == 5); //test getAllBancnote
}