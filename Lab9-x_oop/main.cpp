#include "testRepository.h"
#include "testService.h"
#include "testRepositoryFile.h"
#include "UI.h"

int main() {
    testRepositoryFile();
    testRepository();
    testService();
    auto* repo = new Repository();
    Service service(repo);
    UI interface(service);
    interface.showMenu();
    delete repo;
    return 0;
}