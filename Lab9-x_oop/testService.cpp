#include "testService.h"
#include "Service.h"
#include <cassert>

void testService() {
    auto* repo = new Repository();
    Service service(repo);
    service.addItemServ(1, "Bilet urban", 3);
    service.addItemServ(2, "Bilet interurban", 6);
    service.addItemServ(3, "Abonament zilnic", 10);
    assert(service.findItemServ(1, "Bilet urban", 3));
    assert(service.findItemServ(2, "Bilet interurban", 6));
    assert(service.findItemServ(3, "Abonament zilnic", 10)); //test addItemServ, findItemServ
    service.updateItemServ(3, "Abonament zilnic", 10, 4, "Abonament saptamanal", 40);
    assert(service.findItemServ(4, "Abonament saptamanal", 40)); //test updateItemServ
    service.deleteItemServ(1, "Bilet urban", 3);
    assert(!service.findItemServ(1, "Bilet urban", 3)); //test deleteItemServ
    for (int i = 0 ; i < 20 ; ++i)
        service.addBancnotaServ(1);
    for (int i = 0 ; i < 20 ; ++i)
        service.addBancnotaServ(5);
    // assert(service.payItemServ(20, 10));
    // assert(!service.payItemServ(10, 20));
    // assert(service.payItemServ(130, 0));
    // assert(!service.payItemServ(141, 0)); //test addBancnotaServ, payItemServ
    delete repo;
}